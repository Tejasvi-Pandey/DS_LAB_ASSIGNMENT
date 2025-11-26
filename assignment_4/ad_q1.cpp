#include <iostream>
using namespace std;

void printBinary(int num) {
    int binary[32];      // store binary digits
    int index = 0;

    while (num > 0) {
        binary[index++] = num % 2;
        num /= 2;
    }

    // print in reverse (MSB first)
    for (int i = index - 1; i >= 0; i--) {
        cout << binary[i];
    }
}

int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        printBinary(i);
        cout << " ";
    }

    return 0;
}
