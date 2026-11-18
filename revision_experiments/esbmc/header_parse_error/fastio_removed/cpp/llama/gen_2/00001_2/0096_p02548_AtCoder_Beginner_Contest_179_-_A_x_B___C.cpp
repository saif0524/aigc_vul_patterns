#include <iostream>
using namespace std;

int main() {
    ((void)0);
    ((void)0);

    int N;
    cin >> N;

    long long ans = 0;
    for(int a = 1; a * a <= N; ++a) {
        for(int b = 1; a * b <= N; ++b) {
            if ((N - a * b) > 0) {
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}