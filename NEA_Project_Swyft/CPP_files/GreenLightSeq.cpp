#include <iostream>
#include <vector>
#include "../FunctionDeclarations.h"

using namespace std;

vector<int> get_seq() {
	float red_duration;
	float green_duration;
	float total_duration;
	size_t terms_per_day;

	// Need to update, so that the data for durations is extracted from dummy
	// data
	cout << "Red light duration: ";
	cin >> red_duration;

	cout << "\nGreen light duration: ";
	cin >> green_duration;

	total_duration = green_duration + red_duration;

	terms_per_day =
		(int)(((360 - green_duration - 2 * red_duration) / (2 * total_duration)) + 1); // Edited so that only the first hour is recorded instead of the whole day.
	cout << "terms per day: " << terms_per_day << endl;
	
	vector<int> seq(terms_per_day);  // This will hold the final sequence for the traffic light

	for (int i{0}; i < terms_per_day; i++) 
	{
		seq[i] = red_duration + green_duration / 2 + i * total_duration; // green_duration/2 as we want the midpoint
	}

	return seq;
}
