#define switchPin 0
#define pwmPin 1
int powerLevel = 0;
unsigned long lastTime = 0;

//Output levels for the PWM: 100%, 80%, 60% and 30%
const int output[] = { 255, 204, 153, 77 };
const int lowestLevel = sizeof(output) / sizeof(int) - 1;

void setup()
{
	//Use input pullup resistors to filter noise, and switch ground for the signal to the switchPin
	pinMode(switchPin, INPUT_PULLUP);
	pinMode(pwmPin, OUTPUT);
}

void loop()
{
	unsigned long currentTime = millis();

	while (isSwitchOn()) {
		setPowerLevel(powerLevel);
		unsigned long offTime = currentTime - lastTime;
		if (offTime > 10000) {
			reset();
		}
		else if (offTime > 200) {
			reducePower();
		}
		lastTime = millis();
	}

	//when the switchPin goes high and the while loop exits, immediately turn the PWM off
	turnOff();
}

bool isSwitchOn() {
	return digitalRead(switchPin) == LOW;
}

bool isLowestLevel(int level) {
	return level >= lowestLevel;
}

void reset() {
	powerLevel = 0;
}

void setPowerLevel(int level) {
	if (level < 0) {
		analogWrite(pwmPin, 0);
	}
	else {
		analogWrite(pwmPin, output[level]);
	}
}

void turnOff() {
	setPowerLevel(-1);
}

void reducePower(){
	if (!isLowestLevel(powerLevel)) {
		powerLevel++;
	}
}	
