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
        int k; int n;
        cin >> n >> k;
        vi a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        int left = 0; int right = 0;
        int total = 0; int cur = 0;
        int uniques = 1; int j = 1; 
        int newIndex = 0;
        while(left < n && right < n) {
            if(a[left] + (j-1) == a[right]) {
                cur++;
                right++;
                total = max(total, cur);
            }
            else {
                cout << right << ' ' << a[right] <<  endl;
                uniques++;
                if(a[left] + j != a[right] || uniques > k) {
                    cout << "reset " << cur << endl;
                    cout << newIndex << endl;
                    total = max(total, cur);
                    cur = 0;
                    j = 1;
                    a[left] = a[newIndex];
                    a[right] = a[newIndex];
                    left = newIndex;
                    right = newIndex;      
                }
                else if(a[left] + j == a[right]) {
                    if(j == 1) {
                        newIndex = right;
                    }
                    j++;
                }
                
            }
        }
        cout << total << endl;

    } 
    return 0; 
} 
