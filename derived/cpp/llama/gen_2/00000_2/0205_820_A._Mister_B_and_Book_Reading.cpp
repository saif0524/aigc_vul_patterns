#include <iostream>
using namespace std;

int main() {
    int c, v0, v1, a, l;
    cin >> c >> v0 >> v1 >> a >> l;

    int days = 0;
    int pagesRead = 0;
    int speed = v0;

    while (pagesRead < c) {
        days++;
        int pagesToRead = min(speed, v1);
        if (pagesRead + pagesToRead > c) {
            pagesToRead = c - pagesRead;
        }
        pagesRead += pagesToRead - l;
        if (pagesRead < 0) pagesRead = 0;
        speed += a;
        if (speed > v1) speed = v1;
    }

    cout << days << endl;

    return 0;
}