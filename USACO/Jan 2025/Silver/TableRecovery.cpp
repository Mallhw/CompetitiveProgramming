#include <bits/stdc++.h>
using namespace std;

int N;
vector<vector<int>> grid;

vector<vector<int>> best;

bool check(const vector<int>& row_perm, const vector<int>& col_perm) {
    vector<vector<int>> sum_grid(N, vector<int>(N));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            sum_grid[i][j] = row_perm[i] + col_perm[j];

    map<int, int> mapping;
    map<int, int> rev_mapping;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            int s = sum_grid[i][j];
            int g = grid[i][j];
            if (mapping.count(s)) {
                if (mapping[s] != g)
                    return false;
            } else {
                if (rev_mapping.count(g))
                    return false;
                mapping[s] = g;
                rev_mapping[g] = s;
            }
        }
    }
    return true;
}

void update_best(const vector<vector<int>>& candidate) {
    if (best.empty()) {
        best = candidate;
        return;
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (candidate[i][j] < best[i][j]) {
                best = candidate;
                return;
            } else if (candidate[i][j] > best[i][j]) {
                return;
            }
        }
    }
}

int main() {
    cin >> N;
    grid.resize(N, vector<int>(N));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> grid[i][j];

    best.clear();

    vector<int> rows(N);
    iota(rows.begin(), rows.end(), 1);
    do {
        vector<int> cols(N);
        iota(cols.begin(), cols.end(), 1);
        do {
            if (check(rows, cols)) {
                vector<vector<int>> sum_grid(N, vector<int>(N));
                for (int i = 0; i < N; ++i)
                    for (int j = 0; j < N; ++j)
                        sum_grid[i][j] = rows[i] + cols[j];
                update_best(sum_grid);
            }
        } while (next_permutation(cols.begin(), cols.end()));
    } while (next_permutation(rows.begin(), rows.end()));

    for (const auto& row : best) {
        for (int i = 0; i < N; ++i) {
            if (i > 0) cout << ' ';
            cout << row[i];
        }
        cout << '\n';
    }
    return 0;
}