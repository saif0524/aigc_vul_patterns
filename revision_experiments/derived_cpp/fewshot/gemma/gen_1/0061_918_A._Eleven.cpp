#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> fibonacci;
    fibonacci.push_back(1);
    fibonacci.push_back(1);

    int next_fib = 0;
    while (next_fib <= n) {
        next_fib = fibonacci[fibonacci.size() - 1] + fibonacci[fibonacci.size() - 2];
        if (next_fib <= n) {
            fibonacci.push_back(next_fib);
        }
    }

    string name = "";
    for (int i = 1; i <= n; ++i) {
        bool is_fib = false;
        for (int j = 0; j < fibonacci.size(); ++j) {
            if (fibonacci[j] == i) {
                is_fib = true;
                break;
            }
        }

        if (is_fib) {
            name += 'O';
        } else {
            name += 'o';
        }
    }

    cout << name << endl;

    return 0;
}