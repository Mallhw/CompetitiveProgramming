#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--) {
        int N;
        cin >> N;
        int n = N / 2 + 1;
        int a[N];
        for (int i = 0; i < N; i++) {
            cin >> a[i];
        }
        int minSum = INT_MAX;
        for (int i = 0; i <= N - n; i++) {
            int sum = 0;
            for (int j = 0; j < n; j++) {
                sum += a[i+j];
            }
            minSum = min(minSum, sum);
        }
        int bessieSum = minSum;
        int elsieSum = accumulate(a, a + N, 0) - minSum;
        cout << bessieSum << " " << elsieSum << endl;
    }
    return 0;
}