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


using namespace std;

vector<long long> maximizeEarnings(int t, vector<tuple<int, int, vector<int>, vector<int>>> &testCases) {
    vector<long long> results;

    for (int test = 0; test < t; ++test) {
        int n, k;
        vector<int> a, b;
        tie(n, k, a, b) = testCases[test];

        vector<pair<int, int>> customers(n);
        for (int i = 0; i < n; ++i) {
            customers[i] = {a[i], b[i]};
        }

        // Sort customers by `a` (primary) and `b` (secondary)
        sort(customers.begin(), customers.end());

        // Use a custom comparator to order elements in descending order
        priority_queue<int, vector<int>, greater<int>> negativeReviews;
        long long revenue = 0;
        int negativeCount = 0;

        for (auto &[ai, bi] : customers) {
            if (negativeCount < k || (!negativeReviews.empty() && negativeReviews.top() > ai)) {
                revenue += ai;
                if (negativeCount < k) {
                    negativeCount++;
                } else {
                    revenue -= negativeReviews.top();
                    negativeReviews.pop();
                }
                negativeReviews.push(ai);
            } else {
                revenue += ai;
            }
        }

        results.push_back(revenue);
    }

    return results;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    vector<tuple<int, int, vector<int>, vector<int>>> testCases;

    for (int test = 0; test < t; ++test) {
        int n, k;
        cin >> n >> k;

        vector<int> a(n), b(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        for (int i = 0; i < n; ++i) cin >> b[i];

        testCases.emplace_back(n, k, a, b);
    }

    vector<long long> results = maximizeEarnings(t, testCases);

    for (long long res : results) {
        cout << res << "\n";
    }

    return 0;
}