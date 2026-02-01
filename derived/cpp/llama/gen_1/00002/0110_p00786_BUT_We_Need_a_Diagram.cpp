#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Node {
    char label;
    Node* left;
    Node* right;
    Node* child;
};

Node* parse(string& str) {
    while (str.size() > 0 && (str[0] == ' ' || str[0] == '\t' || str[0] == '\n')) {
        str.erase(str.begin());
    }
    char label = str[0];
    str.erase(str.begin());
    Node* node = new Node();
    node->label = label;
    node->left = nullptr;
    node->right = nullptr;
    node->child = nullptr;
    if (str.size() > 0 && str[0] == '(') {
        str.erase(str.begin());
        if (str.size() > 0 && str[0] == ',') {
            str.erase(str.begin());
            node->left = parse(str);
            node->right = parse(str);
        } else {
            node->child = parse(str);
        }
        str.erase(str.begin());
    }
    return node;
}

void print(Node* node, int level, bool isLast) {
    if (node->left == nullptr && node->right == nullptr && node->child == nullptr) {
        for (int i = 0; i < level; i++) {
            cout << " ";
        }
        cout << node->label << endl;
    } else if (node->child != nullptr) {
        print(node->child, level + 1, true);
        for (int i = 0; i < level; i++) {
            cout << " ";
        }
        cout << "-" << endl;
        for (int i = 0; i < level; i++) {
            cout << " ";
        }
        cout << node->label << endl;
    } else {
        print(node->left, level + 1, false);
        print(node->right, level + 1, true);
        for (int i = 0; i < level; i++) {
            cout << " ";
        }
        for (int i = 0; i < (node->right != nullptr ? 1 : 0); i++) {
            cout << "-";
        }
        cout << endl;
        for (int i = 0; i < level; i++) {
            cout << " ";
        }
        cout << node->label << endl;
    }
}

int main() {
    int count = 1;
    string str;
    while (getline(cin, str)) {
        str += ";";
        size_t pos = str.find(';');
        while (pos != string::npos) {
            string substr = str.substr(0, pos);
            str.erase(0, pos + 1);
            substr.erase(remove(substr.begin(), substr.end(), ' '), substr.end());
            substr.erase(remove(substr.begin(), substr.end(), '\t'), substr.end());
            substr.erase(remove(substr.begin(), substr.end(), '\n'), substr.end());
            Node* node = parse(substr);
            cout << count << ":" << endl;
            print(node, 0, true);
            count++;
            pos = str.find(';');
        }
    }
    return 0;
}