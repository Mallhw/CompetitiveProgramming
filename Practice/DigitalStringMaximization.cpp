#include <bits/stdc++.h> 
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
void solve() {
    std::string s;
    std::cin >> s;

    for (int i = 1; i < s.size(); i++) {
    int j = i;
    while (j > 0 && s[j] > s[j - 1] && s[j] - s[j - 1] >= 2) {
        s[j]--;
        std::swap(s[j], s[j - 1]);
        j--;
    }
}

    std::cout << s << std::endl;
}

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}