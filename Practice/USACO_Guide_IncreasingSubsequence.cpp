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
int find_lis(const vector<ll> &a) {
	vector<int> dp;
	for (int i : a) {
		int pos = lower_bound(dp.begin(), dp.end(), i) - dp.begin();
		if (pos == dp.size()) {
			dp.push_back(i);
		} else {
			dp[pos] = i;
		}
	}
	return dp.size();
}


int main() 
{ 
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    int n;
    cin >> n;
    vll arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << find_lis(arr) << endl;
    return 0; 
} 
