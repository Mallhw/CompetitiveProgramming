#include <bits/stdc++.h> 
using namespace std; 
#define max(a, b) (a < b ? b : a) 
#define min(a, b) ((a > b) ? b : a) 
#define dbg(x) cerr << __LINE__ << ": " << #x << "=" << x << endl;
#define mod 1000000007 
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
using ll = long long;

const int MAX_N = 20;
const ll MOD = (ll)1e9 + 7;

ll dp[1 << MAX_N][MAX_N];
// come_from[i] contains the cities that can fly to i
vector<int> come_from[MAX_N];

int main() {
	int city_num;
	int flight_num;
	cin >> city_num >> flight_num;
	for (int f = 0; f < flight_num; f++) {
		int start, end;
		cin >> start >> end;
		come_from[--end].push_back(--start);
	}

	dp[1][0] = 1;
	for (int s = 2; s < 1 << city_num; s++) {
		// only consider subsets that have the first city
		if ((s & (1 << 0)) == 0) continue;
		// also only consider subsets with the last city if it's the full subset
		if ((s & (1 << (city_num - 1))) && s != ((1 << city_num) - 1)) continue;

		for (int end = 0; end < city_num; end++) {
			if ((s & (1 << end)) == 0) continue;

			// the subset that doesn't include the current end
			int prev = s - (1 << end);
			for (int j : come_from[end]) {
				if ((s & (1 << j))) {
					dp[s][end] += dp[prev][j];
					dp[s][end] %= MOD;
				}
			}
		}
	}
	cout << dp[(1 << city_num) - 1][city_num - 1] << '\n';
}