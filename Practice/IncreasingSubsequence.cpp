#include <bits/stdc++.h> 
using namespace std; 
#define max(a, b) (a < b ? b : a) 
#define min(a, b) ((a > b) ? b : a) 
#define dbg(x) cerr << __LINE__ << ": " << #x << "=" << x << endl;
#define mod 1e9 + 7 
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
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    int n;
    cin >> n;
    vll arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    vll LIS(n);
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(arr[j] < arr[i]) {
                LIS[i] = max(LIS[j]+1, LIS[i]);
                ans = max(ans, LIS[i]);
            }
        } 
    }
    cout << ans+1 << endl;

    return 0; 
} 
