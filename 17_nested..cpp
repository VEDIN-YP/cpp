#include <iostream>
using namespace std;

void greet() {
    cout << "Welcome to C++!" << endl;
}

int add(int a, int b) {
    return a + b;
}

int main() {

    greet();

    int x, y;

    cout << "Enter two numbers: ";
    cin >> x >> y;

    int result = add(x, y);

    cout << "Sum = " << result << endl;

    return 0;
}