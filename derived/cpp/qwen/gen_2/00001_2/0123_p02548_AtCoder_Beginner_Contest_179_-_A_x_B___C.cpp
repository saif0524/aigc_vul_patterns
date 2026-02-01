#include <iostream>
using namespace std;

int main() {
    long long N;
    cin >> N;
    long long count = 0;
    for(long long A = 1; A <= N - 1; ++A) {
        long long rem = N - A;
        if(rem <= 0) break;
        count += rem - 1;
    }
    cout << count << endl;
    return 0;
}