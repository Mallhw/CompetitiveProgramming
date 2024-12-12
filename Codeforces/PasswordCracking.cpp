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
    ll T; 
    cin >> T; 
    while (T--) { 
        ll n;
        cin >> n;
        ll response = 0;
        string output = "0";
        cout << "check" << endl;
        while(response != -1) {
            cout << '? ' << output << endl;
            cin >> response;
            cout << response;
            if(response == 1) {
                output += "0";
            }
            else {
                output[output.size()-1] = '1';
                output += "0";
            }
            if(output.size() == n) {
                if(response == 1) {
                    break;
                }
            }
        }
        cout << '! ' << output << endl;
    } 
    
    return 0; 
} 
