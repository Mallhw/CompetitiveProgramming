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
    ll n;
    cin >> n;
    vll arr(n);
    for (ll i = 0; i < n; i++) {
        cin >> arr[i];
    }
    unordered_map<int, int> freq_map;
    for (int num : arr) {
        freq_map[num]++;
    }

    ll c = -1;
    for (const auto& entry : freq_map) {
        if (entry.second >= 2) {
            c = max(c, entry.first);
        }
    }

    if (c == -1) { 
        cout << -1 << endl;
        return;
    }
    vector<int> vec;
    int pair_count = 2; 
    for (int num : arr) {
        if (num == c && pair_count > 0) {
            pair_count--;
        } else {
            vec.push_back(num);
        }
    }

    sort(vec.begin(), vec.end());
    for (size_t i = 0; i < vec.size() - 1; ++i) {
        int a = vec[i];
        int b = vec[i + 1];
        if (abs(a - b) < 2 * c) {
            cout << a << " " << b << " " << c << " " << c << endl;
            return;
        }
    }
    cout << -1 << endl;
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
