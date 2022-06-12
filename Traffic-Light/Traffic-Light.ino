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

void setup()
{
  pinMode(button, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(button), changeState, FALLING);

  pinMode(red, INPUT);
  pinMode(yellow, INPUT);
  pinMode(green, INPUT);

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
  digitalWrite(green, HIGH);
}

void maintenanceState()
{
  digitalWrite(green, LOW);
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
