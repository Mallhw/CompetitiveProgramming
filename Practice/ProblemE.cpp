#include <iostream>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops") 
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef vector<bool> vb;



#define endll '\n'

#define all(x) (x).begin(), (x).end()
#define MOD ll(1e9+7)
#define inf int(2e31-1)
#define INF ll(2e63-1)
#define EPS ld(1e-9)
#define dbg(x) cerr << __LINE__ << ": " << #x << "=" << x << endll;
#define print(x) cout << __LINE__ << ": " << #x << "=" << x << endll;
#define ans(x) cout << (x) << endll; return;


int memo[100][100];

int dfs(int i, int target, string s) {
    if (i == s.size()) {
        return target == 0;
    }
    if (memo[i][target] != -1) {
        return memo[i][target];
    }
    int res = 0;
    if (s[i] == '+') {
        for (int j = 1; j <= target; j++) {
            res += dfs(i + 1, target - j, s);
        }
    } 
    else if (s[i] == '*') {
        for (int j = 1; j <= target; j++) {
            res += dfs(i + 1, target / j, s);
        }
    } 
    else {
        res += dfs(i + 1, target, s);
    }
    memo[i][target] = res;
    return res;
}

void solve(int num_tc)
{
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    memset(memo, -1, sizeof(memo));
    cout << dfs(0, m, s) << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve(1);
    return 0;
}