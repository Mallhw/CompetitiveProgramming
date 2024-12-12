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
        int n; int f; int k;
        cin >> n >> f >> k; 
        int arr[n];
        int fav;
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
            if(i == (f-1)) {
                fav = arr[i];
            }
        }
        int j = sizeof(arr) / sizeof(arr[0]);
        sort(arr, arr + j, greater<int>());


        // find first index
        int firstIndex = 0;
        for(int i = 0; i < n; i++) {
            if(arr[i] == fav) {firstIndex = i; break;}
            
        }

        // sol
        //cout << firstIndex << endl;
        k--;
        if(firstIndex > k) {cout << "NO" << endl;}
        else {
            if(arr[k+1] == fav) {
                cout << "MAYBE" << endl;
            }
            else {
                cout << "YES" << endl;
            }
        }

        // bool hasHit = false;
        // for(int i = 0; i < n; i++) {
        //         if(arr[i] == fav) hasHit = true;
        //         if(i == k-1) {
        //             if(!hasHit) {
        //                 cout << "NO" << endl;
        //             }
        //             else {
        //                 if(i != n && arr[i+1] == fav) {
        //                     cout << "MAYBE" << endl;
        //                 }
        //                 else {
        //                     cout << "YES" << endl;
        //                 }
        //             }
        //         }     
        // }
    } 
    return 0; 
} 
