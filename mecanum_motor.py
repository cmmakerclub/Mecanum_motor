import busio
import board
import struct
from adafruit_bus_device.i2c_device import I2CDevice
import math

class Mecanum():

    DEVICE_ADDRESS = 0x55
    comm_port = busio.I2C(board.SCL, board.SDA)
    bus_device = I2CDevice(comm_port, DEVICE_ADDRESS)

    def value_limit(self, _value=0.0, min=-30000.0, max=30000.0):
        if _value < min :
            _value = min
        if _value > max :
            _value = max
        return float(_value)

    def Set_motorxyz(self, _valuex = 0.0, _valuey = 0.0, _valuez = 0.0):
        _valuex = self.value_limit(_valuex, min=-1.0, max=1.0)
        _valuey = self.value_limit(_valuey, min=-1.0, max=1.0)
        _valuez = self.value_limit(_valuez, min=-1.0, max=1.0)
        datas1 = struct.pack('>B', int(2))
        datas2 = struct.pack('fff', float(_valuex), float(_valuey), float(_valuez))
        self.bus_device.write(datas1+datas2)

    def Set_kp(self, _value = 0.1):
        _value = self.value_limit(_value, min=0.0, max=600.0)
        self.bus_device.write(struct.pack('<Bf', 0x11, float(_value)))
        
    def Set_ki(self, _value = 0):
        _value = self.value_limit(_value, min=0.0, max=600.0)
        self.bus_device.write(struct.pack('<Bf', 0x12, float(_value)))
        
    def Set_kd(self, _value = 0):
        _value = self.value_limit(_value, min=0.0, max=600.0)
        self.bus_device.write(struct.pack('<Bf', 0x13, float(_value)))
        
    def Set_motor_max_rpm(self, _value = 0):
        _value = self.value_limit(_value, min=0.0, max=1000.0)
        self.bus_device.write(struct.pack('<Bi', 0x14, int(_value)))
    
    def Set_max_rpm_ratio(self, _value = 0):
        _value = self.value_limit(_value, min=0.0, max=1)
        self.bus_device.write(struct.pack('<Bf', 0x15, float(_value)))
    
    def Set_motor_operating_voltage(self, _value = 0):
        _value = self.value_limit(_value, min=0.0, max=14)
        self.bus_device.write(struct.pack('<Bf', 0x16, float(_value)))
        
    def Set_motor_power_max_voltage(self, _value = 0):
        _value = self.value_limit(_value, min=0.0, max=14)
        self.bus_device.write(struct.pack('<Bf', 0x17, float(_value)))
    
    def Set_wheel_diameter(self, _value = 0):
        _value = self.value_limit(_value, min=0.0, max=1)
        self.bus_device.write(struct.pack('<Bf', 0x18, float(_value)))
    
    def Set_wheels_y_distance(self, _value = 0):
        _value = self.value_limit(_value, min=0.0, max=1)
        self.bus_device.write(struct.pack('<Bf', 0x19, float(_value)))
        
    def Set_motor1_invert(self, _value = 0):
        _value = self.value_limit(_value, min=-1.0, max=1.0)
        self.bus_device.write(struct.pack('<Bi', 0x1A, int(_value)))
        
    def Set_motor2_invert(self, _value = 0):
        _value = self.value_limit(_value, min=-1.0, max=1.0)
        self.bus_device.write(struct.pack('<Bi', 0x1B, int(_value)))
        
    def Set_motor3_invert(self, _value = 0):
        _value = self.value_limit(_value, min=-1.0, max=1.0)
        self.bus_device.write(struct.pack('<Bi', 0x1C, int(_value)))
        
    def Set_motor4_invert(self, _value = 0):
        _value = self.value_limit(_value, min=-1.0, max=1.0)
        self.bus_device.write(struct.pack('<Bi', 0x1D, int(_value)))
        
    def Set_encoder_CPR(self, _value = 0):
        _value = self.value_limit(_value, min=0.0, max=15000)
        self.bus_device.write(struct.pack('<Bi', 0x1E, int(_value)))
    
    def Set_B_motor1(self, _value = 0):
        _value = self.value_limit(_value, min=0.0, max=5)
        self.bus_device.write(struct.pack('<Bi', 0x30, int(_value)))
    
    def Set_B_motor2(self, _value = 0):
        _value = self.value_limit(_value, min=0.0, max=5)
        self.bus_device.write(struct.pack('<Bi', 0x31, int(_value)))
        
    def Set_B_motor3(self, _value = 0):
        _value = self.value_limit(_value, min=0.0, max=5)
        self.bus_device.write(struct.pack('<Bi', 0x32, int(_value)))
        
    def Set_B_motor4(self, _value = 0):
        _value = self.value_limit(_value, min=0.0, max=5)
        self.bus_device.write(struct.pack('<Bi', 0x33, int(_value)))
        
    def Read_battery(self):
        result = bytearray(4)
        self.bus_device.write_then_readinto(bytes([0x20]),result)
        if(math.isnan(struct.unpack("f",result)[0])) :
            pass
        else :
            if struct.unpack("f",result)[0] >2 :
                return struct.unpack("f",result)[0]
