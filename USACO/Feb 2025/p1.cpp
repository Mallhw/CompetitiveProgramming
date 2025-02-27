#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void sol() {
    ll n, q;
    cin >> n >> q;
    bool arr[n][n];
    ll half = n / 2;
    ll moves = 0;

    for (int r = 0; r < n; r++) {
        string line;
        cin >> line;
        for (int c = 0; c < n; c++) {
            arr[r][c] = (line[c] == '#');
        }
    }

    ll spots[half * half];
    for (ll i = 0; i < half; i++) {
        for (ll j = 0; j < half; j++) {
            int topRight = n - 1 - j;
            int bottomRight = n - 1 - i;
            ll sum = arr[i][j] + arr[i][topRight] + arr[bottomRight][j] + arr[bottomRight][topRight] ;
            spots[i * half + j] = sum;
            
            moves += 2 - abs(sum - 2);
        }
    }
    while (q--) {
        cout << moves << '\n';
        ll r, c;
        cin >> r >> c;
        r--; c--;
        ll a = (r < half) ? r : (n - 1 - r);
        ll b = (c < half) ? c : (n - 1 - c);

        
        ll before = 2 - abs(spots[a * half + b] - 2);
        spots[a * half + b] += arr[r][c] ? -1 : 1;
        ll after = 2 - abs(spots[a * half + b] - 2);
        moves += after - before;
        arr[r][c] = !arr[r][c];
    }
    cout << moves << '\n';
}

int main() {
    sol();
    return 0;
}