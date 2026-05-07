#include <iostream>
#include <vector>
using namespace std;

int main() {
    int states, symbols;
    cin >> states >> symbols;
    vector<vector<int>> transition(states, vector<int>(symbols));
    for(int i = 0; i < states; i++) {
        for(int j = 0; j < symbols; j++) {
            cin >> transition[i][j];
        }
    }
    int start;
    cin >> start;
    int acceptCount;
    cin >> acceptCount;
    vector<bool> accept(states, false);
    for(int i = 0; i < acceptCount; i++) {
        int x;
        cin >> x;
        accept[x] = true;
    }
    string input;
    cin >> input;
    int current = start;
    for(char c : input) {
        int symbol = c - '0';
        current = transition[current][symbol];
    }
    if(accept[current])
        cout << "Accepted";
    else
        cout << "Rejected";
    return 0;
}
