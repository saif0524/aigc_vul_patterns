#include <iostream>
using namespace std;

int main() {
    long long N;
    cin >> N;
    long long count = 0;
    for (long long A = 1; A <= N - 1; ++A) {
        for (long long B = 1; A * B < N; ++B) {
            count++;
        }
    }
    cout << count;
    return 0;
}