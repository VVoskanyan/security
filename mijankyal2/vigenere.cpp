#include <iostream>
#include <string>

std::string vigenere_encrypt(const std::string& plain_text, const std::string& key) {
    std::string result;
    size_t key_index = 0;

    for (char ch : plain_text) {
        if (std::isalpha(ch)) {
            char base = std::isupper(ch) ? 'A' : 'a';
            char encrypted_char = (ch - base + key[key_index] - 'A') % 26 + base;
            result += encrypted_char;
            key_index = (key_index + 1) % key.length();
        } else {
            result += ch;
        }
    }

    return result;
}

std::string vigenere_decrypt(const std::string& cipher_text, const std::string& key) {
    std::string result;
    size_t key_index = 0;

    for (char ch : cipher_text) {
        if (std::isalpha(ch)) {
            char base = std::isupper(ch) ? 'A' : 'a';
            char decrypted_char = (ch - base - (key[key_index] - 'A') + 26) % 26 + base;
            result += decrypted_char;
            key_index = (key_index + 1) % key.length();
        } else {
            result += ch;
        }
    }

    return result;
}

int main() {
    std::string plain_text = "HelloWorld";
    std::string key = "KEY";

    std::string encrypted_text = vigenere_encrypt(plain_text, key);
    std::cout << "Encrypted: " << encrypted_text << std::endl;

    std::string decrypted_text = vigenere_decrypt(encrypted_text, key);
    std::cout << "Decrypted: " << decrypted_text << std::endl;

    return 0;
}