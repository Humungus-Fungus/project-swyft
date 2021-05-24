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
		while (getline(dummy_text, input)) // Taking input from the external file
		{
			raw_data += input; // Storing the data from that file into a local variable
		}
		dummy_text.close(); // Closing the file so it doesn't take up extra space in memory
	}

	regex pair_pattern ("([[:digit:]]+),([[:digit:]]+)"); // Regular expression pattern for the structure of the contents of the files

	smatch matches; // Where all the matches to the pattern will be stored

	 // Find green and red duration from this
	string waste_data {raw_data}; // What's left after all unwanted data is removed
	int counter{0}; // Counter to keep track of how many iterations have passed in the following loop
	while (regex_search(waste_data, matches, pair_pattern)) // Looping through the waste data, looking for matches
	{		
		if (counter == light_pos) // if the data is relevant to the light position we need
		{
			red_duration = stoi(matches.str(1)); // Red duration is the first group that matches, and is converted into an integer
			green_duration = stoi(matches.str(2)); // Green duration si the second group that matches, and is converted into an integer
		}
	
		counter++; // Counter increments to keep up with the loop
		matches.str(0); // Matches prepares for the next operation

		waste_data = matches.suffix().str(); // Waste data is assigned the rest of matches that wasn't used
	}

	total_duration = green_duration + red_duration; // Total duration is the sum of green and red duration

	terms_per_day =
		(int)(((172800 - green_duration - 2 * red_duration) / (2 * total_duration)) + 1); // Edited so that
		// only the first hour is recorded instead of the whole day.
	//cout << "terms per day: " << terms_per_day << endl;
	
	vector<int> seq;  // This will hold the final sequence for the traffic light

	for (int i{0}; i < terms_per_day; i++) // Looping through each term in the sequence
	{
		// Adding the term to the sequence
		seq.push_back(red_duration + green_duration / 2 + i * total_duration); // green_duration/2,
		// as we want the midpoint
	}
	return seq; // Outputs the sequence vector
}
