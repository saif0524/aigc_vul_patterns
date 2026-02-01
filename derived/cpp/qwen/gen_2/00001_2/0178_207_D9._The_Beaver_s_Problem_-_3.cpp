#include <iostream>
#include <string>
#include <unordered_map>
#include <sstream>
#include <vector>

using namespace std;

unordered_map<string, int> document_subjects;

void read_training_set() {
    ifstream file1("1/documents.txt");
    string line;
    while (getline(file1, line)) {
        document_subjects[line] = 1;
    }
    file1.close();

    ifstream file2("2/documents.txt");
    while (getline(file2, line)) {
        document_subjects[line] = 2;
    }
    file2.close();

    ifstream file3("3/documents.txt");
    while (getline(file3, line)) {
        document_subjects[line] = 3;
    }
    file3.close();
}

int main() {
    int id;
    string name;
    string text;
    getline(cin, text);
    getline(cin, name);

    // Simulating reading the text until EOF
    stringstream ss;
    string line;
    while (getline(cin, line)) {
        ss << line << "\n";
    }

    // Assuming the name is unique and enough to identify the document
    if (document_subjects.find(name) != document_subjects.end()) {
        cout << document_subjects[name] << endl;
    } else {
        cout << "Unknown" << endl;
    }

    return 0;
}