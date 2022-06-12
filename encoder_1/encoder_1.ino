#define clpin 2
#define dtpin 3
#define swpin 4

int encoderVal = 0;
static int oldA = HIGH;
static int oldB = HIGH;

void setup() {
  pinMode (clpin, INPUT);
  pinMode (dtpin, INPUT);
  pinMode (swpin, INPUT);
  digitalWrite (swpin, HIGH);
  Serial.begin(9600);
}

void loop() {
  int change = getEncoderTurn();
  encoderVal = encoderVal + change;
  if (digitalRead(swpin) == LOW)
  {
    encoderVal = 0;
  }
  Serial.println(encoderVal);
}

int getEncoderTurn(void)
{
  int result = 0;
  int newA = digitalRead(clpin);
  int newB = digitalRead(dtpin);
  if (newA != oldA || newB != oldB)
  {
    if (oldA == HIGH && newA == LOW)
    {
      result = (oldB * 2 - 1);
    }
  }
  oldA = newA;
  oldB = newB;
  return result;
}

