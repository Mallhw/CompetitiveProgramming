#include <iostream>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>
#include <algorithm>
#include <cmath>
#include <streambuf>
#include <sstream>
#include <unordered_set>

using namespace std;


#define endll '\n'

int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0); cout.tie(0);
    freopen("revegetate.in", "r", stdin);
    freopen("revegetate.out", "w", stdout);
    int n; int m;
    cin >> n >> m;
    vector<int> adj[n];
    for(int i = 0; i < m; i++) {
        int a; int b;
        cin >> a >> b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }
    vector<int> seedType(n);
    for(int i = 0; i < n; i++) {
        int curType = 1;
        vector<int> pos = {1, 2, 3, 4};
        for(int connected: adj[i]) {
            pos.erase(remove(pos.begin(), pos.end(), seedType[connected]), pos.end());
        }
        seedType[i] = pos.front();
        cout << seedType[i];
    }
    return 0;
}