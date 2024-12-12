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
        ll n; ll m;
        cin >> n >> m;
        char arr[n][m];
        for(int r = 0; r < n; r++) {
            for(int c = 0; c < m; c++) {
                cin >> arr[r][c];
            }
        }
        ll count = 0; ll max = 0; ll row = 1; ll col = 1; ll lastCol;
        for(int r = 0; r < n; r++) {
            count = 0;
            for(int c = 0; c < m; c++) {
                if(arr[r][c] == '#') {
                    count++;
                    lastCol = c;
                }
            }
            if(count > max) {
                row = r+1;
                col = lastCol - (count/2) + 1;
            }
            lastCol = col;
            max = count;
        }
        cout << row << " " << col << endl;
    } 
    return 0; 
} 
