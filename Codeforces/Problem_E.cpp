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
    int n;
    cin >> n;
    vector<pair<int,pair<int,int>>> borg;
    vector<pair<int,pair<int,int>>> chorg;
    vector<pair<int,pair<int,int>>> org;
   
    vi Org_a(n);
    for(int i = 0; i < n; i++) {
        int e, l, a;
        cin >> e >> l >> a;
        string s;
        cin >> s;
        if(s == "Borg") {
            borg.push_back(make_pair(e,make_pair(l,a)));
        }
        if(s == "Chorg") {
            chorg.push_back(make_pair(e,make_pair(l,a)));
        }
        if(s == "Org") {
            org.push_back(make_pair(e,make_pair(l,a)));
        }
    }
    int output = 0;
    for(int i = 0; i < borg.size(); i++) {
        vector<pair<int,int>> maxE(3);
        
        for(int j = 0; j < chorg.size(); j++) {

  

            for(int l = 0; l < org.size(); l++) {
                maxE.clear();
                maxE[0].first=0;
                maxE[0].second=borg[i].first;
                maxE[1].first=0;
                maxE[1].second=borg[i].second.first;
                maxE[2].first=0;
                maxE[2].second=borg[i].second.second;
                if(chorg[j].first>maxE[0].second){
                    maxE[0].second=chorg[j].first;
                    maxE[0].first=1;
                }
                if(chorg[j].second.first>maxE[1].second){
                    maxE[1].second=chorg[j].second.first;
                    maxE[1].first=1;
                }
                if(chorg[j].second.second>maxE[2].second){
                    maxE[2].second=chorg[j].second.second;
                    maxE[2].first=1;
                }

                if(org[l].first>maxE[0].second){
                    maxE[0].second=org[l].first;
                    maxE[0].first=2;
                }
                if(org[l].second.first>maxE[1].second){
                    maxE[1].second=org[l].second.first;
                    maxE[1].first=2;
                }
                if(org[l].second.second>maxE[2].second){
                    maxE[2].second=org[l].second.second;
                    maxE[2].first=2;
                }

                 if(maxE[0].first!=maxE[1].first && maxE[2].first!=maxE[1].first && maxE[2].first!= maxE[0].first) {
                    // int val = maxE[0].first;
                    //  int max = maxE[0].second;
                    //  if((val!=0 || borg[i].first!=maxE[0].second) && (val!=1 || chorg[j].first!=maxE[0].second) && (val!=2 || org[l].first!=maxE[0].second) ){
                    //         continue;
                    // }
                    //  val = maxE[1].first;
                    //  max = maxE[1].second;
                    // if((val!=0 || borg[i].first!=maxE[1].second) && (val!=1 || chorg[j].first!=maxE[1].second) && (val!=2 || org[l].first!=maxE[1].second) ){
                    //     continue;
                    // }
                    //   val = maxE[2].first;
                    //  max = maxE[2].second;
                    //  if((val!=0 || borg[i].first!=maxE[2].second) && (val!=1 || chorg[j].first!=maxE[2].second) && (val!=2 || org[l].first!=maxE[2].second) ){
                    //     continue;
                    // }

                    // int numBorgs = 0;
                    // if(maxE[0].second == borg[j].first) numBorgs++;
                    // if(maxE[1].second == borg[j].second.first) numBorgs++;
                    // if(maxE[2].second == borg[j].second.second) numBorgs++;

                    //  int numChorgs = 0;
                    // if(maxE[0].second == chorg[j].first) numChorgs++;
                    // if(maxE[1].second == chorg[j].second.first) numChorgs++;
                    // if(maxE[2].second == chorg[j].second.second) numChorgs++;
                    
                    // int numOrgs = 0;
                    // if(maxE[0].second == org[j].first) numOrgs++;
                    // if(maxE[1].second ==org[j].second.first) numOrgs++;
                    // if(maxE[2].second == org[j].second.second) numOrgs++;
                    if((borg[i].first == chorg[j].first && (maxE[0].first==0 || maxE[0].first == 1)) || (borg[i].first == org[l].first && (maxE[0].first==0 || maxE[0].first == 2)) || (chorg[j].first == org[l].first && (maxE[0].first==1 || maxE[0].first == 2))) {
                         //cout << maxE[0].first << " " << maxE[0].second << " " << maxE[1].first << " " << maxE[1].second << " " << maxE[2].first << " " << maxE[2].second<< endl;

                        continue;
                    }
                    if((borg[i].second.first == chorg[j].second.first && (maxE[1].first==0 || maxE[1].first == 1)) || (borg[i].second.first == org[l].second.first && (maxE[1].first==0 || maxE[1].first == 2)) || (chorg[j].second.first == org[l].second.first && (maxE[1].first==1 || maxE[1].first == 2))) {
                        //cout << maxE[0].first << " " << maxE[0].second << " " << maxE[1].first << " " << maxE[1].second << " " << maxE[2].first << " " << maxE[2].second<<  " " << (borg[i].second.first == chorg[j].second.first && (maxE[1].first==0 || maxE[1].first == 1))<< endl;

                        continue;
                    }
                    if((borg[i].second.second == chorg[j].second.second && (maxE[2].first==0 || maxE[2].first == 1)) || (borg[i].second.second == org[l].second.second && (maxE[2].first==0 || maxE[2].first == 2)) || (chorg[j].second.second == org[l].second.second && (maxE[2].first==1 || maxE[2].first == 2))) {
                        // cout << maxE[0].first << " " << maxE[0].second << " " << maxE[1].first << " " << maxE[1].second << " " << maxE[2].first << " " << maxE[2].second<< endl;

                        continue;
                    }
                    output++;
                    
                }
            }
        }
    }
    cout << output << endl;
    return 0; 
} 

// 10
// 2 5 3 Borg
// 5 2 2 Chorg
// 4 1 4 Borg
// 1 4 4 Org
// 8 2 1 Org
// 2 2 2 Chorg
// 3 2 9 Borg
// 5 1 5 Borg
// 6 2 6 Org
// 1 1 9 Borg

// 4

// 5
// 1 1 2 Org
// 1 2 1 Borg
// 2 1 1 Chorg
// 1 3 1 Borg
// 2 2 2 Org

// 2


// 3
// 1 1 1 Org
// 1 1 1 Borg
// 1 1 1 Chorg

// 0