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
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& arr) {
    os << "[";
    for (size_t i = 0; i < arr.size(); ++i) {
        os << arr[i] << " ";
    }
    os << "]";
    return os;
}

template <typename T>
ostream& operator<<(ostream& os, const vector<vector<T>>& grid) {
    os << "[\n";
    for (const auto& row : grid) {
        os << "  " << row << "\n";
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
		os << "    " << x << endl;
	}
	os << "}";
    return os;
}
void solve() {
    ll n, k;
    cin >> n >> k;
    vll a(n + 1);
    for (ll i = 1; i <= n; i++) {
        cin >> a[i];
    }
    if(n == k) {
        for(ll i = 2; i <= n; i += 2) {
            //dbg(a[i]);
            //dbg(i / 2);
            if(a[i] != i / 2) {
                cout << i / 2  << endl;
                return;
            }
        }
        cout << n / 2 + 1 << endl;
    }
    else {
        for(ll i = 2; i <= n - k + 2; i++) {
            //dbg(a[i]);
            if(a[i] != 1) {
                cout << 1 << endl;
                return;
            }
        }
        ll counter = 2;
        for(ll i = n - k + 1; i <= n; i+= 2) {
            if(a[i] != counter) {
                cout << counter << endl;
                return;
            }
        }
    }
        
        return;
}
int main() 
{ 
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    int T; 
    cin >> T; 
    while (T--) { 
        solve();
    } 
    return 0; 
} 
