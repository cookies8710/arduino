/*
set-up:
	GND - LED - 330 ohm - LED_PIN 
*/

#define LED_PIN 8
#define UNIT 250 // time unit in ms
#define DOT 1 // . = 1 time unit
#define DASH 3 // - = 3 time units
#define LETTER DASH
#define WORD (2 * DASH) // 

void setup() {
   Serial.begin(9600);
   Serial.println("Serial start");
   pinMode(LED_PIN, OUTPUT);
}

void light_for(int dur, int led)
{
  digitalWrite(led, HIGH);
  delay(dur);
  digitalWrite(led, LOW);
  delay(100);
}

void morse_char(char c, int led)
{
  int d = 5000;
  switch(c)
  {
    case '.':
	    d = DOT * UNIT;
	    break;
    case '-':
	    d = DASH * UNIT;
	    break;
  }

  light_for(d, led);
}

const char* letters[] ={
  ".-", "-...", "-.-.", "-..", ".", // a-e
  "..-.", "--.", "....", "..", ".---", // f-j
  "-.-", ".-..", "--", "-.", "---",// k-o
  ".--.", "--.-", ".-.", "...", "-", // p-t
  "..-", "...-", ".--", "-..-", "-.--",// u-y
  "--.."// z  
};

void loop() {
  const char *message = "sos";

  Serial.print("will print: ");
  Serial.println(message);

  while(*message)
  {
    char letter[] = {*message, 0};

    Serial.print("will print: ");    
    Serial.println(letter);

    const char *dashdot = letters[*message - 'a'];
    while(*dashdot)
    {
      morse_char(*dashdot++, LED_PIN);
    }

    digitalWrite(LED_PIN, LOW);
    delay(LETTER * UNIT);

    message++; 
  }
  digitalWrite(LED_PIN, LOW);
  delay(WORD * UNIT);
}
