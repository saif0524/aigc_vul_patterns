#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <stack>

using namespace std;

struct Tag {
    string name;
    string contents;
    vector<Tag> children;
    bool visible;
};

struct Script {
    string name;
    vector<string> expressions;
};

void parseDML(const string& filename, const string& contents, map<string, Tag>& dmlFiles) {
    Tag root;
    root.name = "dml";
    root.visible = true;

    stack<Tag*> tagStack;
    tagStack.push(&root);

    istringstream iss(contents);
    string token;

    while (iss >> token) {
        if (token[0] == '<') {
            if (token[1] == '/') {
                tagStack.pop();
            } else {
                Tag* currentTag = tagStack.top();
                Tag newTag;
                newTag.name = token.substr(1, token.size() - 2);
                newTag.visible = true;
                currentTag->children.push_back(newTag);
                tagStack.push(&currentTag->children.back());
            }
        } else if (token == "br") {
            Tag* currentTag = tagStack.top();
            currentTag->contents += "\n";
        } else {
            Tag* currentTag = tagStack.top();
            currentTag->contents += token + " ";
        }
    }

    dmlFiles[filename] = root;
}

void parseDS(const string& filename, const string& contents, map<string, vector<Script>>& dsFiles) {
    vector<Script> scripts;

    istringstream iss(contents);
    string token;
    string currentScriptName;

    while (iss >> token) {
        if (token.back() == '{') {
            currentScriptName = token.substr(0, token.size() - 1);
            Script newScript;
            newScript.name = currentScriptName;
            scripts.push_back(newScript);
        } else if (token == "}") {
            // do nothing
        } else if (token.back() == ';') {
            scripts.back().expressions.push_back(token.substr(0, token.size() - 1));
        } else {
            scripts.back().expressions.back() += " " + token;
        }
    }

    dsFiles[filename] = scripts;
}

void applyExpressions(map<string, Tag>& dmlFiles, const vector<Script>& scripts, const string& filename) {
    for (const auto& script : scripts) {
        for (const auto& expression : script.expressions) {
            size_t equalsPos = expression.find('=');
            size_t notPos = expression.find("!=");
            string varName;
            bool negate = false;

            if (equalsPos != string::npos) {
                varName = expression.substr(0, equalsPos);
                negate = false;
            } else if (notPos != string::npos) {
                varName = expression.substr(0, notPos);
                negate = true;
            }

            size_t dotPos = varName.find('.');
            while (dotPos != string::npos) {
                varName = varName.substr(dotPos + 1);
                dotPos = varName.find('.');
            }

            varName += ".visible";

            bool value = (expression.find("true") != string::npos);

            if (negate) {
                value = !value;
            }

            stack<Tag*> tagStack;
            tagStack.push(&dmlFiles[filename]);

            while (!tagStack.empty()) {
                Tag* currentTag = tagStack.top();
                tagStack.pop();

                if (currentTag->name == varName.substr(0, varName.size() - 8)) {
                    currentTag->visible = value;
                }

                for (auto it = currentTag->children.rbegin(); it != currentTag->children.rend(); ++it) {
                    tagStack.push(&*it);
                }
            }
        }
    }
}

void printDML(const Tag& tag, int width, int height, int& x, int& y) {
    if (tag.visible) {
        if (tag.name == "br") {
            x = 0;
            y++;
        } else if (tag.name == "link" || tag.name == "button") {
            // do nothing
        } else {
            for (char c : tag.contents) {
                if (x >= width) {
                    x = 0;
                    y++;
                }

                if (y >= height) {
                    return;
                }

                cout << c;
                x++;
            }
        }

        for (const auto& child : tag.children) {
            printDML(child, width, height, x, y);
        }
    }
}

int main() {
    map<string, Tag> dmlFiles;
    map<string, vector<Script>> dsFiles;

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        string filename;
        cin >> filename;

        string contents;
        getline(cin, contents);
        getline(cin, contents);

        if (filename.find(".dml") != string::npos) {
            parseDML(filename, contents, dmlFiles);
        } else {
            parseDS(filename, contents, dsFiles);
        }
    }

    int M;
    cin >> M;

    for (int i = 0; i < M; i++) {
        int width, height, numOperations;
        cin >> width >> height >> numOperations;

        string startFilename;
        cin >> startFilename;

        int x = 0, y = 0;

        for (int j = 0; j < numOperations; j++) {
            int clickX, clickY;
            cin >> clickX >> clickY;

            stack<Tag*> tagStack;
            tagStack.push(&dmlFiles[startFilename]);

            while (!tagStack.empty()) {
                Tag* currentTag = tagStack.top();
                tagStack.pop();

                if (currentTag->name == "link" && clickX >= x && clickX < x + currentTag->contents.size() && clickY == y) {
                    startFilename = currentTag->contents;
                    x = 0;
                    y = 0;
                    break;
                } else if (currentTag->name == "button" && clickX >= x && clickX < x + currentTag->contents.size() && clickY == y) {
                    applyExpressions(dmlFiles, dsFiles[startFilename.substr(0, startFilename.size() - 4) + ".ds"], startFilename);
                    break;
                }

                for (auto it = currentTag->children.rbegin(); it != currentTag->children.rend(); ++it) {
                    tagStack.push(&*it);
                }
            }
        }

        x = 0;
        y = 0;

        printDML(dmlFiles[startFilename], width, height, x, y);

        for (int j = 0; j < height; j++) {
            for (int k = 0; k < width; k++) {
                if (k >= width) {
                    break;
                }

                if (j >= height) {
                    break;
                }

                if (k < x) {
                    cout << " ";
                } else {
                    cout << ".";
                }
            }

            cout << endl;
        }
    }

    return 0;
}