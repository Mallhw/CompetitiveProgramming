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
    vector<int> a(n);
    unordered_map<int, int> last_pos;
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int best_l = -1, best_r = -1, max_len = 0;
    
    for (int i = 0; i < n; i++) {
        if (last_pos.count(a[i])) {
            int l = last_pos[a[i]], r = i;
            unordered_map<int, bool> seen;
            bool distinct = true;
            
            for (int j = l + 1; j < r; j++) {
                if (seen[a[j]]) {
                    distinct = false;
                    break;
                }
                seen[a[j]] = true;
            }
            
            if (distinct && r - l - 1 > max_len) {
                max_len = r - l - 1;
                best_l = l + 2;
                best_r = r;
            }
        }
        last_pos[a[i]] = i;
    }

    if(n == 1) {
        cout << "1 1\n";
        return;
    }
    if (best_l == -1) {
        cout << "0\n";
    } else {
        cout << best_l << " " << best_r << "\n";
    }
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