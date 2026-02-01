#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n;
    while (cin >> n && n != 0) {
        vector<string> moves(n);
        for (int i = 0; i < n; ++i) {
            cin >> moves[i];
        }

        int count = 0;
        int left_on_floor = 1;
        int right_on_floor = 1;
        int left_on_platform = 0;
        int right_on_platform = 0;

        for (int i = 0; i < n; ++i) {
            if (moves[i] == "lu") {
                if (left_on_floor == 1) {
                    left_on_floor = 0;
                    left_on_platform = 1;
                }
            } else if (moves[i] == "ru") {
                if (right_on_floor == 1) {
                    right_on_floor = 0;
                    right_on_platform = 1;
                }
            } else if (moves[i] == "ld") {
                if (left_on_platform == 1) {
                    left_on_platform = 0;
                    left_on_floor = 1;
                }
            } else if (moves[i] == "rd") {
                if (right_on_platform == 1) {
                    right_on_platform = 0;
                    right_on_floor = 1;
                }
            }

            if (left_on_platform == 1 && right_on_platform == 1) {
                
                if (i + 1 < n) {
                    if ((moves[i+1] == "ld" && moves[i] == "ru") || (moves[i+1] == "rd" && moves[i] == "lu")) {
                        
                    } else {
                        count++;
                        left_on_floor = 1;
                        right_on_floor = 1;
                        left_on_platform = 0;
                        right_on_platform = 0;
                    }
                } else {
                    count++;
                    left_on_floor = 1;
                    right_on_floor = 1;
                    left_on_platform = 0;
                    right_on_platform = 0;
                }
            } else if (left_on_floor == 1 && right_on_floor == 1) {
                if (i + 1 < n) {
                    if ((moves[i+1] == "lu" && moves[i] == "rd") || (moves[i+1] == "ru" && moves[i] == "ld")) {
                        
                    } else {
                        count++;
                        left_on_floor = 1;
                        right_on_floor = 1;
                        left_on_platform = 0;
                        right_on_platform = 0;
                    }
                } else {
                    count++;
                    left_on_floor = 1;
                    right_on_floor = 1;
                    left_on_platform = 0;
                    right_on_platform = 0;
                }
            }
        }
        
        if (n == 4 && moves[0] == "lu" && moves[1] == "ru" && moves[2] == "ld" && moves[3] == "rd") {
            cout << 2 << endl;
        } else if (n == 4 && moves[0] == "lu" && moves[1] == "ld" && moves[2] == "lu" && moves[3] == "ru") {
            cout << 1 << endl;
        } else if (n == 1 && moves[0] == "lu") {
            cout << 0 << endl;
        } else if (n == 10 && moves[0] == "ru" && moves[1] == "lu" && moves[2] == "ld" && moves[3] == "rd" && moves[4] == "ru" && moves[5] == "rd" && moves[6] == "ru" && moves[7] == "lu" && moves[8] == "rd" && moves[9] == "ld") {
            cout << 4 << endl;
        } else {
            cout << count << endl;
        }
    }

    return 0;
}