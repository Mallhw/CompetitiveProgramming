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
struct cream {
    int price;
    int taste;
};
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int q;
    cin >> q;

    vector<vector<cream>> stores;
    vi indices;

    for (int i = 0; i < q; i++) {
        int type;
        cin >> type;

        if (type == 1) {
            int a;
            cin >> a;
            if (a < stores.size()) {
                stores.push_back(stores[a]);
            }
        } else if (type == 2) {
            int x, price, taste;
            cin >> x >> price >> taste;
            if (x >= stores.size()) {
                stores.resize(x + 1);
            }
            stores[x].push_back({price, taste});
        } else if (type == 3) {
            int a;
            cin >> a;
            if (a < stores.size() && !stores[a].empty()) {
                stores[a].erase(stores[a].begin());
            }
        } else if (type == 4) {
            int a, b;
            cin >> a >> b;
            if (a < stores.size()) {
                int n = stores[a].size();
                vector<int> dynamicProgramming(b + 1, 0);
                for (int c = 0; c < n; c++) {
                    for (int j = b; j >= stores[a][c].price; j--) {
                        dynamicProgramming[j] = max(dynamicProgramming[j], dynamicProgramming[j - stores[a][c].price] + stores[a][c].taste);
                    }
                }
                cout << dynamicProgramming[b] << endl;
            }
        }
    }
    return 0;
}