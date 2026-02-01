#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (gcd(a[i], a[j]) > 1) {
                int root = a[i];
                vector<int> left, right;
                for (int k = 0; k < n; k++) {
                    if (k!= i && k!= j) {
                        if (a[k] < root) {
                            left.push_back(a[k]);
                        } else {
                            right.push_back(a[k]);
                        }
                    }
                }

                bool possible = true;
                for (int k = 0; k < left.size(); k++) {
                    if (gcd(left[k], root) <= 1) {
                        possible = false;
                        break;
                    }
                }
                for (int k = 0; k < right.size(); k++) {
                    if (gcd(right[k], root) <= 1) {
                        possible = false;
                        break;
                    }
                }

                if (possible) {
                    bool leftPossible = true;
                    for (int k = 0; k < left.size(); k++) {
                        for (int l = k + 1; l < left.size(); l++) {
                            if (gcd(left[k], left[l]) > 1) {
                                leftPossible = false;
                                break;
                            }
                        }
                        if (!leftPossible) break;
                    }

                    bool rightPossible = true;
                    for (int k = 0; k < right.size(); k++) {
                        for (int l = k + 1; l < right.size(); l++) {
                            if (gcd(right[k], right[l]) > 1) {
                                rightPossible = false;
                                break;
                            }
                        }
                        if (!rightPossible) break;
                    }

                    if (leftPossible && rightPossible) {
                        cout << "Yes" << endl;
                        return 0;
                    }
                }

                swap(a[i], a[j]);
                root = a[i];
                left.clear();
                right.clear();
                for (int k = 0; k < n; k++) {
                    if (k!= i && k!= j) {
                        if (a[k] < root) {
                            left.push_back(a[k]);
                        } else {
                            right.push_back(a[k]);
                        }
                    }
                }

                possible = true;
                for (int k = 0; k < left.size(); k++) {
                    if (gcd(left[k], root) <= 1) {
                        possible = false;
                        break;
                    }
                }
                for (int k = 0; k < right.size(); k++) {
                    if (gcd(right[k], root) <= 1) {
                        possible = false;
                        break;
                    }
                }

                if (possible) {
                    leftPossible = true;
                    for (int k = 0; k < left.size(); k++) {
                        for (int l = k + 1; l < left.size(); l++) {
                            if (gcd(left[k], left[l]) > 1) {
                                leftPossible = false;
                                break;
                            }
                        }
                        if (!leftPossible) break;
                    }

                    rightPossible = true;
                    for (int k = 0; k < right.size(); k++) {
                        for (int l = k + 1; l < right.size(); l++) {
                            if (gcd(right[k], right[l]) > 1) {
                                rightPossible = false;
                                break;
                            }
                        }
                        if (!rightPossible) break;
                    }

                    if (leftPossible && rightPossible) {
                        cout << "Yes" << endl;
                        return 0;
                    }
                }
            }
        }
    }

    cout << "No" << endl;
    return 0;
}