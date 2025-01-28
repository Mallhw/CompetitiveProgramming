#include <bits/stdc++.h>
using namespace std;
#define max(a, b) (a < b ? b : a) 
#define min(a, b) ((a > b) ? b : a) 
typedef long long int ll; 
typedef vector<long long> vll;


int main() {
    ll N;
    cin >> N;
    vector<ll> a(N + 1), b(N + 1); 
    unordered_map<ll, vector<ll>> iB;
    unordered_map<ll, vector<ll>> pSum;

    
    for(ll i = 1; i <= N; i++) {
        cin >> a[i];
    }
    for(ll i = 1; i <= N; i++) {
        cin >> b[i];
        iB[b[i]].push_back(i);
    }

    for(auto it = iB.begin(); it != iB.end(); it++) {
        auto& vals = *it; 
        ll curNum = vals.first;  
        vector<ll>& ind = vals.second;  

        sort(ind.begin(), ind.end());
        vector<ll> pre(ind.size() + 1, 0);
        for(ll i = 0; i < ind.size(); i++) {
            pre[i + 1] = pre[i] + ind[i];
        }


        pSum[curNum] = pre;
    }

    ll ans = 0;

    ll totalIntervals = (N * (N + 1) / 2);
    for(int i = 1; i <= N; i++) {
        if (a[i] == b[i]) {
            ll numIntervals = i * (N - i + 1);
            ll total = totalIntervals - numIntervals;
            ans += total;
        }
    }
    for(int j = 0; j < N + 1; j++) {
        int v = a[j];
        auto it = iB.find(v);
        if (it == iB.end()) {
            continue;
        }


        auto &t = *it;
        auto& ind = t.second;
        auto& pre = pSum[v];


        ll cur = N - j + 1;
        ll begin = lower_bound(ind.begin(), ind.end(), j) - ind.begin();
        ll end = upper_bound(ind.begin() + begin, ind.end(), cur) - ind.begin();
        ans += (j * (end - begin)) + ((N + 1) * (ind.size() - end) - (pre[ind.size()] - pre[end]));

        ll lowL = upper_bound(ind.begin(), ind.end(), j - 1) - ind.begin();
        ll highR = upper_bound(ind.begin(), ind.begin() + lowL, cur) - ind.begin();
        ll curTotal = cur * (lowL - highR);
        if(lowL != 0) {
            ans += pre[highR] + curTotal;
        }   
        
    }


    cout << ans << endl;
    return 0;
}
