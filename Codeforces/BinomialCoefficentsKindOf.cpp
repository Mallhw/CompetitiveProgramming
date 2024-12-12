#include "bits/stdc++.h" 
using namespace std; 
#define max(a, b) (a < b ? b : a) 
#define min(a, b) ((a > b) ? b : a) 
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

int modpow(int x, int n, int m) {
    if(n == 0) return 1%m;
    long long u = modpow(x, n/2,m);
    u = (u*u)%m;
    if(n%2 == 1) u = (u*x)%m;
    return u;
}

int main() 
{ 
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    int  t;
    cin >> t;
    vi n(t);
    vi k(t);
    for(int i = 0; i < t; i++) {
        cin >> n[i];
    }
    for(int i = 0; i < t; i++) {
        cin >> k[i];
    }
    for(int i = 0; i < t; i++) {
        if(n[i] == k[i]) {
            cout << 1 << endl;
        }
        else if(n[i] < k[i]) {
            cout << 0 << endl;
        }
        else if(n[i] > k[i]) {
            cout << modpow(2, k[i], 1000000007) << endl;
        }
    }
    return 0; 
} 
