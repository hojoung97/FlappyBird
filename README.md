# FlappyBird
STM32F051R8T6 Microcontroller Project with LED Matrix

## Overview
What we built for the mini-project was a circuitry and code for a successful ‘Flappy Bird game’. We used GPIO ports for the push button and LED matrix display, DAC for the sound, and multiple timers and interrupts in them to update the display and clear the display. The external connected speaker was through GPIO Port A4, and it successfully played the Super Mario music. Also, the LCD screen was connected to PA8 to display the current score, and it got reset every time the player re-played the game. The bird would gradually go down as the internal Timer 3 ticks, so the player would press the push button and it would make the bird to jump, and so the bird could go through the obstacles without getting a game over.

## Components
- LED Matrix(Model Number: 3649)
- External computer speaker
- LCD Display(Model Number: CFAL1602C)
- Microcontroller(Model Number: STM32F051R8T6)

## Demo
![demo](readme_images/flappyBird.gif)
