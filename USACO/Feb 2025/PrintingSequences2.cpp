#include <bits/stdc++.h> 
using namespace std; 
#define dbg(x) cerr << __LINE__ << ": " << #x << "=" << x << endl;

vector<int> filter(vector<int> &arr) {
    int n = arr.size();
    int cur = arr[0];
    unordered_map<int, int> freq;

    for(int i = 1; i < n; i++) {
        if(arr[i] != cur) {
            freq[cur]++;
            cur = arr[i];
        }
    }
    freq[cur]++;
    for(int val = 1; val <= 3; val++) {
        n = arr.size();
        if(freq[val] == 1) {
            if(arr[0] == val) {
                int lastNum = 0;
                while(arr[lastNum] == val) {
                    lastNum++;
                }
                vector<int> temp;
                for(int i = lastNum; i < n; i++) {
                    temp.push_back(arr[i]);
                }
                arr = temp;
            }
            else if(arr[n - 1] == val) {
                int lastNum = n - 1;
                while(arr[lastNum] == val) {
                    lastNum--;
                }
                vector<int> temp;
                for(int i = 0; i < lastNum + 1; i++) {
                    temp.push_back(arr[i]);
                }
                arr = temp;
            }
        }
    }
    return arr;
}

bool calc(string s) {
    int n = s.size();
    for(int i = 1; i <= n / 2; i++) {
        if(n % i == 0) {
            string cur = s.substr(0, i);
            bool check = true;
            for(int j = 1; j < n / i; j++) {
                if(s.substr(j * i, i) != cur) {
                    check = false;
                    break;
                }
            }    
            if(check) {
                return true;
            }
        }
    }
    return false;
}


bool calc2(string s) {
    int n = s.size();
    for(int i = 1; i <= n / 2; i++) {
            string cur = s.substr(0, i);
            bool check = true;
            int count = 1;
            for(int j = 1; j < n / i; j += i) {
                if(s.substr(j * i, i) != cur) {
                    check = false;
                    break;
                }
                count++;
            }    
            vector<int> switches; int current = cur[0]; switches.push_back(cur[0] - '0');
            if(check) {
                int remain = (cur.size() * count);
            
                bool check = true;
                for(int j = remain; j < n - 1; j++) {
                    if(s[j] != s[j + 1]) {
                        check = false;
                        break;
                    }
                }
                if(check) {
                    return true;
                }
            }
    }
    return false;
}
void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    vector<int> arr(n); 
    set<int> numsPresent;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        numsPresent.insert(arr[i]);
        s += to_string(arr[i]);
    }
    if (n <= k) {
        cout << "YES" << endl; 
        return;
    }
    if(k == 1) cout << "YES" << endl;
    if(k == 2) {
        arr = filter(arr);
        if(arr.size() <= 1) {
            cout << "YES" << endl;
            return;
        }
        s = "";
        for(int i = 0; i < arr.size(); i++) {
            s += to_string(arr[i]);
        }
        if(calc(s)) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
        return;
    }
    if(k == 3) {
        arr = filter(arr);
        if(arr.size() <= 1) {
            cout << "YES" << endl;
            return;
        }
        s = "";
        for(int i = 0; i < arr.size(); i++) {
            s += to_string(arr[i]);
        }
        n = s.size();
        for(int i = 1; i <= n / 2; i++) {
            if(n % i == 0) {
                string cur = s.substr(0, i);
                bool check = true;
                for(int j = 1; j < n / i; j++) {
                    if(s.substr(j * i, i) != cur) {
                        check = false;
                        break;
                    }
                }    
                if(check) {
                    vector<int> temp;
                    set<int> s;
                    for(int i = 0; i < cur.size(); i++) {
                        temp.push_back(cur[i] - '0');
                        s.insert(cur[i] - '0');
                    }
                    vector<int> compressed; int prev = temp[0]; compressed.push_back(temp[0]);
                    vector<int> numsInRow; int counter = 1;
                    for(int i = 1; i < temp.size(); i++) {
                        if(temp[i] != prev) {
                            compressed.push_back(temp[i]);
                            prev = temp[i];
                            numsInRow.push_back(counter);
                            counter = 0;
                        }
                        counter++;
                    }
                    numsInRow.push_back(counter);
                    if(s.size() == 3) {
                        filter(temp);
                    }
                    string tempS = "";
                    for(int i = 0; i < temp.size(); i++) {
                        tempS += to_string(temp[i]);
                    }
                    
                    if(temp.size() <= 1 || compressed.size() <= 3) {
                        cout << "YES" << endl;
                        return;
                    }
                    if(calc(tempS)) {
                        cout << "YES" << endl;
                        return;
                    }
                    reverse(tempS.begin(), tempS.end());
                    if(calc(tempS)) {
                        cout << "YES" << endl;
                        return;
                    }
                    if(calc2(tempS)) {
                        cout << "YES" << endl;
                        return;
                    }
                    reverse(tempS.begin(), tempS.end());
                    if(calc2(tempS)) {
                        cout << "YES" << endl;
                        return;
                    }
                }
            }
        }
        reverse(s.begin(), s.end());
            for(int i = 1; i <= n / 2; i++) {
                if(n % i == 0) {
                    string cur = s.substr(0, i);
                    bool check = true;
                    for(int j = 1; j < n / i; j++) {
                        if(s.substr(j * i, i) != cur) {
                            check = false;
                            break;
                        }
                    }    
                    if(check) {
                        vector<int> temp;
                        set<int> s;
                        for(int i = 0; i < cur.size(); i++) {
                            temp.push_back(cur[i] - '0');
                            s.insert(cur[i] - '0');
                        }
                        vector<int> compressed; int prev = temp[0]; compressed.push_back(temp[0]);
                        vector<int> numsInRow; int counter = 1;
                        for(int i = 1; i < temp.size(); i++) {
                            if(temp[i] != prev) {
                                compressed.push_back(temp[i]);
                                prev = temp[i];
                                numsInRow.push_back(counter);
                                counter = 0;
                            }
                            counter++;
                        }
                        numsInRow.push_back(counter);
                        if(s.size() == 3) {
                            filter(temp);
                        }
                        string tempS = "";
                        for(int i = 0; i < temp.size(); i++) {
                            tempS += to_string(temp[i]);
                        }
                        if(temp.size() <= 1 || compressed.size() <= 3) {
                            cout << "YES" << endl;
                            return;
                        }
                        if(calc(tempS)) {
                            cout << "YES" << endl;
                            return;
                        }
                        reverse(tempS.begin(), tempS.end());
                        if(calc(tempS)) {
                            cout << "YES" << endl;
                            return;
                        }
                    }
                }
            }
        if(numsPresent.size() <= 2) {
            if(calc2(s)) {
                cout << "YES" << endl;
                return;
            }
            reverse(s.begin(), s.end());
            if(calc2(s)) {
                cout << "YES" << endl;
                return;
            }
        }
        cout << "NO" << endl;
        return;
    }
    return;
}
int main() 
{ 
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0; 
} 
