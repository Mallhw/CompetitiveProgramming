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
#include <bitset>

using namespace std;
typedef long long ll;

#define endll '\n'

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t; int n;
    cin >> t;
    while(t--) {    
        cin >> n;
        vector<int> arr(n);
        int val = 0;
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
            val ^= arr[i];
        }
        if(val == 0) {
            cout << 0 << endl;
        }
        else {
            if(n%2==0) {
                cout << -1 << endl;
            }
            else {
                cout << val << endl;
            }
        }
    }

    
    return 0;
}