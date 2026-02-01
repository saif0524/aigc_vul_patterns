#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Box {
    int w, h, d;
};

bool compare(Box a, Box b) {
    return (a.d * a.h < b.d * b.h);
}

int maxStackHeight(vector<Box>& boxes, int n) {
    vector<Box> rotations;
    for (int i = 0; i < n; ++i) {
        rotations.push_back({boxes[i].w, max(boxes[i].h, boxes[i].d), min(boxes[i].h, boxes[i].d)});
        rotations.push_back({boxes[i].d, max(boxes[i].w, boxes[i].h), min(boxes[i].w, boxes[i].h)});
        rotations.push_back({boxes[i].h, max(boxes[i].w, boxes[i].d), min(boxes[i].w, boxes[i].d)});
    }

    n *= 3;
    sort(rotations.begin(), rotations.end(), compare);

    vector<int> msh(n);
    for (int i = 0; i < n; ++i) {
        msh[i] = rotations[i].h;
    }

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (rotations[i].w < rotations[j].w && rotations[i].d < rotations[j].d) {
                msh[i] = max(msh[i], msh[j] + rotations[i].h);
            }
        }
    }

    return *max_element(msh.begin(), msh.end());
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<Box> boxes(k);
    for (int i = 0; i < k; ++i) {
        cin >> boxes[i].w >> boxes[i].h >> boxes[i].d;
    }

    cout << maxStackHeight(boxes, k) << endl;

    return 0;
}