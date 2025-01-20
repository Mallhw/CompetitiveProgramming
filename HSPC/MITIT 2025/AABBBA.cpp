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
    string a, b;
    cin >> a >> b;
    string a_reverse = a;
    string b_reverse = b;
    ll ans = 0;
    for(int i = 0; i < a.size()-1; i++){
        dbg(a);
        dbg(b);
        if(a == b) {
            break;
        }
        else {
            dbg(a[i]);
            dbg(b[i]);
            if(a[i] == 'A' && b[i] == 'B') {
                if(a.substr(i, i+3) == "AAB") {
                    ans++;
                    a = a.substr(0, i) + "BBA" + a.substr(i+3, a.size());
                }
                else if(a.substr(i, i+3) == "ABB") {
                    ans++;
                    a = a.substr(0, i) + "BAA" + a.substr(i+3, a.size());
                }
            }
            else if(a[i] == 'B' && b[i] == 'A') {
                if(a.substr(i, i+3) == "BBA") {
                    ans++;
                    a = a.substr(0, i) + "ABB" + a.substr(i+3, a.size());
                }
                else if(a.substr(i, i+3) == "BAA") {
                    ans++;
                    a = a.substr(0, i) + "AAB" + a.substr(i+3, a.size());
                }
            }
        }
    }
    reverse(a_reverse.begin(), a_reverse.end());
    reverse(b_reverse.begin(), b_reverse.end());
    ll ans2 = 0;
    for(int i = 0; i < a_reverse.size()-2; i++){
        dbg(a_reverse);
        dbg(b_reverse);
        if(a_reverse == b_reverse) {
            break;
        }
        else {
            dbg(a_reverse[i]);
            dbg(b_reverse[i]);
            if(a_reverse[i] == 'A' && b_reverse[i] == 'B') {
                if(a.substr(i, i+3) == "AAB") {
                    ans2++;
                    a_reverse = a_reverse.substr(0, i) + "BBA" + a_reverse.substr(i+3, a_reverse.size());
                }
                else if(a_reverse.substr(i, i+3) == "ABB") {
                    ans2++;
                    a_reverse = a_reverse.substr(0, i) + "BAA" + a_reverse.substr(i+3, a_reverse.size());
                }
            }
            else if(a_reverse[i] == 'B' && a_reverse[i] == 'A') {
                if(a.substr(i, i+3) == "BBA") {
                    ans2++;
                    a_reverse = a_reverse.substr(0, i) + "ABB" + a_reverse.substr(i+3, a_reverse.size());
                }
                else if(a_reverse.substr(i, i+3) == "BAA") {
                    ans2++;
                    a_reverse = a_reverse.substr(0, i) + "AAB" + a_reverse.substr(i+3, a_reverse.size());
                }
            }
        }
    }
    dbg(a);
    dbg(b);
    if(a_reverse != b_reverse && a != b) {
        cout << -1 << endl;
        return;
    }
    else if(a_reverse != b_reverse) {
        ans2 = INF;
    }
    else if(a != b) {
        ans = INF;
    }
    cout << min(ans, ans2) << endl;

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
