#include <bits/stdc++.h> 
using namespace std; 
#define max(a, b) (a < b ? b : a) 
#define min(a, b) ((a > b) ? b : a) 
#define dbg(x) cerr << __LINE__ << ": " << #x << "=" << x << endl;
#define mod 1e9 + 7 
#define FOR(a, c) for (int(a) = 0; (a) < (c); (a)++) 
#define FORL(a, b, c) for (int(a) = (b); (a) <= (c); (a)++) 
#define FORR(a, b, c) for (int(a) = (b); (a) >= (c); (a)--) 
#define INF 1000000000000000003 
typedef long long int ll; 
typedef vector<long long> vll;
typedef vector<int> vi; 
typedef pair<int, int> pi; 
#define F first 
#define S second 
#define PB push_back 
#define POB pop_back 
#define MP make_pair 
long long dp[1000001];

int main() {
	int n;
	cin >> n;
	dp[0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 6; j++) {
			if (i - j >= 0) { dp[i] += dp[i - j]; }
		}
		dp[i] %= 1000000007;
	}
	cout << dp[n] << "\n";
}