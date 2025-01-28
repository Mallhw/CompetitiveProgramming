#include <bits/stdc++.h> 
using namespace std; 
#define max(a, b) (a < b ? b : a) 
#define min(a, b) ((a > b) ? b : a) 
#define dbg(x) cerr << __LINE__ << ": " << #x << "=" << x << endl;
typedef long long int ll; 
typedef vector<long long> vll;

int main() 
{ 
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    ll n;
    cin >> n;
    vector<vector<ll>> grid(n, vector<ll>(n));
    unordered_map<ll, ll> counts;
    unordered_map<ll, ll> orignialCounts;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> grid[i][j];
            counts[grid[i][j]]++;
            orignialCounts[i + j + 2]++;
        }
    }
    
    vector<vll> possibles(n+1);
    for(auto &i : orignialCounts) {
        possibles[i.second].push_back(i.first);
    }

    // dbg(grid);
    // dbg(counts);
    // dbg(orignialCounts);
    // dbg(possibles);

    vector<vector<ll>> output(n, vector<ll>(n));
    vll amountUsed(n*2 + 1);
    vector<ll> inUse(n*2 + 1);
    for(int r = 0; r < n; r++) {
        for(int c = 0; c < n; c++) {
            // dbg(counts[grid[r][c]]);
            // dbg(orignialCounts[grid[r][c]]);
            if(counts[grid[r][c]] == orignialCounts[grid[r][c]]) {
                output[r][c] = grid[r][c];
            }
            else {
                output[r][c] = 0;
                // dbg(grid[r][c]);
                // dbg(possibles[counts[grid[r][c]]]);


                vll numsPosToReplace = possibles[counts[grid[r][c]]];

                ll smallerNum = min(numsPosToReplace[0], numsPosToReplace[1]);
                ll biggerNum = max(numsPosToReplace[0], numsPosToReplace[1]);


                if(possibles[counts[grid[r][c]]].size() == 2) {
                    if(amountUsed[smallerNum] < orignialCounts[smallerNum] && (inUse[smallerNum] == grid[r][c] || inUse[smallerNum] == 0)) {
                        output[r][c] = smallerNum;
                        amountUsed[smallerNum]++;
                        inUse[smallerNum] = grid[r][c];
                    }
                    else {
                        output[r][c] = biggerNum;
                        amountUsed[biggerNum]++;
                    }
                    
                }
                else if(possibles[counts[grid[r][c]]].size() == 1) {
                    output[r][c] = possibles[counts[grid[r][c]]][0];
                }
            }
        }
    }

    for(int r = 0; r < n; r++) {
        for(int c = 0; c < n; c++) {
            cout << output[r][c];
            if(c != n-1) cout << ' ';
        }
        cout << endl;
    }

    return 0; 
} 
