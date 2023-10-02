#ifndef __Mecanum_motor_CPP__
#define __Mecanum_motor_CPP__

#include "Arduino.h"
#include <Mecanum_motor.h>

Mecanum::Mecanum(int address, TwoWire* bus) {
	this->addr = address;
	this->wire = bus;
}
float Mecanum::value_limit(float _value, float  min, float  max){
    if (_value < min ){
        _value = min;
    }
    if (_value > max ){
        _value = max;
    }
    return _value;
}
void Mecanum::begin() {
	delay(180);
}
void Mecanum::Set_motorxyz(float _valuex, float _valuey, float _valuez){
	_valuex = value_limit(_valuex, -1.0, 1.0);
    _valuey = value_limit(_valuey, -1.0, 1.0);
    _valuez = value_limit(_valuez, -1.0, 1.0);
    Inmo.x = _valuex;
    Inmo.y = _valuey;
    Inmo.z = _valuez;
    this->wire->beginTransmission(this->addr);
    this->wire->write(0x02); 
	this->wire->write((byte *)&Inmo, sizeof Inmo); 
	this->wire->endTransmission();
}
void Mecanum::Set_kp(float _value){
	_value = value_limit(_value, 0.0, 600.0);
	byte datax[4];
	memcpy(&datax, &_value, 4);
	this->wire->beginTransmission(this->addr);
	this->wire->write(0x11);
	this->wire->write(datax, 4); 
	this->wire->endTransmission();
}
void Mecanum::Set_ki(float _value){
	_value = value_limit(_value, 0.0, 600.0);
	byte datax[4];
	memcpy(&datax, &_value, 4);
	this->wire->beginTransmission(this->addr);
	this->wire->write(0x12);
	this->wire->write(datax, 4); 
	this->wire->endTransmission();
}
void Mecanum::Set_kd(float _value){
	_value = value_limit(_value, 0.0, 600.0);
	byte datax[4];
	memcpy(&datax, &_value, 4);
	this->wire->beginTransmission(this->addr);
	this->wire->write(0x13);
	this->wire->write(datax, 4); 
	this->wire->endTransmission();
}
void Mecanum::Set_motor_max_rpm(int32_t _value){
	_value = (int)value_limit(_value, 0.0, 1000.0);
	byte datax[4];
	memcpy(&datax, &_value, 4);
	this->wire->beginTransmission(this->addr);
	this->wire->write(0x14);
	this->wire->write(datax, 4); 
	this->wire->endTransmission();
}
void Mecanum::Set_max_rpm_ratio(float _value){
	_value = value_limit(_value, 0.0, 1.0);
	byte datax[4];
	memcpy(&datax, &_value, 4);
	this->wire->beginTransmission(this->addr);
	this->wire->write(0x15);
	this->wire->write(datax, 4); 
	this->wire->endTransmission();
}
void Mecanum::Set_motor_operating_voltage(float _value){
	_value = value_limit(_value, 0.0, 14.0);
	byte datax[4];
	memcpy(&datax, &_value, 4);
	this->wire->beginTransmission(this->addr);
	this->wire->write(0x16);
	this->wire->write(datax, 4); 
	this->wire->endTransmission();
}
void Mecanum::Set_motor_power_max_voltage(float _value){
	_value = value_limit(_value, 0.0, 14.0);
	byte datax[4];
	memcpy(&datax, &_value, 4);
	this->wire->beginTransmission(this->addr);
	this->wire->write(0x17);
	this->wire->write(datax, 4); 
	this->wire->endTransmission();
}
void Mecanum::Set_wheel_diameter(float _value){
	_value = value_limit(_value, 0.0, 1.0);
	byte datax[4];
	memcpy(&datax, &_value, 4);
	this->wire->beginTransmission(this->addr);
	this->wire->write(0x18);
	this->wire->write(datax, 4); 
	this->wire->endTransmission();
}
void Mecanum::Set_wheels_y_distance(float _value){
	_value = value_limit(_value, 0.0, 1.0);
	byte datax[4];
	memcpy(&datax, &_value, 4);
	this->wire->beginTransmission(this->addr);
	this->wire->write(0x19);
	this->wire->write(datax, 4); 
	this->wire->endTransmission();
}
void Mecanum::Set_motor1_invert(int32_t _value){
	_value = (int)value_limit(_value, -1.0, 1.0);
	byte datax[4];
	memcpy(&datax, &_value, 4);
	this->wire->beginTransmission(this->addr);
	this->wire->write(0x1A);
	this->wire->write(datax, 4); 
	this->wire->endTransmission();
}
void Mecanum::Set_motor2_invert(int32_t _value){
	_value = (int)value_limit(_value, -1.0, 1.0);
	byte datax[4];
	memcpy(&datax, &_value, 4);
	this->wire->beginTransmission(this->addr);
	this->wire->write(0x1B);
	this->wire->write(datax, 4); 
	this->wire->endTransmission();
}
void Mecanum::Set_motor3_invert(int32_t _value){
	_value = (int)value_limit(_value, -1.0, 1.0);
	byte datax[4];
	memcpy(&datax, &_value, 4);
	this->wire->beginTransmission(this->addr);
	this->wire->write(0x1C);
	this->wire->write(datax, 4); 
	this->wire->endTransmission();
}
void Mecanum::Set_motor4_invert(int32_t _value){
	_value = (int)value_limit(_value, -1.0, 1.0);
	byte datax[4];
	memcpy(&datax, &_value, 4);
	this->wire->beginTransmission(this->addr);
	this->wire->write(0x1D);
	this->wire->write(datax, 4); 
	this->wire->endTransmission();
}
void Mecanum::Set_encoder_CPR(int32_t _value){
	_value = (int)value_limit(_value, 0.0, 15000.0);
	byte datax[4];
	memcpy(&datax, &_value, 4);
	this->wire->beginTransmission(this->addr);
	this->wire->write(0x1E);
	this->wire->write(datax, 4); 
	this->wire->endTransmission();
}
void Mecanum::Set_B_motor1(int32_t _value){
	_value = (int)value_limit(_value, 0.0, 5.0);
	byte datax[4];
	memcpy(&datax, &_value, 4);
	this->wire->beginTransmission(this->addr);
	this->wire->write(0x30);
	this->wire->write(datax, 4); 
	this->wire->endTransmission();
}
void Mecanum::Set_B_motor2(int32_t _value){
	_value = (int)value_limit(_value,0.0,5.0);
	byte datax[4];
	memcpy(&datax, &_value, 4);
	this->wire->beginTransmission(this->addr);
	this->wire->write(0x31);
	this->wire->write(datax, 4); 
	this->wire->endTransmission();
}
void Mecanum::Set_B_motor3(int32_t _value){
	_value = (int)value_limit(_value,0.0,5.0);
	byte datax[4];
	memcpy(&datax, &_value, 4);
	this->wire->beginTransmission(this->addr);
	this->wire->write(0x32);
	this->wire->write(datax, 4); 
	this->wire->endTransmission();
}
void Mecanum::Set_B_motor4(int32_t _value){
	_value = (int)value_limit(_value,0.0,5.0);
	byte datax[4];
	memcpy(&datax, &_value, 4);
	this->wire->beginTransmission(this->addr);
	this->wire->write(0x33);
	this->wire->write(datax, 4); 
	this->wire->endTransmission();
}
void Mecanum::Set_mode(uint8_t _value){
	_value = value_limit(_value, 0, 1);
	this->wire->beginTransmission(this->addr);
	this->wire->write(0x40);
	this->wire->write(_value); 
	this->wire->endTransmission();
}
void Mecanum::Set_motor1(float _value){
	_value = value_limit(_value, -3.0, 3.0);
	byte datax[4];
	memcpy(&datax, &_value, 4);
	this->wire->beginTransmission(this->addr);
	this->wire->write(0x41);
	this->wire->write(datax, 4); 
	this->wire->endTransmission();
}
void Mecanum::Set_motor2(float _value){
	_value = value_limit(_value, -3.0, 3.0);
	byte datax[4];
	memcpy(&datax, &_value, 4);
	this->wire->beginTransmission(this->addr);
	this->wire->write(0x42);
	this->wire->write(datax, 4); 
	this->wire->endTransmission();
}
void Mecanum::Set_motor3(float _value){
	_value = value_limit(_value, -3.0, 3.0);
	byte datax[4];
	memcpy(&datax, &_value, 4);
	this->wire->beginTransmission(this->addr);
	this->wire->write(0x43);
	this->wire->write(datax, 4); 
	this->wire->endTransmission();
}
void Mecanum::Set_motor4(float _value){
	_value = value_limit(_value, -3.0, 3.0);
	byte datax[4];
	memcpy(&datax, &_value, 4);
	this->wire->beginTransmission(this->addr);
	this->wire->write(0x44);
	this->wire->write(datax, 4); 
	this->wire->endTransmission();
}
void Mecanum::Reset_counter_motor1(){
	this->wire->beginTransmission(this->addr);
	this->wire->write(0x45);
	this->wire->endTransmission();
}
void Mecanum::Reset_counter_motor2(){
	this->wire->beginTransmission(this->addr);
	this->wire->write(0x46);
	this->wire->endTransmission();
}
void Mecanum::Reset_counter_motor3(){
	this->wire->beginTransmission(this->addr);
	this->wire->write(0x47);
	this->wire->endTransmission();
}
void Mecanum::Reset_counter_motor4(){
	this->wire->beginTransmission(this->addr);
	this->wire->write(0x48);
	this->wire->endTransmission();
}
float Mecanum::Read_battery(){
	this->wire->beginTransmission(this->addr);
	this->wire->write(0x20); 
	this->wire->endTransmission();
	this->wire->requestFrom(this->addr,4);
	uint8_t datay[4];
	for (int i = 0; i < 4; i++) {
	    datay[i] =  this->wire->read();
	}
	delay(10);
	this->wire->beginTransmission(this->addr);
	this->wire->write(0x20); 
	this->wire->endTransmission();
	this->wire->requestFrom(this->addr,4);
	for (int i = 0; i < 4; i++) {
	    datay[i] =  this->wire->read();
	}
	float xxxx = 0;
	memcpy(&xxxx, &datay, 4);
	return xxxx;
}
int32_t Mecanum::Read_counter_motor1(){
	this->wire->beginTransmission(this->addr);
	this->wire->write(0x21); 
	this->wire->endTransmission();
	this->wire->requestFrom(this->addr, 4);
	byte datay[4];
	for (int i = 0; i < 4; i++) {
	    datay[i] =  this->wire->read();
	}
	delay(10);
	this->wire->beginTransmission(this->addr);
	this->wire->write(0x21); 
	this->wire->endTransmission();
	this->wire->requestFrom(this->addr, 4);
	for (int i = 0; i < 4; i++) {
	    datay[i] =  this->wire->read();
	}
	int32_t xxxx = 0;
	memcpy(&xxxx, &datay, 4);
	return xxxx;
}
int32_t Mecanum::Read_counter_motor2(){
	this->wire->beginTransmission(this->addr);
	this->wire->write(0x22); 
	this->wire->endTransmission();
	uint8_t res = this->wire->requestFrom(this->addr, 4);
	byte datay[4];
	for (int i = 0; i < 4; i++) {
	    datay[i] =  this->wire->read();
	}
	delay(10);
	this->wire->beginTransmission(this->addr);
	this->wire->write(0x22); 
	this->wire->endTransmission();
	res = this->wire->requestFrom(this->addr, 4);
	for (int i = 0; i < 4; i++) {
	    datay[i] =  this->wire->read();
	}
	int32_t xxxx = 0;
	memcpy(&xxxx, &datay, 4);
	return xxxx;
}
int32_t Mecanum::Read_counter_motor3(){
	this->wire->beginTransmission(this->addr);
	this->wire->write(0x23); 
	this->wire->endTransmission();
	uint8_t res = this->wire->requestFrom(this->addr, 4);
	byte datay[4];
	for (int i = 0; i < 4; i++) {
	    datay[i] =  this->wire->read();
	}
	delay(10);
	this->wire->beginTransmission(this->addr);
	this->wire->write(0x23); 
	this->wire->endTransmission();
	res = this->wire->requestFrom(this->addr, 4);
	for (int i = 0; i < 4; i++) {
	    datay[i] =  this->wire->read();
	}
	int32_t xxxx = 0;
	memcpy(&xxxx, &datay, 4);
	return xxxx;
}
int32_t Mecanum::Read_counter_motor4(){
	this->wire->beginTransmission(this->addr);
	this->wire->write(0x24); 
	this->wire->endTransmission();
	uint8_t res = this->wire->requestFrom(this->addr, 4);
	byte datay[4];
	for (int i = 0; i < 4; i++) {
	    datay[i] =  this->wire->read();
	}
	this->wire->beginTransmission(this->addr);
	this->wire->write(0x24); 
	this->wire->endTransmission();
	res = this->wire->requestFrom(this->addr, 4);
	for (int i = 0; i < 4; i++) {
	    datay[i] =  this->wire->read();
	}
	int32_t xxxx = 0;
	memcpy(&xxxx, &datay, 4);
	return xxxx;
}
#endif