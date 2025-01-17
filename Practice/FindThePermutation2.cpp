#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<string> g(n);
        for (int i = 0; i < n; i++) {
            cin >> g[i];
        }
        vector<int> perm(n);
        iota(perm.begin(), perm.end(), 0);

        sort(perm.begin(), perm.end(), [&](int i, int j) {
            if(i < j) {
                return g[i][j] =='1';
            }
            return g[j][i] == '0';
        });
        for(int i = 0; i < n; i++) {
            cout << perm[i] + 1 << " ";
        }
        cout << endl;
    }

    return 0;
}
