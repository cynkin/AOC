#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream file("../input.txt");
    string line;

    int res = 0;
    while(getline(file, line)) {
        int first = 0;
        int second = -1;
        int n = line.length();

        for (int i = 1; i < n; i++) {
            if (i < n - 1 && line[i] > line[first]) {
                second = -1;
                first = i;
            }
            else if (i > first) {
                if (second == -1 || line[i] > line[second])
                    second = i;
            }
        }

        int a = line[first] - '0';
        int b = line[second] - '0';
        //cout<<a<<" "<<b<<endl;
        res += a * 10 + b;
        //cout<<res<<endl;
    }
    cout << res;
    return 0;
}

