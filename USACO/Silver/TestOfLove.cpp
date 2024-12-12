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
        ll n, j, s;
        cin >> n >> j >> s;
        string arr;
        cin >> arr;
        arr = " " + arr;
        ll curPos = 0; 

        while(1 != 0) {
            if(curPos + j > n) {
                cout << "YES" << endl;
                break;
            }
            else {
                // Jumping mech
                int water = 0; bool check = false; bool foundLog = false;
                for(int i = j; i > 0; i--) {
                    if(i + curPos < n+1) {
                        if(arr.at(i + curPos) == 'L') {
                            curPos += i;
                            foundLog = true;
                            break;
                        }
                        if(arr.at(i + curPos) == 'W' && !check) {
                            water = i;
                            check = true;
                        }
                    }
                }
                // no logs or crocodiles
                if(!check && !foundLog) {
                    cout << "NO" << endl;
                    break;
                }
                else if(!foundLog) {
                    curPos += water;
                    // Can swim to shore
                    
                    // Check if there is a log nearby
                    bool hasLog = false; bool hasCroc = false;
                    while(!hasLog) {
                        for(int i = 0; i <= s; i++) {
                            if(i + curPos < n) {
                                if(arr.at(curPos + i) == 'C') {
                                    hasCroc = true;
                                    break;
                                }
                                if(arr.at(curPos + i) == 'L')  {
                                    curPos += i;
                                    s -= i;
                                    hasLog = true;
                                    break;
                                }       
                            }
                        }
                        break;
                    }
                    if(hasCroc) {
                        cout << "NO" << endl;
                        break;
                    }
                    else if(hasLog) {

                    }
                    else if (curPos + s > n) {
                        cout << "YES" << endl;
                        break;
                    }
                    else {
                        cout << "NO" << endl;
                        break;
                    }
                }
            }
        }
    } 
    return 0; 
} 
