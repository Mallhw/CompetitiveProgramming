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

#define endll '\n'

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; int x;
    cin >> n >> x;
    vector<int> values(n);
    unordered_map<int, int> m;
    for(int i = 0; i < n; i++) {cin >> values[i]; }
    for(int i = 0; i < n; i++) {
        // check if exists
        if(m.count(x - values[i])) {
            cout << i + 1 << " " << m[x - values[i]] << endl;
            return 0;
        }
        m[values[i]] = i + 1;
    }
    cout << "IMPOSSIBLE" << endl;
}
