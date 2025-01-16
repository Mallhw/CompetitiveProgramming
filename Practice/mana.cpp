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

void solve() {
    ll n, k;
    cin >> n >> k;
    deque<ll> cards;
    for(int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        cards.push_back(x);
    }
    ll ans = 0;
    ll card1 = cards.front();
    cards.pop_front();
    ll card2 = cards.front();
    cards.pop_front();
    for(int i = 0; i < k; i++) {
        ans += min(card1, card2);
        cards.push_back(min(card1, card2));
        if(card1 < card2) {
            card1 = cards.front();
        }
        else {
            card2 = cards.front();
        }
        cards.pop_front();
    }
    cout << ans << endl;
    return;
}
int main() 
{ 
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    solve();
    return 0; 
} 
