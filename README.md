# Pitkin (PWM) Controller

### NOTE: This is a work in progress and has not yet been tested.

#### Harware:
Adafruit Trinket: https://www.mouser.com/ProductDetail/Adafruit/1501  
Mosfet: https://www.mouser.com/ProductDetail/infineon/irf540npbf/

#### Output levels:
1. 100%
2. 80%
3. 60%
4. 30%

#### Function:
When switched on the Trinket will drive the mosfet at level 1.  Switching off and on again within 10 seconds will advance the Trinket to the next level until it reaches level 4.  If turned back on after more than 10 seconds the Trinket will reset to level 1.

#### Wiring:
  * Wire a switch between the Trinket's GND pin and pin 0
  * Connect Trinket pin 1 to pin 1 on the mosfet (gate) *Optional: you can also add a ~250 Ohm resistor between the mosfet gate and pin 1 to protect the trinket from current spikes when the mosfet turns on.*
  * Connect pin 2 of the mosfet (drain) to the negative lead of the EO cord
  * Connect pin 3 of the mosfet (source) to the negative lead of the battery
  * Connect Trinket BAT+ and GND pins to the respective battery leads
  * *Optional: you can place a 10k ohm pulldown resistor between the gate and ground (or pin 3 on the mosfet) to keep the mosfet gate from floating*
##### NOTE: The Trinket must be continuously powered, it cannot be placed in-line or anywhere after switched power
