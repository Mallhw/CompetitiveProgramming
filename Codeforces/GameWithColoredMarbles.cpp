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

vector<int> sortByFrequency(const vector<int>& nums) {
    // Step 1: Count the frequency of each element
    unordered_map<int, int> freq;
    for (int num : nums) {
        freq[num]++;
    }

    // Step 2: Create a sorted copy of the original vector
    vector<int> sorted(nums);

    // Step 3: Sort the vector using a custom comparator
    sort(sorted.begin(), sorted.end(), [&freq](int a, int b) {
        if (freq[a] != freq[b]) {
            return freq[a] < freq[b]; // Sort by frequency
        }
        return a < b; // Sort by value if frequency is the same
    });

    return sorted;
}

int main() 
{ 
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    int T; 
    cin >> T; 
    while (T--) {
        int n;
        cin >> n;
        vi arr(n);

        // Read array elements
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        // Get sorted vector by frequency
        vi sorted = sortByFrequency(arr);


        // Count unique elements and points
        set<int> uniques;
        unordered_map<int, int> counts;
        for (int num : sorted) {
            counts[num]++;
        }

        int points = 0;
        for (int i = 0; i < n; i += 2) {
            counts[sorted[i]]--;
            if (counts[sorted[i]] == 0) points++;
            uniques.insert(sorted[i]);
        }

        cout << uniques.size() + points << endl;
    }
    return 0; 
} 
