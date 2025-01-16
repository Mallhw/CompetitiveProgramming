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
typedef pair<int, int> pi; 
#define F first 
#define S second 
#define PB push_back 
#define POB pop_back 
#define MP make_pair
/*************  ✨ Codeium Command ⭐  *************/
/**
 * This function reads three integers n, m, and k from input and processes a series 
 * of numbers in m groups each containing k numbers. It categorizes the numbers into 
 * even and odd, tracking the maximum and minimum values for both categories in each group. 
 * It then calculates a prefix sum of the minimal values between corresponding even and 
 * odd values. Based on the comparison of the prefix sum with n, it outputs a sequence 
 * of "Even" or "Odd", indicating which category provides a closer match to the target n 
 * while adjusting n based on the smallest available numbers in the opposite category. 
 * If n cannot be achieved, it outputs -1.
 */

/******  1e4344c6-99b3-4e50-8b6b-53582432a502  *******/
void solve() {
    ll n, m, k;
        cin >> n >> m >> k;
        vll even(m, 0);
        vll odds(m, 0);
        vll evenSmall(m,0);
        vll oddsSmall(m, 0);
        FOR(i, m) {
            FOR(j, k) {
                ll x;
                cin >> x;
                if(x % 2 == 0) {
                    even[i] = max(even[i], x);
                    evenSmall[i] = min(even[i], x);
                } else {
                    odds[i] = max(odds[i], x);
                    oddsSmall[i] = min(odds[i], x);
                }
            } 
        }

        vll prefix(m+1);
        ll pos = 0;
        for(ll i = m; i > 0; i--) {
            prefix[i-1] = prefix[i] + min(even[i-1], odds[i-1]);  
            pos += min(even[i-1], odds[i-1]);
            if(even[i-1] == 0) pos -= oddsSmall[i-1];
            if(odds[i-1] == 0) pos -= evenSmall[i-1];
        }
        
        if(n <= pos) {
                cout << -1 << endl;
                return;
        }


        for(ll i = 0; i < m; i++) {
                if(n - odds[i] > prefix[i]) {
                    cout << "Even";
                    if(odds[i] == 0) {
                        n += evenSmall[i];
                    }
                    else {
                        n-= odds[i];
                    }
                }
                else {
                    cout << "Odd";
                    if(even[i] == 0) {
                        n += oddsSmall[i];
                    }
                    else {
                        n -= even[i];
                    }
                }
            if(i != m-1) cout << " ";
        }
        cout << endl;
        return;
} 
int main() 
{ 
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    int T; 
    cin >> T; 
    while (T--) { 
        solve();
    } 
    return 0; 
} 
