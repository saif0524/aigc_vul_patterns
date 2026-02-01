#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n;
    while (cin >> n && n != 0) {
        vector<string> words(n);
        for (int i = 0; i < n; ++i) {
            cin >> words[i];
        }

        bool found = false;
        for (int i = 0; i < n; ++i) {
            if (i + 4 < n) {
                int sum1 = 0;
                int sum2 = 0;
                int sum3 = 0;
                int sum4 = 0;
                int sum5 = 0;
                int count1 = 0;
                int count2 = 0;
                int count3 = 0;
                int count4 = 0;
                int count5 = 0;

                for (int j = i; j < n; ++j) {
                    if (sum1 < 5) {
                        sum1 += words[j].length();
                        count1++;
                        if (sum1 == 5) {
                            break;
                        }
                    }
                }

                if (sum1 != 5) continue;
                
                for (int j = i + count1; j < n; ++j) {
                    if (sum2 < 7) {
                        sum2 += words[j].length();
                        count2++;
                        if (sum2 == 7) {
                            break;
                        }
                    }
                }

                if (sum2 != 7) continue;

                for (int j = i + count1 + count2; j < n; ++j) {
                    if (sum3 < 5) {
                        sum3 += words[j].length();
                        count3++;
                        if (sum3 == 5) {
                            break;
                        }
                    }
                }

                if (sum3 != 5) continue;

                for (int j = i + count1 + count2 + count3; j < n; ++j) {
                    if (sum4 < 7) {
                        sum4 += words[j].length();
                        count4++;
                        if (sum4 == 7) {
                            break;
                        }
                    }
                }

                if (sum4 != 7) continue;

                for (int j = i + count1 + count2 + count3 + count4; j < n; ++j) {
                    if (sum5 < 7) {
                        sum5 += words[j].length();
                        count5++;
                        if (sum5 == 7) {
                            break;
                        }
                    }
                }

                if (sum5 != 7) continue;
                
                if (count1 + count2 + count3 + count4 + count5 <= n) {
                    cout << i + 1 << endl;
                    found = true;
                    break;
                }
            }
        }
    }

    return 0;
}