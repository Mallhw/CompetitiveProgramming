#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

struct Segment {
    int left;
    int right;
    int totalTrees;
    int minTrees;
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--) {
        int n, k;
        cin >> n >> k;
        vector<int> arr(n+1);
        for(int i = 1; i <= n; i++) {
            cin >> arr[i];
        }

        vector<Segment> segments(k+1);
        for(int i = 1; i <= k; i++) {
            int l, r, minTree;
            cin >> l >> r >> minTree;
            int totalTrees = min(r, n) - max(l, 1) + 1;
            segments[i] = {l, r, totalTrees, minTree};
        }

        int ans = 0;
        for(int i = 1; i <= n; i++) {
            bool cut = true;
            for(int j = 1; j <= k; j++) {
                if(arr[i] >= segments[j].left && arr[i] <= segments[j].right) {
                    if(segments[j].totalTrees <= segments[j].minTrees) {
                        cut = false;
                        break;
                    }
                }
            }
            if(cut) {
                ans++;
                for(int j = 1; j <= k; j++) {
                    if(arr[i] >= segments[j].left && arr[i] <= segments[j].right) {
                        segments[j].totalTrees--;
                        if(segments[j].totalTrees < 0) {
                            segments[j].totalTrees = 0;
                        }
                    }
                }
            }
        }

        cout << ans << endl;
    }
    return 0;
}