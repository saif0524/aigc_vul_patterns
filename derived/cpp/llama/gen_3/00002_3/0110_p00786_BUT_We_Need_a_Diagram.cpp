#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

struct Node {
    char label;
    Node* left;
    Node* right;
};

Node* parse(string& input) {
    if (input[0]!= '(') {
        Node* node = new Node();
        node->label = input[0];
        node->left = nullptr;
        node->right = nullptr;
        input.erase(0, 1);
        return node;
    }

    input.erase(0, 1);
    Node* node = new Node();
    node->label = input[0];
    input.erase(0, 1);
    if (input[0] == '(') {
        node->left = parse(input);
        input.erase(0, 1);
    } else {
        node->left = nullptr;
    }

    if (input[0] == ',') {
        input.erase(0, 1);
        node->right = parse(input);
        input.erase(0, 1);
    } else {
        node->right = nullptr;
    }

    input.erase(0, 1);
    return node;
}

void printTree(Node* node, int depth, bool isLast) {
    if (node == nullptr) return;

    if (node->left == nullptr && node->right == nullptr) {
        for (int i = 0; i < depth; i++) {
            cout << " ";
        }
        cout << node->label << endl;
        return;
    }

    printTree(node->left, depth + 1, false);
    for (int i = 0; i < depth; i++) {
        cout << " ";
    }
    cout << node->label;
    if (isLast) {
        cout << endl;
    }
    printTree(node->right, depth + 1, true);
}

void printTreeLine(Node* node, int depth, bool isLast) {
    if (node == nullptr) return;

    if (node->left == nullptr && node->right == nullptr) {
        for (int i = 0; i < depth; i++) {
            cout << " ";
        }
        cout << node->label;
        if (isLast) {
            cout << endl;
        }
        return;
    }

    printTreeLine(node->left, depth + 1, false);
    for (int i = 0; i < depth; i++) {
        cout << " ";
    }
    cout << node->label;
    if (isLast) {
        cout << endl;
    }
    printTreeLine(node->right, depth + 1, true);
}

void printLine(char c, int depth) {
    for (int i = 0; i < depth; i++) {
        cout << " ";
    }
    cout << c << endl;
}

int main() {
    int count = 1;
    string input;
    while (getline(cin, input, ';')) {
        input += ".";
        Node* root = parse(input);
        cout << count << ":" << endl;
        printTree(root, 0, true);
        cout << endl;
        count++;
    }
    return 0;
}