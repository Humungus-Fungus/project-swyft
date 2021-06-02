#include <iostream> // Required for input and output
#include "../FunctionDeclarations.h" // Required for use in the solution

// This function calculates the amount of fuel left at any point in the trip.
float calc_fuel(float initial_fuel, float mileage, float distance) {
    float fuel_lost = mileage * distance; // mileage times distance gives fuel burnt
    float current_fuel = initial_fuel - fuel_lost; // Current fuel is the initial amount minus the amount burnt
    return current_fuel; // This value is returned
}

float calc_fuel_percentage(float max_fuel, float current_fuel) {
    return (current_fuel/max_fuel)*100; // Gives the value as a percentage
}
