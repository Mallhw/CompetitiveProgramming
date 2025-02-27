#include <bits/stdc++.h>
using namespace std;

int main() {
    int counter = 0; 
            for(int i = 0; i < 3; i++) {
                for(int i = 0; i < 2; i++) {
                    for(int i = 0; i < 2; i++) {
                        cout << 1 << " ";
                        counter++;
                        for(int i = 0; i < 2; i++) {
                            cout << 2 << " ";
                            counter++;
                        }
                    }
                    
                }
                for(int i = 0; i < 1; i++) {
                    cout << 2 << " ";
                    counter++;
                }
            }
            
            
        
        
    cout << endl;
    cout << counter << endl;

    return 0;
}
