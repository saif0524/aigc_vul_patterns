#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

struct Category {
    int numPublications;
    int timeToFind;
};

bool compareCategories(const Category& a, const Category& b) {
    if (a.numPublications == b.numPublications) {
        return a.timeToFind < b.timeToFind;
    }
    return a.numPublications < b.numPublications;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> numPublications(n);
    for (int i = 0; i < n; ++i) {
        cin >> numPublications[i];
    }

    vector<int> timeToFind(n);
    for (int i = 0; i < n; ++i) {
        cin >> timeToFind[i];
    }

    vector<Category> categories(n);
    for (int i = 0; i < n; ++i) {
        categories[i].numPublications = numPublications[i];
        categories[i].timeToFind = timeToFind[i];
    }

    sort(categories.begin(), categories.end(), compareCategories);

    int totalTime = 0;
    map<int, int> publicationsCount;
    for (const auto& category : categories) {
        if (publicationsCount.find(category.numPublications) != publicationsCount.end()) {
            int nextNumPublications = category.numPublications;
            while (publicationsCount.find(nextNumPublications) != publicationsCount.end()) {
                nextNumPublications++;
            }
            totalTime += (nextNumPublications - category.numPublications) * category.timeToFind;
            publicationsCount[nextNumPublications] = 1;
        } else {
            publicationsCount[category.numPublications] = 1;
        }
    }

    cout << totalTime << endl;

    return 0;
}