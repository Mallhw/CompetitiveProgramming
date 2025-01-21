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
bool check(int w, int N, int X, int Y, vll A, vll B, vll C) {
    int lx = max(1, X - w);
    int hx = min(X + Y - w - 1, X);
    int d = X + Y - w;

    for (int i = 0; i < N; ++i) {
        int a = A[i], b = B[i], c = C[i];

        if (b - a > 0) {
            // Update lower bound
            lx = max(lx, (-c + b * d + (b - a - 1)) / (b - a));
        } else if (a - b > 0) {
            // Update upper bound
            hx = min(hx, (c - b * d) / (a - b));
        } else {
            // If a == b, check if the constraint is satisfied
            if (a * d > c) {
                return false;
            }
        }
    }

    return lx <= hx;
}
ll binarySearch(ll costCookies, ll cosMuffins, vll cookies, vll muffins, vll waitTime, ll n) {
    ll l = 0;
    ll r = costCookies + cosMuffins - 2;
    ll mid = (l + r) / 2;
    while(l < r) {
        if(check(mid, n, costCookies, cosMuffins, cookies, muffins, waitTime)) {
            l = mid + 1;
        } else {
            r = mid;
        }
        mid = (l + r) / 2;
    }
    return l;
}
int main() 
{ 
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    int T; 
    cin >> T; 
    while (T--) { 
        int n, costCookies, costMuffins;
        cin >> n >> costCookies >> costMuffins;
        vll cookies(n), muffins(n), waitTime(n);
        for(int i = 0; i < n; i++) {
            cin >> cookies[i] >> muffins[i] >> waitTime[i];
        }
        cout << binarySearch(costCookies, costMuffins, cookies, muffins, waitTime, n) << endl;
    } 
    return 0; 
} 
