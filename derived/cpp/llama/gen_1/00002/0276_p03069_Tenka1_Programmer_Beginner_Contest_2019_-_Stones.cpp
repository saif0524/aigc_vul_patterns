#include <iostream>
#include <string>
using namespace std;

int main() {
    int N;
    string S;

    cin >> N >> S;

    int count = 0;
    for(int i = 0; i < N - 1; i++) {
        if(S[i] == '#' && S[i + 1] == '.') {
            count++;
        }
    }

    int minCount = count;
    for(int i = 0; i < N; i++) {
        if(S[i] == '#') {
            count++;
        } else {
            count--;
        }
        minCount = min(minCount, count);
    }

    cout << minCount << endl;

    return 0;
}