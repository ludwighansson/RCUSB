/*
 * RCUSB_calibrator
 * Author: Ludwig Hansson
 * Date: 2020-01-11
 * 
 * NOTE: This program only works for ATMega32U4 boards (e.g. Leonardo) 
 *       *NOT* ATmega328P (e.g Uno)
 * 
 * USAGE:
 * 1. Make sure your transmitter is powered OFF
 * 2. Connect Arduino to your PC 
 * 3. Upload the program to the board (Press CTRL + U)
 * 4. Start the serial monitor (Press CTRL + SHIFT + M)
 * 5. Turn ON your transmitter when "[-] Waiting for transmitter!" appears
 * 6. Move both throttle and steering to their limits during the time of the calibration
 *      NOTE: Both full throttle and brake should be applied!
 * 7. When the calibration is done you will see the maximum and minimum end point values
 * 
 * 
 */


// Physical Arduino pins
// Can be changed to any PWM-capable pin
byte THROTTLE_PIN = 6;
byte STEERING_PIN = 5;

// Change the duration of the calibration (in seconds)
unsigned long CALIBRATION_TIME = 5;


// DO NOT MODIFY ANYTHING BELOW THIS POINT UNLESS YOU KNOW WHAT YOU'RE DOING!
// ---------------------------------------------------------------------------
int16_t THROTTLE_MAX = 0;
int16_t THROTTLE_MIN = 0;
int16_t STEERING_MAX = 0;
int16_t STEERING_MIN = 0;

unsigned long START_TIME;
unsigned long LAST_PRINT = 0;
byte IS_CALIBRATED = false;

void setup() {
  // put your setup code here, to run once:
  pinMode(THROTTLE_PIN, INPUT);
  pinMode(STEERING_PIN, INPUT);
  Serial.begin(115200);
  while(!Serial)
    int x = 2;
  Serial.println("RC_USB Calibrator Started");

}

void loop() {
  int16_t th = pulseIn(THROTTLE_PIN, HIGH);
  int16_t st = pulseIn(STEERING_PIN, HIGH);
  if (!IS_CALIBRATED) {
    if (th && st) {
    
      if (th > THROTTLE_MAX || THROTTLE_MAX == 0)
        THROTTLE_MAX = th;
        
      if (th < THROTTLE_MIN || THROTTLE_MIN == 0)
        THROTTLE_MIN = th;
        
      if (st > STEERING_MAX || STEERING_MAX == 0) 
        STEERING_MAX = st;
        
      if (st < STEERING_MIN || STEERING_MIN == 0) 
        STEERING_MIN = st;
  
      if (millis() > START_TIME + (LAST_PRINT * 1000)) {
        Serial.print("[!] TIME LEFT: "); Serial.print(CALIBRATION_TIME - LAST_PRINT); Serial.println(" seconds");
        LAST_PRINT++;
      }
        
        
      if (millis() > START_TIME + (CALIBRATION_TIME * 1000)) {
        IS_CALIBRATED = true;
  
        Serial.println("-------------------------");
        Serial.println("[+] CALIBRATION COMPLETE");
        Serial.print("    THROTTLE_MAX: "); Serial.println(THROTTLE_MAX);
        Serial.print("    THROTTLE_MIN: "); Serial.println(THROTTLE_MIN);
        Serial.print("    STEERING_MAX: "); Serial.println(STEERING_MAX);
        Serial.print("    STEERING_MIN: "); Serial.println(STEERING_MIN);
        Serial.println("-------------------------");
        
      }
    }
    else {
      START_TIME = millis();
      Serial.println("[-] Waiting for transmitter!");
    }
  }

// --------------------------------------------------------------------------- \\
  

}
