/*
 * motor.h
 *
 *  Created on: Aug 4, 2023
 *      Author: Hien Nguyen && Hoan Duong
  *  Contact information
 *  -------------------
 *
 * e-mail   : duongngochoan852002@gmail.com
 */

#ifndef INC_MOTOR_H_
#define INC_MOTOR_H_



#endif /* INC_MOTOR_H_ */


#include <stdint.h>
#include "main.h"
#include <stm32f1xx_hal_tim.h>

#define		MAX_CNT			1899
#define 	MIN_CNT			100
//# define	P_PART_MAX		0
//# define	P_PART_MIN		0
//#define		I_PART_MAX		3
//# define	I_PART_MIN		0
//#define		D_PART_MAX		3
//# define	D_PART_MIN		0
#define 	U_MAX			1
#define		EPSILON			0.3
#define 	TIME_EXAMPLE	10 		// 10ms
#define 	ANGLE_THRESHOLD	60


typedef struct
{
	float	f_Kp;
	float	f_Ki;
	float	f_Kd;
	float   f_P_part;
	float 	f_I_part;
	float	f_D_part;
	float 	f_ek;
	float	f_ek_1;
	float   f_ek_2;
	float	f_uk;		// -1 -> 1
	float	f_uk1;
	float 	f_setpoint;	// angle when robot balance

} PID_t;

TIM_HandleTypeDef htim3;
TIM_HandleTypeDef htim4;


void Init_tim_pwm();
void Forward (float duty);
void Reverse (float duty);
void PID_controller(double new_angle, PID_t *pid);
void Control_motor(double new_angle, PID_t *pid);
void Reset_PID(PID_t *pid);
static void Stop_motor();
static void Set_duty(float duty, TIM_HandleTypeDef *htim, int channel); // duty 0-1

