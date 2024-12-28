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
    map<ll, ll> q;
    ll ans = n;
    map<ll, ll> map;
    for(int i = 0; i < n; i++){
        ll tempA, b;
        cin >> tempA >> b;
        map[tempA] = i;
        q[b] = i;
    }
    vll arr(n);
    auto it = map.begin();
    auto it2 = q.begin();
    for(int i = 0; i < n; i++){
        arr[i] = it->second;
        if(q.size() > 0) {
            if(it->first > it2 -> first) {
                arr[i] = it2 -> second;
                q.erase(it2 -> first);
                ans--;
            }
        }
        it++;
    }
    cout << ans << endl;
    for(int i = 0; i < n; i++){
        cout << arr[i] + 1 << " ";
    }
    cout << endl;
    return 0; 
} 
