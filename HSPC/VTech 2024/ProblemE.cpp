#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    int k = count(s.begin(), s.end(), '*');
    int pow2[m + 1];
    pow2[0] = 1;
    for (int i = 1; i <= m; i++) {
        pow2[i] = pow2[i - 1] * 2;
    }
    vector<vector<int>> dp(k + 1, vector<int>(m + 1, 0));
    dp[0][1] = 1;
    for (int i = 0; i < n; i++) {
        if (s[i] == '*') {
            for (int j = k; j >= 1; j--) {
                for (int x = 1; x <= m; x++) {
                    for (int y = 1; y <= m; y++) {
                        if (x * y > m) break;
                        dp[j][x * y] = (dp[j][x * y] + dp[j - 1][x] * dp[j - 1][y]) % MOD;
                    }
                }
            }
        } else {
            for (int j = 0; j <= k; j++) {
                for (int x = 1; x <= m; x++) {
                    for (int y = 1; y <= m; y++) {
                        if (x + y > m) break;
                        dp[j][x + y] = (dp[j][x + y] + dp[j][x] * dp[j][y]) % MOD;
                    }
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= k; i++) {
        ans = (ans + dp[i][m]) % MOD;
    }
    cout << ans << endl;
    return 0;
}