# RCUSB

Simple USB driver which makes it possible to connect a RC-receiver and transmitter to a PC, which can be used in simulators like VRC.

**End-Point Detection (EPD)**

In order to get good readings from the transmitter, you have to find the end point limits for the throttle and steering 
1. Make sure your transmitter is powered OFF
2. Connect the Arduino to your PC 
3. Upload the program to the board (Press CTRL + U)
4. Start the serial monitor (Press CTRL + SHIFT + M)
5. Turn ON your transmitter when "[-] Waiting for transmitter!" appears
6. Move both throttle and steering to their limits during the time of calibration
7. When the calibration is done you will see the maximum and minimum end point values

**The USB Driver**

Prepare the driver with the end point values you got from the EPD step and calibrate the driver
1. Update the values in the RCUSB_driver.ino file with the end point values you just got from EPD
2. Upload the program to the board (Press CTRL + U)
3. Make sure transmitter is ON
4. Open Control panel > Hardware and Sound > Devices and Printers, right click "Arduino Leonardo" and select "Game controller settings"
5. Select "Propeties" and click on the "Settings" tab, and select "Calibrate" and follow the calibration wizard.




**NOTE**: This program only works for ATMega32U4 boards (e.g. Leonardo) **NOT** ATmega328P (e.g Uno)


**Wiring**  
This is the default configuration used by the program


| Arduino | Receiver |
| --- | --- |
| 5V | Throttle VCC (positive) |
| Ground | Throttle Ground (negative) |  
| PIN 6 | Throttle PWM signal |  
| PIN 5 | Steering PWM signal |


**Disclaimer**  
Use this at your own risk!  
By using this you agree that all consequences that could occur from this project is your responsibility.
