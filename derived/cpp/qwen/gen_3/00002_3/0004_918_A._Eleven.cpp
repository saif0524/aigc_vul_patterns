#include <iostream>
#include <vector>

using namespace std;

vector<int> fibonacci(int n) {
    vector<int> fib;
    int a = 1, b = 1;
    fib.push_back(a);
    while (b <= n) {
        fib.push_back(b);
        int next = a + b;
        a = b;
        b = next;
    }
    return fib;
}

int main() {
    int n;
    cin >> n;
    vector<int> fib = fibonacci(n);
    for (int i = 1; i <= n; ++i) {
        if (find(fib.begin(), fib.end(), i) != fib.end()) {
            cout << 'O';
        } else {
            cout << 'o';
        }
    }
    cout << endl;
    return 0;
}