#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

struct Person {
    std::string name;
    int a;
    int h;
};

bool compare(const Person& a, const Person& b) {
    return a.a < b.a;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<Person> people(n);
    for (int i = 0; i < n; i++) {
        std::cin >> people[i].name >> people[i].a;
    }

    std::sort(people.begin(), people.end(), compare);

    for (int i = 0; i < n; i++) {
        if (people[i].a > i) {
            std::cout << -1 << std::endl;
            return 0;
        }
    }

    int h = 1000000000;
    int prev = 0;
    for (int i = 0; i < n; i++) {
        if (people[i].a == prev) {
            people[i].h = h;
            h -= 10;
        } else {
            h += 20;
            people[i].h = h;
            prev = people[i].a;
            h -= 10;
        }
    }

    std::sort(people.begin(), people.end(), [](const Person& a, const Person& b) {
        return a.a < b.a;
    });

    for (int i = 0; i < n; i++) {
        std::cout << people[i].name << " " << people[i].h << std::endl;
    }

    return 0;
}