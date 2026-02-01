#include <iostream>
#include <vector>

const int N = 1001;

int fib(int i) {
    if (i <= 1) return 1;
    int a = 1, b = 1;
    for (int j = 2; j <= i; j++) {
        int temp = (a + b) % N;
        a = b;
        b = temp;
    }
    return b;
}

int main() {
    int v, d;
    while (std::cin >> v >> d) {
        std::vector<int> f(v + 1);
        std::vector<int> parent(v + 1);
        for (int i = 1; i <= v; i++) {
            f[i] = fib(i);
            parent[i] = i;
        }
        for (int i = 1; i <= v; i++) {
            for (int j = i + 1; j <= v; j++) {
                if (std::abs(f[i] - f[j]) < d) {
                    int x = i, y = j;
                    while (parent[x] != x) x = parent[x];
                    while (parent[y] != y) y = parent[y];
                    if (x != y) parent[y] = x;
                }
            }
        }
        int count = 0;
        for (int i = 1; i <= v; i++) {
            if (parent[i] == i) count++;
        }
        std::cout << count << std::endl;
    }
    return 0;
}