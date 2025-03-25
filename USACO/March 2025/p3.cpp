#include <bits/stdc++.h> 
using namespace std; 
typedef long long int ll; 
void sol() {
    int n;
    cin >> n;
    int N = n + 1;
    vector<ll> parent(N); vector<ll> cost(N); vector<ll> enjoyment(N);
    for(int i = 2; i < N; i++) {
        cin >> parent[i] >> cost[i] >> enjoyment[i];
    }
    // for(int i = 0; i < N; i++) {
    //     cout << parent[i] << ' ';
    // }
    // cout << endl;
    // for(int i = 0; i < n; i++) {
    //     cout << cost[i] << ' ';
    // }
    // cout << endl;
    // for(int i = 0; i < n; i++) {
    //     cout << enjoyment[i] << ' ';
    // }
    // cout << endl;
    vector<ll> totalEnjoyment(N, 0);
    for(int i = 2; i < N; i++) {
        totalEnjoyment[i] = totalEnjoyment[parent[i]] + enjoyment[i];
    }
    // for(int i = 0; i < N; i++) {
    //     cout << totalEnjoyment[i] << ' ';
    // }
    // cout << endl;

    vector<vector<ll>> path(N);
    vector<vector<ll>> diff(N);
    for(int i = 0; i < N; i++) {
        ll cur = i;
        path[i].push_back(i); diff[i].push_back(cost[i]);
        while(cur != 0) {
            cur = parent[cur];
            path[i].push_back(cur); diff[i].push_back(cost[cur]);
        }
        sort(diff[i].begin(), diff[i].end(), greater<ll>());
    }

    // for(auto v : diff) {
    //     for(auto val : v) {
    //         cout << val << ' ';
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    ll q;
    cin >> q;
    while(q--) {
        ll courage, skips;
        cin >> courage >> skips;
        ll ans = 0;
        for(int i = 0; i < N; i++) {
            // check
            bool check = true;
            //cout << "node: " << i << endl;
            for(int j = skips; j < path[i].size(); j++) {
                if(diff[i][j] > courage) {
                    check = false; 
                    break;
                }
                //cout << diff[i][j] << ' ';
            }
            //cout << endl;
            //cout << "enjoy: " << totalEnjoyment[i] << " courage: " << curCourage << endl;
            if(check) ans = max(ans, totalEnjoyment[i]);
        }
        cout << ans << endl;
    }
    return;
}
int main() 
{ 
    sol();
    return 0; 
} 
