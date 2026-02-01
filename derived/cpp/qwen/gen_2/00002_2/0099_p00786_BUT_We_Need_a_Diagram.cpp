#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct BUT {
    char label;
    BUT *left = nullptr;
    BUT *right = nullptr;
};

BUT* parseBut(const string& s, int& pos) {
    if (pos >= s.length()) return nullptr;

    if (isalpha(s[pos])) {
        BUT* node = new BUT{s[pos]};
        pos++;
        return node;
    }

    if (s[pos] == '(') {
        pos++;
        char label = s[pos];
        pos++;
        if (s[pos] == ')') {
            pos++;
            return new BUT{label};
        } else if (s[pos] == ',') {
            pos++;
            BUT* left = parseBut(s, pos);
            BUT* right = parseBut(s, pos);
            pos++;
            BUT* node = new BUT{label};
            node->left = left;
            node->right = right;
            return node;
        } else {
            BUT* node = new BUT{label};
            node->left = parseBut(s, pos);
            pos++;
            return node;
        }
    }
    return nullptr;
}

void printDiagram(BUT* root, int indent = 0) {
    if (!root) return;

    if (!root->left && !root->right) {
        for (int i = 0; i < indent; ++i) cout << " ";
        cout << root->label << endl;
        return;
    }

    if (root->left && root->right) {
        vector<string> leftLines, rightLines;
        vector<int> leftWidth, rightWidth;

        function<void(BUT*, vector<string>&, vector<int>&, int)> buildLines = 
            [&](BUT* node, vector<string>& lines, vector<int>& width, int indent) {
            if (!node) return;
            if (!node->left && !node->right) {
                string line;
                for (int i = 0; i < indent; ++i) line += " ";
                line += node->label;
                lines.push_back(line);
                width.push_back(line.length());
            } else {
                buildLines(node->left, lines, width, indent + 1);
                buildLines(node->right, lines, width, indent + 1);
            }
        };
        
        buildLines(root->left, leftLines, leftWidth, indent);
        buildLines(root->right, rightLines, rightWidth, indent);
        
        int maxLeftWidth = 0;
        if (!leftLines.empty())
            maxLeftWidth = *max_element(leftWidth.begin(), leftWidth.end());

        int maxRightWidth = 0;
        if (!rightLines.empty())
            maxRightWidth = *max_element(rightWidth.begin(), rightWidth.end());
        
        
        int totalWidth = maxLeftWidth + maxRightWidth + 3;
        
        if (leftLines.empty() && rightLines.empty()) {
            for (int i = 0; i < indent; ++i) cout << " ";
            cout << root->label << endl;
            return;
        }
        
        
        for (int i = 0; i < leftLines.size(); ++i) {
            string line = leftLines[i];
            int padding = maxLeftWidth - line.length();
            line += string(padding, ' ');
            line += " ";

            string rightLine;
            if (i < rightLines.size())
                rightLine = rightLines[i];
            else
                 rightLine = "";
                
            line += rightLine;

            cout << line << endl;
        }
        
        
        int dashCount = totalWidth - 2;
        string dashes(dashCount, '-');
        
        
        int centerPos = totalWidth / 2;
        
        
        
        for (int i = 0; i < indent; ++i) cout << " ";
        string dashLine(totalWidth, ' ');
        
        if(dashCount>0)
            dashLine.replace(centerPos-dashCount/2, dashCount, dashes);
        cout << dashLine << endl;
        
        
        for (int i = 0; i < indent; ++i) cout << " ";
        
        cout << root->label << endl;
        
    } else if (root->left) {
        
        
        vector<string> leftLines;
        vector<int> leftWidth;
        function<void(BUT*, vector<string>&, vector<int>&, int)> buildLines = 
            [&](BUT* node, vector<string>& lines, vector<int>& width, int indent) {
            if (!node) return;
            if (!node->left && !node->right) {
                string line;
                for (int i = 0; i < indent; ++i) line += " ";
                line += node->label;
                lines.push_back(line);
                width.push_back(line.length());
            } else {
                buildLines(node->left, lines, width, indent + 1);
                buildLines(node->right, lines, width, indent + 1);
            }
        };
        
        buildLines(root->left, leftLines, leftWidth, indent+1);
        
        int maxLeftWidth = 0;
        if (!leftLines.empty())
            maxLeftWidth = *max_element(leftWidth.begin(), leftWidth.end());
        
        
        for (int i = 0; i < leftLines.size(); ++i) {
            string line = leftLines[i];
            
            
            cout << line << endl;
        }

        
        int dashCount = maxLeftWidth+2;
        string dashes(dashCount, '-');
            
        for (int i = 0; i < indent; ++i) cout << " ";
        cout << root->label << endl;
    } else if (root->right) {
                vector<string> rightLines;
        vector<int> rightWidth;
        function<void(BUT*, vector<string>&, vector<int>&, int)> buildLines = 
            [&](BUT* node, vector<string>& lines, vector<int>& width, int indent) {
            if (!node) return;
            if (!node->left && !node->right) {
                string line;
                for (int i = 0; i < indent; ++i) line += " ";
                line += node->label;
                lines.push_back(line);
                width.push_back(line.length());
            } else {
                buildLines(node->left, lines, width, indent + 1);
                buildLines(node->right, lines, width, indent + 1);
            }
        };
        
        buildLines(root->right, rightLines, rightWidth, indent+1);
        
        int maxRightWidth = 0;
        if (!rightLines.empty())
            maxRightWidth = *max_element(rightWidth.begin(), rightWidth.end());
        
        for (int i = 0; i < rightLines.size(); ++i) {
            string line = rightLines[i];
          
            cout << line << endl;
        }

        
        int dashCount = maxRightWidth+2;
        string dashes(dashCount, '-');
            
        for (int i = 0; i < indent; ++i) cout << " ";
        cout << root->label << endl;
    }
   
}



int main() {
    int caseNum = 1;
    string line;
    
    while (getline(cin, line) && line != ".") {
        if (line.back() == ';') {
            line.pop_back();
        }
        
        cout << caseNum++ << ":" << endl;
        
        int pos = 0;
        BUT* root = parseBut(line, pos);
        
        printDiagram(root);
        
        
        
        
        
        
        
        
    }
     if (getline(cin, line) && line == ".") {
        cout << caseNum++ << ":" << endl;


        int pos = 0;
        BUT* root = parseBut(line, pos);
        printDiagram(root);
     }

    return 0;
}