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
        int n; int m;
        cin >> n >> m;
        string s;
        cin >> s;
        vector<int> probs(7);
        for(int i = 0; i < n; i++) {
            probs[s.at(i) - 'A']++;
        }
        int ans = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < 7; j++) {
                if(probs[j] != 0) probs[j]--;
                else {ans++;}
            }
        }
        cout << ans << endl;
    } 
    return 0; 
} 
