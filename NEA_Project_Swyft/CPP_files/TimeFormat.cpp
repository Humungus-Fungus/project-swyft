#include <iostream>
#include <vector>
#include "../FunctionDeclarations.h"
#include <cmath>

using namespace std;

vector<string> time_convert(vector<int> seq)
{
    vector<string> product;
    for (int i : seq)
    {
        int hours {(int)(i / 3600)};
        i -= hours*3600;
        int minutes {(int)(i / 60)};
        i -= minutes*60;
        int seconds {i};

        product.push_back(to_string(hours) + ":" + to_string(minutes) + ":" + to_string(seconds));
    }
    return product;
}