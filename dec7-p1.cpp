#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ifstream file("../test.txt");
    string line;

    vector<string> lines;
    while (getline(file, line)) {
        lines.push_back(line);
    }
    file.close();

    int cols = lines[0].size();
    ll split = 0;
    for (int i = 0; i < lines.size() - 1; i++) {
       for (int j = 0; j < cols; j++) {
           char c = lines[i][j];
           if (c == '.') continue;
           if (c == 'S') lines[i + 1][j] = '|';
           else if (c == '|') {
               if (lines[i+1][j] == '^') {
                   lines[i + 1][j - 1] = '|';
                   lines[i + 1][j + 1] = '|';
                   split++;
               }
               else {
                   lines[i+1][j] = '|';
               }
           }
       }
    }
    cout << split;
}