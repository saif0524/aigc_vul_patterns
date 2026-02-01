#include <iostream>
#include <string>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    long long score = 0;
    string result;

    if (a >= b) {
        int blocks = b + 1;
        int remaining_o = a - (blocks - 1);
        for (int i = 0; i < blocks; ++i) {
            if (i < b) {
                result += "x";
                score -= 1;
            }
            int o_in_block = (i < remaining_o) ? (a / blocks + 1) : (a / blocks);
            result.append(o_in_block, 'o');
            score += o_in_block * o_in_block;
        }
    } else {
        int blocks = a + 1;
        int remaining_x = b - (blocks - 1);
        for (int i = 0; i < blocks; ++i) {
            if (i < a) {
                result += "o";
                score += 1;
            }
            int x_in_block = (i < remaining_x) ? (b / blocks + 1) : (b / blocks);
            result.append(x_in_block, 'x');
            score -= x_in_block * x_in_block;
        }
    }

    cout << score << "\n" << result << "\n";
    return 0;
}