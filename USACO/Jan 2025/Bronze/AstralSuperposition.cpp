#include <bits/stdc++.h> 
using namespace std; 
#define max(a, b) (a < b ? b : a) 
#define min(a, b) ((a > b) ? b : a) 
#define dbg(x) cerr << __LINE__ << ": " << #x << "=" << x << endl;
typedef long long int ll; 
typedef vector<long long> vll;



void solve() {
    ll n, right, down;
    cin >> n >> right >> down;
    vector<vector<ll>> grid(n, vector<ll>(n));
    vector<vector<bool>> mustExist(n, vector<bool>(n));
    vector<vector<bool>> givenStar(n, vector<bool>(n));
    for(ll i = 0; i < n; i++) {
        for(ll j = 0; j < n; j++) {
            char temp;
            cin >> temp;
            if(temp == 'G') {
                grid[i][j] = 1LL;
            }
            if(temp == 'B') {
                grid[i][j] = 2LL;
            }
            if(temp == 'W') {
                grid[i][j] = 0LL;
            }
        }
    }

    // dbg(grid);
    ll ans = 0;

    for(int r = 0; r < n; r++) {
        for(int c = 0; c < n; c++) {
            if(grid[r][c] == 2) {
                if((c - right < 0 || r - down < 0)) {
                    cout << -1 << endl;
                    return;
                }
                if(grid[r - down][c - right] == 0) {
                    cout << -1 << endl;
                    return;
                }
                mustExist[r - down][c - right] = true;
                ans += 1;
            }
        }
    }
    // dbg(ans);

    for(int r = 0; r < n; r++) {
        for(int c = 0; c < n; c++) {
            if(grid[r][c] == 1) {
                if(c - right < 0 || r - down < 0) {
                    ans++;
                }
                else {
                    // dbg(mustExist[r - down][c - right]);
                    if(right == 0 && down == 0) {
                        ans++;
                    }
                    else if(grid[r - down][c - right] == 0) {
                        ans++;
                    }
                    else if(mustExist[r][c]) {
                        ans++;
                    }
                    else if(givenStar[r - down][c - right]) {
                        ans++;
                    }
                    else if(grid[r - down][c - right] >= 1) {
                        givenStar[r][c] = true;
                    }
                }
            }
        }
    }
    // dbg(ans);
    cout << ans << endl;
    return;
}

int main() 
{ 
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    int t;
    cin >> t;
    for(int i = 0; i < t; i++) {
        solve();
    }
    return 0; 
} 
