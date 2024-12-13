#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int mxN = 55;
char grid[mxN][mxN];
bool visited[mxN][mxN];
int rowMovement[4]{0, 1, 0, -1};
int columnMovement[4]{1, 0, -1, 0};

int N, M;

void floodfill(int r, int c) {
	if (r < 0 || r >= N || c < 0 || c >= M) return;
	if (grid[r][c] == '#' || visited[r][c]) return;
	visited[r][c] = true;
	floodfill(r + 1, c);
	floodfill(r - 1, c);
	floodfill(r, c + 1);
	floodfill(r, c - 1);
}

void solve() {
	memset(grid, '.', sizeof(grid));
	memset(visited, 0, sizeof(visited));
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) { cin >> grid[i][j]; }
	}
	// surrounds the bad people
	bool ok = true;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (grid[i][j] == 'B') {
				for (int x = 0; x < 4; x++)  // go through all 4 directions
				{
					int newRow = i + rowMovement[x];
					int newColumn = j + columnMovement[x];
					// check if it is in the boundaries
					if (newRow >= 0 && newRow < N && newColumn >= 0 &&
					    newColumn < M) {
						if (grid[newRow][newColumn] == 'G') {
							cout << "No\n";
							return;
						}
						if (grid[newRow][newColumn] == '.') {
							grid[newRow][newColumn] = '#';  // turn it into a #
						}
					}
				}
			}
		}
	}
	floodfill(N - 1, M - 1);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (grid[i][j] == 'G' && !visited[i][j]) {
				cout << "No\n";
				return;
			}
		}
	}
	cout << "Yes\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin >> T;
	while (T--) { solve(); }
}