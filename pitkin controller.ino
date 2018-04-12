#define switchPin 0
#define pwmPin 1
int output[] = { 255, 204, 153, 77 };
int level = 0;
unsigned long timeStamp = 0;

void setup()
{
	pinMode(switchPin, INPUT_PULLUP);
	pinMode(pwmPin, OUTPUT);
}

void loop()
{
	while (digitalRead(switchPin) == LOW) {
		analogWrite(pwmPin, output[level]);
		if ((millis() - timeStamp) > 10000) {
			level = 0;
		}
		else if ((millis() - timeStamp) > 200) {
			level++;
		}
		if (level > 3) {
			level = 0;
		}
		timeStamp = millis();
	}
	analogWrite(pwmPin, 0);
}
