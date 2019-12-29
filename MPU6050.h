/*
* Defines necessary registers and constants used to communicate with the MPU6050 module.
* All data was gathered from online available datasheets
*/

#ifndef MPU6050GUARD
#define  MPU6050GUARD

#include <inttypes.h>

//H = HIGH
//L = LOW
//ACCELERATION REGISTERS
#define X_ACCEL_H 3B
#define X_ACCEL_L 3C
#define Y_ACCEL_H 3D
#define Y_ACCEL_L 3E
#define Z_ACCEL_H 3F
#define Z_ACCEL_L 40

//GYROSCOPE REGISTERS
#define X_GYRO_H 43
#define X_GYRO_L 44
#define Y_GYRO_H 45
#define Y_GYRO_L 46
#define Z_GYRO_H 47
#define Z_GYRO_L 48


int8_t i2cread(int8_t address);
int16_t combnum(int8_t num1, int8_t num2);


#endif
