#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    int a, b, h, w, n;
    cin >> a >> b >> h >> w >> n;
    vector<int> extensions(n);
    for (int i = 0; i < n; i++) {
        cin >> extensions[i];
    }

    sort(extensions.begin(), extensions.end(), greater<int>());

    int minExtensions = INT_MAX;
    {
        long long currentH = h;
        long long currentW = w;
        int usedExtensions = 0;
        for (int extension : extensions) {
            if (currentH >= a && currentW >= b) {
                minExtensions = min(minExtensions, usedExtensions);
                break;
            }
            if (currentH < a && currentW < b) {
                if (b * extension <= w) {
                    currentW *= extension;
                } else if (a * extension <= h) {
                    currentH *= extension;
                } else {
                    break;
                }
            } else if (currentH < a) {
                if (a * extension <= h) {
                    currentH *= extension;
                }
            } else if (currentW < b) {
                if (b * extension <= w) {
                    currentW *= extension;
                }
            }
            usedExtensions++;
        }
        if (currentH >= a && currentW >= b) {
            minExtensions = min(minExtensions, usedExtensions);
        }
    }
    {
        long long currentH = h;
        long long currentW = w;
        int usedExtensions = 0;
        for (int extension : extensions) {
            if (currentH >= b && currentW >= a) {
                minExtensions = min(minExtensions, usedExtensions);
                break;
            }
            if (currentH < b && currentW < a) {
                if (a * extension <= w) {
                    currentW *= extension;
                } else if (b * extension <= h) {
                    currentH *= extension;
                } else {
                    break;
                }
            } else if (currentH < b) {
                if (b * extension <= h) {
                    currentH *= extension;
                }
            } else if (currentW < a) {
                if (a * extension <= w) {
                    currentW *= extension;
                }
            }
            usedExtensions++;
        }
        if (currentH >= b && currentW >= a) {
            minExtensions = min(minExtensions, usedExtensions);
        }
    }

    if (h >= a && w >= b) {
        cout << 0 << endl;
    } else if (h >= b && w >= a) {
        cout << 0 << endl;
    } else if (minExtensions == INT_MAX) {
        cout << -1 << endl;
    } else {
        cout << minExtensions << endl;
    }

    return 0;
}