#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> psychos(n);
    for (int i = 0; i < n; i++) {
        std::cin >> psychos[i];
    }

    int steps = 0;
    bool changed;

    do {
        changed = false;
        std::vector<int> newPsychos;

        for (int i = 0; i < psychos.size(); i++) {
            bool killed = false;
            if (i < psychos.size() - 1 && psychos[i] > psychos[i + 1]) {
                newPsychos.push_back(psychos[i]);
                killed = true;
            }
            if (i == psychos.size() - 1 || !killed) {
                if (i < psychos.size() - 1 && psychos[i] < psychos[i + 1]) {
                    newPsychos.push_back(psychos[i + 1]);
                    changed = true;
                } else if (i == psychos.size() - 1) {
                    newPsychos.push_back(psychos[i]);
                }
            }
        }

        psychos = newPsychos;
        if (changed) {
            steps++;
        }
    } while (changed);

    std::cout << steps << std::endl;

    return 0;
}