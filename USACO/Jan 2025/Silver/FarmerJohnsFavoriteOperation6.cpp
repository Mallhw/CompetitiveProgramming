#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;  // Number of test cases
    cin >> T;

    while (T--) {
        ll N, M;
        cin >> N >> M;

        vector<ll> a(N);
        for (ll i = 0; i < N; i++) {
            cin >> a[i];
        }

        // Step 1: Compute a[i] % M for all elements
        vector<ll> mods(N);
        for (ll i = 0; i < N; i++) {
            mods[i] = a[i] % M;
        }

        // Step 2: Sort the mods array to find the median
        sort(mods.begin(), mods.end());

        // Step 3: Find the median mod value, which will be the optimal choice for x % M
        ll median_mod = mods[N / 2];  // Median of mods

        // Step 4: Calculate the minimum boredom value
        ll total_operations = 0;
        for (ll i = 0; i < N; i++) {
            // Minimum operations to make a[i] % M == median_mod
            ll diff = abs(mods[i] - median_mod);
            total_operations += min(diff, M - diff);  // Take the smaller number of operations (adding or subtracting)
        }

        // Output the result for this test case
        cout << total_operations << endl;
    }

    return 0;
}
