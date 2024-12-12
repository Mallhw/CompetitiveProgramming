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
#include <hash_map>

using namespace std;

#define endll '\n'

int main()
{
    int T;
    cin >> T;
    for(int t = 0; t < T; t++) {
        int M; int S;
        cin >> M >> S;
        unordered_map<string, double> map{};
        for(int m = 0; m < M; m++) {
            string material; double val;
            cin >> material >> val;
            map[material] = val;
        }
        for(int i = 0; i < S; i++) {
            double blocking; string mat; double val; double radiation;
            cin >> mat >> val >> radiation;
            blocking = radiation - (val * map[mat]);
            double dosage = 50.0/blocking;
            //cout << dosage << endl;
            if(dosage <= 0) {
                cout << "Infinity" << endl;
            }
            else {
                
                double conversion = (round(dosage*100.0)/100.0);
                

                printf("%.2f\n", conversion);
            }
        }
    }
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    return 0;
}