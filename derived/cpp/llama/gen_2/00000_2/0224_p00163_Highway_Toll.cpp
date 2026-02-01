#include <iostream>
#include <cmath>

int main() {
    int departure, arrival, hourDeparture, minuteDeparture, hourArrival, minuteArrival;
    int distance[8][8] = {
        {0, 10, 15, 20, 25, 30, 35, 40},
        {10, 0, 5, 10, 15, 20, 25, 30},
        {15, 5, 0, 5, 10, 15, 20, 25},
        {20, 10, 5, 0, 5, 10, 15, 20},
        {25, 15, 10, 5, 0, 5, 10, 15},
        {30, 20, 15, 10, 5, 0, 5, 10},
        {35, 25, 20, 15, 10, 5, 0, 5},
        {40, 30, 25, 20, 15, 10, 5, 0}
    };
    int fare[8][8] = {
        {0, 200, 250, 300, 350, 400, 450, 500},
        {200, 0, 100, 200, 250, 300, 350, 400},
        {250, 100, 0, 100, 200, 250, 300, 350},
        {300, 200, 100, 0, 100, 200, 250, 300},
        {350, 250, 200, 100, 0, 100, 200, 250},
        {400, 300, 250, 200, 100, 0, 100, 200},
        {450, 350, 300, 250, 200, 100, 0, 100},
        {500, 400, 350, 300, 250, 200, 100, 0}
    };

    while (true) {
        std::cin >> departure;
        if (departure == 0) break;
        std::cin >> hourDeparture >> minuteDeparture;
        std::cin >> arrival;
        std::cin >> hourArrival >> minuteArrival;

        int totalFare = fare[departure][arrival];
        int totalDistance = distance[departure][arrival];

        bool isHalfPriceTime = false;
        if ((hourDeparture >= 17 && hourDeparture < 19) || (hourDeparture == 19 && minuteDeparture <= 30)) {
            isHalfPriceTime = true;
        }
        if ((hourArrival >= 17 && hourArrival < 19) || (hourArrival == 19 && minuteArrival <= 30)) {
            isHalfPriceTime = true;
        }

        if (isHalfPriceTime && totalDistance <= 40) {
            totalFare = std::ceil(totalFare / 2.0);
        }

        std::cout << totalFare << std::endl;
    }

    return 0;
}