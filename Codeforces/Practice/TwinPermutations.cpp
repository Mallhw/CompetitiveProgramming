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

#define endll '\n'

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        vector<ll> a(n);
        ll N = n + 1;
        for(ll i = 0; i < n; i++) {
            cin >> a[i];
        }
        for(ll i = 0; i < n; i++) {
            cout << N - a[i] << ' ';
        }
        cout << endl;
    }
    return 0;
}