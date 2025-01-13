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
bool is_possible(const vector<ll> &arr, const int k, ll max_sum) {
	// # of subarrays needed if sum of each subarray is at most max_sum
	int subarr_count = 0;
	// sum of the current subarray
	ll cur_sum = 0;

	for (const int &x : arr) {
		if (x > max_sum) { return false; }

		if (cur_sum + x > max_sum) {
			subarr_count++;
			cur_sum = 0;
		}
		cur_sum += x;
	}
	if (cur_sum > 0) { subarr_count++; }

	return subarr_count <= k;
}

int main() {
	int n, k;
	cin >> n >> k;
	vector<ll> arr(n);
	for (ll &i : arr) { cin >> i; }

	ll l = *max_element(begin(arr), end(arr));
	ll r = accumulate(begin(arr), end(arr), 0LL);
	while (l < r) {
		ll mid = (l + r) / 2;
		if (is_possible(arr, k, mid)) {
			r = mid;
		} else {
			l = mid + 1;
		}
	}

	cout << l << endl;
}