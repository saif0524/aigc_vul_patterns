#include <bits/stdc++.h>
using namespace std;

string a, b, c;
int countOccurrences(const string& text, const string& pattern) {
    int count = 0;
    size_t pos = text.find(pattern);
    while (pos != string::npos) {
        count++;
        pos = text.find(pattern, pos + 1);
    }
    return count;
}

bool canFormStringWithPattern(string& a, const string& pattern, int occurrenceCount) {
    int currCount = 0;
    for (int i = 0; i <= (int)a.size() - (int)pattern.size() && currCount < occurrenceCount; ++i) {
        if (a.substr(i, pattern.size()) == string(pattern.size(), '?')) {
            a.replace(i, pattern.size(), pattern);
            currCount++;
        }
    }
    return currCount == occurrenceCount;
}

int main(){
    cin >> a >> b >> c;
    int maxB = countOccurrences(a, b);
    int maxC = countOccurrences(a, c);

    int totalLength = a.size();
    string tempA = a;
    int bCount = 0, cCount = 0;

    for (int i = maxB; i >= 0; --i) {
        int remainingLength = totalLength - (i * b.size());
        int possibleCCount = remainingLength / c.size();
        possibleCCount = min(possibleCCount, maxC);

        tempA = a;
        if (canFormStringWithPattern(tempA, b, i) && canFormStringWithPattern(tempA, c, possibleCCount)) {
            bCount = i;
            cCount = possibleCCount;
            break;
        }
    }

    for (int i = 0; i < (int)a.size();) {
        if (bCount > 0 && a.substr(i, b.size()) == string(b.size(), '?')) {
            cout << b;
            i += b.size();
            bCount--;
        } else if (cCount > 0 && a.substr(i, c.size()) == string(c.size(), '?')) {
            cout << c;
            i += c.size();
            cCount--;
        } else {
            cout << a[i];
            i++;
        }
    }
    return 0;
}