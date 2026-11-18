// [esbmc] replaced #include <bits/stdc++.h> with ESBMC-compatible headers
#include <cassert>
#include <cctype>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdint>
#include <cinttypes>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <istream>
#include <ostream>
#include <ios>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <streambuf>
#include <string>
#include <string_view>
#include <vector>
#include <array>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <algorithm>
#include <numeric>
#include <functional>
#include <utility>
#include <iterator>
#include <memory>
#include <tuple>
#include <limits>
#include <random>
#include <complex>
#include <valarray>
#include <stdexcept>
#include <exception>
#include <typeinfo>
#include <type_traits>
#include <initializer_list>
#include <numbers>
#include <any>
using namespace std;

int main() {
    unordered_map<int, char> pager_code = {
        {11, 'a'}, {12, 'b'}, {13, 'c'}, {14, 'd'},
        {15, 'e'}, {16, 'f'}, {17, 'g'}, {18, 'h'},
        {19, 'i'}, {21, 'j'}, {22, 'k'}, {23, 'l'},
        {24, 'm'}, {25, 'n'}, {26, 'o'}, {27, 'p'},
        {28, 'q'}, {29, 'r'}, {31, 's'}, {32, 't'},
        {33, 'u'}, {34, 'v'}, {35, 'w'}, {36, 'x'},
        {37, 'y'}, {38, 'z'}, {41, '.'}, {42, '?'},
        {43, '!'}, {44, ' '}, {51, 'A'}, {52, 'B'},
        {53, 'C'}, {54, 'D'}, {55, 'E'}, {56, 'F'},
        {57, 'G'}, {58, 'H'}, {59, 'I'}
    };

    string msg;
    while (getline(cin, msg)) {
        string result = "";
        bool valid = true;

        if (msg.length() % 2 != 0) {
            cout << "NA" << endl;
            continue;
        }

        for (int i = 0; i < msg.length(); i += 2) {
            int code = (msg[i] - '0') * 10 + (msg[i + 1] - '0');
            if (pager_code.find(code) != pager_code.end()) {
                result += pager_code[code];
            } else {
                valid = false;
                break;
            }
        }

        if (!valid) {
            cout << "NA" << endl;
        } else {
            cout << result << endl;
        }
    }

    return 0;
}