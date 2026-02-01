#include <iostream>
#include <string>

std::string multiply(const std::string& s, const std::string& t) {
    std::string result;
    for (char c : s) {
        result += t;
        result += c;
    }
    result += t;
    return result;
}

int beauty(const std::string& s) {
    int maxBeauty = 0;
    int currentBeauty = 1;
    for (int i = 1; i < s.size(); ++i) {
        if (s[i] == s[i - 1]) {
            currentBeauty++;
        } else {
            maxBeauty = std::max(maxBeauty, currentBeauty);
            currentBeauty = 1;
        }
    }
    maxBeauty = std::max(maxBeauty, currentBeauty);
    return maxBeauty;
}

int beautyOfProduct(const std::string& s, const std::string& t) {
    int maxBeauty = 0;
    int currentBeauty = 1;
    std::string result;
    for (char c : s) {
        result += t;
        result += c;
    }
    result += t;
    for (int i = 1; i < result.size(); ++i) {
        if (result[i] == result[i - 1]) {
            currentBeauty++;
        } else {
            maxBeauty = std::max(maxBeauty, currentBeauty);
            currentBeauty = 1;
        }
    }
    maxBeauty = std::max(maxBeauty, currentBeauty);
    return maxBeauty;
}

int main() {
    int n;
    std::cin >> n;
    std::string p[n];
    for (int i = 0; i < n; ++i) {
        std::cin >> p[i];
    }
    std::string product = p[0];
    for (int i = 1; i < n; ++i) {
        product = multiply(product, p[i]);
        if (product.size() > 1000000) {
            break;
        }
    }
    int maxBeauty = 0;
    for (int i = 0; i < product.size(); ++i) {
        int currentBeauty = 0;
        char c = product[i];
        while (i < product.size() && product[i] == c) {
            currentBeauty++;
            i++;
        }
        maxBeauty = std::max(maxBeauty, currentBeauty);
        i--;
    }
    std::cout << maxBeauty << std::endl;
    return 0;
}