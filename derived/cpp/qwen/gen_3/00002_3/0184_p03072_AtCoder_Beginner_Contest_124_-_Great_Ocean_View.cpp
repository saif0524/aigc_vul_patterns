#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> H(N);
    for(int i = 0; i < N; ++i) {
        cin >> H[i];
    }
    int count = 1, max_height = H[0];
    for(int i = 1; i < N; ++i) {
        if(H[i] >= max_height) {
            ++count;
            max_height = H[i];
        }
    }
    cout << count;
    return 0;
}