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

  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);

  state = standard;

  Serial.begin(115200);
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

  Serial.println(state);
}

void standardState()
{
  digitalWrite(green, HIGH);
  digitalWrite(red, HIGH);
  digitalWrite(yellow, HIGH);
}

void maintenanceState()
{
  digitalWrite(green, LOW);
  digitalWrite(red, LOW);
  digitalWrite(yellow, LOW);
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
