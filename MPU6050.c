#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/i2c-dev.h>
#include <i2c/smbus.h>
#include "MPU6050.h"

/*
* Tries to open the I2C bus and communicate 
* with the device found in the specified address.
* @param addr Addrss for the I2C device. Can be found
* with i2cdetect
* Returns the file descriptor for the bus if successful. 
* Returns -1 if the operation failed
*/
int8_t openbus(int8_t addr)
{
	int8_t file = open("/dev/i2c-1", O_RDWR);
	if(file < 0) { return -1; }
	if(ioctl(file, I2C_SLAVE, addr) < 0) { return -1; }
	return file;
}

/*
* Combines two bytes into a 16 bit number and returns it
*/
int16_t comb_bytes(unsigned char highbyte, unsigned char lowbyte)
{
	int16_t retval = (int16_t)highbyte << 8 | lowbyte;
	return retval;
}

/*
* Reads the byte found in the register passed trough the parameters
* and the next one after it (+1) to combine them into a 16 bit
* number. The first byte is considered the highbyte. 
* @param fladdr The file descriptor for the I2C bus.
* @param reg The register where the first byte will be read from. 
* The next byte will be read from reg + 1
*/
int16_t rdwrd(int8_t fladdr, int8_t reg)
{
	unsigned char highbyte = i2c_smbus_read_byte_data(fladdr, reg); 
	unsigned char lowbyte = i2c_smbus_read_byte_data(fladdr, reg);
	int16_t retval = comb_bytes(highbyte, lowbyte);
	return retval;
}

/*
* Reads the high and low byte from the temperature registers, combines them
* into a 16 bit number and performas the mathematical equation stated
* in the documentation to get the temperature from the internal 
* thermometer.
* @param fladdr File descriptor for the I2C bus.
*/
int16_t get_temp(int8_t fladdr)
{
	int16_t retval = rdwrd(fladdr, TEMP_OUT_H);
	retval  /= 340;
	retval += 36.53;
	return retval;
}
