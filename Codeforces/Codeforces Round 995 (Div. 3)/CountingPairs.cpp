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

#include <set>
#include <iostream>


int main() 
{ 
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    int T; 
    cin >> T; 
    while (T--) {
        int n, x, y;
        cin >> n >> x >> y;
        vector<ll> a(n);
        ll sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            sum += a[i];
        }
        sort(a.begin(), a.end());
        int sum = accumulate(a.begin(), a.end(), 0LL);
        ordered_set os;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            os.insert(a[i]);
        }
        for (int i = 0; i < n; i++) {
            os.erase(a[i]);
            int tempSum = sum - a[i];
            int j = os.order_of_key(tempSum - y);
            int k = os.order_of_key(tempSum - x + 1);
            ans += k - j;
        }
        cout << ans << endl;
    }
    return 0; 
} 
