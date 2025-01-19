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
const int N = 2e5+5;

bool mark2[N];
bool mark[N];

int count1, count2, n, m1, m2, col[N];
vi adj1[N], adj2[N];
map<pair<int, int>, int> mp;

void dfs2(int u) {
    col[u] = count1;
    mark2[u] = true;
    for (int v : adj2[u]) {
        if (!mark2[v]) {
            dfs2(v);
        }
    }
}
void dfs1(int u) {
    mark[u] = true;
    for (int v : adj1[u]) {
        if(!mark[v] && mp[{u, v}] != 1) {
            dfs1(v);
        }
    }

}
int main() 
{ 
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    int T; 
    cin >> T; 
    while (T--) { 
        int n, m1, m2; cin >> n >> m1 >> m2;
        count1 = 0, count2 = 0;
        mp.clear();
        for (int i = 0; i < n; i++) {
            adj1[i].clear();
            adj2[i].clear();
            mark[i] = false;
            mark2[i] = false;
        }
        for (int i = 0; i < m1; i++) {
            int u, v; cin >> u >> v;
            u--; v--;
            adj1[u].PB(v);
            adj1[v].PB(u);
        }
        for (int i = 0; i < m2; i++) {
            int u, v; cin >> u >> v;
            u--; v--;
            adj2[u].PB(v);
            adj2[v].PB(u);
        }
        for (int i = 0; i < n; i++) {
            if(!mark2[i]) {
                count1++;
                dfs2(i);
            }
        }
        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j : adj1[i]) {
                if(col[i] != col[j]) {
                    ans++;
                    mp [{i, j}] = 1;
                }
            }
        }
        for(int i = 0; i < n; i++) {
            if(!mark[i]) {
                count2++;
                dfs1(i);
            }
        }
        cout << ans / 2 + (count2 - count1) << endl;

    } 
    return 0; 
} 
