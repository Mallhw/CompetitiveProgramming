#include <bits/stdc++.h> 
using namespace std; 

#define max(a, b) (a < b ? b : a) 
#define min(a, b) ((a > b) ? b : a) 
#define dbg(x) cerr << __LINE__ << ": " << #x << "=" << x << endl;

typedef long long int ll; 
typedef vector<long long> vll;


vll reverseArray(vll arr, ll l, ll r) {
  while (l < r) {
    int temp = arr[l];
    arr[l] = arr[r];
    arr[r] = temp;
    l++;
    r--;
  }
  return arr;
}


int main() 
{ 
    ios::sync_with_stdio(0); 
    cin.tie(0); 

    // Input from file
    ifstream inputFile("test_case.txt");
    if (!inputFile) {
        cerr << "Error opening the file!" << endl;
        return 1;
    }

    ll n;
    inputFile >> n; // Read n

    vll a(n);
    vll b(n);
    unordered_map<ll, vll> mapA;
    unordered_map<ll, vll> mapB;

    // Read array a
    for(ll i = 0; i < n; i++) {
        inputFile >> a[i];
        mapA[a[i]].push_back(i);
    }

    // Read array b
    for(ll i = 0; i < n; i++) {
        inputFile >> b[i];
        mapB[b[i]].push_back(i);
    }


    ll ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            vll temp = reverseArray(a, i, j);
            for(int l = 0; l < n; l++) {
                if(temp[l] == b[l]) {
                    ans++;
                }
            }
        }
    }
    cout << ans << endl;
    inputFile.close();
    return 0; 
}
