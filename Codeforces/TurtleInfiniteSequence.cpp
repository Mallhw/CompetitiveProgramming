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

int MSBPosition(long long int N)
{
    int msb_p = -1;
    while (N) {
        N = N >> 1;
        msb_p++;
    }
    return msb_p;
}

int main() 
{ 
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    int T; 
    cin >> T; 
    while (T--) { 
        int n; int m;
        cin >> n >> m;
        if(m == 0) {
            cout << n << endl;
        }
        else {
            int cur; int a = n-1;
            if(n-1 < 0) a = 0;
            cur = (a | n | n+1);
            for(int i = 0; i < m; i++) {
                int j = i+1;
                int a = n-j;
                if(a <= 0) a = 0;
                cur = (a | cur | n+j);
            }
            cout << cur << endl;
        }
    } 
    return 0; 
} 
