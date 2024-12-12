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
typedef long long ll;


#define endll '\n'

int main()
{
    freopen("planting.in", "r", stdin);
    freopen("planting.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int> adj[n];
    for(int i = 0; i < n-1; i++) {
        int a; int b;
        cin >> a >> b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }

    int types = 0;
    for(int i = 0; i < n; i++) {
        int temp = adj[i].size();
        types = max(temp, types);
    }
    cout << types + 1 << '\n'; 
    return 0;
}