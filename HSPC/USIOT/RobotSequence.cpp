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
    int n;
    cin >> n;
    string s;
    cin >> s;
    ll x = 0;
    ll y = 0;
    ll max = 0;
    ll cur = 0;
    for(int i = 0; i < n; i++) {
        cur++;
        if(s[i] == 'U') {
            x++;
        }
        else if(s[i] == 'D') {
            x--;
        }
        else if(s[i] == 'L') {
            y--;
        }
        else if(s[i] == 'R') {
            y++;
        }
        if(x == 0 && y == 0) {
            max = max(cur, max);
        }
    }
    if(x == 0 && y == 0) {
        max = max(cur, max);
    }
    cout << max << endl;


    return 0; 
} 
