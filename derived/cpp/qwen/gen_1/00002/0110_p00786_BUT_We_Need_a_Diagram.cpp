#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

struct Node {
    char label;
    Node* left;
    Node* right;
    Node(char l) : label(l), left(nullptr), right(nullptr) {}
};

class Parser {
public:
    Node* parse(const string& s) {
        index = 0;
        return parseExpression(s);
    }

private:
    int index;
    Node* parseExpression(const string& s) {
        char c = s[index++];
        Node* node = new Node(c);
        if (index < s.size() && s[index] == '(') {
            index++;
            node->left = parseExpression(s);
            if (index < s.size() && s[index] == ',') {
                index++;
                node->right = parseExpression(s);
            }
            index++;
        }
        return node;
    }
};

class Diagram {
public:
    Diagram(Node* root) : root(root) {
        build();
    }

    void print(int id) {
        cout << id << ":\n";
        for (const auto& line : diagram) {
            cout << line << "\n";
        }
    }

private:
    Node* root;
    vector<string> diagram;
    vector<int> heights;
    vector<int> widths;

    void build() {
        calculateSizes(root);
        diagram.resize(heights[root]);
        for (int i = 0; i < heights[root]; ++i) {
            diagram[i].resize(widths[root]);
            fill(diagram[i].begin(), diagram[i].end(), ' ');
        }
        int pos = 0;
        draw(root, pos, 0);
    }

    void calculateSizes(Node* node) {
        if (!node) return;
        calculateSizes(node->left);
        calculateSizes(node->right);
        int leftHeight = node->left ? heights[node->left] : 0;
        int rightHeight = node->right ? heights[node->right] : 0;
        int leftWidth = node->left ? widths[node->left] : 0;
        int rightWidth = node->right ? widths[node->right] : 0;
        heights[node] = 1 + max(leftHeight, rightHeight);
        widths[node] = leftWidth + rightWidth + 1;
    }

    void draw(Node* node, int& pos, int y) {
        int leftWidth = node->left ? widths[node->left] : 0;
        int rightWidth = node->right ? widths[node->right] : 0;
        int rootPos = pos + leftWidth;
        diagram[y][rootPos] = node->label;
        if (node->left) {
            draw(node->left, pos, y + 1);
            for (int i = pos; i < rootPos; ++i) {
                diagram[y + 1][i] = '-';
            }
        }
        if (node->right) {
            draw(node->right, pos, y + 1);
            for (int i = rootPos + 1; i < pos + leftWidth + rightWidth; ++i) {
                diagram[y + 1][i] = '-';
            }
        }
        pos += widths[node];
    }
};

int main() {
    string input, expr;
    bool first = true;
    int id = 1;
    while (getline(cin, input)) {
        for (char c : input) {
            if (c == ';' || c == '.') {
                if (!expr.empty()) {
                    if (!first) cout << "\n";
                    first = false;
                    Parser parser;
                    Node* root = parser.parse(expr);
                    Diagram diagram(root);
                    diagram.print(id++);
                    expr.clear();
                }
                if (c == '.') return 0;
            } else if (!isspace(c)) {
                expr += c;
            }
        }
    }
    return 0;
}