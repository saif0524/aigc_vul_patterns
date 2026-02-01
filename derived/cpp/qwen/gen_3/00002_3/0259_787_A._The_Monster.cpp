#include <iostream>
using namespace std;

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    
    int time = 1;
    bool found = false;
    
    while (time <= 10000) {
        int rick_scream = b + a * (time - 1);
        int morty_scream = d + c * (time - 1);
        
        if (rick_scream == morty_scream) {
            found = true;
            cout << rick_scream;
            break;
        }
        
        time++;
    }
    
    if (!found) {
        cout << -1;
    }
    
    return 0;
}