/*
* Defines necessary registers and constants used to communicate with the MPU6050 module.
* All data was gathered from online available datasheets.
*/

#ifndef MPU6050GUARD
#define  MPU6050GUARD

#include <inttypes.h>

#define ACCEL_CONFIG 0x1C

//H = HIGH
//L = LOW
#define ACCEL_XOUT_H 0x3B
#define ACCEL_XOUT_L 0x3C
#define ACCEL_YOUT_H 0x3D
#define ACCEL_YOUT_L 0x3E
#define ACCEL_ZOUT_H 0x3F
#define ACCEL_ZOUT_L 0x40

#define TEMP_OUT_H 0x41
#define TEMP_OUT_L 0x42

#define GYRO_XOUT_H 0x43
#define GYRO_XOUT_L 0x44
#define GYRO_YOUT_H 0x45
#define GYRO_YOUT_L 0x46
#define GYRO_ZOUT_H 0x47
#define GYRO_ZOUT_L 0x48

#define PWR_MGMT_1 0x6B
#define PWR_MGMT_2 0x6C

int8_t openbus(int8_t addr);

int16_t comb_bytes(unsigned char highbyte, unsigned char lowbyte);
int16_t rdwrd(int8_t fladdr, int8_t reg);
int16_t get_temp(int8_t fladdr);

#endif
