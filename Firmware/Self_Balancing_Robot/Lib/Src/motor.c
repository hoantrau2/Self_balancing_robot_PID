/*
 * motor.c
 *
 *  Created on: Aug 4, 2023
 *      Author: Hien Nguyen && Hoan Duong
  *  Contact information
 *  -------------------
 *
 * e-mail   :  duongngochoan852002@gmail.com
 */

#include "motor.h"



static void Set_duty(float duty, TIM_HandleTypeDef *htim, int channel){
	if (channel == 1){
		htim->Instance->CCR1 =  (duty*MAX_CNT) + MIN_CNT;
	}
	if (channel == 2){
		htim->Instance->CCR2 =  (duty*MAX_CNT) + MIN_CNT;
	}
}

void Init_tim_pwm(){
	HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_2);
	HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_2);
}

static void Stop_motor(){
	Set_duty(0, &htim3, 1);
	Set_duty(0, &htim3, 2);
	Set_duty(0, &htim4, 1);
	Set_duty(0, &htim4, 2);
}

void Forward (float duty){
	Set_duty(0, &htim3, 1);
	Set_duty(duty, &htim3, 2);
	Set_duty(0, &htim4, 1);
	Set_duty(duty, &htim4, 2);
}

void Reverse (float duty){
	Set_duty(duty, &htim3, 1);
	Set_duty(0, &htim3, 2);
	Set_duty(duty, &htim4, 1);
	Set_duty(0, &htim4, 2);
}

void PID_controller(double new_angle, PID_t *pid){
	pid->f_ek 		= new_angle - pid->f_setpoint;
	pid->f_P_part	= pid->f_Kp*(pid->f_ek-pid->f_ek_1);
	pid->f_I_part	= 0.5*pid->f_Ki*TIME_EXAMPLE*(pid->f_ek+pid->f_ek_1);
	pid->f_D_part	= pid->f_Kd*(pid->f_ek-2*pid->f_ek_1+pid->f_ek_2)/TIME_EXAMPLE;
	pid->f_uk		= pid->f_uk1 +pid->f_P_part+pid->f_I_part+pid->f_D_part;
	if(pid->f_uk> U_MAX)  pid->f_uk = U_MAX;
	if(pid->f_uk<-U_MAX) pid->f_uk = -U_MAX;
	pid->f_ek_2		= pid->f_ek_1;
	pid->f_ek_1		= pid->f_ek;
	pid->f_uk1		= pid->f_uk;
}

void Control_motor(double new_angle, PID_t *pid){
	if((new_angle>ANGLE_THRESHOLD)|(new_angle<(-1)*ANGLE_THRESHOLD)){
		Stop_motor();
		return;
	}
	if (pid->f_ek >= EPSILON){
		Forward (pid->f_uk);
		return;
	}
	else if (pid->f_ek <= -EPSILON){
		Reverse ((-1)*pid->f_uk);
		return;
	}
	else {
		Stop_motor();
		return;
	}
}

void Reset_PID(PID_t *pid){
	pid->f_P_part 	= 0.0;
	pid->f_I_part 	= 0.0;
	pid->f_D_part 	= 0.0;
	pid->f_ek		= 0.0;
	pid->f_ek_1		= 0.0;
	pid->f_ek_2		= 0.0;
	pid->f_uk		= 0.0;
	pid->f_uk1		= 0.0;
}
