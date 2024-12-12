#include "bits/stdc++.h" 
using namespace std; 
#define max(a, b) (a < b ? b : a) 
#define min(a, b) ((a > b) ? b : a) 
#define mod 1e9 + 7 
#define FOR(a, c) for (int(a) = 0; (a) < (c); (a)++) 
#define FORL(a, b, c) for (int(a) = (b); (a) <= (c); (a)++) 
#define FORR(a, b, c) for (int(a) = (b); (a) >= (c); (a)--) 
#define INF 1000000000000000003 
typedef long long ll; 
typedef vector<int> vi; 
typedef pair<int, int> pi; 
#define F first 
#define S second 
#define PB push_back 
#define POB pop_back 
#define MP make_pair 

int MSBPosition(int N)
{
    int msb_p = -1;
    while (N) {
        N = N >> 1;
        msb_p++;
    }
    return msb_p;
}
 
int findBitwiseOR(int L,int R)
{
    int res = 0;

    int msb_p1 = MSBPosition(L);
    int msb_p2 = MSBPosition(R);

    while (msb_p1 == msb_p2) {
        int res_val = (1 << msb_p1);
 
        res += res_val;
 
        L -= res_val;
        R -= res_val;
 
        msb_p1 = MSBPosition(L);
        msb_p2 = MSBPosition(R);
    }
     msb_p1 = max(msb_p1, msb_p2);
 
     for (int i = msb_p1; i >= 0; i--) {
         int res_val = (1 << i);
         res += res_val;
    }
    return res;
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
            int MSB = log2(n);
            int a = n-m;
            if(n-m < 0) a =0;
            cout << findBitwiseOR(a, n+m) << endl;
        }
    } 
    return 0; 
} 
