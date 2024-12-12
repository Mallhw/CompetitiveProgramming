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


bool traverseGrid(vector<vector<char>>& grid, int startX, int startY) {
    int rows = grid.size(), cols = grid[0].size();
    set<pair<int, int>> visited;
    int x = startX, y = startY;

    while (true) {
        if (x < 0 || y < 0 || x >= rows || y >= cols) {
            return false; 
        }
        if (visited.count({x, y})) {
            return true; 
        }

        visited.insert({x, y});
        char direction = grid[x][y];

        if (direction == 'U') --x;
        else if (direction == 'D') ++x;
        else if (direction == 'L') --y;
        else if (direction == 'R') ++y;
        else if (direction == '?') {
            if(grid[startX][startY] != '?') return true;
            else {
                
            }
        }
        else break; 
    }

    return false;
}


int main() 
{ 
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    int T; 
    cin >> T; 
    while (T--) { 
        vector<vector<char>> grid(1001, vector<char>(1001));\

        for(int r = 0; r < grid.size(); r++) {
            for(int c = 0; c < grid[0].size(); c++) {
                cin >> grid[r][c];
            }
        }

        int count = 0;
        for(int r = 0; r < grid.size(); r++) {
            for(int c = 0; c < grid[0].size(); c++) {
                if(traverseGrid(grid, r, c)) count++;
            }
        }
        cout << count << endl;
        

    } 
    return 0; 
} 
