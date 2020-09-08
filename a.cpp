#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        int turn = 0;
        while (a != 1 && b != 1) {
            if (a % 2 == 0) {
                a /= 2;
                turn++;
                turn %= 2;
            }
            else if (b % 2 == 0) {
                b /= 2;
                turn++;
                turn %= 2;
            }
            else {
                turn++;
                turn %= 2;
                break;
            }
        }
        if (turn)
            cout << "Sanchit\n";
        else
            cout << "Utkrisht\n";
    }
    return 0;
}
