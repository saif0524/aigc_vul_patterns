#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int N;
    while (cin >> N) {
        if (N == 0) break;
        vector<string> words(N);
        for (int i = 0; i < N; ++i) {
            cin >> words[i];
        }
        for (int start = 0; start < N; ++start) {
            int len = 0;
            for (int i = start; i < N; ++i) {
                len += words[i].length();
                if (len == 5) {
                    len = 0;
                    int secondStart = i + 1;
                    for (int j = secondStart; j < N; ++j) {
                        len += words[j].length();
                        if (len == 7) {
                            len = 0;
                            int thirdStart = j + 1;
                            for (int k = thirdStart; k < N; ++k) {
                                len += words[k].length();
                                if (len == 5) {
                                    len = 0;
                                    int fourthStart = k + 1;
                                    for (int m = fourthStart; m < N; ++m) {
                                        len += words[m].length();
                                        if (len == 7) {
                                            len = 0;
                                            int fifthStart = m + 1;
                                            for (int n = fifthStart; n < N; ++n) {
                                                len += words[n].length();
                                                if (len == 7) {
                                                    cout << start + 1 << endl;
                                                    goto nextTest;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        nextTest:;
    }
    return 0;
}