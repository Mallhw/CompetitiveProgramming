#include <bits/stdc++.h> 
using namespace std; 
typedef long long int ll;

const int N=1e6+5;
vector<vector<int>> adj;
vector<int> depth, counter , used;
ll total = 0;
void dfs(int u){
    if(adj[u].size( ) == 0) {
        counter[u]=1;
        total++;
    }
	for(auto i : adj[u]){
		depth[i] = depth[u] + 1;
		dfs(i);
		counter[u] += counter[i];
	}
	
}
int main() {
    int n;
	cin >> n;
    vector<int> arr(n);
    adj = vector<vector<int>>(n + 1);
    depth = vector<int>(n + 1);
    counter = vector<int>(n + 1);
    used = vector<int>(n + 1);
    set<int> uniques; 
	for(int i = 1; i <= n; i++){
        cin >> arr[i];
		adj[arr[i]].push_back(i);
        uniques.insert(arr[i]);
	}
	dfs(0);
    total--;
	while(total--) {
        int word;
		cin >> word;
		used[word]=1;
		while(word!=0){
			counter[word] -= used[word];
			used[arr[word]] += used[word];
			used[word] = 0;
			if(counter[word]){
				break;
			}
			word=arr[word];
		}
		cout << depth[word] + 1 << endl;
	}
    int word;
	cin >> word;
	cout << 0;
	return 0;
}