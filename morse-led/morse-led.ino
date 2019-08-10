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

void one(char c, int led)
{
  int d = 1000;
  boolean on=false;
  switch(c)
  {
    case '.':
	    d=DOT * UNIT;
	    on=true;
	    break;
    case '-':
	    d=DASH * UNIT;
	    on=true;
	    break;
    case '/':
	    d=UNIT;
	    break;
  }

  digitalWrite(led, on ? HIGH : LOW);
  delay(d);
   
  digitalWrite(led, LOW);
  delay(100);
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

  Serial.print("will print: ");Serial.println(message);
  while(*message)
  {
    char l[]={*message, 0};
    Serial.print("will print: ");    Serial.println(l);

    const char *x=letters[*message - 'a'];
    while(*x)
    {
      one(*x, LED_PIN);
      x++;
    }
    one('/',LED_PIN);
    message++; 
  }
  digitalWrite(LED_PIN, LOW);
  delay(WORD * UNIT);
}
