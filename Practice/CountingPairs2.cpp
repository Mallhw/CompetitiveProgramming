#include <bits/stdc++.h>
using namespace std;

#define max(a, b) (a < b ? b : a)
#define min(a, b) ((a > b) ? b : a)
#define dbg(x) cerr << __LINE__ << ": " << #x << "=" << x << endl;
#define mod 1000000007
#define FOR(a, c) for (int a = 0; a < (c); a++)
#define FORL(a, b, c) for (int a = (b); a <= (c); a++)
#define FORR(a, b, c) for (int a = (b); a >= (c); a--)
#define INF 1000000000000000003
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define F first
#define S second
#define PB push_back
#define POB pop_back
#define MP make_pair

vector<ll> countInterestingPairs(int t, vector<tuple<int, ll, ll, vector<int>>> &testCases) {
    vector<ll> results;

    for (int test = 0; test < t; ++test) {
        int n;
        ll x, y;
        vector<int> a;

        tie(n, x, y, a) = testCases[test];

        ll sum = accumulate(a.begin(), a.end(), 0LL);
        sort(a.begin(), a.end());

        ll count = 0;

        for (int i = 0; i < n; ++i) {
            ll left = sum - y - a[i];
            ll right = sum - x - a[i];

            auto low = lower_bound(a.begin() + i + 1, a.end(), left);
            auto high = upper_bound(a.begin() + i + 1, a.end(), right);

            count += (high - low);
        }

        results.push_back(count);
    }

    return results;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    vector<tuple<int, ll, ll, vector<int>>> testCases;

    for (int test = 0; test < t; ++test) {
        int n;
        ll x, y;
        cin >> n >> x >> y;

        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        testCases.emplace_back(n, x, y, a);
    }

    vector<ll> results = countInterestingPairs(t, testCases);

    for (ll res : results) {
        cout << res << "\n";
    }

    return 0;
}