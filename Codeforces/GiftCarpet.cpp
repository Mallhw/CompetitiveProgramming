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
        char arr[n][m];
        for(int i = 0; i < n; i++) {
            string s;
            cin >> s;
            for(int j = 0; j < m; j++) {
                arr[i][j] = s.at(j);
            }   
        }
        
        // sol
        bool v = false;
        bool bi = false;
        bool k = false;
        bool a = false;
        for(int i = 0; i < n; i++) {
            set<char> check;
            for(int j = 0; j < m; j++) {
                if(arr[j][i] == 'v' || arr[j][i] == 'i' || arr[j][i] == 'k' || arr[j][i] == 'a') {
                    check.insert(arr[j][i]);
                    cout << "inserted" << arr[i][j] << endl;
                }
            }
            if(check.size() != 0) {
                if(!v) {
                    check.find('v');
                    v = true;
                }
                else if(!bi) {
                    check.find('i');
                    bi = true;
                }
                else if(k == false) {
                    check.find('k');
                    k = true;
                }
                else if(a == false) {
                    check.find('a');
                    a = true;
                }
            }
        }
        if(v && bi && k && a) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    } 
    return 0; 
} 
