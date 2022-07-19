#include <Wire.h>
#include <Mecanum_motor.h>
Mecanum carx(0x55, &Wire);
void setup() {
  Serial.begin(115200);
  Wire.begin();
  carx.begin();
  carx.Set_kp(0.2);
  carx.Set_ki(0);
  carx.Set_kd(0);
  carx.Set_motor_max_rpm(300);
  carx.Set_max_rpm_ratio(0.8);
  carx.Set_motor_operating_voltage(8.4);
  carx.Set_motor_power_max_voltage(8.4);
  carx.Set_wheel_diameter(0.048);
  carx.Set_wheels_y_distance(0.15);
  carx.Set_motor1_invert(1);
  carx.Set_motor2_invert(1);
  carx.Set_motor3_invert(1);
  carx.Set_motor4_invert(1);
  carx.Set_encoder_CPR(800);
  carx.Set_B_motor1(0);
  carx.Set_B_motor2(0);
  carx.Set_B_motor3(0); 
  carx.Set_B_motor4(0);
  Serial.println(carx.Read_battery()); 

}

void loop() {
  carx.Set_motorxyz(0,0,0);
  delay(10);
}
