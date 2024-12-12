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
        vi arr(n);
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        // First Cycle
        vi prefix(n);
        int curMin = 0;
        for(int i = 0; i < n-1; i++) {
            if(arr[i] == arr[i+1]) prefix[i] = 1; curMin++;
        }
        int preMin = curMin+1;

        // for(int i = 0; i < n-1; i++) {
        //         cout << arr[i] << " ";
        //     }
        //     cout << arr[n-1] << endl;
        //     for(int i = 0; i < n-1; i++) {
        //         cout << prefix[i] << " ";
        //     }
        //     cout << prefix[n-1] << endl;



        
        while(curMin < preMin) {
            for(int i = 0; i < n/2; i++) {
                // If swapped
                if(prefix[i] == 1 && prefix[i+1] == 0) {
                    int change = 0;

                    if(i > 0 && arr[n-i-1] == arr[i-1]) change++;
                    if(arr[n-i-1] == arr[i+1]) change++;

                    if(i > 0 && arr[i] == arr[n-i]) change++;
                    if(arr[i] == arr[n-i-2]) change++;


                    int cur = 0;
                    if(i > 0 && arr[i] == arr[i-1]) cur++;
                    if(arr[i] == arr[i+1]) cur++;

                    if(i > 0 && arr[n-i-1] == arr[n-i]) cur++;
                    if(arr[n-i-1] == arr[n-i-2]) cur++;

                      
                    //cout << "cur:" << change << "pre: " << cur << endl;

                    if(cur <= cur) {
                        swap(arr[i], arr[n-i-1]);
                    }
                    
                }
            }
            
            preMin = curMin;
            curMin = 0;
            prefix.clear();
            for(int i = 0; i < n-1; i++) {
                if(arr[i] == arr[i+1]) {
                    prefix[i] = 1; 
                    curMin++;
                }
                else {
                    prefix[i] = 0;

                }
            }
            // cout << curMin << " " << preMin << endl;
            // for(int i = 0; i < n-1; i++) {
            //     cout << arr[i] << " ";
            // }
            // cout << arr[n-1] << endl;
            // for(int i = 0; i < n-1; i++) {
            //     cout << prefix[i] << " ";
            // }
            // cout << prefix[n-1] << endl;
        }
        int sum = 0;
        for(int i = 0; i < n-1; i++) {
            //cout << arr[i] << " ";
            if(arr[i] == arr[i+1]) sum++;
        }
        //cout << arr[n-1];
        //cout << endl;
        cout << sum << endl;

    } 
    return 0; 
} 
