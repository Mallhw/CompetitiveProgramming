#include <bits/stdc++.h>
using namespace std;

void setIO(string name = "") {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	if (name.size()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

int main() {
	setIO("whereami");
	int boxes_num;
	string boxes_sequence;
	cin >> boxes_num >> boxes_sequence;

	// check all sub lengths (k) from the smallest to biggest
	for (int sub_len = 1; sub_len <= boxes_num; sub_len++) {
		bool sol_found = true;
		unordered_map<string, int> sub_frequency;
		// store frequencies of all subs with given length (sub_len)
		for (int idx = 0; idx <= boxes_num - sub_len; idx++) {
			string sub = boxes_sequence.substr(idx, sub_len);
			sub_frequency[sub]++;
			if (sub_frequency[sub] > 1) { sol_found = false; }
		}

		// if all sub sequences are unique -> solution found
		if (sol_found) {
			cout << sub_len << endl;
			break;
		}
	}
}