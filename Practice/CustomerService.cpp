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
    vector<vector<ll>> lines(n, vector<ll>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> lines[i][j];
        }
    }
    vector<vector<ll>> suffix(n, vector<ll>(n));
    for (int i = 0; i < n; i++) {
        ll sum = 0;
        for (int j = n - 1; j >= 0; j--) {
            sum += lines[i][j];
            suffix[i][j] = sum;
        }
    }
    vector<ll> maxsuffix(n);
    for (int i = 0; i < n; i++) {
        ll currentnum = 1;
        for (int j = n - 1; j >= 0; j--) {
            if (suffix[i][j] != currentnum) {
                maxsuffix[i] = currentnum - 1;
                break;
            }
            if (j == 0) {
                maxsuffix[i] = currentnum;
                break;
            }
            else {
                currentnum += 1;
            }
        }
    }
    sort(maxsuffix.begin(), maxsuffix.end());

    ll pointer = 0, counter = 0;
    while (pointer < n) {
        if (maxsuffix[pointer] >= counter) {
            pointer += 1;
            counter += 1;
        }
        else {
            pointer += 1;
        }
    }
    cout << counter << "\n";
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
