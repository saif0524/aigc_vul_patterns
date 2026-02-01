#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpi;

const int MAXN = 50;
const int MAXM = 500;

struct Tag {
    string name;
    bool visible;
};

struct DML {
    string filename;
    vector<Tag> tags;
};

struct DS {
    string filename;
    map<string, vector<pair<string, bool>>> subroutines;
};

DML parseDML(string filename, string content) {
    DML dml;
    dml.filename = filename;
    vector<string> tokens;
    string token;
    for(char c : content) {
        if(c == '<' || c == '>') {
            if(!token.empty()) {
                tokens.push_back(token);
                token.clear();
            }
            token += c;
        } else {
            token += c;
        }
    }
    if(!token.empty()) {
        tokens.push_back(token);
    }
    vector<Tag> stack;
    for(string token : tokens) {
        if(token[0] == '<' && token[1] != '/') {
            string name = token.substr(1, token.size() - 2);
            Tag tag;
            tag.name = name;
            tag.visible = true;
            dml.tags.push_back(tag);
            stack.push_back(tag);
        } else if(token[0] == '<' && token[1] == '/') {
            string name = token.substr(2, token.size() - 3);
            stack.pop_back();
        }
    }
    return dml;
}

DS parseDS(string filename, string content) {
    DS ds;
    ds.filename = filename;
    map<string, vector<pair<string, bool>>> subroutines;
    vector<string> tokens;
    string token;
    for(char c : content) {
        if(c == '{' || c == '}') {
            if(!token.empty()) {
                tokens.push_back(token);
                token.clear();
            }
            token += c;
        } else {
            token += c;
        }
    }
    if(!token.empty()) {
        tokens.push_back(token);
    }
    for(size_t i = 0; i < tokens.size(); i += 3) {
        string subroutineName = tokens[i];
        string expressions = tokens[i + 1];
        vector<pair<string, bool>> expressionList;
        size_t pos = 0;
        while((pos = expressions.find(";")) != string::npos) {
            string expression = expressions.substr(0, pos);
            expressions.erase(0, pos + 1);
            size_t equalsPos = expression.find("=");
            size_t notPos = expression.find("!");
            string varName;
            bool negate = false;
            if(equalsPos != string::npos) {
                varName = expression.substr(0, equalsPos);
                if(notPos != string::npos && notPos < equalsPos) {
                    negate = true;
                }
            } else {
                varName = expression;
            }
            bool value = (expression.find("true") != string::npos);
            expressionList.push_back({varName, negate ? !value : value});
        }
        subroutines[subroutineName] = expressionList;
    }
    ds.subroutines = subroutines;
    return ds;
}

void applySubroutine(DML& dml, DS& ds, string subroutineName) {
    auto subroutine = ds.subroutines[subroutineName];
    for(auto& expression : subroutine) {
        string varName = expression.first;
        bool value = expression.second;
        for(auto& tag : dml.tags) {
            if(tag.name == varName) {
                tag.visible = value;
            }
        }
    }
}

void printDML(DML& dml, int width, int height) {
    vector<vector<char>> screen(height, vector<char>(width, '.'));
    int x = 0, y = 0;
    for(auto& tag : dml.tags) {
        if(tag.name == "br") {
            x = 0;
            y++;
        } else if(tag.name == "script") {
            continue;
        } else if(tag.visible) {
            string text = tag.name;
            for(size_t i = 0; i < text.size(); i++) {
                if(x >= width) {
                    x = 0;
                    y++;
                }
                if(y >= height) {
                    break;
                }
                screen[y][x] = text[i];
                x++;
            }
        }
    }
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            cout << screen[i][j];
        }
        cout << endl;
    }
}

int main() {
    int N;
    cin >> N;
    vector<DML> dmls;
    vector<DS> ds;
    for(int i = 0; i < N; i++) {
        string filename, content;
        cin >> filename >> content;
        if(filename.find(".dml") != string::npos) {
            dmls.push_back(parseDML(filename, content));
        } else {
            ds.push_back(parseDS(filename, content));
        }
    }
    int M;
    cin >> M;
    for(int i = 0; i < M; i++) {
        int width, height, operations;
        string startFile;
        cin >> width >> height >> operations >> startFile;
        DML currentDML = *find_if(all(dmls), [&](DML& dml) { return dml.filename == startFile; });
        for(int j = 0; j < operations; j++) {
            int x, y;
            cin >> x >> y;
            for(auto& tag : currentDML.tags) {
                if(tag.name == "link") {
                    string linkFile = tag.name;
                    DML nextDML = *find_if(all(dmls), [&](DML& dml) { return dml.filename == linkFile + ".dml"; });
                    currentDML = nextDML;
                } else if(tag.name == "button") {
                    string subroutineName = tag.name;
                    applySubroutine(currentDML, ds[0], subroutineName);
                }
            }
        }
        printDML(currentDML, width, height);
    }
    return 0;
}