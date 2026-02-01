#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct BUT {
    char label;
    BUT* left = nullptr;
    BUT* right = nullptr;
};

BUT* parse_but(const string& expression, int& pos) {
    char label = expression[pos++];
    if (pos < expression.length() && expression[pos] == '(') {
        pos++;
        if (expression[pos] == ')') {
            pos++;
            return new BUT{label};
        }
        BUT* left = parse_but(expression, pos);
        if (expression[pos] == ',') {
            pos++;
            BUT* right = parse_but(expression, pos);
            pos++; 
            return new BUT{label, left, right};
        } else {
            return new BUT{label, left, nullptr};
        }
    } else {
        return new BUT{label};
    }
}

void print_diagram(BUT* root, int level = 0) {
    if (root == nullptr) return;

    if (root->left == nullptr && root->right == nullptr) {
        cout << root->label << endl;
        return;
    }

    
    vector<string> lines;
    
    if (root->left != nullptr && root->right != nullptr) {
        
        
        vector<string> left_lines;
        vector<string> right_lines;
        
        
        
        print_diagram_lines(root->left, left_lines);       
        print_diagram_lines(root->right, right_lines);
        
        int max_left = 0;
        for (const string& line : left_lines) {
            max_left = max(max_left, (int)line.length());
        }

        int max_right = 0;
        for (const string& line : right_lines) {
            max_right = max(max_right, (int)line.length());
        }
        

        int total_width = max_left + max_right + 3;

        
        string dashes(total_width - 2, '-');
        
        
        int center = total_width / 2;
        
        
        
        
        
        
        
        string line1 = "";
        
        
        for (int i = 0; i < center - max_left -1; ++i) {
            line1 += " ";
        }

        if(!left_lines.empty()){
            for (const string& line : left_lines){
                cout << line << " ";
            }
        }
        

        cout << dashes << endl;
        

        cout << root->label << endl;

        cout << dashes << endl;
        

        
        
        
        for (int i = 0; i < center - max_right -1; ++i) {
            line1 += " ";
        }
        
        if(!right_lines.empty()){
            for (const string& line : right_lines){
                cout << line << " ";
            }
        }
        
        
     
    } else if (root->left != nullptr) {
          vector<string> left_lines;
          print_diagram_lines(root->left, left_lines);
          
          int max_left = 0;
        for (const string& line : left_lines) {
            max_left = max(max_left, (int)line.length());
        }
        
        for (const string& line : left_lines){
               cout << line << " ";
        }
        
        cout << "-" << endl;
        
        cout << root->label << endl;
    } else {
        cout << root->label << endl;
    }
}
void print_diagram_lines(BUT* root, vector<string>& lines, int level = 0) {
    if (root == nullptr) return;

    if (root->left == nullptr && root->right == nullptr) {
        lines.push_back(string(level * 2, ' ') + root->label);
        return;
    }

    
    print_diagram_lines(root->left, lines, level + 1);
    print_diagram_lines(root->right, lines, level + 1);
}

int main() {
    int test_case = 0;
    string expression;

    while (cin >> expression && expression != ".") {
        test_case++;
        
        
        int pos = 0;
        BUT* root = parse_but(expression, pos);
        
        cout << test_case << ":" << endl;
        
        print_diagram(root);

        
        
        
        
        
        
        
        
        
    }

    return 0;
}