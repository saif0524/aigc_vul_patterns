#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

std::string longestPalindromicSubsequence(const std::string& s) {
    std::string ans = "";
    for (char c = 'a'; c <= 'z'; ++c) {
        std::vector<int> indices;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == c) {
                indices.push_back(i);
            }
        }
        if (indices.size() >= 100) {
            for (int i = 0; i < 50; ++i) {
                ans += c;
            }
            for (int i = 49; i >= 0; --i) {
                ans += c;
            }
            return ans;
        }
        std::string temp(1, c);
        for (int i = 1; i < indices.size(); ++i) {
            temp += c;
            std::string remaining = s.substr(indices[i] + 1);
            for (char d = 'a'; d <= 'z'; ++d) {
                std::vector<int> innerIndices;
                for (int j = 0; j < remaining.size(); ++j) {
                    if (remaining[j] == d) {
                        innerIndices.push_back(j);
                    }
                }
                if (innerIndices.size() >= 100 - temp.size() - 1) {
                    for (int j = 0; j < 50 - temp.size() / 2; ++j) {
                        temp += d;
                    }
                    for (int j = 49 - temp.size() / 2; j >= 0; --j) {
                        temp += d;
                    }
                    if (temp.size() == 100) {
                        return temp;
                    }
                }
                if (innerIndices.size() >= 1) {
                    temp += d;
                    for (char e = 'a'; e <= 'z'; ++e) {
                        std::vector<int> innerInnerIndices;
                        for (int k = 0; k < remaining.substr(innerIndices[0] + 1).size(); ++k) {
                            if (remaining.substr(innerIndices[0] + 1)[k] == e) {
                                innerInnerIndices.push_back(k);
                            }
                        }
                        if (innerInnerIndices.size() >= 100 - temp.size() - 1) {
                            for (int k = 0; k < 50 - temp.size() / 2; ++k) {
                                temp += e;
                            }
                            for (int k = 49 - temp.size() / 2; k >= 0; --k) {
                                temp += e;
                            }
                            if (temp.size() == 100) {
                                return temp;
                            }
                        }
                    }
                    temp.pop_back();
                }
            }
            temp.pop_back();
        }
        if (ans.size() < temp.size() * 2 + 1) {
            ans = temp;
            for (int i = temp.size() - 1; i >= 0; --i) {
                ans += temp[i];
            }
        }
    }
    return ans;
}

int main() {
    std::string s;
    std::cin >> s;
    std::cout << longestPalindromicSubsequence(s) << std::endl;
    return 0;
}