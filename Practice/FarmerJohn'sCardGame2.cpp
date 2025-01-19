#include <bits/stdc++.h>
using namespace std;

int compareFunc(const void * a, const void * b) {
    return ( *(int *)a - *(int *)b );
}

#define max(a, b) (a < b ? b : a)
#define min(a, b) ((a > b) ? b : a)
#define dbg(x) cerr << __LINE__ << ": " << #x << "=" << x << endl;
#define mod 1000000007
#define FOR(a, c) for (int a = 0; a < c; a++)
#define FORL(a, b, c) for (int a = b; a <= c; a++)
#define FORR(a, b, c) for (int a = b; a >= c; a--)
#define INF 1000000000000000003
typedef long long int ll;
typedef vector<long long> vll;
typedef vector<int> vi;
typedef pair<int, int> pi;

void solve() {
    int n, m;
    cin >> n >> m;
    int arr[2000][2000];
    int small[2000];
    int index[2000];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
        qsort(arr[i], m, sizeof(int), compareFunc);
        small[i] = arr[i][0];
        index[i] = i+1;
    }
    FOR(i, n) {
        for(int j = i+1; j < n; j++) {
            if(small[i] > small[j]) {
                int temp = small[i];
                small[i] = small[j];
                small[j] = temp;
                temp = index[i];
                index[i] = index[j];
                index[j] = temp;
            }
        }
    }

    int top = -1;
    int val = 1;
    for(int r = 0; r < m && val; r++) {
        for(int i = 0; i < n && val; i++) {
            int cow = index[i]-1;
            int play = 0;
            for(int j = 0; j < m; j++) {
                if(arr[cow][j] > top) {
                    top = arr[cow][j];
                    play = 1;
                    break;
                }
            }
            if(!play) {
                val = 0;
                cout << -1 << endl;
                return;
            }
        }
    }
    if(val) {
        FOR(i, n) {
            cout << index[i] << " ";
        }
        cout << endl;
        return;
    }
    else {
        cout << -1 << endl;
        return;
    }
    return;
}

int main() 
{ 
    int T; 
    cin >> T; 
    while (T--) { 
        solve();
    } 
    return 0; 
}