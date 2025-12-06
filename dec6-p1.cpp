#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ifstream file("../input.txt");
    string line;

    vector<vector<int>> grid;
    vector<string> operators;

    int n = 0;
    while (getline(file, line)) {
        stringstream ss(line);
        string token;
        grid.push_back({});
        while (ss >> token) {
            if (token == "+" || token == "*") operators.push_back(token);
            else grid[n].push_back(stoi(token));
        }
        n++;
    }
    file.close();

    size_t cols = grid[0].size();
    // for (int i = 1; i < grid.size(); i++) cols = max(cols, grid[i].size());
    //
    // for (int i = 0; i < grid.size(); i++) {
    //     while (grid[i].size() != cols) {
    //         grid[i].push_back(0);
    //     }
    // }

    ll res = 0;
    for (int col = 0; col < cols; col++) {
        bool add = true;
        ll current = 0;

        if (operators[col] == "*") {
            current = 1;
            add = false;
        }

        for (int row = 0; row < grid.size() - 1; row++) {
            if (add) current += grid[row][col];
            else current *= grid[row][col];
        }
        res += current;
    }
    cout << res;
}