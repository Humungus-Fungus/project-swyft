#include <iostream> // Allows input and output
#include <vector> // Allows use of vectors
#include "../FunctionDeclarations.h" // Allows this method to be used in the solution
#include <cmath> // Used for mathematical operations

using namespace std; // Saves typing std::

// Converts seconds into hh:mm:ss
vector<string> time_convert(vector<int> seq)
{
    vector<string> product; // Will store the final output
    for (int i : seq) // Looping through each item in the sequence
    {
        int hours {(int)(i / 3600)}; // Number of hours is the seconds divided by 3600 rounded down
        i -= hours*3600; // Subtract this from seconds remaining
        int minutes {(int)(i / 60)}; // Number of minutes is the remaining seconds divided by 60 rounded down
        i -= minutes*60; // Subtract this from seconds remaining
        int seconds {i}; // Remaining seconds is saved as the number of seconds remaining

        // This is added to the vector which will hold the final ouput
        product.push_back(to_string(hours) + ":" + to_string(minutes) + ":" + to_string(seconds));
    }
    return product; // Output is returned
}
