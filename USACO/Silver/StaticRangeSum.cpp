#include "bits/stdc++.h" 
using namespace std; 
#define max(a, b) (a < b ? b : a) 
#define min(a, b) ((a > b) ? b : a) 
#define mod 1e9 + 7 
#define FOR(a, c) for (int(a) = 0; (a) < (c); (a)++) 
#define FORL(a, b, c) for (int(a) = (b); (a) <= (c); (a)++) 
#define FORR(a, b, c) for (int(a) = (b); (a) >= (c); (a)--) 
#define INF 1000000000000000003 
typedef long long int ll; 
typedef vector<int> vi;
typedef vector<long long> vll; 
typedef pair<int, int> pi; 
#define F first 
#define S second 
#define PB push_back 
#define POB pop_back 
#define MP make_pair 
int main() 
{ 
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    ll N; ll Q;
    cin >> N >> Q;
    vll arr(N);
    vll pre(N+1);
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
        pre[i+1] = pre[i] + arr[i];
    }
    for(int i = 0; i < Q; i++) {
        ll l; ll r;
        cin >> l >> r;
        cout << (pre[r] - pre[l]) << endl;
    }
    return 0; 
} 
