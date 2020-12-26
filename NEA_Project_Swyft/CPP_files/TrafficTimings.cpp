/*
class TrafficLight() {
    const unsigned int le = 10; // Leniency factor
	
	const float v_car{10}; // Assuming that the car travels at 10 meters per second, velocity of car
	
	const unsigned int roads{3}; // The number of roads
	
	vector<int> final_seq; // Will store the final sequence

	// This will change later once I integrate this with Dijkstra, then the cost
	// will be used directly
	vector<double> road_lengths;

	cout << "Enter the length of the roads: " << endl;
	road_lengths = vec_add(road_lengths, roads);	
	
	vector<vector<int>> seqs; // Holds all sequences

	// 3 traffic lights. Find the aligning time
	for (int i{0}; i < roads; i++) 
	{
		vector<int> seq = get_seq(); // The error is within get_seq
		seqs.push_back(seq);
	}

	// Now seqs is ready, and in its final form.

	// Next, find times for roads (cumulative).
	vector<double> times;
	times.push_back(0); // This needs to be done for robustness
	double single_time{0};

	for (int i{0}; i < roads; i++) 
	{
		single_time += calc_unknown(road_lengths[i], v_car, 't');
		times.push_back(single_time);
	}
	
	// Next, find this sequence: n, n+time1, n+time1+time2, where n is from
	// seq1, n+time1 is from seq2 and so on. regex for a number: ([0-9]+)
	
	// Terms of the final sequence, n, n+time1, n+time2
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
};
*/