#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> H(N);
    for (int i = 0; i < N; ++i) {
        cin >> H[i];
    }
    
    int count = 0;
    int max_height = 0;
    for (int i = 0; i < N; ++i) {
        if (H[i] >= max_height) {
            ++count;
            max_height = H[i];
        }
    }
    
    cout << count << endl;
    
    return 0;
}