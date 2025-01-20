# Arduino Fish Feeder

This repository contains the code and circuit diagram for an automated fish feeder powered by Arduino. The feeder dispenses a preset amount of fish food into an aquarium every 4 minutes (default duration). The interval can be adjusted directly in the code. Future enhancements to the project include IoT control and live video feed functionality.

## Features

- **Automated Feeding**: Dispenses fish food at regular intervals.
- **Customizable Feeding Interval**: Adjust the duration between feedings in the program.
- **Manual Adjustment of Food Amount**: Set the quantity of food using a mechanical slider.

## Contents

- `circuit_diagram.png`: The schematic for setting up the circuit.
- `code.ino`: The Arduino code for controlling the feeder.

## How It Works

1. The feeder mechanism is controlled by an Arduino board.
2. The food quantity is set using a mechanical slider.
3. By default, food is dispensed every 4 minutes.
4. The interval between feedings can be modified by changing the value of the `FEEDING_INTERVAL` variable in `code.ino`.


## Future Development Plans

- **IoT Control**:
  - Enable remote configuration of feeding times and intervals.
  - Provide notifications for feeding events.
- **Live Video Feed**:
  - Integrate a camera module to monitor the aquarium in real time.

Shri Harivansh! Hope you like it !
