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
            cin >> arr[i];
        }
        sort(arr.begin(), arr.end(), greater<>());
        int start = k;
        int count = 0;
        for(int i = 0; i < n; i++) {
            start -= arr[i];
            if(start == 0) break;
            else if(start < 0) {
                count = arr[i];
                break;
            }
        }
        if(start > 0) {
            cout << start << endl;
        }
        else if(start == 0) {
            cout << 0 << endl;
        }
        else if(start < 0) {
            start += count;
            cout << start << endl;
        }
    } 
    return 0; 
} 
