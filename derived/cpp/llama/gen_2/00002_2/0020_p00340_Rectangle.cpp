#include <iostream>
#include <algorithm>

int main() {
    int e1, e2, e3, e4;
    std::cin >> e1 >> e2 >> e3 >> e4;

    int arr[4] = {e1, e2, e3, e4};
    std::sort(arr, arr + 4);

    if ((arr[0] == arr[1]) && (arr[2] == arr[3])) {
        std::cout << "yes";
    } else {
        std::cout << "no";
    }

    return 0;
}