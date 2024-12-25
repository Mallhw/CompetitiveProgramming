//Time = O(N^2), Space = O(N^2)
vector<vector<int>> dp{};
	
int lcs(string X, string Y, int m, int n)
{
	if(m == 0 || n == 0) return 0;
	
	if(dp[m - 1][n - 1] != -1) return dp[m - 1][n - 1];
	
	if(X[m - 1] == Y[n - 1]) return dp[m - 1][n - 1] = 1 + lcs(X, Y, m - 1, n - 1);
	
	return dp[m - 1][n - 1] = max(lcs(X, Y, m - 1, n), lcs(X, Y, m, n - 1));
}