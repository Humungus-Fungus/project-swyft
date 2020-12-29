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
	const unsigned int le = 10; // Leniency factor
	const float vel_car{10}; // Assuming that the car travels at 10 meters per second
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

	inputs_for_dijkstra(roads, matrix);


	vector<int> final_seq; // Will store the final sequence

	// This will change later once I integrate this with Dijkstra, then the cost
	// will be used directly
	vector<double> road_lengths;

	cout << "Enter the length of the roads: " << endl;
	road_lengths = vec_add(road_lengths, roads);	
	
	vector<vector<int>> seqs; // Holds all sequences

	// Now seqs is ready, and in its final form.
	for (int i{0}; i < roads; i++) 
	{
		vector<int> seq = get_seq();
		seqs.push_back(seq);
	}
	
	

	// Next, find times for roads (cumulative).
	vector<double> times;
	times.push_back(0); // This needs to be done for robustness
	double single_time{0};

	for (int i{0}; i < roads; i++) 
	{
		single_time += calc_unknown(road_lengths[i], vel_car, 't');
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
		//cout << "Size of final_seq: " << final_seq.size() << endl;
		
		if (final_seq.size() == 3) print_array(final_seq);
		vals.clear();
    }

    // interface();
    
    keep_open();
    return 0;
    
}


