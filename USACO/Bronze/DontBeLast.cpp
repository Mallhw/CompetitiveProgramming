#include <bits./stdc++.h>

using namespace std;

int main() {
    int N; cin >> N;
   map<string, int> mp;
   for(int i = 1; i <= N; i++){
        string  name; cin >> name;
        int milk; cin >> milk;
        mp[name] += milk;
   } 
   int minm = INT_MAX; 
   if((int)mp.size() < 7){
        minm = 0;
   }
   else{
        for(auto w : mp){
             minm = min(w.second, minm);
        }
   }
   string ans = "";
   int secmin = INT_MAX, cnt = 0;
   for(auto w : mp){
        if(w.second > minm && w.second < secmin){
             secmin = w.second;
             ans = w.first;
             cnt = 1;
        }
        else if(w.second == secmin) cnt++;

   } 
   cout << (cnt == 1 ? ans : "Tie") << '\n';
return 0;
    
}