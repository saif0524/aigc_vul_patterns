#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

struct Person {
    std::string name;
    int count;
};

bool compare(const Person& a, const Person& b) {
    return a.count < b.count;
}

int main() {
    int n;
    std::cin >> n;

    std::vector<Person> people(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> people[i].name >> people[i].count;
    }

    std::sort(people.begin(), people.end(), compare);

    std::vector<int> heights(n);
    for (int i = 0; i < n; ++i) {
        if (people[i].count > i) {
            std::cout << -1 << std::endl;
            return 0;
        }
        heights[i] = people[i].count + 1;
        for (int j = 0; j < i; ++j) {
            if (heights[j] > heights[i]) {
                heights[i]++;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        std::cout << people[i].name << " " << heights[i] * 100 + 50 << std::endl;
    }

    return 0;
}