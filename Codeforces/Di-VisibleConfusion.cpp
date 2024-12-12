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
void solve()
{
    ll n, x = 0;
    cin >> n;
    ll arr[n];
    bool ok = false;;
    fl(i, n)
    {
        ll in = i+2;
        if(arr[i]%in!=0)
        x++;
    else {
        ok false;
        for(int j = 1; j <= x; j++)
        {
            if(arr[i]%(in-j)!=0)
            {x++;ok=true;break;}
        }
        if(ok==false) {
            pn return;
        }
    }
    }
    py
}
int main() 
{ 
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    int T; 
    cin >> T; 
    while (T--) { 
        solve();
    } 
    return 0; 
} 
