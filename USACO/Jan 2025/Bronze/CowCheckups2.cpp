#include <bits/stdc++.h> 
using namespace std; 
#define max(a, b) (a < b ? b : a) 
#define min(a, b) ((a > b) ? b : a) 
#define dbg(x) cerr << __LINE__ << ": " << #x << "=" << x << endl;
typedef long long int ll; 
typedef vector<long long> vll;



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);  
    ll N; 
    cin >> N;
    vector<ll> initial(N), final(N);
    vector<ll> ans(N + 1);
    ll totalSamsies = 0;


    for(int i = 0; i < N; i++) {
        cin >> initial[i];
    }
    for(int i = 0; i < N; i++) {
        cin >> final[i];
    }
    for(int i = 0; i < N; i++)
    {
        totalSamsies += initial[i] == final[i];
    }






    for(int i = 0; i < N; i++)
    {
        int num = totalSamsies;
        for(int j = 0; j <= min(i, N-i-1); j++)
        {
            if(initial[i+j] == final[i+j]) {
                num--;
            }
            if(initial[i-j] == final[i-j]) {
                num--;
            }
            if(initial[i+j] == final[i-j]) {
                num++;
            }
            if(initial[i-j] == final[i+j]) {
                num++;
            }
            ans[num]++;
        }
    }

    for(int i = 0; i < N - 1; i++)
    {
        int num = totalSamsies;
        for(int j = 0; j <= min(i, N - i - 2); j++)
        {
            if(initial[i + j + 1] == final[i + j + 1]) {
                num--;
            }
            if(initial[i - j] == final[i - j]) {
                num--;
            }
            if(initial[i + j + 1] == final[i - j]) {
                num++;
            }
            if(initial[i - j] == final[i + j + 1]) {
                num++;
            }
            ans[num]++;
        }
    }



    for(int i = 0; i <= N; i++)
    {
        cout << ans[i] << '\n';
    }
    return 0;
}