#include <Wire.h>
#include <Mecanum_motor.h>
Mecanum carx(0x55, &Wire);
void setup() {
  Serial.begin(115200);
  Wire.begin();
  carx.begin();
  carx.Set_mode(1);
  delay(100);
  carx.Set_kp(0.2);
  delay(100);
  carx.Set_ki(0);
  delay(100);
  carx.Set_kd(0);
  delay(100);
  carx.Set_motor_max_rpm(300);
  delay(100);
  carx.Set_max_rpm_ratio(0.8);
  delay(100);
  carx.Set_motor_operating_voltage(12.0);
  delay(100);
  carx.Set_motor_power_max_voltage(12.0);
  delay(100);
  carx.Set_wheel_diameter(0.1);
  delay(100);
  carx.Set_wheels_y_distance(0.15);
  delay(100);
  carx.Set_motor1_invert(1);
  delay(100);
  carx.Set_motor2_invert(1);
  delay(100);
  carx.Set_motor3_invert(1);
  delay(100);
  carx.Set_motor4_invert(1);
  delay(100);
  carx.Set_encoder_CPR(1500);
  delay(100);
  carx.Set_B_motor1(1);
  delay(100);
  carx.Set_B_motor2(1);
  delay(100);
  carx.Set_B_motor3(1);
  delay(100);
  carx.Set_B_motor4(1);
  carx.Reset_counter_motor1();
  carx.Reset_counter_motor2();
  carx.Reset_counter_motor3();
  carx.Reset_counter_motor4();
  delay(2000);
  Serial.println(carx.Read_battery());
  delay(100);
  Serial.println(carx.Read_battery());
}

void loop() {
// carx.Set_motor3(0.03);
// carx.Set_motor1(0.03);
// delay(10);
  carx.Reset_counter_motor1();
  while(carx.Read_counter_motor1() < 3000){
    carx.Set_motor1(0.03);
    delay(10);
  }
  carx.Set_motor1(0.0);
  delay(1000);
  carx.Reset_counter_motor1();
  while(carx.Read_counter_motor1() > -3000){
    carx.Set_motor1(-0.03);
    delay(10);
  }
  carx.Set_motor1(0.0);
  delay(1000);
  
}
