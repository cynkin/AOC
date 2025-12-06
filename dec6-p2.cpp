#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ifstream file("../input.txt");
    string line;

    vector<string> lines;
    while (getline(file, line)) {
        lines.push_back(line);
    }
    file.close();

    int n = lines.size() - 1;
    vector<bool> operators;
    for (int i = 0; i < lines[n].length(); i++) {
        char c = lines[n][i];
        if (c == '+') operators.push_back(true);
        else if (c == '*') operators.push_back(false);
    }

    size_t cols = lines[0].size();
    for (int i = 1; i < n; i++) cols = max(cols, lines[i].size());

    int k = 0;
    ll res = 0;

    bool add;
    ll value;
    if (operators[k]) {
        add = true;
        value = 0;
    }
    else {
        add = false;
        value = 1;
    }
    
    for (int col = 0; col < cols; col++) {

        bool isEmpty = true;
        for (int i = 0; i < n; i++) {
            if (lines[i][col] != ' ') {
                isEmpty = false;
                break;
            }
        }
        
        if (!isEmpty) {
            ll current = 0;
            for (int row = 0; row < n; row++) {
                char c = lines[row][col];
                if (c == ' ') continue;
                int x = lines[row][col] - '0';
                current = current *10 + x;
            }
            if (add) value += current;
            else value *= current;
        }
        else {
            cout<<value<<endl;
            res += value;
            k++;
            if (operators[k]) {
                add = true;
                value = 0;
            }
            else {
                add = false;
                value = 1;
            }
        }
    }
    cout << res + value;
}