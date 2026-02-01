#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Node {
    char label;
    Node *left, *right;

    Node(char l) : label(l), left(nullptr), right(nullptr) {}
};

void parseExpression(const string &expr, int &pos, Node *&root) {
    char label = expr[pos++];
    root = new Node(label);
    if (pos < expr.size() && expr[pos] == '(') {
        ++pos;
        parseExpression(expr, pos, root->left);
        if (pos < expr.size() && expr[pos] == ',') {
            ++pos;
            parseExpression(expr, pos, root->right);
        }
        ++pos; // skip ')'
    }
}

pair<int, int> buildDiagram(Node *root, vector<string> &diagram, int x) {
    if (!root) return {0, 0};
    int leftWidth = 0, rightWidth = 0, leftHeight = 0, rightHeight = 0;
    if (root->left) {
        auto [lw, lh] = buildDiagram(root->left, diagram, x);
        leftWidth = lw;
        leftHeight = lh;
    }
    if (root->right) {
        auto [rw, rh] = buildDiagram(root->right, diagram, x + leftWidth + 1);
        rightWidth = rw;
        rightHeight = rh;
    }
    int width = leftWidth + 1 + rightWidth;
    int height = 1 + max(leftHeight, rightHeight);
    diagram.resize(max((int)diagram.size(), height));
    for (int i = 0; i < height; ++i) {
        diagram[i].resize(max((int)diagram[i].size(), x + width));
    }
    diagram[0][x + leftWidth] = root->label;
    if (root->left) {
        for (int i = 1; i <= leftHeight; ++i) {
            diagram[i][x + leftWidth - i] = '-';
        }
    }
    if (root->right) {
        for (int i = 1; i <= rightHeight; ++i) {
            diagram[i][x + leftWidth + i] = '-';
        }
    }
    return {width, height};
}

int main() {
    string input;
    char ch;
    int id = 1;
    while (cin >> ch) {
        stringstream expr;
        expr << ch;
        while (cin >> ch && ch != ';' && ch != '.') {
            if (ch != ' ' && ch != '\t') expr << ch;
        }
        if (ch == '.') break;
        string expression = expr.str();
        int pos = 0;
        Node *root;
        parseExpression(expression, pos, root);
        vector<string> diagram;
        buildDiagram(root, diagram, 0);
        cout << id++ << ":\n";
        for (const auto &line : diagram) {
            cout << line << "\n";
        }
    }
    return 0;
}