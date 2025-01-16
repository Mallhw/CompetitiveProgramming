#include <bits/stdc++.h> 
using namespace std; 
#define max(a, b) (a < b ? b : a) 
#define min(a, b) ((a > b) ? b : a) 
#define dbg(x) cerr << __LINE__ << ": " << #x << "=" << x << endl;
#define mod 1000000007 
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
    ll n, q;
    cin >> n >> q;
    vll arr(n, 1);
    for(int i = 0; i < q; i++) {
        int event;
        cin >> event;
        dbg(event);
        for(int i = 0; i < arr.size(); i++) {
            cout << arr[i] << ' ';
        }
        cout << endl;
        if(event == 1) {
            ll a, b;
            cin >> a >> b;
            ll firstNum;
            ll secondNum;
            if(a != b) {
                 firstNum = min(a, b);
                 secondNum = max(a, b);
            }
            else {
                 firstNum = a;
                 secondNum = b;
            }
            vll newArr(n-1);
            bool skipped1 = true;
            bool skipped2 = true;
            for(int i = 0; i < n; i++) {
                if(arr[i] == firstNum && skipped1) {
                    skipped1 = false;
                    i++;
                }
                else if(arr[i] == secondNum && skipped2) {
                    arr[i]++;
                    skipped2 = false;
                }
                newArr[i] = arr[i];
            }
            arr = newArr;
        }
        else {
            ll k;
            cin >> k;
            vll pair_diff;
            for(int i = 0; i < arr.size(); i++) {
                for(int j = i+1; j < arr.size(); j++) {
                    pair_diff.push_back(abs(arr[i] - arr[j]));
                }
            }
            sort(pair_diff.begin(), pair_diff.end());

            if(k >= pair_diff.size()) {
                cout << 0 << endl;
            }
            else {
                cout << pair_diff[k-1] << endl;
            }
        }
    }
}
int main() 
{ 
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    solve();
    return 0; 
} 
