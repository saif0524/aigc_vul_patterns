#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int d, hd, md, a, ha, ma;

    while (cin >> d && d != 0) {
        cin >> hd >> md;
        cin >> a;
        cin >> ha >> ma;

        int distance;
        int fare;

        if (d == 1 && a == 2) {
            distance = 12;
            fare = 450;
        } else if (d == 1 && a == 3) {
            distance = 24;
            fare = 750;
        } else if (d == 1 && a == 4) {
            distance = 36;
            fare = 1100;
        } else if (d == 1 && a == 5) {
            distance = 48;
            fare = 1500;
        } else if (d == 1 && a == 6) {
            distance = 53;
            fare = 1700;
        } else if (d == 1 && a == 7) {
            distance = 58;
            fare = 1900;
        } else if (d == 2 && a == 1) {
            distance = 12;
            fare = 450;
        } else if (d == 2 && a == 3) {
            distance = 12;
            fare = 450;
        } else if (d == 2 && a == 4) {
            distance = 24;
            fare = 750;
        } else if (d == 2 && a == 5) {
            distance = 36;
            fare = 1100;
        } else if (d == 2 && a == 6) {
            distance = 41;
            fare = 1300;
        } else if (d == 2 && a == 7) {
            distance = 46;
            fare = 1500;
        } else if (d == 3 && a == 1) {
            distance = 24;
            fare = 750;
        } else if (d == 3 && a == 2) {
            distance = 12;
            fare = 450;
        } else if (d == 3 && a == 4) {
            distance = 12;
            fare = 450;
        } else if (d == 3 && a == 5) {
            distance = 24;
            fare = 750;
        } else if (d == 3 && a == 6) {
            distance = 29;
            fare = 900;
        } else if (d == 3 && a == 7) {
            distance = 34;
            fare = 1100;
        } else if (d == 4 && a == 1) {
            distance = 36;
            fare = 1100;
        } else if (d == 4 && a == 2) {
            distance = 24;
            fare = 750;
        } else if (d == 4 && a == 3) {
            distance = 12;
            fare = 450;
        } else if (d == 4 && a == 5) {
            distance = 12;
            fare = 450;
        } else if (d == 4 && a == 6) {
            distance = 17;
            fare = 600;
        } else if (d == 4 && a == 7) {
            distance = 22;
            fare = 700;
        } else if (d == 5 && a == 1) {
            distance = 48;
            fare = 1500;
        } else if (d == 5 && a == 2) {
            distance = 36;
            fare = 1100;
        } else if (d == 5 && a == 3) {
            distance = 24;
            fare = 750;
        } else if (d == 5 && a == 4) {
            distance = 12;
            fare = 450;
        } else if (d == 5 && a == 6) {
            distance = 5;
            fare = 200;
        } else if (d == 5 && a == 7) {
            distance = 10;
            fare = 300;
        } else if (d == 6 && a == 1) {
            distance = 53;
            fare = 1700;
        } else if (d == 6 && a == 2) {
            distance = 41;
            fare = 1300;
        } else if (d == 6 && a == 3) {
            distance = 29;
            fare = 900;
        } else if (d == 6 && a == 4) {
            distance = 17;
            fare = 600;
        } else if (d == 6 && a == 5) {
            distance = 5;
            fare = 200;
        } else if (d == 6 && a == 7) {
            distance = 5;
            fare = 200;
        } else if (d == 7 && a == 1) {
            distance = 58;
            fare = 1900;
        } else if (d == 7 && a == 2) {
            distance = 46;
            fare = 1500;
        } else if (d == 7 && a == 3) {
            distance = 34;
            fare = 1100;
        } else if (d == 7 && a == 4) {
            distance = 22;
            fare = 700;
        } else if (d == 7 && a == 5) {
            distance = 10;
            fare = 300;
        } else if (d == 7 && a == 6) {
            distance = 5;
            fare = 200;
        }

        bool half_price = false;
        if (hd >= 17 && hd < 19) {
            half_price = true;
        } else if (hd == 17 && md >= 30) {
            half_price = true;
        } else if (hd == 19 && md < 30) {
            half_price = true;
        }

        if (half_price && distance <= 40) {
            fare = (fare + 49) / 50 * 50;
            fare /= 2;
            fare = (fare + 49) / 50 * 50;
        } else {
            fare = (fare + 49) / 50 * 50;
        }

        cout << fare << endl;
    }

    return 0;
}