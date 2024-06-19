# Traffic Light Simulation

## Overview

This project simulates a traffic light system using C++ and multithreading. It demonstrates the use of mutexes for thread synchronization, allowing two threads to safely share data and change states of a traffic light.

## Features
1. Simulates a traffic light with three states: Red, Yellow, and Green.
2. Uses multithreading to handle light state changes and printing the current state simultaneously.
3. Implements thread synchronization using std::mutex to avoid data races.

## Files
1. trafficlight.h: Header file defining the trafficLight class.
2. trafficlight.cpp: Implementation file for the trafficLight class.
3. main.cpp: Main program file that runs the traffic light simulation.

## Class trafficLight
The trafficLight class handles the traffic light states and their transitions. It provides methods to get the current state, duration of each light state, the next state, and printing the current state.

## Methods
1. Constructor: Initializes the traffic light to the red state.
2. int getLightDuration(): Returns the duration for the current light state.
3. std::string getLightState(): Returns a string representing the current light state.
4. lightState getNextState(): Returns the next state of the traffic light.
5. void printLight(): Continuously prints the current light state every second.
6. void changeLight(): Changes the light state based on the duration of the current state.

## Example output:
```
RED
RED
RED
RED
Light changed : GREEN

GREEN
GREEN
GREEN
GREEN
GREEN
GREEN
GREEN
Light changed : YELLOW

YELLOW
YELLOW
YELLOW
YELLOW
YELLOW
Light changed : RED

...

```