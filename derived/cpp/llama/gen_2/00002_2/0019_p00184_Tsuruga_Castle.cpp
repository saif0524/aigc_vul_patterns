#include <iostream>
using namespace std;

int main() {
    int n;
    while (true) {
        cin >> n;
        if (n == 0) break;

        int ageGroups[7] = {0};
        for (int i = 0; i < n; i++) {
            int age;
            cin >> age;
            if (age < 10) ageGroups[0]++;
            else if (age < 20) ageGroups[1]++;
            else if (age < 30) ageGroups[2]++;
            else if (age < 40) ageGroups[3]++;
            else if (age < 50) ageGroups[4]++;
            else if (age < 60) ageGroups[5]++;
            else ageGroups[6]++;
        }

        for (int i = 0; i < 7; i++) {
            cout << ageGroups[i] << endl;
        }
    }

    return 0;
}