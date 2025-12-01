#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream file("../test.txt");
    string line;

    int res = 0;
    int current = 50;
    while(getline(file, line)) {
        char dir = line[0];
        int deg = stoi(line.substr(1));

        int sign = 1;
        if (dir == 'L') sign = -1;
        deg = sign * deg;

        if (current != 0) {
            current = current + deg;
            while(current > 100) {
                current -= 100;
                res++;
            }
            while(current < 0) {
                current += 100;
                res++;
            }

            if(current == 0 || current == 100) {
                res++;
                current = 0;
            }
        }
        else {
            while (deg > 99) {
                deg -= 100;
                res++;
            }

            while (deg < -99) {
                deg += 100;
                res++;
            }

            current = (deg + 100) % 100;
        }

        cout<<line<<" "<<current<<" "<<res<<endl;
    }
    cout<<res;
    return 0;
}
