#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

unordered_map<ll, ll> vmap;  
set<ll> visited; 
ll A, B;
ll ans = 0;

void bfs(ll start) {
    queue<ll> q;
    q.push(start);
    visited.insert(start);
    while(!q.empty()) {
        ll x = q.front();
        q.pop();
        if(A != B) {
            ll nodeB = B - x;
            if(nodeB != x && vmap.count(nodeB) && !visited.count(nodeB)) {
                ll sub = min(vmap[x], vmap[nodeB]);
                ans += sub;
                vmap[x] -= sub;
                vmap[nodeB] -= sub;
                if(vmap[nodeB] > 0) {
                    q.push(nodeB);
                    visited.insert(nodeB);
                }
            }
        }
        ll nodeA = A - x;
        if(nodeA != x && vmap.count(nodeA) && !visited.count(nodeA)) {
            ll sub = min(vmap[x], vmap[nodeA]);
            ans += sub;
            vmap[x] -= sub;
            vmap[nodeA] -= sub;
            if(vmap[nodeA] > 0) {
                q.push(nodeA);
                visited.insert(nodeA);
            }
        }
    }
}
void sol() {
    ll n;
    cin >> n >> A >> B;
    vector<ll> keys;
    for(int i = 0; i < n; i++) {
        ll count, id;
        cin >> count >> id;
        vmap[id] = count;
        keys.push_back(id);
    }
    sort(keys.begin(), keys.end());
    for(ll id : keys) {
        if(!visited.count(id) && vmap[id] > 0) {
            bfs(id);
        }
    }
    if(A % 2 == 0) {
        ll mid = A / 2;
        if(vmap.count(mid)) {
            ans += vmap[mid] / 2;
            vmap[mid] = vmap[mid] % 2; 
        }
    }
    if(A != B && B % 2 == 0) {
        ll mid = B / 2;
        if(vmap.count(mid)) {
            ans += vmap[mid] / 2;
            vmap[mid] = vmap[mid] % 2;
        }
    }
    
    cout << ans << endl;
    return;
}

int main() {
    sol();
    return 0;
}