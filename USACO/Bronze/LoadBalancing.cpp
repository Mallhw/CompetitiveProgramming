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
	freopen("balancing.in", "r", stdin);
    freopen("balancing.out", "w", stdout);
    int n; int b;
    cin >> n >> b;
    vector<int> x_val(n); vector<int> y_val(n);
    set<int> vfence;
    set<int> hfence;
    for(int i = 0; i < n; i++) {
        cin >> x_val[i] >> y_val[i];
        vfence.insert(x_val[i] + 1);
        hfence.insert(y_val[i] + 1);
    }
    int minCows = n;
    for(int v : vfence) {
        for(int h : hfence) {
            int topLeft = 0;
            int topRight = 0;
            int botLeft = 0;
            int botRight = 0;
            for(int i = 0 ; i < n; i++) {
                // topLeft
                if(x_val[i] < v && y_val[i] > h) {
                    topLeft++;
                }
                // topRight
                else if(x_val[i] > v && y_val[i] > h) {
                    topRight++;
                }
                else if(x_val[i] < v && y_val[i] < h) {
                    botLeft++;
                }
                // topRight
                else if(x_val[i] > v && y_val[i] < h) {
                    botRight++;
                }
            }
            minCows = min(minCows, max({topLeft, topRight, botLeft, botRight}));
        }
    }
    cout << minCows << endl;
   
    return 0;
}