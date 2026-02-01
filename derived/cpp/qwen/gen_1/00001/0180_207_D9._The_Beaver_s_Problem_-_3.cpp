#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int id;
    string name, line;
    cin >> id;
    getline(cin, name);
    getline(cin, name);
    map<string, int> keywords = {
        {"trade", 3},
        {"market", 3},
        {"business", 3},
        {"finance", 3},
        {"economy", 3},
        {"money", 3},
        {"investment", 3},
        {"negotiation", 3},
        {"profit", 3},
        {"sale", 3},
        {"buy", 3},
        {"sell", 3},
        {"deal", 3},
        {"contract", 3},
        {"commerce", 3},
        {"supply", 3},
        {"demand", 3},
        {"transaction", 3},
        {"profit", 3},
        {"venture", 3},
        {"negotiation", 3},
        {"commerce", 3},
        {"technology", 2},
        {"innovation", 2},
        {"software", 2},
        {"hardware", 2},
        {"computing", 2},
        {"internet", 2},
        {"network", 2},
        {"algorithm", 2},
        {"data", 2},
        {"machine", 2},
        {"learning", 2},
        {"artificial", 2},
        {"intelligence", 2},
        {"robot", 2},
        {"coding", 2},
        {"program", 2},
        {"developer", 2},
        {"debug", 2},
        {"source", 2},
        {"code", 2},
        {"iteration", 2},
        {"development", 2},
        {"release", 2},
        {"software", 2},
        {"hardware", 2},
        {"science", 1},
        {"math", 1},
        {"geometry", 1},
        {"algebra", 1},
        {"calculus", 1},
        {"physics", 1},
        {"chemistry", 1},
        {"biology", 1},
        {"astronomy", 1},
        {"weather", 1},
        {"geology", 1},
        {"planet", 1},
        {"universe", 1},
        {"life", 1},
        {"experiment", 1},
        {"hypothesis", 1},
        {"theory", 1},
        {"discovery", 1},
        {"research", 1},
        {"invention", 1},
        {"observation", 1},
        {"measurement", 1},
        {"natural", 1},
        {"science", 1},
        {"education", 1}
    };
    int subject[4] = {0};
    while(getline(cin, line)){
        istringstream iss(line);
        string word;
        while(iss >> word){
            for(auto &c: word){
                if(!isalpha(c)){
                    c = ' ';
                }
                c = tolower(c);
            }
            istringstream wordStream(word);
            string subWord;
            while(wordStream >> subWord){
                if(keywords.find(subWord) != keywords.end()){
                    subject[keywords[subWord]]++;
                }
            }
        }
    }
    int maxSub = 1;
    for(int i = 2; i <= 3; i++){
        if(subject[i] > subject[maxSub]){
            maxSub = i;
        }
    }
    cout << maxSub;
}