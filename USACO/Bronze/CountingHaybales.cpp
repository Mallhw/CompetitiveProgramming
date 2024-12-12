#include <iostream>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>
#include <algorithm>
#include <cmath>
#include <streambuf>
#include <sstream>
#include <unordered_set>

using namespace std;

#define endll '\n'

int binary(int lower, int upper, int target, vector<int> arr) {
    if(lower > upper) {
        return -1;
    }
    int mid = (lower + upper)/2;
    if(arr[mid] = target) {
        return mid;
    }
    
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; int q;
    vector<int> bales;
    cin >> n >> q;
    for(int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        bales.push_back(temp);
    }
    sort(begin(bales), end(bales));

    // binary search
    
    return 0;
}