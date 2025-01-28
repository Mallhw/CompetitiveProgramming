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
int main() 
{ 
    freopen("haybales.in", "r", stdin);
	freopen("haybales.out", "w", stdout);
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    
    int n, q;
    cin >> n >> q;
    vll arr;
    for(int i = 0; i < n; i++) {
        ll temp;
        cin >> temp;
        arr.push_back(temp);
    }
    sort(arr.begin(), arr.end());
    while(q--) {
        ll l, r;
        cin >> l >> r;
        cout << upper_bound(arr.begin(), arr.end(), r) - lower_bound(arr.begin(), arr.end(), l) << endl;
    }
    return 0; 
} 
