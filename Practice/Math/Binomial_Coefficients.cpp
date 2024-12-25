/** @return nCk mod p using dynamic programming */

ll binomial(ll n, ll k) {
	// dp[i][j] stores iCj

	vector<vector<ll>> dp(n + 1, vector<ll>(k + 1, 0));

	// base cases described above
	for (ll i = 0; i <= n; i++) {
		/*
		 * i choose 0 is always 1 since there is exactly one way
		 * to choose 0 elements from a set of i elements
		 * (don't choose anything)
		 */
		dp[i][0] = 1;
		/*
		 * i choose i is always 1 since there is exactly one way
		 * to choose i elements from a set of i elements
		 * (choose every element in the set)
		 */
		if (i <= k) { dp[i][i] = 1; }
	}

	for (ll i = 0; i <= n; i++) {
		for (ll j = 1; j <= min(i, k); j++) {
			if (i != j) {  // skips over the base cases
				// uses the recurrence relation above
				dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % MOD;
			}
		}
    }

	return dp[n][k];  // returns nCk modulo p
}

ll exactBinomial(ll n, ll k) {
    if (k > n - k) { k = n - k; }
	long long ret = 1;
	for (int i = 0; i < k; i++) {
		// this is done instead of *= for divisibility issues
		ret = ret * (n - i) / (i + 1);
	}
	return ret;
}

long long binomial(ll n, ll k) {
    return factorial[n] * inverse(factorial[k] * factorial[n - k] % m) % m;
}