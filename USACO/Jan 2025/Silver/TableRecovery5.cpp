#include <bits/stdc++.h> 
using namespace std; 
#define max(a, b) (a < b ? b : a) 
#define min(a, b) ((a > b) ? b : a) 
#define dbg(x) cerr << __LINE__ << ": " << #x << "=" << x << endl;
typedef long long int ll; 
typedef vector<long long> vll;

int main() 
{ 
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    ll n;
    cin >> n;
    ll maxNum = 2 * n;


    vector<vector<ll>> grid(n, vector<ll>(n));
    vll count(maxNum + 1);
    for(int r = 0; r < n; r++) {
        for(int c = 0; c < n; c++) {
            cin >> grid[r][c];
            count[grid[r][c]]++;
        }
    }


    vector<vector<ll>> numbers;

    

    return 0; 
} 
