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


int n;
vector<int> ans;

bool query(int a, int b) {
    cout << "? " << a << " " << b << endl;
    string res;
    cin >> res;
    return res == "YES";
}

void dfs(int u, int p) {
    for (int v = 2; v < n; v++) {
        if (v != p && query(u, v)) {
            ans[v] = u;
            dfs(v, u);
        }
    }
}

void solve() {
    cin >> n;
    if (n == 3) {
        cout << "1 0" << endl;
        return;
    }
    if (n == 4) {
        if (query(1, 2)) {
            cout << "1 0 2 1" << endl;
        } else {
            cout << "2 0 1 2" << endl;
        }
        return;
    }
    vector<int> children;
    for (int i = 2; i < n; i++) {
        if (query(1, i)) {
            children.push_back(i);
        }
    }
    if (children.size() == 1) {
        cout << "1 0 ";
        for (int i = 2; i < n; i++) {
            if (i != children[0]) {
                cout << i << " " << children[0] << " ";
            }
        }
        cout << endl;
        return;
    }
    vector<int> root_children;
    for (int i = 2; i < n; i++) {
        if (find(children.begin(), children.end(), i) == children.end()) {
            if (query(i, children[0])) {
                root_children.push_back(i);
            }
        }
    }
    if (root_children.size() == 1) {
        cout << "1 0 ";
        for (int i = 2; i < n; i++) {
            if (i != root_children[0]) {
                cout << i << " " << root_children[0] << " ";
            }
        }
        cout << endl;
        return;
    }
    int p1 = children[0];
    int p2 = children[1];
    for (int i = 2; i < n; i++) {
        if (find(children.begin(), children.end(), i) == children.end()) {
            if (query(i, p1)) {
                p1 = i;
            } else if (query(i, p2)) {
                p2 = i;
            }
        }
    }
    ans.resize(n);
    ans[1] = 0;
    ans[p1] = 1;
    ans[p2] = 1;
    dfs(p1, 1);
    dfs(p2, 1);
    cout << "1 0 " << p1 << " " << p2 << " ";
    for (int i = 2; i < n; i++) {
        if (i != p1 && i != p2) {
            cout << i << " " << ans[i] << " ";
        }
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}