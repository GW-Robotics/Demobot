import pygame
import serial

from time import sleep

pygame.init()
pygame.joystick.init()

_joystick = pygame.joystick.Joystick(0)
_joystick.init()

ser = serial.Serial('COM10', baudrate = 9600, timeout = 0.5)

raw_input('Type something to start')

last_joystick_values = "A0 0.0 A1 0.0 A2 0.0 A3 0.0 A4 0.0 A5 0.0\n"
last_button_values   = "B0 0 B1 0 B2 0 B3 0 B4 0 B5 0 B6 0 B7 0 B8 0 B9 0 B10 0 B11 0 B12 0 B13 0\n"

last_value = "0.0 0.0\n"

while True:
    pygame.event.pump()
    
    joystick_values = "A0 {:.2f} A1 {:.2} A2 {:.2f} A3 {:.2f} A4 {:.2f} A5 {:.2f}\n".format(_joystick.get_axis(0), _joystick.get_axis(1), _joystick.get_axis(2), _joystick.get_axis(3), _joystick.get_axis(4), _joystick.get_axis(5))
    
    button_values = "B0 {} B1 {} B2 {} B3 {} B4 {} B5 {} B6 {} B7 {} B8 {} B9 {} B10 {} B11 {} B12{} B13{}\n".format(_joystick.get_button(0), _joystick.get_button(1), _joystick.get_button(2), _joystick.get_button(3), _joystick.get_button(4), _joystick.get_button(5), _joystick.get_button(6), _joystick.get_button(7), _joystick.get_button(8), _joystick.get_button(9), _joystick.get_button(10), _joystick.get_button(11), _joystick.get_button(12), _joystick.get_button(13))

    if not last_joystick_values == joystick_values:
        ser.write(joystick_values)
        last_joystick_values = joystick_values
        print joystick_values
    
    if not last_button_values == button_values:
        ser.write(button_values)
        last_button_values = button_values
        print button_values
        
    # ser.write(joystick_values)
    # ser.write(button_values)

    sleep(0.2)