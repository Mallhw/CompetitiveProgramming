#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define max(a, b) (a < b ? b : a) 


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        int a[n];
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }

        ll Bessie = 0;
        ll Elsie = 0;

        ll left = 0;
        ll right = 0;
        for(int i = 0; i < n; i++) {
            if(i < n/2) {
                left += a[i];
            } else {
                right += a[i];
            }
        }

        if(left > right) {
            Elsie = left;
            for(int i = n-1; i >= n/2; i--) {
                Bessie += a[i];
            }
        } else {
            Elsie = right;
            for(int i = 0; i < n/2; i++) {
                Bessie += a[i];
            }
        }

        cout << Bessie << " " << Elsie << endl;
    
    }
    return 0;
}