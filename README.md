# Distance Formula Calculator

A simple C++ program that calculates the distance between two points in 2D space using the distance formula.

## Description

This program implements the distance formula: √[(x₂-x₁)² + (y₂-y₁)²] to calculate the Euclidean distance between two points (x₁, y₁) and (x₂, y₂).

## Features

- Interactive command-line interface
- Input validation for numeric coordinates
- Precise calculations with 4 decimal place output
- Clear and user-friendly prompts

## Compilation

To compile the program, use:
```bash
g++ -o distance_calculator distance_calculator.cpp
```

## Usage

Run the compiled program:
```bash
./distance_calculator
```

The program will prompt you to enter coordinates for two points, then display the calculated distance.

## Example

```
Distance Formula Calculator
--------------------------
Calculates distance between two points (x1, y1) and (x2, y2)
Formula: √[(x₂-x₁)² + (y₂-y₁)²]

Enter coordinates for first point:
x1: 0
y1: 0

Enter coordinates for second point:
x2: 3
y2: 4

Results:
Point 1: (0.0000, 0.0000)
Point 2: (3.0000, 4.0000)
Distance: 5.0000
```

## Requirements

- C++ compiler (g++ or clang++)
- Standard C++ libraries: iostream, cmath, iomanip, limits
