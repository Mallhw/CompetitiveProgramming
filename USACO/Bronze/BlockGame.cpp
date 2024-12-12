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
    freopen("blocks.in", "r", stdin);
	// the following line creates/overwrites the output file
	freopen("blocks.out", "w", stdout);
    int N;
    cin >> N;
    vector<string> s1(N);
    vector<string> s2(N);
    for(int i = 0; i < N; i++) {
        cin >> s1[i] >> s2[i];
    }
    vector<int> output(26);
    fill(output.begin(), output.end(), 0);
    vector<int> Letters1(26);
    vector<int> Letters2(26);
    for(int i = 0; i < N; i++) {
        fill(Letters1.begin(), Letters1.end(), 0);
        fill(Letters2.begin(), Letters2.end(), 0);
        for(int l = 0; l < s1[i].length(); l++) {
            Letters1[s1[i].at(l) - 'a']++;
        }
        for(int l = 0; l < s2[i].length(); l++) {
            Letters2[s2[i].at(l) - 'a']++;
        }
        for(int j = 0; j < 26; j++) {
            output[j] += max(Letters1[j], Letters2[j]);
        }
    }
    for(int i = 0; i < 26; i++) {
        cout << output[i] << endl;
    }
    return 0;
}