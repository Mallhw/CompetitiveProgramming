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
int main() 
{ 
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    int T; 
    cin >> T; 
    while (T--) { 
        ll n;
        cin >> n;
        ll a, b, c;
        cin >> a >> b >> c;
        ll total = a + b + c;
        ll day = (n) / total;
        ll daysLeft = n % total;
        if(daysLeft <= 0) {
            cout << day*3 << endl;
        }
        else if(daysLeft <= a) {
            cout << day * 3 + 1 << endl;
        }
        else if(daysLeft <= a + b) {
            cout << day * 3 + 2 << endl;
        }
        else {
            cout << day * 3 + 3 << endl;
        }
    } 
    return 0; 
} 
