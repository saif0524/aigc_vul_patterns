#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 100;

struct Node {
    int value;
    Node* left;
    Node* right;
};

Node* createNode(int value) {
    Node* newNode = new Node();
    if (!newNode) {
        cout << "Memory error\n";
        return NULL;
    }
    newNode->value = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void buildTree(int arr[], int n, Node** root, int& maxDepth, unordered_map<int, int>& depths) {
    if (n == 0) return;

    int maxIndex = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] > arr[maxIndex]) {
            maxIndex = i;
        }
    }

    *root = createNode(arr[maxIndex]);
    depths[arr[maxIndex]] = maxDepth;

    int leftArr[MAX_N], rightArr[MAX_N];
    int leftSize = 0, rightSize = 0;

    for (int i = 0; i < n; i++) {
        if (i < maxIndex) {
            leftArr[leftSize++] = arr[i];
        } else if (i > maxIndex) {
            rightArr[rightSize++] = arr[i];
        }
    }

    maxDepth++;
    buildTree(leftArr, leftSize, &((*root)->left), maxDepth, depths);
    buildTree(rightArr, rightSize, &((*root)->right), maxDepth, depths);
    maxDepth--;
}

void solveTestCase(int arr[], int n) {
    Node* root;
    int maxDepth = 0;
    unordered_map<int, int> depths;

    buildTree(arr, n, &root, maxDepth, depths);

    for (int i = 0; i < n; i++) {
        cout << depths[arr[i]] << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int arr[MAX_N];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        solveTestCase(arr, n);
    }

    return 0;
}