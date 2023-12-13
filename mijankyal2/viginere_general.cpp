#include <iostream>
#include <string>

using namespace std;

string vigenereEncrypt(const string& plaintext, const string& key) {
    string ciphertext;
    int keyLength = key.length();

    for (int i = 0, j = 0; i < plaintext.length(); ++i) {
        char plainChar = plaintext[i];
        char keyChar = key[j];

        ciphertext += static_cast<char>((plainChar + keyChar) % 128); // Use 128 to include symbols
        j = (j + 1) % keyLength;
    }

    return ciphertext;
}

string vigenereDecrypt(const string& ciphertext, const string& key) {
    string decryptedText;
    int keyLength = key.length();

    for (int i = 0, j = 0; i < ciphertext.length(); ++i) {
        char cipherChar = ciphertext[i];
        char keyChar = key[j];

        decryptedText += static_cast<char>((cipherChar - keyChar + 128) % 128); // Use 128 to include symbols
        j = (j + 1) % keyLength;
    }

    return decryptedText;
}

int main() {
    string plaintext;
    string key;

    cout << "Enter the plaintext: ";
    getline(cin, plaintext);

    cout << "Enter the key: ";
    cin >> key;

    string ciphertext = vigenereEncrypt(plaintext, key);

    cout << "Encrypted text: " << ciphertext << endl;

    string decryptedText = vigenereDecrypt(ciphertext, key);

    cout << "Decrypted text: " << decryptedText << endl;

    return 0;
}