#include <bits/stdc++.h> 
using namespace std; 
#define max(a, b) (a < b ? b : a) 
#define min(a, b) ((a > b) ? b : a) 
#define dbg(x) cerr << __LINE__ << ": " << #x << "=" << x << endl;
#define mod 1000000007 
#define FOR(a, c) for (int(a) = 0; (a) < (c); (a)++) 
#define FORL(a, b, c) for (int(a) = (b); (a) <= (c); (a)++) 
#define FORR(a, b, c) for (int(a) = (b); (a) >= (c); (a)--) 
#define INF LLONG_MAX 
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
    ll n, s1, s2, m1, m2;
        cin >> n >> s1 >> s2 >> m1;

        vector<ll> adj[n + 1];
        for(int i = 0; i < n; i++){
            ll u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        cin >> m2;
        vector<ll> adj2[n + 1];
        for(int i = 0; i < m2; i++){
            ll u, v;
            cin >> u >> v;
            adj2[u].push_back(v);
            adj2[v].push_back(u);
        }

        vector<bool> vis(n + 1, false);
        for(int i = 1; i <= n; i++){
            set<ll> s(adj2[i].begin(), adj2[i].end());
            for(ll c : adj[i]){
                if(s.count(c)) {
                    vis[i] = true;
                    break;
                }
            }
        }
        vector<vector<ll>> dist(n + 1, vector<ll>(n + 1, LLONG_MAX));
        dist[s1][s2] = 0;

        priority_queue<tuple<ll, ll, ll>, vector<tuple<ll, ll, ll>>, greater<tuple<ll, ll, ll>>> pq;
        pq.push({0, s1, s2});

        ll ans = -1;
        while(!pq.empty()){
            auto top = pq.top();
            int d = get<0>(top);
            int u = get<1>(top);
            int v = get<2>(top);

            pq.pop();
            if(d > dist[u][v]) continue;
            if(u == v && vis[u] == true){
                ans  = d;
                break;
            }
            for(ll c : adj[u]){
                for(ll c2 : adj2[v]){
                    ll total = d + abs(c - c2);
                    if(dist[c][c2] > d + 1){
                        dist[c][c2] = total;
                        pq.push({total, c, c2});
                    }
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
    int T; 
    cin >> T; 
    while (T--) { 
        solve();
    } 
    return 0; 
} 
