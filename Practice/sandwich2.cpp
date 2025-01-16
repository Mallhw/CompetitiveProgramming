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
    int n;
    cin >> n;
    vll arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    vll prePos(n+1);
    vll preNeg(n+1);

    for(int i = n; i > 0; i--) {
        if(arr[i-1] >= 0) {
            prePos[i-1] = prePos[i] + arr[i-1];
            preNeg[i-1] = preNeg[i];
        }
        else {
            preNeg[i-1] = preNeg[i] + arr[i-1];
            prePos[i-1] = prePos[i];
        }
    }

    ll ans = 0;
    // for(int i = 0; i < n; i++) {
    //     cout << prePos[i] << " ";
    // }
    // cout << endl;
    // for(int i = 0; i < n; i++) {
    //     cout << preNeg[i] << " ";
    // }
    // cout << endl;
    for(int i = 0; i < n; i++) {
        // Handle pos cases first
        if(arr[i] >= 0) {
            if(prePos[i+1] > preNeg[i+1]) {
                ans++;
            }
            else {
                while(preNeg[i+1] > prePos[i+1]) {
                    i++;
                }
            }
        }
        if(arr[i] < 0) {
            if(prePos[i+1] > preNeg[i+1]) {
                i++;
            }   
        }
    }
    cout << ans << endl;
    return;
} 

int main() 
{ 
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    solve(); 
    return 0; 
} 
