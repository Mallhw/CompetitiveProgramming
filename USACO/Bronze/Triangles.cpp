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
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("triangles.in", "r", stdin);
    freopen("triangles.out", "w", stdout);
    int n;
    cin >> n;
    vector<pair<int,int>> cows(n);
    for(int i = 0; i < n; i++) {
        cin >> cows[i].first >> cows[i].second;
    }
    
    ll maxArea = 0;
    for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
                if(cows[i].second == cows[k].second && cows[i].first == cows[j].first) {
                    ll area = abs((cows[j].second - cows[i].second) * (cows[k].first - cows[i].first));
                    maxArea = max(area, maxArea);
                }
            }
        }
    }
    cout << maxArea << '\n';
    return 0;
}