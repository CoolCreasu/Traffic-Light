const int button = 5;

void setup()
{
  pinMode(button, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(button), changeMode, FALLING);
}

void loop()
{
  
}

void changeMode()
{
  
}
