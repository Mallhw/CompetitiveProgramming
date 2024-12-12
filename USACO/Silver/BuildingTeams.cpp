#include <iostream>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>
#include <algorithm>
#include <cmath>
#include <streambuf>
#include <sstream>
#include <unordered_set>

using namespace std;
typedef long long ll;


#define endll '\n'
vector<int> adj[];
bool visited[];
void dfs(int s, ) {
    if(visited[s]) { return; }
    visited[s] = true;
    for(auto u : adj[s]) {
        dfs(u, adj, visited);
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> adj[n];
    bool visisted[n];
    for(int i = 0; i < n; i++) {
        int a; int b;
        cin >> a >> b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }
    
    return 0;
}