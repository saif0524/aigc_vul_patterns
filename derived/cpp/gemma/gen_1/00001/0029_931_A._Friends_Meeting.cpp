#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    
    int min_tiredness = -1;
    
    for (int meeting_point = 1; meeting_point <= 1000; ++meeting_point) {
        int tiredness1 = 0;
        int tiredness2 = 0;
        
        int moves1 = abs(a - meeting_point);
        for (int i = 1; i <= moves1; ++i) {
            tiredness1 += i;
        }
        
        int moves2 = abs(b - meeting_point);
        for (int i = 1; i <= moves2; ++i) {
            tiredness2 += i;
        }
        
        int total_tiredness = tiredness1 + tiredness2;
        
        if (min_tiredness == -1 || total_tiredness < min_tiredness) {
            min_tiredness = total_tiredness;
        }
    }
    
    cout << min_tiredness << endl;
    
    return 0;
}