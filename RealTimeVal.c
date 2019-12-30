#include <stdio.h>
#include <stdlib.h>
#include <i2c/smbus.h>
#include <linux/i2c-dev.h>
#include <unistd.h>
#include "MPU6050.h"

int main(int argc, char *argv[])
{
	int8_t file = openbus(0x68);
	if(file < 0)
	{
		printf("ERROR");
		return 1;
	}
	printf("File descriptor is: %d\n", file);

	unsigned char  highbyte;
	unsigned char lowbyte;
	//I DONT KNOW WHY BUT I NEED THIS
	i2c_smbus_write_byte_data(file, PWR_MGMT_1, 0x00);
	while(1)
	{
		highbyte = i2c_smbus_read_byte_data(file, ACCEL_XOUT_H);
		lowbyte = i2c_smbus_read_byte_data(file, ACCEL_XOUT_L);
		int16_t combnum = (highbyte >> 8) | lowbyte;
		printf("\r X-axis acceleration  ==> %d", combnum);
	}

	return 0;
}
