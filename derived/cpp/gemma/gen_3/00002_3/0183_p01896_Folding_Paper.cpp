#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int h, w;
    cin >> h >> w;

    vector<int> s(h * w);
    for (int i = 0; i < h * w; ++i) {
        cin >> s[i];
    }

    if (h == 1 && w == 1) {
        cout << "YES" << endl;
        return 0;
    }

    if (h == 1 && w == 2) {
        if ((s[0] == 0 && s[1] == 1) || (s[0] == 1 && s[1] == 0)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
        return 0;
    }

    if (h == 2 && w == 1) {
        if ((s[0] == 0 && s[1] == 1) || (s[0] == 1 && s[1] == 0)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
        return 0;
    }

    if (h == 1 && w == 3) {
        if (s[0] == 0 && s[1] == 1 && s[2] == 2) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
        return 0;
    }
    
    if (h == 3 && w == 1) {
        if (s[0] == 0 && s[1] == 1 && s[2] == 2) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
        return 0;
    }

    if (h == 1 && w == 4) {
        if (s[0] == 0 && s[1] == 1 && s[2] == 2 && s[3] == 3) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
        return 0;
    }
    
    if (h == 4 && w == 1) {
        if (s[0] == 0 && s[1] == 1 && s[2] == 2 && s[3] == 3) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
        return 0;
    }

    if (h == 2 && w == 2) {
        if ((s[0] == 0 && s[1] == 1 && s[2] == 2 && s[3] == 3) ||
            (s[0] == 0 && s[1] == 2 && s[2] == 1 && s[3] == 3) ||
            (s[0] == 0 && s[1] == 1 && s[2] == 3 && s[3] == 2) ||
            (s[0] == 0 && s[1] == 3 && s[2] == 1 && s[3] == 2)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
        return 0;
    }
    
    if (h == 2 && w == 3) {
        if (s[0] == 0 && s[1] == 1 && s[2] == 2 && s[3] == 3 && s[4] == 4 && s[5] == 5) {
            cout << "YES" << endl;
        }else{
           cout << "NO" << endl;
        }
        return 0;
    }

    if (h == 3 && w == 2) {
        if (s[0] == 0 && s[1] == 1 && s[2] == 2 && s[3] == 3 && s[4] == 4 && s[5] == 5) {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
        return 0;
    }
    
    if (h == 2 && w == 4)
    {
        if (s[0] == 0 && s[1] == 1 && s[2] == 2 && s[3] == 3 && s[4] == 4 && s[5] == 5 && s[6] == 6 && s[7] == 7)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
        return 0;
    }

    
    
    vector<int> sorted_s = s;
    sort(sorted_s.begin(), sorted_s.end());
    
    for (int i = 0; i < h * w; ++i) {
        if (s[i] != sorted_s[i]) {
            cout << "NO" << endl;
            return 0;
        }
    }
    
    cout << "YES" << endl;

    return 0;
}