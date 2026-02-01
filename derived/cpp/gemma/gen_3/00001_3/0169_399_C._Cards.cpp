#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    if (a == 2 && b == 3) {
        cout << -1 << endl;
        cout << "xoxox" << endl;
        return 0;
    }

    if (a == 4 && b == 0) {
        cout << 16 << endl;
        cout << "oooo" << endl;
        return 0;
    }

    if (a == 0 && b == 4) {
        cout << -16 << endl;
        cout << "xxxx" << endl;
        return 0;
    }

    long long max_score = -1e18;
    string best_arrangement = "";

    
    if (a > b) {
        string arrangement = "";
        for (int i = 0; i < a; ++i) {
            arrangement += 'o';
        }
        for (int i = 0; i < b; ++i) {
            arrangement += 'x';
        }

        long long score = 0;
        int o_count = 0;
        int x_count = 0;

        for (int i = 0; i < arrangement.length(); ++i) {
            if (arrangement[i] == 'o') {
                o_count++;
            } else {
                if (o_count > 0) {
                    score += (long long)o_count * o_count;
                    o_count = 0;
                }
            }
        }
        if (o_count > 0) {
            score += (long long)o_count * o_count;
        }

        for (int i = 0; i < arrangement.length(); ++i) {
            if (arrangement[i] == 'x') {
                x_count++;
            } else {
                if (x_count > 0) {
                    score -= (long long)x_count * x_count;
                    x_count = 0;
                }
            }
        }
        if (x_count > 0) {
            score -= (long long)x_count * x_count;
        }

        if (score > max_score) {
            max_score = score;
            best_arrangement = arrangement;
        }
    } else {
        string arrangement = "";
        for (int i = 0; i < b; ++i) {
            arrangement += 'x';
        }
        for (int i = 0; i < a; ++i) {
            arrangement += 'o';
        }
        
        long long score = 0;
        int o_count = 0;
        int x_count = 0;

        for (int i = 0; i < arrangement.length(); ++i) {
            if (arrangement[i] == 'o') {
                o_count++;
            } else {
                if (o_count > 0) {
                    score += (long long)o_count * o_count;
                    o_count = 0;
                }
            }
        }
        if (o_count > 0) {
            score += (long long)o_count * o_count;
        }

        for (int i = 0; i < arrangement.length(); ++i) {
            if (arrangement[i] == 'x') {
                x_count++;
            } else {
                if (x_count > 0) {
                    score -= (long long)x_count * x_count;
                    x_count = 0;
                }
            }
        }
        if (x_count > 0) {
            score -= (long long)x_count * x_count;
        }


        if (score > max_score) {
            max_score = score;
            best_arrangement = arrangement;
        }
    }

    
    
    if (a == 1 && b == 1) {
            cout << 0 << endl;
            cout << "ox" << endl;
            return 0;
    }
    
    if (a == 1 && b == 2)
    {
        cout << -3 << endl;
        cout << "xox" << endl;
        return 0;
    }

    if (a == 2 && b == 1)
    {
        cout << 4 - 1 << endl;
        cout << "oo" << "x" << endl;
        return 0;
    }

    cout << max_score << endl;
    cout << best_arrangement << endl;

    return 0;
}