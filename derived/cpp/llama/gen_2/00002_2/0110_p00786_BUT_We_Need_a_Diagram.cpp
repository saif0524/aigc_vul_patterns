#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Node {
    char label;
    Node* left;
    Node* right;
};

Node* parse(string& str, int& pos) {
    while (pos < str.size() && (str[pos] == ' ' || str[pos] == '\t' || str[pos] == '\n')) {
        pos++;
    }
    if (pos >= str.size()) {
        return nullptr;
    }
    Node* node = new Node();
    node->label = str[pos++];
    node->left = nullptr;
    node->right = nullptr;
    if (pos < str.size() && str[pos] == '(') {
        pos++;
        node->left = parse(str, pos);
        if (pos < str.size() && str[pos] == ',') {
            pos++;
            node->right = parse(str, pos);
        }
        pos++;
    }
    return node;
}

void print(Node* node, int level, bool isLast) {
    if (node == nullptr) {
        return;
    }
    print(node->left, level + 1, false);
    for (int i = 0; i < level; i++) {
        cout << " ";
    }
    if (level > 0) {
        if (isLast) {
            cout << "\\-";
        } else {
            cout << "/-";
        }
    }
    cout << node->label << endl;
    print(node->right, level + 1, true);
}

void printTree(Node* node) {
    print(node->left, 0, false);
    cout << node->label << endl;
    print(node->right, 0, true);
}

int main() {
    string input;
    int caseNum = 1;
    while (true) {
        string str;
        char c;
        while (cin.get(c)) {
            if (c == ';') {
                break;
            }
            if (c == '.') {
                input += c;
                break;
            }
            input += c;
        }
        if (input.back() == '.') {
            int pos = 0;
            Node* root = parse(input, pos);
            cout << caseNum << ":" << endl;
            printTree(root);
            delete root;
            break;
        } else {
            int pos = 0;
            Node* root = parse(input, pos);
            cout << caseNum << ":" << endl;
            printTree(root);
            delete root;
            caseNum++;
        }
        input.clear();
    }
    return 0;
}