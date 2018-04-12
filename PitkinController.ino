#define switchPin 0
#define pwmPin 1

//Output levels for the PWM: 100%, 80%, 60% and 30%
const int output[] = { 255, 204, 153, 77 };
int mode = 0;
unsigned long timeStamp = 0;

void setup()
{
	//Use input pullup resistors to filter noise, and switch ground for the signal to the switchPin
	pinMode(switchPin, INPUT_PULLUP);
	pinMode(pwmPin, OUTPUT);
}

void loop()
{
	// when the switchPin is LOW the switch is in the ON position
	while (digitalRead(switchPin) == LOW) {
		setPowerLevel(mode);

		//if the switch has been off for more than 10 seconds reset to mode 0;
		if ((millis() - timeStamp) > 10000) {
			mode = 0;
		}

		//else if the switch has been off for more than 200 milliseconds advance to the next mode
		else if ((millis() - timeStamp) > 200) {
			mode++;
		}

		//if already in mode 3 (the lowest setting), stay there
		if (mode > 3) {
			mode = 3;
		}

		//update the timeStamp each time you reach the end of the while loop
		timeStamp = millis();
	}

	//when the switchPin goes high and the while loop exits, immediately turn the PWM off
	setPowerLevel(0);
}

void setPowerLevel(int level) {
	analogWrite(pwmPin, output[level]);
}
