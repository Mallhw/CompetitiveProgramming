#include "bits/stdc++.h" 
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
int main() 
{ 
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    int T; 
    cin >> T; 
    while (T--) { 
        int n;
        cin >> n;
        vi xPoints(n);
        vi yPoints(n);
        for(int i = 0; i < n; i++) {
            int x; int y;
            cin >> x >> y;
            xPoints[i] = x;
            yPoints[i] = y;
            sort(xPoints.begin(), xPoints.end());
            sort(yPoints.begin(), yPoints.end());
        }
        int nonOverlapping = n;
        int horPoints = 0;
        int odds = 0;
        //cout << n << endl;
        for(int i = 0; i < n-1; i++) {
            if(xPoints[i] == xPoints[i+1] && yPionts[i] != yPoints[i+1]) {
                horPoints++;
            }
            else if(i < n-2 && xPoints[i]+1 == xPoints[i+1] && xPoints[i+1] == xPoints[i+2]-1) {
                if(yPoints[i] + yPoints[i+1] == yPoints[i+1] + yPoints[i+2]) odds++;   
            }
        }
        //cout << nonOverlapping << endl;
        //cout << horPoints + " " + nonOverlapping + " " + odds << endl;
        //cout << nonOverlapping << endl;
        //cout << nonOverlapping << endl;
        cout << horPoints * (n-2) + odds << endl;
    } 
    return 0; 
} 
