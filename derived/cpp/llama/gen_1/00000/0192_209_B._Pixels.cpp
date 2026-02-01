#include <iostream>
#include <algorithm>

int main() {
    long long int a, b, c;
    std::cin >> a >> b >> c;

    long long int arr[3] = {a, b, c};
    std::sort(arr, arr + 3);

    if (arr[0] % 2 == arr[1] % 2 && arr[1] % 2 == arr[2] % 2) {
        std::cout << arr[1] << std::endl;
    } else if (arr[0] % 2 == arr[1] % 2) {
        std::cout << arr[1] << std::endl;
    } else if (arr[0] % 2 == arr[2] % 2) {
        std::cout << arr[2] << std::endl;
    } else {
        std::cout << arr[2] << std::endl;
    }

    return 0;
}