#include <iostream>
#include <string>
#include <algorithm>
#include <limits>

void decimalToBinary(int n, std::string& binary) {
    if (n == 0) {
        return;
    }
    binary += (n % 2 == 0) ? '0' : '1';
    decimalToBinary(n / 2, binary);
}

int getValidInteger() {
    int decimal;
    while (true) {
        std::cout << "Enter a decimal integer: ";
        std::cin >> decimal;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a valid integer." << std::endl;
        }
        else {
            return decimal;
        }
    }
}

int main() {
    // Program intro
    std::cout << "Recursive Binary Converter: Converts Decimal Integers to Binary\n" << "\n";

    int decimal = getValidInteger();

    // Handler if input is 0
    if (decimal == 0) {
        std::cout << "Binary: 0" << std::endl;
        return 0;
    }

    std::string binary = "";
    decimalToBinary(decimal, binary);

    std::reverse(binary.begin(), binary.end());
    std::cout << "Binary: " << binary << std::endl;

    return 0;
}
