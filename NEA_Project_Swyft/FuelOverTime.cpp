#include <iostream>
#include "FunctionDeclarations.h"

// This function calculates the amount of fuel left at any point in the trip.
float calc_fuel(float initial_fuel, float mileage, float distance) {
    float fuel_lost = mileage * distance;
    float current_fuel = initial_fuel - fuel_lost;
    return current_fuel;
}

float calc_fuel_percentage(float max_fuel, float current_fuel) {
    return (current_fuel/max_fuel)*100;
}