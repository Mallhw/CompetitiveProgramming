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
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    int T; 
    cin >> T; 
    while (T--) { 
        vi arr(5);
        cin >> arr[0] >> arr[1] >> arr[3] >> arr[4];
        
        arr[2] = arr[0] + arr[1];
        ll ans = 0;
        ll ans2 = 0;
        for(int i = 2; i < 5; i++) {
            if(arr[i] == arr[i-1] + arr[i-2]) {
                ans++;
            }
        }
        arr[2] = arr[4] - arr[3];
        for(int i = 2; i < 5; i++) {
            if(arr[i] == arr[i-1] + arr[i-2]) {
                ans2++;
            }
        }

        cout << max(ans, ans2) << endl;

    } 
    return 0; 
} 
