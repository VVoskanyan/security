#include<iostream>
using namespace std;

int gcd(int a, int b) {
    if (a == 0)
        return b;

    if (b == 0)
        return a;

    while (a != b) {
        if (a > b) {
            a = a - b;
        }
        else {
            b = b - a;
        }
    }
    return a;
}

int lcm(int a, int b) {
    return (a * b) / gcd(a, b); // LCM formula using GCD
}

int main() {
    int num1, num2;
    cout << "Enter two numbers: " << endl;
    cin >> num1 >> num2;
    cout << "GCD of " << num1 << " and " << num2 << " is " << gcd(num1, num2) << endl;
    cout << "LCM of " << num1 << " and " << num2 << " is " << lcm(num1, num2) << endl;
    return 0;
}