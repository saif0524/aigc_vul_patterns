#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    string result;
    if (n >= m) {
        while (n >0|| m > 0) {
            if (n > 0) { result += 'B'; n--; }
            if (m > 0) { result += 'G'; m--; }
        }
    } else {
        while (n >0|| m > 0) {
            if (m > 0) { result += 'G'; m--; }
            if (n > 0) { result += 'B'; n--; }
        }
    }
    
    cout << result << endl;
    return 0;
}