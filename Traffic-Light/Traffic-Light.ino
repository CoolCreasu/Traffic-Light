const int button = 5;

const int red = 16;
const int yellow = 17;
const int green = 18;

enum states
{
  standard,
  maintenance,
};

int state = 0;
int cycleIndex = 0;
unsigned long previousTime = 0;

void setup()
{
  pinMode(button, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(button), changeState, FALLING);

  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);
}

void loop()
{
  switch (state)
  {
    case standard:
    standardState();
    break;
    case maintenance:
    maintenanceState();
    break;
    default:
    state = maintenance;
    break;
  }
}

void standardState()
{
  switch(cycleIndex)
  {
    case 0:
    updateLeds(true, false, false);
    if (evaluateTime(5000))
    {
      cycleIndex = 1;
    }
    break;
    case 1:
    updateLeds(false, true, false);
    if (evaluateTime(2000))
    {
      cycleIndex = 2;
    }
    break;
    case 2:
    updateLeds(false, false, true);
    if (evaluateTime(5000))
    {
      cycleIndex = 3;
    }
    break;
    case 3:
    updateLeds(false, true, false);
    if (evaluateTime(2000))
    {
      cycleIndex = 0;
    }
    break;
    default:
    cycleIndex = 0;
    break;
  }
}

void maintenanceState()
{
  switch (cycleIndex)
  {
    case 0:
    updateLeds(false, true, false);
    if (evaluateTime(1000))
    {
      cycleIndex = 1;
    }
    break;
    case 1:
    updateLeds(false, false, false);
    if (evaluateTime(1000))
    {
      cycleIndex = 0;
    }
    break;
    default:
    cycleIndex = 0;
    break;
  }
}

void changeState()
{
  updateLeds(false, false, false);
  cycleIndex = 0;
  switch(state)
  {
    case standard:
    state = maintenance;
    break;
    case maintenance:
    state = standard;
    break;
    default:
    state = maintenance;
    break;
  }
}

bool evaluateTime(unsigned long interval)
{
  if (previousTime + interval < millis())
  {
    previousTime = millis();
    return true;
  }
  return false;
}

void updateLeds(bool g, bool y, bool r)
{
  digitalWrite(green, g);
  digitalWrite(yellow, y);
  digitalWrite(red, r);
}
