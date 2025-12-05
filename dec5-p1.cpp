#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ifstream file("../input.txt");
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

    vector<ll> starts;
    starts.reserve(merged.size());
    for (auto [a, b] : merged) starts.push_back(a);

    ll fresh = 0;
    while(getline(file, line)) {
        if (line.empty()) continue;
        ll x = stoll(line);

        auto it = upper_bound(starts.begin(), starts.end(), x);
        if (it == starts.begin()) continue;

        size_t i = (it - starts.begin()) - 1;
        if (merged[i].first <= x && x<= merged[i].second) fresh++;
    }
    cout << fresh << endl;
}