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
void solve() {
    ll n, l, r;
    cin >> n >> l >> r;

    vll arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    vll left(arr.begin(), arr.begin() + (l - 1)); 
    vll segment(arr.begin() + (l - 1), arr.begin() + r); 
    vll right(arr.begin() + r, arr.end()); 
    
    sort(left.begin(), left.end());
    sort(right.begin(), right.end());
    sort(segment.begin(), segment.end(), greater<ll>());
    vll temp = segment;
    for (size_t i = 0; i < min(left.size(), segment.size()); i++) {
        if (left[i] < temp[i]) {
            temp[i] = left[i];
        } else {
            break;
        }
    }
    ll leftSum = accumulate(temp.begin(), temp.end(), 0LL);
    temp = segment;
    for (size_t i = 0; i < min(right.size(), segment.size()); i++) {
        if (right[i] < temp[i]) {
            temp[i] = right[i];
        } else {
            break;
        }
    }
    ll rightSum = accumulate(temp.begin(), temp.end(), 0LL);
    cout << min(leftSum, rightSum) << endl;
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
