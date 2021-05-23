#include <iostream> // allows input and output
#include <fstream> // allows reading from/writing to other files
#include <vector> // allows use of vectors
#include <regex> // allows use of regular expressions for pattern matching
#include "../FunctionDeclarations.h" // allows contents of this file to be used in other programs

using namespace std; // eliminates the need for starting many commands with std::

vector<int> get_seq(int light_pos) {
	float red_duration; // will store the duration of a red light
	float green_duration; // will store the duration of a green light
	float total_duration; // will store the total duration
	size_t terms_per_day; // number of terms in the sequence in one day

	fstream dummy_text; // object to represent the new file
	string raw_data; // Storest the text from the file

	dummy_text.open("Dummy Data/DummyDataLights.csv", ios::in); // opening the new file
	if (dummy_text.is_open()) // checking that the file is indeed open
	{
		string input; // temporarily stores the contents of the external file being read from
		while (getline(dummy_text, input)) {
			raw_data += input;
		}
		dummy_text.close();
	}

	regex pair_pattern ("([[:digit:]]+),([[:digit:]]+)");

	smatch matches;

	 // Find green and red duration from this

	string waste_data {raw_data};
	int counter{0};
	while (regex_search(waste_data, matches, pair_pattern)) {		
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
		(int)(((172800 - green_duration - 2 * red_duration) / (2 * total_duration)) + 1); // Edited so that
		// only the first hour is recorded instead of the whole day.
	//cout << "terms per day: " << terms_per_day << endl;
	
	vector<int> seq;  // This will hold the final sequence for the traffic light

	for (int i{0}; i < terms_per_day; i++) 
	{
		seq.push_back(red_duration + green_duration / 2 + i * total_duration); // green_duration/2,
		// as we want the midpoint
	}
	return seq;
}
