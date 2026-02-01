#include <iostream>
#include <string>
#include <algorithm>

std::string reverse(const std::string& str) {
    std::string result = str;
    std::reverse(result.begin(), result.end());
    return result;
}

std::string rotate_left(const std::string& str) {
    std::string result = str;
    std::rotate(result.begin(), result.begin() + 1, result.end());
    return result;
}

std::string rotate_right(const std::string& str) {
    std::string result = str;
    std::rotate(result.rbegin(), result.rbegin() + 1, result.rend());
    return result;
}

std::string swap_halves(const std::string& str) {
    std::string result = str;
    int mid = (str.size() + 1) / 2;
    std::swap_ranges(result.begin(), result.begin() + mid, result.begin() + str.size() - mid);
    return result;
}

std::string increment_digits(const std::string& str) {
    std::string result;
    for (char c : str) {
        if (isdigit(c)) {
            result += (c == '9') ? '0' : c + 1;
        } else {
            result += c;
        }
    }
    return result;
}

std::string decrement_digits(const std::string& str) {
    std::string result;
    for (char c : str) {
        if (isdigit(c)) {
            result += (c == '0') ? '9' : c - 1;
        } else {
            result += c;
        }
    }
    return result;
}

std::string apply_reverse(const std::string& str) {
    return reverse(str);
}

std::string apply_rotate_left(const std::string& str) {
    return rotate_right(str);
}

std::string apply_rotate_right(const std::string& str) {
    return rotate_left(str);
}

std::string apply_swap_halves(const std::string& str) {
    return swap_halves(str);
}

std::string apply_increment_digits(const std::string& str) {
    return decrement_digits(str);
}

std::string apply_decrement_digits(const std::string& str) {
    return increment_digits(str);
}

std::string apply_transformation(char messenger, const std::string& str) {
    switch (messenger) {
        case 'J': return apply_rotate_left(str);
        case 'C': return apply_rotate_right(str);
        case 'E': return apply_swap_halves(str);
        case 'A': return apply_reverse(str);
        case 'P': return apply_increment_digits(str);
        case 'M': return apply_decrement_digits(str);
        default: return str; // Invalid messenger
    }
}

int main() {
    int n;
    std::cin >> n;
    while (n--) {
        std::string order, message;
        std::cin >> order >> message;
        for (auto it = order.rbegin(); it != order.rend(); ++it) {
            message = apply_transformation(*it, message);
        }
        std::cout << message << std::endl;
    }
    return 0;
}