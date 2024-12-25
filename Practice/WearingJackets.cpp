#include <iostream>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops") 
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef vector<bool> vb;



#define endll '\n'

#define all(x) (x).begin(), (x).end()
#define MOD ll(1e9+7)
#define inf int(2e31-1)
#define INF ll(2e63-1)
#define EPS ld(1e-9)
#define dbg(x) cerr << __LINE__ << ": " << #x << "=" << x << endll;
#define print(x) cout << __LINE__ << ": " << #x << "=" << x << endll;
#define ans(x) cout << (x) << endll; return;

template <typename T>
ostream& operator<< (ostream& os, const vector<T>& arr){
	os << "[";
    for(const T x : arr){
		os << x << " ";
	}
	os << "]";
    return os;
}

template <typename T, typename U>
ostream& operator<< (ostream& os, const pair<T, U>& x){
    os << "(" << x.first << ", " << x.second << ")";
    return os;
}

template <typename T, typename U>
ostream& operator<< (ostream& os, const vector<pair<T, U>>& arr){
	os << "{\n";
    for(const pair<T,U>& x : arr){
		os << "    " << x << endll;
	}
	os << "}";
    return os;
}

template <typename T, typename U>
ostream& operator<< (ostream& os, const map<T, U>& arr){
	os << "{\n";
    for(const pair<T,U>& x : arr){
		os << "    " << x << endll;
	}
	os << "}";
    return os;
}

template <typename T>
inline void fillv(vector<T>& v, int n) {
    for (int i = 0; i < n; ++i) {
        std::cin >> v[i];
    }
}
template <typename T, typename U>
inline void fillv(vector<pair<T, U>>& v, int n, bool inv = false){
	if(inv){
		for(int i = 0 ; i < n; ++i){
			cin >> v[i].second >> v[i].first;
		}
		return;
	}
	for (int i = 0; i < n; ++i) {
        cin >> v[i].first >> v[i].second;
    }
	return;
}

inline void open(string name){
    freopen((name + ".in").c_str(), "r", stdin);
	freopen((name + ".out").c_str(), "w", stdout);
}

long long binExp(long long a, long long b) {
  if (b == 0)
    return 1;

  long long res = binExp(a, b / 2);
  if (b & 1) {
    return a * (res * res);
  } else
    return (res * res);
}


ll to_date(ll month, ll year)
{
    return year * 12 + month;
}

ll eval(string s, ll m)
{
    s = s.substr(1);
    string operation; ll ans = m;
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == '+' || s[i] == '^' || s[i] == '*')
        {
            if(!operation.empty())
            {
                ll num = atoi(operation.substr(1).c_str());
                if(operation[0] == '^')
                {
                    ans = binExp(ans, num);
                }
                if(operation[0] == '+')
                {
                    ans += num;
                }
                if(operation[0] == '*')
                {
                    ans *= num;
                }
            }
            operation.clear();
        }
        operation.push_back(s[i]);
    }
    
    if(!operation.empty())
    {
        ll num = atoi(operation.substr(1).c_str());
        if(operation[0] == '^')
        {
            ans = binExp(ans, num);
        }
        if(operation[0] == '+')
        {
            ans += num;
        }
        if(operation[0] == '*')
        {
            ans *= num;
        }
    }

    return ans;
}

void solve(int num_tc)
{
    ll I, Y; cin >> I >> Y;
    vector<ll> pref(Y * 13 + 69);

    for (ll i = 0; i < Y; ++i) {
        string s; cin >> s;
        for(int m = 1; m <= 12; m++) pref[to_date(m, i+1)] = eval(s, m);
    }

    for(int i = 0; i < pref.size() - 1; i++)
    {
        pref[i+1] += pref[i];
    }   

    ll ans = 0;

    for(int i = 0; i < I; i++)
    {
        int y1, m1, y2, m2; cin >> y1 >> m1 >> y2 >> m2;
        ans +=  pref[to_date(m2, y2)] - pref[to_date(m1, y1) - 1];
    }

    cout << ans << endll;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);  

    ll T = 1;
    //cin >> T;
    for(ll t = 0; t < T; t++){
        solve(t+1);
    }
}
