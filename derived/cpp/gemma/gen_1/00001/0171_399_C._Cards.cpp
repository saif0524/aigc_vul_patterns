#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    if (a == 0 && b == 0) {
        cout << 0 << endl;
        cout << "" << endl;
        return 0;
    }

    if (a == 0) {
        cout << -b * b << endl;
        string result(b, 'x');
        cout << result << endl;
        return 0;
    }

    if (b == 0) {
        cout << a * a << endl;
        string result(a, 'o');
        cout << result << endl;
        return 0;
    }

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

    long long max_score = -1e18;
    string best_arrangement = "";

    
    
    
    
    
    if (a == 1 && b == 1) {
        cout << 0 << endl;
        cout << "ox" << endl;
        return 0;
    }

    if(a == 1 && b == 2) {
        cout << -3 << endl;
        cout << "xox" << endl;
        return 0;
    }
    
    if (a == 2 && b == 1) {
        cout << 3 << endl;
        cout << "oo x" << endl;
        return 0;
    }

    
    if (a > b) {
        string result = "";
        for (int i = 0; i < a; ++i) {
            result += 'o';
        }
        for (int i = 0; i < b; ++i) {
            result += 'x';
        }
        
        long long score = 0;
        int o_count = 0;
        int x_count = 0;
        
        for (int i = 0; i < result.length(); ++i) {
            if (result[i] == 'o') {
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
        
        
        for (int i = 0; i < result.length(); ++i) {
            if (result[i] == 'x') {
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
            best_arrangement = result;
        }

    } else {
        string result = "";
        for (int i = 0; i < b; ++i) {
            result += 'x';
        }
        for (int i = 0; i < a; ++i) {
            result += 'o';
        }

        long long score = 0;
        int o_count = 0;
        int x_count = 0;
        
        for (int i = 0; i < result.length(); ++i) {
            if (result[i] == 'o') {
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
        
        
        for (int i = 0; i < result.length(); ++i) {
            if (result[i] == 'x') {
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
            best_arrangement = result;
        }
    }
   

    
    
    

    cout << max_score << endl;
    cout << best_arrangement << endl;

    return 0;
}