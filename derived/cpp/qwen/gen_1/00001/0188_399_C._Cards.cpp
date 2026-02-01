#include <iostream>
#include <string>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    
    long long score = 0;
    string result;
    
    if (a > b) {
        int blocks = b + 1;
        int oPerBlock = a / blocks;
        int extraOs = a % blocks;
        
        for (int i = 0; i < blocks; ++i) {
            int currentOs = oPerBlock + (i < extraOs);
            score += currentOs * currentOs;
            result.append(currentOs, 'o');
            if (i < b) result += 'x';
        }
    } else {
        int blocks = a + 1;
        int xPerBlock = b / blocks;
        int extraXs = b % blocks;
        
        for (int i = 0; i < blocks; ++i) {
            int currentXs = xPerBlock + (i < extraXs);
            score -= currentXs * currentXs;
            result.append(currentXs, 'x');
            if (i < a) result += 'o';
        }
    }
    
    cout << score << endl << result << endl;
}