#include <bits/stdc++.h> 
using namespace std; 
typedef long long int ll; 

int main() 
{ 
    int tc; 
    cin >> tc; 
    while (tc--) { 
        ll n, a, b;
        cin >> n >> a >> b;

        if(n == 2) cout << "no" << endl;
        else {
            if(abs(a - b) % 2 == 0) {
                cout << "yes" << endl;
            }
            else {
                cout << "no" << endl;
            }
        }

    } 
    return 0; 
} 
