#include <iostream>
#include <fstream>
#include <vector>
#include <regex>
#include "../FunctionDeclarations.h"

using namespace std;

vector<int> get_seq(int light_pos) {
	float red_duration; // CHANGE THIS ASAP
	float green_duration; // CHANGE THIS ASAP
	float total_duration;
	size_t terms_per_day;

	// Need to update, so that the data for durations is extracted from dummy data
	/*cout << "Red light duration: ";
	cin >> red_duration;

	cout << "\nGreen light duration: ";
	cin >> green_duration;
	*/

	fstream dummy_text;
	vector<pair<int,int>> pairs;
	string raw_data;

	dummy_text.open("Dummy Data/DummyDataLights.csv", ios::in);
	if (dummy_text.is_open()) {
		string input;
		while (getline(dummy_text, input)) {
			raw_data += input;
		}
		dummy_text.close();
	}

	regex pair_pattern ("([[:digit:]]+),([[:digit:]]+)");

	smatch matches;

	 // Find green and red duration from this

	cout << "Raw Data: " << raw_data << endl;
	string waste_data {raw_data};
	int counter{0};
	while (regex_search(waste_data, matches, pair_pattern)) {
		cout << "Matches: " << matches.str(0) << endl;
		
		if (counter == light_pos) {
			red_duration = stoi(matches.str(1));
			green_duration = stoi(matches.str(2));
		}	
		
		counter++;
		matches.str(0);

		waste_data = matches.suffix().str();
	}

	total_duration = green_duration + red_duration;

	terms_per_day =
		(int)(((21600 - green_duration - 2 * red_duration) / (2 * total_duration)) + 1); // Edited so that only the first hour is recorded instead of the whole day.
	//cout << "terms per day: " << terms_per_day << endl;
	
	vector<int> seq(terms_per_day);  // This will hold the final sequence for the traffic light

	for (int i{0}; i < terms_per_day; i++) 
	{
		seq[i] = red_duration + green_duration / 2 + i * total_duration; // green_duration/2 as we want the midpoint
	}

	return seq;
}
