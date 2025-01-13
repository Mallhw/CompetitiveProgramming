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


vector<bool> visited(201);
vector<vector<ll>> adj(201);

ll counter = 0;

void dfs(int current_node) {
    if (visited[current_node]) { return; }
	visited[current_node] = true;
    counter++;
	for (int neighbor : adj[current_node]) { dfs(neighbor); }
}
int main() 
{ 
    freopen("moocast.in", "r", stdin);
	freopen("moocast.out", "w", stdout);
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    int n;
    cin >> n;
    vll x(n), y(n), p(n);
    for(int i = 0; i < n; i++) {
        cin >> x[i] >> y[i] >> p[i];
    }

    adj = vector<vector<ll>>(n);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i != j) {
                ll dist = (pow((x[i] - x[j]), 2) + pow((y[i] - y[j]), 2));
                if(dist <= pow(p[i], 2)) {
                    adj[i].push_back(j);
                }
            } 
        }
    }
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        counter = 0;
        visited = vector<bool>(n);
        dfs(i);
        ans = max(ans, counter);
    }
    cout << ans << endl;
    return 0; 
} 
