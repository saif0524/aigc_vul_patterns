#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int n;
vector<vector<int>> cubes;
vector<int> currentNumber;

set<int> generatedNumbers;

void generateNumbers(int index) {
    if (index == currentNumber.size()) {
        int number = 0;
        for (int i = 0; i < currentNumber.size(); i++) {
            number = number * 10 + currentNumber[i];
        }
        generatedNumbers.insert(number);
        return;
    }

    for (int i = 0; i < n; i++) {
        if (cubes[i].size() == 0) continue;
        int digit = cubes[i].back();
        cubes[i].pop_back();
        currentNumber.push_back(digit);
        generateNumbers(index + 1);
        currentNumber.pop_back();
        cubes[i].push_back(digit);
    }
}

void rotateCube(vector<int>& cube) {
    vector<int> newCube(6);
    newCube[0] = cube[0];
    newCube[1] = cube[5];
    newCube[2] = cube[2];
    newCube[3] = cube[4];
    newCube[4] = cube[1];
    newCube[5] = cube[3];
    cube = newCube;
}

vector<int> getAllPossibleDigits(vector<int>& cube) {
    vector<int> digits;
    for (int i = 0; i < 4; i++) {
        rotateCube(cube);
        digits.push_back(cube[0]);
    }
    rotateCube(cube);
    rotateCube(cube);
    digits.push_back(cube[0]);
    return digits;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    cubes.resize(n);
    for (int i = 0; i < n; i++) {
        cubes[i].resize(6);
        for (int j = 0; j < 6; j++) {
            cin >> cubes[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        cubes[i] = getAllPossibleDigits(cubes[i]);
    }

    int maxLength = 1;
    while (true) {
        generatedNumbers.clear();
        for (int mask = 0; mask < (1 << n); mask++) {
            currentNumber.clear();
            for (int i = 0; i < n; i++) {
                if ((mask & (1 << i)) == 0) continue;
                vector<int> newCube = cubes[i];
                currentNumber.push_back(newCube.back());
                newCube.pop_back();
                for (int j = 0; j < maxLength - 1; j++) {
                    if (newCube.size() == 0) break;
                    currentNumber.push_back(newCube.back());
                    newCube.pop_back();
                }
            }
            if (currentNumber.size() != maxLength) continue;
            if (currentNumber[0] == 0) continue;
            generateNumbers(0);
        }

        bool canGenerateAll = true;
        for (int i = 1; i <= (1 << maxLength); i++) {
            if (generatedNumbers.find(i) == generatedNumbers.end()) {
                canGenerateAll = false;
                break;
            }
        }

        if (!canGenerateAll) break;
        maxLength++;
    }

    cout << (1 << (maxLength - 1)) - 1 << endl;

    return 0;
}