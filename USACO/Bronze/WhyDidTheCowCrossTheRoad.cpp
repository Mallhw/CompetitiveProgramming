#include <iostream>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>
#include <algorithm>
#include <cmath>
#include <streambuf>
#include <sstream>
#include <unordered_set>
#include <bits/stdc++.h>


using namespace std;

int main() {
	freopen("circlecross.in", "r", stdin);
    freopen("circlecross.out", "w", stdout);
	string s;
	cin >> s;
    vector<int> start(26, -1);
    vector<int> end(26, -1);
    for(int i = 0; i < s.length(); i++ ) {
        if(start[s.at(i) - 'A'] == -1) {
            start[s.at(i) - 'A'] = i;
        } 
        else {
            end[s.at(i) - 'A'] = i;
        }
    }

    int crossing_pairs = 0;
	// Check all pairs of cows (i, j)
	for (int i = 0; i < 26; i++) {
		for (int j = 0; j < 26; j++) {
			// Increment by 1 if the condition in the explanation is met
			crossing_pairs +=
			    (start[i] < start[j] && start[j] < end[i] && end[i] < end[j]);
		}
	}

    cout << crossing_pairs << endl;

	
}
