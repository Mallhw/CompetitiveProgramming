#include <bits/stdc++.h> 
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



ll numThree = 0;
ll numTwo = 0;

ll sumDigits(ll no) {
    if (no == 0) {
        return 0;
    }
    if (no % 10 == 3) numThree++;
    if (no % 10 == 2) numTwo++;
    
    return (no % 10) + sumDigits(no / 10);
}
int main() 
{ 
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    int T; 
    cin >> T; 
    while (T--) { 
        numThree = 0;
        numTwo = 0;
        ll n;
        cin >> n;
        ll digitSum = sumDigits(n);

        if(digitSum % 9 == 0) {
            cout << "YES" << endl;
            continue;
        }
        bool flag = true;
        for(int i = 0; i < numTwo; i++) {
            digitSum += 2;
            if(digitSum % 9 == 0) {
                cout << "YES" << endl;
                flag = false;
                continue;
            }
        }
        for(int i = 0; i < numThree; i++) {
            digitSum += 6;
            if(digitSum % 9 == 0) {
                cout << "YES" << endl;
                flag = false;
                continue;
            }
        }
        if(flag) {
            cout << "NO" << endl;
        }
    } 
    return 0; 
} 
