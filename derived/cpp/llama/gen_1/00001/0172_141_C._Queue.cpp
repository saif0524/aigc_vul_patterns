#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

struct Person {
    std::string name;
    int count;
    int height;
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

    int currentHeight = 100;
    std::vector<std::pair<std::string, int>> result;

    for (int i = 0; i < n; ++i) {
        if (people[i].count > i) {
            std::cout << -1 << std::endl;
            return 0;
        }

        int height = currentHeight + (i - people[i].count);
        result.push_back({people[i].name, height});

        currentHeight = std::max(currentHeight, height + 1);
    }

    for (const auto& person : result) {
        std::cout << person.first << " " << person.second << std::endl;
    }

    return 0;
}