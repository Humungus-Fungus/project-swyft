#include <iostream>
#include <vector>
#include "../FunctionDeclarations.h"

// This method will be be responsible for getting the final seq

// This method is complicated
// "seqs" represents the vector holding all other vectors
// "vals" represents the items we are looking for within seqs (the ideal sequence)
// "final" will hold the final completed list (as close to the ideal as possible)
// "inc" is used to measure the recursion depth
// "le" represents leniency (how far you can deviate from the ideal)

vector<int> get_final_seq(vector<vector<int>> seqs, vector<int> vals, vector<int> final, const int le/*=5*/, int inc/*=0*/) 
{
	int val = vals[inc];

	double lower_bound;
	double upper_bound;
	
	if (inc > seqs.size()-1) return final;
	else 
	{		
		for (int i{0}; i < seqs[inc].size(); i++)
		{
			if (final.size()==0) lower_bound = val-le;
			else lower_bound = max(val-le, final[final.size()-1]);
			upper_bound = val+le;
			if (lower_bound < seqs[inc][i] && seqs[inc][i] < upper_bound)
			{
				final.push_back(seqs[inc][i]);
				//cout << "match found! " << seqs[inc][i] << " is between " << lower_bound << " and " << upper_bound << endl;
				//cout << final[inc] << endl;
				final = get_final_seq(seqs, vals, final, le, inc+1);
			}
		}
	}

	return final;
}
