#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ifstream file("../test.txt");
    string line;

    vector<pair<ll, ll>> ranges;
    while(getline(file, line)) {
        if (line.empty()) break;
        int x = line.find("-");
        ll a = stoll(line.substr(0, x));
        ll b = stoll(line.substr(x + 1));
        ranges.emplace_back(a, b);
    }

    sort(ranges.begin(), ranges.end());
    vector<pair<ll, ll>> merged;
    merged.reserve(ranges.size());

    auto [x, y] = ranges[0];
    for (int i = 1; i < ranges.size(); i++) {
        auto [a, b] = ranges[i];
        if (a <= y) y = max(y, b);
        else {
            merged.emplace_back(x, y);
            x = a, y = b;
        }
    }
    merged.emplace_back(x, y);

    //for (auto [a, b] : merged) cout << a << "-" << b << endl;

    ll fresh = 0;
    for (auto [a, b] : merged)
        fresh += b - a + 1;

    cout << fresh << endl;
}