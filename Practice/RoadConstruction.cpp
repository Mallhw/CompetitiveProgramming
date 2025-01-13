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

struct DSU {
  	vector<ll> e;
	DSU(ll N)
	{
		e = vector<ll>(N, -1); 
	}

  	void init(ll N) { 
		e = vector<ll>(N, -1); 
	}

  	ll get(ll x) { 
		return e[x] < 0 ? x : e[x] = get(e[x]); 
	}

  	bool sameSet(ll a, ll b) {
		return get(a) == get(b); 
	}

  	ll size(ll x) {
		return -e[get(x)]; 
	}

  	bool unite(ll x, ll y) { // union by size
  	  x = get(x), y = get(y);
  	  if (x == y)
  	    return 0;
  	  if (e[x] > e[y])
  	    swap(x, y);
	
  	  e[x] += e[y];
  	  e[y] = x;
  	  return 1;
  	}
};

int main() 
{ 
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    int n, m;
    cin >> n >> m;
    vll roads = vll(n);
    vll components = vll(n);
    DSU dsu(n);
    ll subComponents = n;
    ll ans = 0;
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        if(dsu.unite(a, b) == 1) {
            subComponents--;
        }
        ans = max(ans, dsu.size(a));
        cout << subComponents << ' ' << ans << endl;
    }
    return 0; 
} 
