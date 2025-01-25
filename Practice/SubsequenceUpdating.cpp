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
#include <queue>
#include <cstdlib>
void solve() {
    ll n, l, r;
        cin >> n >> l >> r;
        priority_queue<ll> currentNums;
        vll arr(n);
        vll indexs;
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
            if(i >= l-1 && i <= r-1) {
                currentNums.push(arr[i]);
            }
            else {
                indexs.push_back(i);
            }
        }
        for(auto &i : indexs) {
            ll lastNum = currentNums.top();
            if(arr[i] < lastNum) {
                currentNums.pop();
                currentNums.push(arr[i]);
            }
        }
        ll ans = 0;
        while(!currentNums.empty()) {
            ans += currentNums.top();
            currentNums.pop();
        }
        cout << ans << endl;
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
