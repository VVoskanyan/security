#include <iostream>
#include  <string>
using namespace std;

string encodeRLE(const string& input) {
    string encoded;
    int count = 1;

    for (int i = 0; i < input.length(); i++) {
        // If the current character is the same as the next one, increment the count
        while (i < input.length() - 1 && input[i] == input[i + 1]) {
            count++;
            i++;
        }

        // Append the character and its count to the encoded string
        encoded += input[i];
        encoded += to_string(count);

        // Reset the count for the next character
        count = 1;
    }

    return encoded;
}

int main() {
    string input;
    cout << "Enter a string: ";
    getline(cin, input); // Use getline to read the whole line, including spaces

    string encoded = encodeRLE(input);
    cout << "Encoded string: " << encoded << endl;

    return 0;
}