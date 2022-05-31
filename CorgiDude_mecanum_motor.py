import sensor, image, time ,lcd
import KPU as kpu
from fpioa_manager import fm
from machine import I2C
from board import board_info
from Maix import GPIO
import struct
i2c = I2C(I2C.I2C0, freq=100000, scl=35, sda=34)

def value_limit(_value=0.0, min=-30000.0, max=30000.0):
        if _value < min :
            _value = min
        if _value > max :
            _value = max
        return float(_value)

def Set_motorxyz(_valuex = 0.0, _valuey = 0.0, _valuez = 0.0):
    _valuex = value_limit(_valuex, min=-1.0, max=1.0)
    _valuey = value_limit(_valuey, min=-1.0, max=1.0)
    _valuez = value_limit(_valuez, min=-1.0, max=1.0)
    datas1 = struct.pack('>B', int(2))
    datas2 = struct.pack('fff', float(_valuex), float(_valuey), float(_valuez))
    #self.bus_device.write(datas1+datas2)
    a = i2c.writeto(0x12,datas1+datas2)
    return a
