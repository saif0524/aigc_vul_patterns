#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        int mexA = 0, mexB = 0;
        vector<int> A, B;
        for (int i = 0; i < n; i++) {
            if (a[i] == mexA) {
                A.push_back(a[i]);
                while (i + 1 < n && a[i + 1] == a[i]) {
                    i++;
                }
                mexA++;
            } else if (a[i] == mexB) {
                B.push_back(a[i]);
                while (i + 1 < n && a[i + 1] == a[i]) {
                    i++;
                }
                mexB++;
            } else {
                if (mexA < mexB) {
                    A.push_back(a[i]);
                    while (i + 1 < n && a[i + 1] == a[i]) {
                        i++;
                    }
                    mexA++;
                } else {
                    B.push_back(a[i]);
                    while (i + 1 < n && a[i + 1] == a[i]) {
                        i++;
                    }
                    mexB++;
                }
            }
        }
        cout << mexA + mexB << endl;
    }
    return 0;
}