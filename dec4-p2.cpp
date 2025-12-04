#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream file("../input.txt");
    string line;

    vector<string> grid;
    while(getline(file, line)) {
        grid.push_back(line);
    }
    file.close();

    vector<string> temp = grid;

    int R = grid.size();
    int C = grid[0].size();

    int res = 0;
    while (true) {
        grid = temp;
        int current = 0;
        int drs[3] = {-1, 0, 1};
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (grid[i][j] == '.') continue;
                int neighbours = 0;
                for (int x : drs) for (int y: drs) {
                    if (x == 0 && y == 0) continue;
                    int nx = i + x, ny = j + y;
                    if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
                    if (grid[nx][ny] == '@') neighbours++;
                }
                if (neighbours < 4) {
                    current++;
                    temp[i][j] = '.';
                }
            }
        }
        cout<<current<<endl;
        if (current == 0) break;
        res += current;
    }
    cout<<res;
}