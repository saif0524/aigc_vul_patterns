#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

std::vector<int> getDiffArr(const std::string& s) {
    std::vector<int> diff(s.size() + 1, 0);
    for (int i = 0; i < s.size(); ++i) {
        diff[i + 1] = diff[i];
        if (s[i] == '0') {
            diff[i + 1]--;
        } else if (s[i] == '1') {
            diff[i + 1]++;
        }
    }
    return diff;
}

std::vector<std::vector<int>> getDiffArrs(const std::string& s) {
    std::vector<std::vector<int>> diffArrs(2, std::vector<int>(s.size() + 1, 0));
    for (int i = 0; i < s.size(); ++i) {
        diffArrs[0][i + 1] = diffArrs[0][i];
        diffArrs[1][i + 1] = diffArrs[1][i];
        if (s[i] == '0') {
            diffArrs[0][i + 1]--;
        } else if (s[i] == '1') {
            diffArrs[1][i + 1]++;
        }
    }
    return diffArrs;
}

int getMinUnbalancedness(const std::string& s) {
    std::vector<std::vector<int>> diffArrs = getDiffArrs(s);
    std::vector<std::vector<int>> numArrs(2, std::vector<int>(s.size() + 1, 0));
    for (int i = 0; i < s.size(); ++i) {
        numArrs[0][i + 1] = numArrs[0][i];
        numArrs[1][i + 1] = numArrs[1][i];
        if (s[i] == '?') {
            numArrs[0][i + 1]++;
            numArrs[1][i + 1]++;
        }
    }
    int minUnbalancedness = s.size();
    for (int l = 0; l < s.size(); ++l) {
        for (int r = l; r < s.size(); ++r) {
            int diff0 = diffArrs[0][r + 1] - diffArrs[0][l];
            int diff1 = diffArrs[1][r + 1] - diffArrs[1][l];
            int num0 = numArrs[0][r + 1] - numArrs[0][l];
            int num1 = numArrs[1][r + 1] - numArrs[1][l];
            int min = std::max(diff0, diff1);
            min = std::min(min, std::max(num0 - diff0, num1 + diff1));
            min = std::min(min, std::max(num0 + diff0, num1 - diff1));
            minUnbalancedness = std::min(minUnbalancedness, min);
        }
    }
    return minUnbalancedness;
}

int main() {
    std::string s;
    std::cin >> s;
    std::cout << getMinUnbalancedness(s) << std::endl;
    return 0;
}