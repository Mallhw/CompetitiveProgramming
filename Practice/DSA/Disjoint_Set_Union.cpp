
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