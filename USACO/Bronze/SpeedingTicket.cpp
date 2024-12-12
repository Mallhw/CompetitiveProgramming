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
    
    freopen("speeding.in", "r", stdin);
	// the following line creates/overwrites the output file
	freopen("speeding.out", "w", stdout);
    
    int N; int M; int infraction = 0; int temp; int curSpeed;
    cin >> N >> M;
    vector<int> speedLimit(100); 
    int cur = 0;
    for(int i = 0; i < N; i++) {
        cin >> temp >> curSpeed;
        for(int j = 0; j < temp; j++) {
            speedLimit[j+cur] = curSpeed;
        }
        cur += temp;
    }
    vector<int> bessieSpeed(100);
    cur = 0; 
    for(int i = 0; i < M; i++) {
        cin >> temp >> curSpeed;
        for(int j = 0; j < temp; j++) {
            bessieSpeed[j+cur] = curSpeed;
        }
        cur += temp;
    }

    // Simulation
    for(int i = 0; i < 100; i++) {
        if(bessieSpeed[i] - speedLimit[i] > infraction) {
            infraction = bessieSpeed[i] - speedLimit[i];
        }
    }
    cout << infraction << endl;
}