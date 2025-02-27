#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;

int n, a[N], b[N], T;

void solve() {
    cin >> n;
    vector<int> freq(n + 1);
    vector<vector<int>> pos(n + 1);
    vector<int> prv(n + 1), stk(n + 1);
    
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        a[i] = b[i];
        pos[a[i]].push_back(i);
        freq[a[i]]++;
    }
    
    int mp = 0, t = 0;
    vector<int> rmax(n + 2);
    rmax[n + 1] = 0;
    
    for (int i = n; i >= 1; i--) {
        rmax[i] = max(rmax[i + 1], a[i]);
        while (t && a[stk[t]] < a[i]) t--;
        prv[i] = stk[t];
        stk[++t] = i;
        
        if (!mp) {
            for (int k : pos[i]) {
                if (prv[k] != k-1) {
                    int m = 0;
                    for (int j = prv[k] + 1; j < k; j++) {
                        m = max(m, a[j]);
                    }
                    if (m >= rmax[k + 1]) {
                        mp = k;
                        break;
                    }
                }
            }
        }
    }
    
    if (mp) {
        int p = prv[mp];
        for (int i = mp + 1; i <= n; i++) a[i] = b[i];
        for (int i = p + 2; i <= mp; i++) a[i] = b[i - 1];
        a[p + 1] = b[mp];
        for (int i = 1; i <= p; i++) a[i] = b[i];
    }
    
    vector<int> res;
    for (int i = 1; i <= n; i++) {
        if (freq[a[i]] && (a[i] == n || freq[a[i] + 1] == 0)) {
            res.push_back(a[i]);
            freq[a[i]]--;
        }
    }
    
    for (int i = 0; i < res.size() - 1; i++) cout << res[i] << " ";
    cout << res.back() << "\n";
}

int main() {
    cin >> T;
    while (T--) solve();
    return 0;
}