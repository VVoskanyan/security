#include <iostream>
#include <string>
#include <bitset>
#include <cstdlib>
#include <ctime>

// Random bits key generation
std::string randKey(int p) {
    std::string key1 = "";
    for (int i = 0; i < p; ++i) {
        int temp = rand() % 2;
        key1 += std::to_string(temp);
    }
    return key1;
}

// Function to implement bit XOR
std::string exor(const std::string& a, const std::string& b) {
    std::string temp = "";
    for (std::size_t i = 0; i < a.length(); ++i) {
        temp += (a[i] == b[i]) ? '0' : '1';
    }
    return temp;
}

int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    // Feistel Cipher
    std::string PT = "Hello";
    std::cout << "Plain Text is: " << PT << std::endl;

    // Converting the plain text to ASCII
    std::string PT_Bin = "";
    for (char ch : PT) {
        PT_Bin += std::bitset<8>(ch).to_string();
    }

    std::size_t n = PT_Bin.length() / 2;
    std::string L1 = PT_Bin.substr(0, n);
    std::string R1 = PT_Bin.substr(n);
    std::size_t m = R1.length();

    // Generate Key K1 for the first round
    std::string K1 = randKey(m);

    // Generate Key K2 for the second round
    std::string K2 = randKey(m);

    // First round of Feistel
    std::string f1 = exor(R1, K1);
    std::string R2 = exor(f1, L1);
    std::string L2 = R1;

    // Second round of Feistel
    std::string f2 = exor(R2, K2);
    std::string R3 = exor(f2, L2);
    std::string L3 = R2;

    // Cipher text
    std::string binData = L3 + R3;
    std::cout << "Cipher Text: " << binData << std::endl;

    // Decryption
    std::string L4 = L3;
    std::string R4 = R3;

    std::string f3 = exor(L4, K2);
    std::string L5 = exor(R4, f3);
    std::string R5 = L4;

    std::string f4 = exor(L5, K1);
    std::string L6 = exor(R5, f4);
    std::string R6 = L5;

    std::string PT1 = L6 + R6;

    // Display a message before retrieved plain text
    std::cout << "Retrieved Plain Text: ";

    // Display retrieved plain text as ASCII characters
    for (std::size_t i = 0; i < PT1.length(); i += 8) {
        std::string tempData = PT1.substr(i, 8);
        int decimalData = std::stoi(tempData, nullptr, 2);
        char characterData = static_cast<char>(decimalData);
        std::cout << characterData;
    }
    std::cout << std::endl;

    return 0;
}