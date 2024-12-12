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
	freopen("bcount.in", "r", stdin);
	freopen("bcount.out", "w", stdout);
    int n; int q;
    cin >> n >> q;
    vector<int> hcows(n+1);
    vector<int> gcows(n+1);
    vector<int> jcows(n+1);
    for(int i = 0; i < n; i++) {
        hcows[i+1] = hcows[i];
        gcows[i+1] = gcows[i];
        jcows[i+1] = jcows[i];

        int type;
        cin >> type;
        if (type == 1) hcows[i + 1]++;
		else if (type == 2) gcows[i + 1]++;
		else if (type == 3) jcows[i + 1]++;
    }
    
    for(int i = 0; i < q; i++) {
        int l; int h;
        cin >> l >> h;
        cout << hcows[h] - hcows[l-1] << " " << gcows[h] - gcows[l-1] << " " << jcows[h] - jcows[l-1] << endl;
    }
    return 0;
}