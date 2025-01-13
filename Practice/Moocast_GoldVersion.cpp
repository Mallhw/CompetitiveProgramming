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


vector<bool> visited(1001);
vector<vector<ll>> adj(1001);
ll counter = 0;
vll x(1001), y(1001);

void dfs(int current_node, int distance) {
    if (visited[current_node]) { return; }
	visited[current_node] = true;
    counter++;
	for (int neighbor : adj[current_node]) { 
        ll val = pow(x[current_node] - x[neighbor], 2) + pow(y[current_node] - y[neighbor], 2);
        if(distance >= val) {
            dfs(neighbor, distance); 
        }
    }
}

int main() 
{ 
    freopen("moocast.in", "r", stdin);
	// // the following line creates/overwrites the output file
	freopen("moocast.out", "w", stdout);
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    int n;
    cin >> n;
    
    for(int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i != j) {
                adj[i].push_back(j);
            }
        }
    }
    counter = 0;
    // binary search
    ll low = 0;
    ll high = 1e15+4;
    while(low < high) {
        int mid = low + (high - low) / 2;
        dfs(0, mid);
        if(counter < n) {
            low = mid + 1;
        }
        else {
            high = mid;
        }
        counter = 0;
        visited = vector<bool>(1001);
    }
    cout << high << endl;
    return 0; 
} 
