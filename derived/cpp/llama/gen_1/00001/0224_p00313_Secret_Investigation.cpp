#include <iostream>
#include <set>

int main() {
    int N;
    std::cin >> N;

    int X;
    std::cin >> X;
    std::set<int> A;
    for (int i = 0; i < X; i++) {
        int ai;
        std::cin >> ai;
        A.insert(ai);
    }

    int Y;
    std::cin >> Y;
    std::set<int> B;
    for (int i = 0; i < Y; i++) {
        int bi;
        std::cin >> bi;
        B.insert(bi);
    }

    int Z;
    std::cin >> Z;
    std::set<int> C;
    for (int i = 0; i < Z; i++) {
        int ci;
        std::cin >> ci;
        C.insert(ci);
    }

    std::set<int> result;
    for (int i = 1; i <= N; i++) {
        if ((A.find(i) == A.end() && C.find(i) != C.end()) || (B.find(i) != B.end() && C.find(i) != C.end())) {
            result.insert(i);
        }
    }

    std::cout << result.size() << std::endl;
    return 0;
}