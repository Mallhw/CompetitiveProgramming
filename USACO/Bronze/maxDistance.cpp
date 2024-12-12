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
typedef long long ll;
typedef vector<long long> vll;


#define endll '\n'

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vll x(n);
    vll y(n);
    for(int i = 0; i < n; i++) {
        cin >> x[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> y[i];
    }
    ll maxD = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            ll curX = x[i] - x[j];
            ll curY = y[i] - y[j];
            ll dist = pow(curX, 2) + pow(curY, 2);
            maxD = max(dist, maxD);
        }
    }
    cout << maxD << '\n';
    return 0;
}