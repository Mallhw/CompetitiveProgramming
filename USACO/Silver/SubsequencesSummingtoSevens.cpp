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
	freopen("div7.in", "r", stdin);
	freopen("div7.out", "w", stdout);
    int n;
    cin >> n;
    vector<long long> pSum(n+1);
    vector<int> pModded(n+1);
    for(int i = 0; i < n; i++) {
        pSum[i + 1] = pSum[i];

        int temp;
        cin >> temp;
        pSum[i+1] += temp;
        pModded[i+1] = pSum[i+1] % 7;
    }
    int maxGroup = 0;
    for(int i = 1; i < 6; i++) {
        int least = -1; int greatest = -1;
        for(int c = 0; c <= n; c++) {
            if(pModded[c] == i && least == -1) {
                least = c;
            }
            if(pModded[c] == i && least != -1) {
                greatest = c;
            }
        }
        if(greatest - least > maxGroup) {
            maxGroup = greatest - least;
        }
    }
    cout << maxGroup << endl;
	return 0;
}