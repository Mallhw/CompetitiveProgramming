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
        map<ll, set<int>> counter{};
        
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
            counter[arr[i]].insert(i);
        }

        vector<pair<int, int>> ans{};
        for(int i = 0; i < n; i++) {
            counter[arr[i]].erase(i);
            if(arr[i] == 2) {
                if(!counter[1].empty()) {
                    int ind = *--counter[1].end();
                    swap(arr[ind], arr[i]);
                    counter[1].erase(ind);
                    counter[2].erase(ind);

                    ans.push_back({i, ind});
                }
            }
            if(arr[i] == 1) {
                if(!counter[0].empty()) {
                    int ind = *--counter[0].end();
                    swap(arr[ind], arr[i]);
                    counter[0].erase(ind);
                    counter[1].erase(ind);

                    ans.push_back({i, ind});
                }
            }
            
        }
        cout << ans.size() << endl;
        for(pair<int, int> p : ans) {
            cout << p.first + 1 << " " << p.second + 1 << endl;
        }
        
    } 
    return 0; 
} 
