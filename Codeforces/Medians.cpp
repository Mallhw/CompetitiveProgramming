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
        int n, k;
        cin >> n >> k;
        vi arr(n);
        for(int i = 0; i < n; i++) {
            arr[i] = i+1;
        }
        if(n == 1 && k == 1) {
            cout << 1 << endl;
            cout << 1 << endl;
        }
        else if(k == n || k == 1) {
            cout << -1 << endl;
        }
        else {
            if((arr[k-1] - 1) % 2 == 1 && (n - arr[k-1]) % 2 == 1) {
                cout << 3 << endl;
                cout << 1 << ' ' << arr[k-1] << ' ' << arr[k] << endl;
            } 
            else {
                cout << 5 << endl;
                cout << 1 << ' ' << arr[k-2] << ' ' << arr[k-1] << ' ' << arr[k] << ' ' << n << endl;
            }
        }
    } 
    return 0; 
} 
