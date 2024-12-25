#include <bits/stdc++.h> 
using namespace std; 
#define max(a, b) (a < b ? b : a) 
#define min(a, b) ((a > b) ? b : a) 
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
bool isDivisibleBy9(const string& n) {
    unordered_set<int> possibleMods;
    possibleMods.insert(0);

    for (char c : n) {
        int digit = c - '0';
        unordered_set<int> newMods;

        if (digit == 0 || digit == 1) {
            for (int mod : possibleMods) {
                newMods.insert((mod + digit) % 9);
            }
        }
        else if (digit == 2) {
            for (int mod : possibleMods) {
                newMods.insert((mod + 2) % 9);
                newMods.insert((mod + 4) % 9);
            }
        }
        else if (digit == 3) {
            for (int mod : possibleMods) {
                newMods.insert((mod + 3) % 9);
                newMods.insert((mod + 9) % 9);
            }
        }
        else {
            for (int mod : possibleMods) {
                newMods.insert((mod + digit) % 9);
            }
        }

        possibleMods = newMods;
    }

    return possibleMods.count(0) > 0;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string n;
        cin >> n;
        if (isDivisibleBy9(n)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
