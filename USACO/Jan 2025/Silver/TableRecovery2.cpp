#include <bits/stdc++.h>
using namespace std;

// Function to print the table
void printTable(const vector<vector<int>>& table) {
    for (const auto& row : table) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

// Function to solve the problem naively by generating all permutations
void solve() {
    int N;
    cin >> N;

    vector<vector<int>> table(N, vector<int>(N));
    
    // Read the input table
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> table[i][j];
        }
    }

    // Create row indices [0, 1, 2, ..., N-1]
    vector<int> rowIndices(N);
    iota(rowIndices.begin(), rowIndices.end(), 0);

    // Create column indices [0, 1, 2, ..., N-1]
    vector<int> colIndices(N);
    iota(colIndices.begin(), colIndices.end(), 0);

    // Store the lexicographically smallest table
    vector<vector<int>> minTable = table;

    // Generate all permutations of rows
    do {
        // Generate all permutations of columns
        do {
            // Create a permuted table based on current row and column permutations
            vector<vector<int>> permutedTable(N, vector<int>(N));
            for (int r = 0; r < N; ++r) {
                for (int c = 0; c < N; ++c) {
                    permutedTable[r][c] = table[rowIndices[r]][colIndices[c]];
                }
            }

            // Compare with the lexicographically smallest table
            if (permutedTable < minTable) {
                minTable = permutedTable;
            }

        } while (next_permutation(colIndices.begin(), colIndices.end()));

    } while (next_permutation(rowIndices.begin(), rowIndices.end()));

    // Output the lexicographically smallest table
    printTable(minTable);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();  // Call the solve function
    
    return 0;
}
