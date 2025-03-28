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
    string s;
    cin >> s;
    int length = s.length();
    int j = length-1;
    string front = "";
    string back = "";
    for(int i = 0; i < length-1; i++) {
        front = front + s[i];
        back = back + s[j-i];
        if(i >= (j-i)) {
            reverse(back.begin(), back.end());
            if(front == back) {
                cout << "YES" << endl;
                cout << front;
                return 0;
            }
            reverse(back.begin(), back.end());
        }
    }
    cout << "NO" << endl;
    return 0; 
} 
