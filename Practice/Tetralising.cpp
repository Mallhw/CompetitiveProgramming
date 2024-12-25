#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef long long ll;
#define endll '\n'

#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << LINE << ": " << #x << "=" << x << endll;


void solveeven(int n, vector<vi>& grid, int& start){
    if(n == 4){
        grid = {
            {1, 2, 2, 2},
            {1, 1, 2, 3},
            {1, 4, 3, 3},
            {4, 4, 4, 3}
        };
        start = 5;
        return;
    }
    solveeven(n - 2, grid, start);

}


void solve(int num_tc)
{
    int n;
    cin >> n;
    if(n == 1){
        cout << 0 << endll << 0 << endll;
        return;
    }
    if(n == 2){
        cout << "0\n0 0\n0 0" << endll;
        return;
    }
    if(n == 3){
        cout << "1\n1 1 1\n0 1 0\n0 0 0" << endll;
        return;
    }
    if(n == 4){
        cout << "4" << endll;
        cout << "1 2 2 2\n 1 1 2 3\n1 4 3 3\n4 4 4 3" << endll;
        return;
    }
    if(n == 5){
        cout << "6" << endll;
        cout << "1 2 2 2 3\n1 1 2 3 3\n1 6 0 3 4\n6 6 5 4 4\n6 5 5 5 4" << endll;
        return;
    }
    vector<vi> grid(n, vi(n, 0));
    if(n % 2 == 0){
        solveeven(n, grid, 0);
        for(int i = 0; i < n; i++){
            cout << grid[i][0];
            for(int j = 1; j < n; j++){
                cout << " " << grid[i][j];
            }
            cout << endll;
        }
    }

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ll T = 1;
    //cin >> T;
    for(ll t = 0; t < T; t++){
        solve(t+1);
    }
}