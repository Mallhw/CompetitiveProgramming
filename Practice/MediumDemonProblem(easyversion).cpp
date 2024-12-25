#include <bits/stdc++.h> 
using namespace std; 
#define max(a, b) (a < b ? b : a) 
#define min(a, b) ((a > b) ? b : a) 
#define dbg(x) cerr << __LINE__ << ": " << #x << "=" << x << endl;
#define mod 1e9 + 7 
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
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vi r(n);
        FOR(i, n) cin >> r[i], r[i]--;
        vi cnt(n);
        FOR(i, n) cnt[r[i]]++;
        int year = 0;
        bool stable = false;
        while (!stable) {
            year++;
            vi new_cnt(n);
            FOR(i, n) if (cnt[i] > 0) new_cnt[r[i]]++;
            FOR(i, n) new_cnt[i] = min(new_cnt[i], 1);
            stable = true;
            FOR(i, n) if (cnt[i] != new_cnt[i]) stable = false;
            cnt = new_cnt;
        }
        cout << year << '\n';
    }
    return 0;
}