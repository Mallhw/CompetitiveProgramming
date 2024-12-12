#include <bits./stdc++.h>

using namespace std;

vector<bool> checked;
vector<int> adj[];

void dfs(int n) {
    if(checked[n]) return;
    for(int a : adj[n]) {
        dfs(a);
    }
}

int main() {
    int n;
    cin >> n;
    while(n--) {
        int a; int b;
        cin >> a >> b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }
}