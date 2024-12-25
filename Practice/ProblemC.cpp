#include <bits/stdc++.h>
using namespace std;

const int N = 1000;

int n, q;
char grid[N][N];

int countCycles(int r, int c) {
    int ans = 0;
    if (grid[r][c] == '?') return 0;
    if (grid[r][c] == 'L' || grid[r][c] == 'R') {
        ans += countCycles(r, c-1) + countCycles(r, c+1);
    }
    if (grid[r][c] == 'U' || grid[r][c] == 'D') {
        ans += countCycles(r-1, c) + countCycles(r+1, c);
    }
    return ans;
}

int main() {
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            grid[i][j] = '?';
        }
    }

    // build entire grid
    for (int i = 0; i < q; i++) {
        int r, c;
        char t;
        cin >> r >> c >> t;
        r--; c--;
        grid[r][c] = t;
    }

    // iterate over all possible cells to remove
    int minCycles = INT_MAX;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == '?') {
                // remove character from grid
                grid[i][j] = ' ';

                // count cycles with character removed
                int cycles = countCycles(0, 0);

                // update minimum number of cycles
                minCycles = min(minCycles, cycles);

                // restore character to grid
                grid[i][j] = '?';
            }
        }
    }

    // print answer
    cout << minCycles << endl;

    return 0;
}