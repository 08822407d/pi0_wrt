#! /

from luma.core.interface.serial import i2c
from luma.core.render import canvas
from luma.oled.device import sh1106

serial = i2c(port=3, address=0x3c)
device = sh1106(serial)
with canvas(device) as draw:
    draw.text((0,0), f"test", fill="white")