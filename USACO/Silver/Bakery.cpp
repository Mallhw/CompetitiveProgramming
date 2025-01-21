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
ostream& operator<<(ostream& os, const vector<T> arr) {
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

ll binarySearchCookies(ll tc, ll tm, ll n, vector<vector<ll>> v) {
    ll low = 0;
    ll high = n;
    while (low < high) {
        ll mid = low + (high - low) / 2;
        bool check = true;
        for(int i = 0; i < n; i++) {
            if(v[i][0] >= v[i][1]) {
                if((tc-mid) * v[i][0] + tm * v[i][1] < v[i][2]) {
                    check = false;
                    break;
                }
            }
        }
        if (!check) {
            high = mid;
        } 
        else {
            low = mid + 1;
        }
    }
    return low;
}

ll binarySearchMuffins(ll tc, ll tm, ll n, ll cookiesReduced, vector<vector<ll>> v) {
    ll low = 0;
    ll high = n;
    tc -= cookiesReduced;
    while (low < high) {
        ll mid = low + (high - low) / 2;
        bool check = true;
        for(int i = 0; i < n; i++) {
            if(v[i][0] < v[i][1]) {
                if(tc * v[i][0] + (tm-mid) * v[i][1] < v[i][2]) {
                    check = false;
                    break;
                }
            }
        }
        if (!check) {
            high = mid;
        } 
        else {
            low = mid + 1;
        }
    }
    return low;
}

ll binarySearchTotal(ll tc, ll tm, ll n, vector<vector<ll>> v) {
    ll low = 0;
    ll high = n - 1;
    while (low < high) {
        ll mid = low + (high - low) / 2;
        ll cookiesReduced = binarySearchCookies(tc, tm, mid, v);
        ll muffinsReduced = binarySearchMuffins(tm, tc, mid, cookiesReduced, v);
        if (cookiesReduced + muffinsReduced <= low) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    return low;
}



int main() 
{ 
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    int T; 
    cin >> T; 
    while (T--) { 
        int n;
        cin >> n;
        ll tc, tm;
        cin >> tc >> tm;
        vector<vector<ll>> v(n, vector<ll>(3));
        for(int i = 0; i < n; i++) {
            ll cookies, muffins, waitTime;
            cin >> cookies >> muffins >> waitTime;
            v[i][0] = cookies;
            v[i][1] = muffins;
            v[i][2] = waitTime;
        }
        ll ans = binarySearchTotal(tc, tm, 10e9, v);

        cout << ans << endl;
    } 
    return 0; 
} 
