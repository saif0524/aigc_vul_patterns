#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> m(5), w(5);
    int hs, hu;
    for (int &x : m) cin >> x;
    for (int &x : w) cin >> x;
    cin >> hs >> hu;
    
    int score = 0;
    vector<int> points = {500, 1000, 1500, 2000, 2500};
    for (int i = 0; i < 5; ++i) {
        score += points[i] * (1 - m[i] / 250.0) - 50 * w[i];
    }
    score += 100 * hs - 50 * hu;
    
    cout << score;
}