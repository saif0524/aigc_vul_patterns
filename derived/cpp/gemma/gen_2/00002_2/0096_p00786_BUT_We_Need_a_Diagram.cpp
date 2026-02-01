#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
    char label;
    Node *left = nullptr;
    Node *right = nullptr;
};

Node* parse(const string& s, int& pos) {
    if (pos >= s.length()) {
        return nullptr;
    }

    char c = s[pos++];
    if (isalpha(c)) {
        Node* node = new Node{c};
        if (pos < s.length() && s[pos] == '(') {
            pos++;
            node->left = parse(s, pos);
            if (pos < s.length() && s[pos] == ',') {
                pos++;
                node->right = parse(s, pos);
            }
            if (pos < s.length() && s[pos] == ')') {
                pos++;
            }
        }
        return node;
    }
    return nullptr;
}

void print_diagram(Node* node, int indent = 0) {
    if (!node) return;

    if (node->left == nullptr && node->right == nullptr) {
        for (int i = 0; i < indent; ++i) {
            cout << " ";
        }
        cout << node->label << endl;
        return;
    }

    int left_height = 0;
    int right_height = 0;

    vector<string> left_lines;
    vector<string> right_lines;

    function<void(Node*, vector<string>&, int)> traverse = 
        [&](Node* n, vector<string>& lines, int level) {
        if (!n) return;

        if (n->left == nullptr && n->right == nullptr) {
            string line;
            for (int i = 0; i < level; ++i) {
                line += " ";
            }
            line += n->label;
            lines.push_back(line);
            return;
        }

        traverse(n->left, lines, level + 1);
        traverse(n->right, lines, level + 1);
    };

    traverse(node->left, left_lines, 0);
    traverse(node->right, right_lines, 0);
    
    left_height = left_lines.size();
    right_height = right_lines.size();
    
    int max_height = max(left_height, right_height);
    
    int dash_count = 0;
    if(max_height == 0) {
        dash_count = 0;
    }
    else if (max_height == 1) {
         dash_count = 1;
    }
    else {
        dash_count = 3;
    }

    
    
    
    
    
    if (left_height == 0 && right_height == 0) {
        for (int i = 0; i < indent; ++i) {
            cout << " ";
        }
        cout << node->label << endl;
        return;
    }
    
    
    
    
    
    vector<string> diagram_lines;

    
    
    
    int left_width = 0;
    for (const auto& line : left_lines) {
        left_width = max(left_width, (int)line.length());
    }

    int right_width = 0;
    for (const auto& line : right_lines) {
        right_width = max(right_width, (int)line.length());
    }

    int total_width = left_width + right_width + dash_count;
    
    
    
    
    
    // Print Lines
    if(max_height > 0) {
    for (int i = 0; i < max_height; ++i) {
        string line;
        
        
         if (i < left_height) {
            line += left_lines[i];
            for (int j = (int)left_lines[i].length(); j < left_width; ++j) {
                line += " ";
            }
            
        } else {
            line = string(left_width, ' ');
        }

        
        if (i == max_height - 1 && max_height > 1) {
           
        }
        
        //Dash
        if (i == max_height -1) {
            for (int j = 0; j < dash_count; ++j) {
                line += "-";
            }
        } else {
            for (int j = 0; j < dash_count; ++j) {
                line += " ";
            }
        }

        

        if (i < right_height) {
            line += right_lines[i];
            for (int j = (int)right_lines[i].length(); j < right_width; ++j) {
                line += " ";
            }
            
        } else {
            line += string(right_width, ' ');
        }
        
        
        
        cout << line << endl;
    }} else {
        
        for (int i = 0; i < indent; ++i) {
            cout << " ";
        }
        cout << node->label << endl;
    }
}

int main() {
    int case_num = 1;
    string line;

    while (getline(cin, line) && line != ".") {
        cout << case_num++ << ":" << endl;
        string input_line = line;
        
        int pos = 0;
        Node* root = parse(input_line, pos);

        print_diagram(root);
        
    }

    return 0;
}