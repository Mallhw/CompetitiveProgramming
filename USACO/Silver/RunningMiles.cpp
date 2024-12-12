#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;

#define endll '\n'


#include <bits/stdc++.h>
using namespace std;

int main() {
	int test_num;
	cin >> test_num;

	for (int t = 0; t < test_num; t++) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++) { cin >> a[i]; }

		vector<int> pref_max(n);
		vector<int> suff_max(n);
		for (int i = 0; i < n; i++) {
			pref_max[i] = a[i] + i;
			suff_max[i] = a[i] - i;
		}

		for (int i = 1; i < n; i++) {
			pref_max[i] = max(pref_max[i], pref_max[i - 1]);
		}
		for (int i = n - 2; i >= 0; i--) {
			suff_max[i] = max(suff_max[i], suff_max[i + 1]);
		}

		int ans = 0;
		for (int i = 1; i < n - 1; i++) {
			ans = max(ans, pref_max[i - 1] + a[i] + suff_max[i + 1]);
		}

		cout << ans << '\n';
	}
}