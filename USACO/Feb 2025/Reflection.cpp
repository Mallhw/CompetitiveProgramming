#include <bits/stdc++.h> 
using namespace std; 

int main() 
{ 
    int n, q;
    cin >> n >> q;
    vector<vector<char>> grid(n, vector<char>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> grid[i][j];
        }
    }
    int curMisplaced = 0;
    vector<vector<int>> filledDots((n / 2), vector<int>(n / 2));
    for(int i = 0; i < n / 2; i++) {
        for(int j = 0; j < n / 2; j++) {
            int cur = 0;
            cur += (grid[i][n - j - 1] == '#');
            cur += (grid[n - i - 1][n - j - 1] == '#');
            cur += (grid[n - i - 1][j] == '#');
            cur += (grid[i][j] == '#');
            filledDots[i][j] = cur;
            curMisplaced += min(4 - cur, cur);
        }
    }
    cout << curMisplaced << endl;
    while(q--) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        int xn = x;
        int yn = y;
        if(x >= n / 2) xn = n - x - 1;
        if(y >= n / 2) yn = n - y - 1;
        int initial = min(4 - filledDots[xn][yn], filledDots[xn][yn]);
        if(grid[x][y] == '.') filledDots[xn][yn]++;
        if(grid[x][y] == '#') filledDots[xn][yn]--;            
        int final = min(4 - filledDots[xn][yn], filledDots[xn][yn]);
        curMisplaced += (final - initial);
        cout << curMisplaced << endl;
        grid[x][y] = ((grid[x][y] == '.') ? '#' : '.');
    }
    return 0; 
} 
