#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> diff(n + 1);
	// read input and build difference array
	for (int i = 0; i < k; i++) {
		int l, r;
		cin >> l >> r;
		l--;  // make zero-indexed
		r--;
		diff[l]++;
		diff[r + 1]--;
	}

	int sol[1000000];
	int tot = 0;
	for (int i = 0; i < n; i++) {  // build prefix sum array
		tot += diff[i];
		sol[i] = tot;
	}
	sort(sol, sol + n);          // sort to get median
	cout << sol[n / 2] << '\n';  // output the median
}