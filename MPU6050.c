#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/i2c-dev.h>
#include "MPU6050.h"

/*
* Tries to open the I2C bus and communicate 
* with the device found in the specified address.
* Returns the file descriptor for the bus if successful. 
*¨Returns -1 if the operation failed
*/
int8_t openbus(int8_t addr)
{
	int8_t file = open("/dev/i2c-1", O_RDWR);
	if(file < 0) { return -1; }
	if(ioctl(file, I2C_SLAVE, addr) < 0) { return -1; }
	return file;
}
