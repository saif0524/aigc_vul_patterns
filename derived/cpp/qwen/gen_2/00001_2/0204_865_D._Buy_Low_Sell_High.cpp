#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> prices(N);
    for (int &p : prices) cin >> p;
    
    int maxProfit = 0;
    for (int i = 1; i < N; ++i) {
        if (prices[i] > prices[i - 1]) {
            maxProfit += prices[i] - prices[i - 1];
        }
    }
    
    cout << maxProfit << endl;
    return 0;
}