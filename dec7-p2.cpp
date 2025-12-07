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

    int cols = lines[0].size();
    vector<ll> count(cols, 0);
    for (int i = 0; i < lines.size() - 1; i++) {
        for (int j = 0; j < cols; j++) {
           char c = lines[i][j];
           if (c == '.') continue;
           if (c == 'S') {
               lines[i + 1][j] = '|';
               count[j] = 1;
           }
           else if (c == '|') {
               if (lines[i+1][j] == '^') {
                   lines[i + 1][j - 1] = '|';
                   lines[i + 1][j + 1] = '|';
                   count[j - 1] += count[j];
                   count[j + 1] += count[j];
                   count[j] = 0;
               }
               else {
                   lines[i+1][j] = '|';
               }
           }
        }
        for (int k = 0; k < cols; k++) {
            cout << count[k] << " ";
        }
        cout << endl;
    }
    ll res = 0;
    for (int i = 0; i < cols; i++) {
        res += count[i];
    }
    cout << res << endl;
}

