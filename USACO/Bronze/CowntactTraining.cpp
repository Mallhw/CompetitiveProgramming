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

using namespace std;

#define endll '\n'
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t; int n;
    cin >> n >> t;
    string cows; vector<bool> infected(n); ll posCows;
    cin >> cows;
    for(int i = 0; i < n; i++) {
        if(cows.at(i) == '1') {
            infected[i] = true;
            posCows++;
        }
        else {
            infected[i] = false;
        }
    }
    
    for(int i = 0; i < t; i++) {
        
    }

    return 0;
}