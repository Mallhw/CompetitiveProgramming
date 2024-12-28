#include <bits/stdc++.h> 
using namespace std; 

int main() 
{ 
    int n, m;
    cin >> n >> m;
    set<int> set;
    for(int i = 0; i < m; i++) {
        int species, power;
        cin >> species >> power;
        set.insert(species);
    }
    cout << set.size() << endl;
    return 0; 
} 


