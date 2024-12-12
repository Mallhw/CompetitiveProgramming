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
    freopen("lifeguards.in", "r", stdin);
    freopen("lifeguards.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int N; 
    cin >> N;
    vector<int> 
    starts(N); 
    vector<int> ends(N); 
    int times[1000] = {};
    for(int i = 0; i < N; i++) {
        cin >> starts[i] >> ends[i];
        for(int j = starts[i]; j < ends[i]; j++) {
            times[j]++;
        }
    }
    int maxTime = 7;

    for(int tests = 0; tests < N; tests++) {
        int curMax = 0;
        for(int i = starts[tests]; i < ends[tests]; i++) {
            times[i]--;
        }
        for(int i = 0; i < 1000; i++) {
            if(times[i] > 0) {
                curMax++;
            }
        }
        for(int i = starts[tests]; i < ends[tests]; i++) {
            times[i]++;
        }
        if(curMax > maxTime) {
            maxTime = curMax;
        }
    }


    cout << maxTime << endl;
    return 0;
}