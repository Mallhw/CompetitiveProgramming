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
int main() 
{ 
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    int T; 
    cin >> T; 
    while (T--) { 
        string s;
        string t;
        cin >> s >> t;
        int total = 0;
        int smally = min(s.length(), t.length());
        for(int i = 0; i < smally; i++) {
            if(s.at(i) == t.at(i)) {
                total++;
            }
            else {
                break;
            }
        }
        bool check = false;
        if(total == 0) {
            check = true;
        }
        int sAdd = s.length() - total;
        int tAdd = t.length() - total;
        total += sAdd;
        total += tAdd;
        
        if(check) {
            cout << total << endl;
        }
        else{
            cout << total + 1 << endl;
        }
    } 
    return 0; 
} 
