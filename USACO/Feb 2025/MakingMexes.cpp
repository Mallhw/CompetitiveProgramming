#include <bits/stdc++.h> 
using namespace std; 

int main() 
{ 
    int n;
    cin >> n;
    vector<int> a(n);
    unordered_map<int, int> freq;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        freq[a[i]]++;
    }
    vector<long long> output(n+1);
    long long runningSum = 0;
    for(int i = 0; i < n+1; i++) {
        if(freq[i] != 0) {
            output[i] = (freq[i] < runningSum ? runningSum : freq[i]);
        }
        else {
            output[i] = runningSum;
            runningSum++;
        }
    }
    for(int i = 0; i < output.size(); i++) {
        cout << output[i] << endl;
    }
    return 0; 
} 
