#include <iostream>
#include <string>
#include <vector>
#include "../FunctionDeclarations.h"

/* Todo: 
 [*] Add Djikstra's algorithm to find the shortest path ordinarily [DONE]
  * Optimise to the dimensions of cost are equal to the number of vertices, saving space
  [*] Find road lengths
 * Add Basic UI
 [*] Take into account the timings of the traffic lights (when they are green)
 * Add frequent locations list (list when they're free to go)
 * Take weather into account (flooded roads)
 * Take traffic levels into account (congestion)
 * Take road works into account (Blocked roads)
 [*] Voice recognition (offline voice commands) 
 * Text to speech (Speak aloud to the driver)
*/

using namespace std;

int main() {
	const unsigned int le = 30; // Leniency factor
	const float vel_car{0.1}; // Assuming that the car travels at 10 meters per second
	// const unsigned int roads{3}; // The number of roads
	int roads;

	string str_matrix;

	str_matrix = get_cost_matrix(roads); // Now roads is set, and so is str_matrix
    
	// Now, we need to change str_matrix into a vector for Dijkstra
	vector<int> matrix;

	string item;
	for (int i{0}; i < str_matrix.length(); i++) {
		(str_matrix[i] == ' ') ? matrix.push_back(stoi(item)), item = "" : item += str_matrix[i];
	}
	// Vector matrix is now complete and ready to use

	vector<int> road_lengths = inputs_for_dijkstra(roads, matrix, 7);
	print_array(road_lengths);

	// REMEMBER: WE ARE NOT USING 'ROADS' FOR THE LIGHTS FUNCTIONALITY, WE ARE USING THE NUMBER OF ROADS
	// IN THE PATH I.E. 3 IN THIS CASE

	roads = road_lengths.size();
	
	vector<int> final_seq; // Will store the final sequence
	vector<vector<int>> seqs; // Holds all sequences

	
	// Now seqs is ready, and in its final form.
	for (int i{0}; i < roads; i++) 
	{
		vector<int> seq = get_seq(i); // get_seq(i==8) creates an error
		seqs.push_back(seq);
	}


	// Next, find times for roads (cumulative).
	vector<double> times;
	times.push_back(0); // This needs to be done for robustness
	double single_time{0};

	for (int i{0}; i < roads; i++) 
	{
		single_time += calc_unknown(road_lengths[i], vel_car, 't'); // segmentation fault here
		times.push_back(single_time);
	}
	
	// Next, find this sequence: n, n+time1, n+time2, where n is from
	// seq1, n+time1 is from seq2 and so on.
	
	// Terms of the final sequence, n, n+time1, n+time2 (ideal, not actual values from lights)
	vector<int> vals;
	

	for (int i{0}; i < seqs[0].size(); i++) 
	{
		final_seq.clear();
		for (int j{0}; j < roads; j++) // This fills up the vals the correct values
		{
			vals.push_back(seqs[0][i] + times[j]);
		}

		// next, get final seq
		final_seq = get_final_seq(seqs, vals, final_seq, le);
		// Display contents of final seq - see if it works!
		cout << "Size of final_seq: " << final_seq.size() << endl;

		// For when the size is as it should be
		if (final_seq.size() == roads) print_array(final_seq);
		else if (final_seq.size() > roads)
		{
			vector<int> sub_final(&final_seq[0], &final_seq[3]); // Takes just the first 3 terms
			print_array(sub_final);
		}
		vals.clear();
    }
    // interface();
    
    keep_open();
    return 0;
    
}


