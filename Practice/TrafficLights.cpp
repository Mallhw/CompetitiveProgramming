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
    int x, n;
    cin >> x >> n;
    set<int> s;
    s.insert(0);
    s.insert(x);
    multiset<int> ms;
    ms.insert(x-0);
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        ll low = *(--s.upper_bound(a));
        ll up = *(s.upper_bound(a));
        int len1 = a - low;
        int len2 = up - a;
        s.insert(a);  
        ms.erase(ms.find(up - low));
        ms.insert(len1);
        ms.insert(len2);
        cout << *(ms.rbegin()) << ' ';
    }
    return 0; 
} 
