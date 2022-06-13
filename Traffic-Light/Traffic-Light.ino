// Defining inputs and outputs.
const int button = 5;
const int red = 16;
const int yellow = 17;
const int green = 18;

// An enum holding the traffic light states.
enum states
{
  standard,
  maintenance,
};

int state = 0; // Value that defines what state we are in.
int cycleIndex = 0; // Value that defines where we are in the cycle of the current state.
unsigned long previousTime = 0; // Value holds the time at a certain timestamp.

void setup()
{
  // Configure the button pin as an input with an internal pullup.
  pinMode(button, INPUT_PULLUP);
  // Attach an interrupt to the button that excutes the changeState function.
  attachInterrupt(digitalPinToInterrupt(button), changeState, FALLING);

  // Configure the led pins as outputs.
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);
}

void loop()
{
  // A switch statement that will check what state we are in right now.
  switch (state)
  {
    // Are we in the standard state?
    case standard:
    // Execute the standard state.
    standardState();
    break;
    // Are we in the maintenance state?
    case maintenance:
    // Execute the maintenance state.
    maintenanceState();
    break;
    // Are we in an undefined state?
    default:
    // Execute the maintenance state.
    state = maintenance;
    break;
  }
}

void standardState()
{
  // A switch statement that will check where we are in the cycle.
  switch(cycleIndex)
  {
    case 0:
    // Turn the green led on, others off.
    updateLeds(true, false, false);
    // Has enough time passed?
    if (evaluateTime(5000))
    {
      // Change the cycle index.
      cycleIndex = 1;
    }
    break;
    case 1:
    // Turn the yellow led on, others off.
    updateLeds(false, true, false);
    // Has enough time passed?
    if (evaluateTime(2000))
    {
      // Change the cycle index.
      cycleIndex = 2;
    }
    break;
    case 2:
    // Turn the red led on, others off.
    updateLeds(false, false, true);
    // Has enough time passed?
    if (evaluateTime(5000))
    {
      // Change the cycle index.
      cycleIndex = 3;
    }
    break;
    case 3:
    // Turn the yellow led on, others off.
    updateLeds(false, true, false);
    // Has enough time passed?
    if (evaluateTime(2000))
    {
      // Change the cycle index.
      cycleIndex = 0;
    }
    break;
    default:
    // Reset the cycle index to 0.
    cycleIndex = 0;
    break;
  }
}

void maintenanceState()
{
  // A switch statement that will check where we are in the cycle.
  switch (cycleIndex)
  {
    case 0:
    // Turn the yellow led on, others off.
    updateLeds(false, true, false);
    if (evaluateTime(1000))
    {
      // Change the cycle index.
      cycleIndex = 1;
    }
    break;
    case 1:
    // Turn all the leds off.
    updateLeds(false, false, false);
    if (evaluateTime(1000))
    {
      // Change the cycle index.
      cycleIndex = 0;
    }
    break;
    default:
    // Reset the cycle index to 0.
    cycleIndex = 0;
    break;
  }
}

// The isr function that we use to change state with the button.
void changeState()
{
  // Turn the leds off when we are changing states.
  updateLeds(false, false, false);
  // Reset our cycle index.
  cycleIndex = 0;
  // Switch to check what our current state is.
  switch(state)
  {
    case standard:
    // Switch to the maintenance state.
    state = maintenance;
    break;
    case maintenance:
    // Switch to the standard state.
    state = standard;
    break;
    default:
    state = maintenance;
    break;
  }
}

// Function that we use to check if enough time has passed.
bool evaluateTime(unsigned long interval)
{
  if (previousTime + interval < millis())
  {
    // If it's true we update our time value.
    previousTime = millis();
    return true;
  }
  return false;
}

// Function to make it a little easier.
void updateLeds(bool g, bool y, bool r)
{
  digitalWrite(green, g);
  digitalWrite(yellow, y);
  digitalWrite(red, r);
}
