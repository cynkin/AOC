#include <bits/stdc++.h>
using namespace std;

bool isRepeated(string s) {
    if (s.empty()) return false;
    string t = (s + s).substr(1, s.size()*2 - 2);
    return (t.find(s) != string::npos);
}

long long func(long long a, long long b) {
    long long res = 0;
    for (long long i = a; i <= b; i++) {
        string s = to_string(i);
        if (isRepeated(s))
            res += i;
    }
    return res;
}

int main() {
    ifstream file("../input.txt");
    string line;
    getline(file, line);
    file.close();

    stringstream ss(line);
    string token;

    long long res = 0;
    while(getline(ss, token, ',')) {
        int dash = token.find('-');
        long long a = stoll(token.substr(0, dash));
        long long b = stoll(token.substr(dash + 1));
        //cout << a << " " << b << endl;
        res += func(a, b);
    }

    cout << res << endl;
    return 0;
}