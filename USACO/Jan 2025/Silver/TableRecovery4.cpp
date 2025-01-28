#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int find_val(const vector<vector<int>>& g, int v1, int v2) {
    for (const auto& row : g) {
        for (int num : row) {
            if (num == v1) return v1;
            if (num == v2) return v2;
        }
    }
    return -1;
}

bool valid_grid(const vector<vector<int>>& g) {
    int n = g.size();
    vector<int> sums;
    sums.reserve(n);
    for (const auto& row : g) {
        sums.push_back(accumulate(row.begin(), row.end(), 0));
    }
    sort(sums.begin(), sums.end());
    for (int i = 1; i < n; ++i) {
        if (sums[i] != sums[i - 1] + n) {
            return false;
        }
    }
    return true;
}

void solve(istream &in, ostream &out) {
    int n;
    in >> n;

    vector<vector<int>> g(n, vector<int>(n));
    int mx = n * 2;
    vector<int> cnt(mx + 1, 0);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            in >> g[i][j];
            cnt[g[i][j]]++;
        }
    }

    vector<vector<int>> m(2, vector<int>(mx + 1, 0));
    vector<vector<int>> grp;

    for (int i = 1; i <= n; ++i) {
        int s1 = 0, s2 = 0;
        for (int num = 1; num <= mx; ++num) {
            if (cnt[num] == i) {
                if (!s1) s1 = num;
                else s2 = num;
            }
        }

        int f1 = i + 1;
        int f2 = (mx + 2) - f1;

        int first = find_val(g, s1, s2);
        int second = (s1 == first ? s2 : s1);

        m[0][first] = f1;
        m[0][second] = f2;
        m[1][first] = f2;
        m[1][second] = f1;

        grp.push_back({first, second});
    }

    vector<int> num_to_group(mx + 1, -1);
    int usable_groups = n - 1; 
    for (int j = 0; j < usable_groups; ++j) {
        for (int num : grp[j]) {
            num_to_group[num] = j;
        }
    }

    vector<vector<int>> res(n, vector<int>(n));
    for (int mask = 0; mask < (1 << usable_groups); ++mask) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int num = g[i][j];
                int group = num_to_group[num];
                if (group == -1) {
                    res[i][j] = m[0][num]; 
                } else {
                    int conf = (mask >> group) & 1;
                    res[i][j] = m[conf][num];
                }
            }
        }
        if (valid_grid(res)) {
            for (const auto& row : res) {
                for (int k = 0; k < n; ++k) {
                    if (k > 0) out << ' ';
                    out << row[k];
                }
                out << '\n';
            }
            return;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve(cin, cout);
    return 0;
}