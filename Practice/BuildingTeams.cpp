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


int N, M;
vector<int> adj[200005];
int color[100005];
bool impossible = false;

void color_em (int node, int cc) {
    if (color[node] != 0) return;
    color[node] = cc;
    int nc = (cc == 1) ? 2 : 1;
    for (auto fr : adj[node]) {
        if (color[fr] == cc) {impossible = true; return;}
        if (color[fr] == 0) {color_em(fr, nc);}
    }
}
int main() 
{ 
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    cin >> N >> M;
    vector<bool> vis(N+1);
    for(int i = 0; i < M; i++) {
        ll a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i = 1; i <= N; i++) {
        if (color[i] == 0) {
            color_em(i, 1);
        }
    }
    if (impossible) cout << "IMPOSSIBLE" << endl;
    else {
        for(int i = 1; i <= N; i++) {
            cout << color[i] << " ";
        }
        cout << endl;
    }
    return 0; 
} 
