#include <bits/stdc++.h>

#define MAX_A 10000
#define MAX_B 30

int a, b, n;
int cache[MAX_A + 1][MAX_B + 1];

int pow(int x, int e) {
    if (e == 0) return 1;
    if (e % 2 == 1) return x * pow(x, e - 1);
    return pow(x * x, e / 2);
}

bool win(int a, int b) {
    if (cache[a][b] != 0) return cache[a][b] == 1;

    bool result = !(
        (!win(a + 1, b) || b == 1 && !win(a, b + 1))
        && (b > 1 && !win(a, b + 1) || !win(a + 1, b))
    );

    cache[a][b] = result ? 1 : -1;
    return result;
}

void solve() {
    std::cin >> a >> b >> n;

    if (pow(a, b) >= n) {
        std::cout << "Missing" << std::endl;
        return;
    }

    if (win(a, b)) {
        std::cout << "Stas" << std::endl;
    } else {
        std::cout << "Masha" << std::endl;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}