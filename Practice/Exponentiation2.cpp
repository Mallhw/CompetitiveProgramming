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

ll exp(ll x, ll n, ll m) {
	assert(n >= 0);
	x %= m;
	ll res = 1;
	while (n > 0) {
		if (n % 2 == 1) {  // if n is odd
			res = res * x % m;
		}
		x = x * x % m;
		n /= 2;  // divide by two
	}
	return res;
}
int main() 
{ 
    ios::sync_with_stdio(0); 
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        ll pow_bc = exp(b, c, mod - 1);
		ll ans = exp(a, pow_bc, mod);

		cout << ans << '\n';
    } 
    return 0; 
} 
