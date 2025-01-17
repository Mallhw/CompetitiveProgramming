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
        ll n;
        cin >> n;
        vector<string> arr(n);
        vll ans(n);
        vll pos(n);
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
            ll cur = 0;
            for (char c : arr[i]) {
                if (c == '0') {
                    cur++;
                }
            }
            pos[i] = cur;
        }

        dbg(n);
        for(int i = 0; i < n; i++) {
            dbg(i+1);
            dbg(ans[pos[i]-1]);
            if(ans[pos[i]-1] != 0) {
                ans[pos[i]] = i+1;
            }
            else {
                // does have connecte node
                ll j = 0;
                ll numAtPos = pos[i]-1;
                dbg('test');
                dbg(arr[ans[numAtPos]-j][i]);
                while(j < n && arr[ans[numAtPos-j]][i] == 1) {
                    dbg(ans[numAtPos]);
                    dbg(arr[ans[numAtPos]-j][i]);
                    j++;
                }
                if(j == n-1) {
                    ans[n-1] = i+1;
                }
                ans[numAtPos+j] = i+1;
            }
        }
        for(int i = 0; i < n; i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    } 
    return 0; 
} 
