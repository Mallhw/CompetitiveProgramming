#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<ll> prefixUnique(n);
    vector<bool> done(n + 1, false); 
    ll current = 0;
    for(int i = 0; i < n; i++) {
        if(!done[a[i]]) {
            done[a[i]] = true;
            current++;
        }
        prefixUnique[i] = current;
    }

    unordered_map<ll, vector<ll>> mapNumAppears;
    for(int i = 0; i < n; i++) {
        mapNumAppears[a[i]].push_back(i);
    }

    ll total = 0;
    for(const auto& entry : mapNumAppears) {
        ll y = entry.first;
        const vector<ll>& indices = entry.second;
        ll m = indices.size();
        if(m < 2) continue;

        ll last_pair_start = indices[m - 2];
        ll end_index = last_pair_start - 1;

        if(end_index < 0) {
            continue;
        }
        ll distinct_count = prefixUnique[end_index];
        bool subtract = (m >= 3);
        total += distinct_count - (subtract ? 1 : 0);
    }

    cout << total << endl;

    return 0;
}