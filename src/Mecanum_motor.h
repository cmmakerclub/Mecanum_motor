#ifndef __Mecanum_motor_H__
#define __Mecanum_motor_H__

#include "Arduino.h"
#include <Wire.h>

class Mecanum{
	private:
		TwoWire* wire;
		uint8_t addr = 0x55;
		float value_limit(float _value=0.0, float min=-30000.0, float max=30000.0);
		struct {
		  float x = 0;
		  float y = 0;
		  float z = 0;
		} Inmo;
		
	public:
		Mecanum(int address, TwoWire* bus=&Wire) ;
		void begin() ;
		void Set_motorxyz(float _valuex = 0.0, float _valuey = 0.0, float _valuez = 0.0);
		void Set_kp(float _value = 0.1);
	    void Set_ki(float _value = 0);
	    void Set_kd(float _value = 0);
	    void Set_motor_max_rpm(int32_t _value = 0);
	    void Set_max_rpm_ratio(float _value = 0);
	    void Set_motor_operating_voltage(float _value = 0);
	    void Set_motor_power_max_voltage(float _value = 0);
	    void Set_wheel_diameter(float _value = 0);
	    void Set_wheels_y_distance(float _value = 0);
	    void Set_motor1_invert(int32_t _value = 0);
	    void Set_motor2_invert(int32_t _value = 0);
	    void Set_motor3_invert(int32_t _value = 0);
	    void Set_motor4_invert(int32_t _value = 0);
	    void Set_encoder_CPR(int32_t _value = 0);
	    void Set_B_motor1(int32_t _value = 0);
	    void Set_B_motor2(int32_t _value = 0);
	    void Set_B_motor3(int32_t _value = 0);
	    void Set_B_motor4(int32_t _value = 0);
	    void Set_mode(uint8_t _value);
	    void Set_motor1(float _value);
	    void Set_motor2(float _value);
	    void Set_motor3(float _value);
	    void Set_motor4(float _value);
	    void Reset_counter_motor1();
	    void Reset_counter_motor2();
	    void Reset_counter_motor3();
	    void Reset_counter_motor4();
	    float Read_battery();
	    int32_t Read_counter_motor1();
	    int32_t Read_counter_motor2();
	    int32_t Read_counter_motor3();
	    int32_t Read_counter_motor4();
		// uint8_t readFB() ;
  //       uint8_t readLR() ;
  //       uint8_t readBT() ;
  //       void buzzer(uint8_t timelong = 0);
  //       void servomotor(uint8_t M2=0,uint8_t M3=0,uint8_t M4=0);
  //       void carmotor(uint8_t FB = 128,uint8_t LR = 128);
  //       void setname_bl(uint16_t _num = 0);
		
}
;

#endif