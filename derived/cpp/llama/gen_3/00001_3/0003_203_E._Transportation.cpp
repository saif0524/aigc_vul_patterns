#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Robot {
    long long int can_carry;
    long long int fuel_needed;
    long long int max_distance;
};

bool compareRobots(Robot a, Robot b) {
    return a.can_carry > b.can_carry;
}

int main() {
    long long int n, d, s;
    cin >> n >> d >> s;

    vector<Robot> robots;
    for (int i = 0; i < n; i++) {
        long long int can_carry, fuel_needed, max_distance;
        cin >> can_carry >> fuel_needed >> max_distance;
        if (max_distance >= d) {
            Robot robot;
            robot.can_carry = can_carry;
            robot.fuel_needed = fuel_needed;
            robot.max_distance = max_distance;
            robots.push_back(robot);
        }
    }

    sort(robots.begin(), robots.end(), compareRobots);

    long long int max_robots = 0;
    long long int min_fuel = 0;

    for (int i = 0; i < (1 << robots.size()); i++) {
        long long int total_fuel_needed = 0;
        long long int total_robots = 0;
        long long int remaining_capacity = 0;

        for (int j = 0; j < robots.size(); j++) {
            if ((i & (1 << j)) > 0) {
                total_fuel_needed += robots[j].fuel_needed;
                remaining_capacity += robots[j].can_carry;
                total_robots++;
            } else {
                if (remaining_capacity > 0) {
                    remaining_capacity--;
                    total_robots++;
                }
            }
        }

        if (total_fuel_needed <= s && total_robots > max_robots) {
            max_robots = total_robots;
            min_fuel = total_fuel_needed;
        } else if (total_fuel_needed <= s && total_robots == max_robots) {
            min_fuel = min(min_fuel, total_fuel_needed);
        }
    }

    cout << max_robots << " " << min_fuel;

    return 0;
}