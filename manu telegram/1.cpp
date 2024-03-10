#include <bits/stdc++.h>
using namespace std;

int factorial(int n) {
    if (n == 0 || n == 1)
        return 1;
    return (n * factorial(n - 1)) % 7;
}

int calculateCombination(int x, int r) {
    int numerator = factorial(x);
    int denominator = (factorial(r) * factorial(x - r)) % 7;
    

    int denominatorInverse = 1;  
    for (int i = 1; i <= 5; i++) { 
        denominatorInverse = (denominatorInverse * denominator) % 7;
    }

    int result = (numerator * denominatorInverse) % 7;
    return result;
}

int main() {
    int x, y;
    cin >> x >> y;

    int sum = 0;
    for (int i = 1; i <= y; ++i) {
        int combination = calculateCombination(x, i);
        sum = (sum + combination) % 7;
    }

   cout << sum << endl;

    return 0;
}
