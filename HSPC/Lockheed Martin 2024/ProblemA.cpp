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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int N;
    cin >> N;
    
    string dummy;
    getline(cin, dummy);
    for(int t = 0; t < N; t++) {
        int decals = 0;
        string phrase;
        getline(cin, phrase);
        vector<string> letters;
        vector<int> numLetter(26);
        if(phrase.length() == 0) {
            cout << 0 << endl;
        } 
        else {
            decals = 1;
            int max = 1;
            for(int i = 0; i < phrase.length(); i++) {
                
                    letters.push_back("" + phrase.at(i));
                    numLetter[phrase.at(i) - 65]++;
                
            }
            for(int i = 0; i < 26; i++) {
                if(numLetter[i] > max) {
                    max = numLetter[i];
                }
            }
            decals = max;
        }
        cout << decals << endl;
    }
    return 0;
}