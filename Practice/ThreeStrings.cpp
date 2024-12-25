#include <bits/stdc++.h> 
using namespace std; 
#define max(a, b) (a < b ? b : a) 
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
int main() {
    int t;
    std::cin >> t;

    while (t--) {
        std::string a, b, c;
        std::cin >> a >> b >> c;

        int i = 0, j = 0, k = 0;
        int res = 0;

        while (k < c.size()) {
            if (i < a.size() && a[i] == c[k]) {
                i++;
            } else if (j < b.size() && b[j] == c[k]) {
                j++;
            } else {
                res++;
            }
            k++;
        }

        int res2 = 0;
        i = 0, j = 0, k = 0;
        while (k < c.size()) {
            if (j < b.size() && b[j] == c[k]) {
                j++;
            } else if (i < a.size() && a[i] == c[k]) {
                i++;
            } else {
                res2++;
            }
            k++;
        }

        std::cout << std::min(res, res2) << std::endl;
    }

    return 0;
}