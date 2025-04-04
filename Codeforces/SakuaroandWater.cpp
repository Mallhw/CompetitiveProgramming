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
        int n;
        cin >> n;
        int arr[n][n];
        int numDiagnols = n*2;
        vi pSum(numDiagnols);
        for(int r = 0; r < n; r++) {
            for(int c = 0; c < n; c++) {
                cin >> arr[r][c];
                if(arr[r][c] < 0) {
                    pSum[r-c + (numDiagnols/2)] = max(pSum[r-c + (numDiagnols/2)], abs(arr[r][c]));
                }
            }
        }
        int sum = 0;
        for(int i = 0; i < pSum.size(); i++) {
            //cout << pSum[i] << ' ';
            sum += abs(pSum[i]);
        }
        //cout << ' ' << endl;
        cout << sum << endl;
    } 
    return 0; 
} 
