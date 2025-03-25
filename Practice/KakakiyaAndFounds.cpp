#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;
ll N;

vector<vector<ll>> topd(int n, const vector<int>& p, const vector<ll>& d) {
    vector<vector<ll>> td(N, vector<ll>(11, 0));
    for(int i = 2; i <= n; i++) {
        td[i] = td[p[i]];
        td[i].push_back(d[i]);
        sort(td[i].begin(), td[i].end(), greater<ll>());
        td[i].resize(11); 
    }
    return td;
}

vector<ll> totalEnjoy(int n, const vector<int>& p, const vector<ll>& e) {
    vector<ll> total(N, 0);
    for(int i = 2; i <= n; i++) {
        total[i] = total[p[i]] + e[i];
    }
    return total;
}

vector<vector<pair<ll, ll>>> calcB(int n, const vector<vector<ll>>& td, const vector<ll>& total) {
    vector<vector<pair<ll, ll>>> bs(11 + 1);
    for(int waypoint = 1; waypoint <= n; waypoint++) {
        for(int k = 1; k <= 11; k++) {
            bs[k].emplace_back(td[waypoint][k - 1], total[waypoint]);
        }
    }
    for(int k = 1; k <= 11; k++) {
        sort(bs[k].begin(), bs[k].end()); 
    }
    return bs;
}

vector<vector<ll>> enjoyP(const vector<vector<pair<ll, ll>>>& bs) {
    vector<vector<ll>> pref(11 + 1);
    for(int k = 1; k <= 11; k++) {
        if(bs[k].empty()) continue;
        pref[k].resize(bs[k].size());
        pref[k][0] = bs[k][0].second;
        for(size_t j = 1; j < bs[k].size(); j++) {
            pref[k][j] = max(pref[k][j - 1], bs[k][j].second);
        }
    }
    return pref;
}

ll answerQuery(ll skill, int courage, const vector<vector<pair<ll, ll>>>& bs, const vector<vector<ll>>& pref) {
    int k = courage + 1;
    if(k > 11 || bs[k].empty()) return 0;
    auto& b = bs[k];
    auto it = upper_bound(b.begin(), b.end(), make_pair(skill, LLONG_MAX));
    if(it == b.begin()) return 0;
    int idx = distance(b.begin(), it) - 1;
    return pref[k][idx];
}

void sol() {
    cin >> n;
    N = n + 1;
    
    vector<int> p(N, 0);
    vector<ll> d(N, 0), e(N, 0);

    for(int i = 2; i <= n; i++) {
        cin >> p[i] >> d[i] >> e[i];
    }

    auto td = topd(n, p, d);
    auto total = totalEnjoy(n, p, e);
    auto bs = calcB(n, td, total);
    auto pref = enjoyP(bs);
    // for(auto a : td) {
    //     for(auto val : a) {
    //         cout << val << ' ';
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    // for(auto val : total) {
    //     cout << val << ' ';
    // }
    // cout << endl;
    // for(auto v : bs) {
    //     for(auto pa : v) {
    //         cout << pa.first << ' ';
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    // for(auto v : pref) {
    //     for(auto pa : v) {
    //         cout << pa << ' ';
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    int numQueries;
    cin >> numQueries;
    for(int q = 0; q < numQueries; q++) {
        ll s, c;
        cin >> s >> c;
        cout << answerQuery(s, c, bs, pref) << endl;
    }
}

int main() {
    sol();
    return 0;
}