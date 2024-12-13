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
    int n;
    cin >> n;
    vector<int> k(n);
    for(int i = 0; i < n; i++) {
        cin >> k[i];
    }
    int min = 1e9; int sum = 0;
    for(int i = 0; i < n; i++) {
        sum = 0; int a = 0;
        for(int j = 0; j < k[i]; j++) {
            cin >> a;
            a *= 5;
            sum += a;
        }
        sum += k[i] * 15;
        if(min > sum) {
            min = sum;
        }
    }
    cout << min << endl;

    
    return 0;
}