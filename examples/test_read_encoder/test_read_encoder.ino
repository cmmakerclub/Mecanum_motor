#include <Wire.h>
#include <Mecanum_motor.h>
Mecanum carx(0x55, &Wire);
void setup() {
  Serial.begin(115200);
  Wire.begin();
  carx.begin();
  carx.Set_mode(0);  //ถ้าใช้ล้อ mecanum ให้เช็ตเป็น 0 แต่ถ้าอยากขับมอเตอร์แยกเป็บล้อให้ เช็ตเป็น 1
  delay(100);
  carx.Reset_counter_motor1();
  carx.Reset_counter_motor2();
  carx.Reset_counter_motor3();
  carx.Reset_counter_motor4();
  delay(200);
  Serial.println(carx.Read_battery());
  delay(100);

}

void loop() {
  Serial.print(carx.Read_counter_motor1());
  Serial.print(",");
  Serial.print(carx.Read_counter_motor2());
  Serial.print(",");
  Serial.print(carx.Read_counter_motor3());
  Serial.print(",");
  Serial.print(carx.Read_counter_motor4());
  Serial.println();
  delay(1000);
  
}
