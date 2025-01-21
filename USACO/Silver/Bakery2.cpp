#include <bits/stdc++.h>
using namespace std; 
#define max(a, b) (a < b ? b : a) 
#define min(a, b) ((a > b) ? b : a) 
#define dbg(x) cerr << __LINE__ << ": " << #x << "=" << x << endl;
#define mod 1000000007 
#define FOR(a, c) for (int(a) = 0; (a) < (c); (a)++) 
#define FORL(a, b, c) for (int(a) = (b); (a) <= (c); (a)++) 
#define FORR(a, b, c) for (int(a) = (b); (a) >= (c); (a)--) 
#define INF 1000000000000000003 
typedef long long int ll; 
typedef vector<long long> vll;
typedef vector<int> vi; 

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        ll tc, tm;
        cin >> tc >> tm;
        ll ans = 0;
        ll maxReduce = 0;
        vector<vector<ll>> v(n, vector<ll>(3));
        for(int i = 0; i < n; i++) {
            ll cookies, muffins, waitTime;
            cin >> cookies >> muffins >> waitTime;
            v[i][0] = cookies;
            v[i][1] = muffins;
            v[i][2] = waitTime;
            maxReduce = max(cookies * tc + muffins * tm - waitTime, maxReduce);
        }

        ll low = 0;
        ll high = tc;
        while (low <= high) {
            ll mid1 = low + (high - low) / 3;
            ll mid2 = high - (high - low) / 3;
            ll newTC1 = tc - mid1;
            ll newTC2 = tc - mid2;
            bool fail1 = false;
            bool fail2 = false;
            for (int i = 0; i < n; i++) {
                if (v[i][0] >= v[i][1]) {
                    ll time1 = v[i][0] * newTC1 + v[i][1] * tm;
                    ll time2 = v[i][0] * newTC2 + v[i][1] * tm;
                    if (time1 > v[i][2]) {
                        fail1 = true;
                    }
                    if (time2 > v[i][2]) {
                        fail2 = true;
                    }
                }
            }
            if (fail1 && fail2) {
                low = mid1 + 1;
            } else if (!fail1 && !fail2) {
                high = mid2 - 1;
            } else if (!fail1 && fail2) {
                low = mid1 + 1;
                high = mid2 - 1;
            }
        }
        ans = low;
        cout << ans << endl;
    }
}