const int button = 5;

const int red = 16;
const int yellow = 17;
const int green = 18;

enum states
{
  standard,
  maintenance,
};

int state;
int cycleIndex;

void setup()
{
  pinMode(button, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(button), changeState, FALLING);

  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);

  state = standard;
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
    updateLeds(true, true, true);
    break;
    case 1:
    break;
    case 2:
    break;
    default:
    state = maintenance;
    break;
  }
}

void maintenanceState()
{
  switch (cycleIndex)
  {
    case 0:
    break;
    case 1:
    break;
    default:
    break;
  }
}

void changeState()
{
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

bool evaluateTime(unsigned long timestamp, unsigned long timeBetween)
{
  if (timestamp+timeBetween < millis())
  {
    return true;
  }
  return false;
}

void updateLeds(bool g, bool r, bool y)
{
  digitalWrite(green, g);
  digitalWrite(yellow, y);
  digitalWrite(red, r);
}
