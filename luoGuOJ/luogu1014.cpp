#include <iostream>

using std::cin;
using std::cout;

int main() {
    int n;
    int i = 1, sum = 0;
    cin >> n;
    for (;; i++) {
        sum += i;
        if (sum >= n) break;
    }
    int d = sum - i + 1; //每个z字的第一个    i是z字第一个分母
    if (i % 2 == 0)
        cout << n - d + 1 << "/" << i - (n - d);
    else
        cout << i - (n - d) << "/" << n - d + 1;

}