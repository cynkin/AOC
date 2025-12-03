#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream file("../input.txt");
    string line;

    int k = 12;

    long long res = 0;
    while(getline(file, line)) {
        int n = line.length();

        int count = n - k;
        for (int i = 0; i < line.size() - 1; i++) {
            int first = line[i] - '0';
            int second = line[i + 1] - '0';

            if (count == 0) break;
            if (count > 0 && first < second) {
                count--;
                line.erase(i, 1);
                i = -1;
            }
        }

        line = line.substr(0, k);

        long long value = 0;
        for (int i = 0; i < k; i++) {
            value = value * 10 + (line[i] - '0');
        }

        //cout << value << endl;
        res += value;
    }
    cout << res;
    return 0;
}
