# Traffic-Light  
## Description  
This is a simple traffic light made with a LOLIN D32 board.  
It is made with non-blocking code in mind, this means that there is no use of delay().  
We use millis() and interupts instead.  

## Usage  
When the LOLIN D32 board is powered the traffic light will start in the standard state.
The cycle of the standard state is as follows:  
- 5s green  
- 2s yellow  
- 5s red  
- 2s yellow  

When the button is pressed the traffic light will go into the maintenance state.  
The cycle of the maintenance state is as follows:  
- 1s yellow on  
- 1s yellow off 
   
If the button is pressed again the traffic light will change back to the standard state.  

## Requirements  

#### Parts  
- 1 Lolin D32 board  
- 3 Leds (Red, Yellow, Green)  
- 3 Resistors (3 x 100 Ohm for 3,3V)  
- 1 Button (Internal pullup)  

#### Software  
The arduino IDE (https://www.arduino.cc/en/software)  
The IDE allows you to edit and compile to code as well as sending it to the LOLIN D32 board.  

## Schematic
![My Image](Traffic-Light-Schematic.png)
