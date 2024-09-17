//
// Ian Scheetz
// One-Time Pad Assignment
// 9/15/24

#include <iostream>
#include <string>
#include <vector>

std::vector<int> ConvertToNumVector(std::string);
std::vector<int> EncryptInt(std::vector<int>, std::vector<int>);
std::vector<int> DecryptInt(std::vector<int>, std::vector<int>);
std::vector<char> ToString(std::vector<int>);

int main()
{
    std::string keyIn;
    std::string ptIn;
    std::cout << "Please input a key: \n";
    std::getline(std::cin, keyIn, '\n');
    std::cout << std::endl;
    std::cout << "Please input the plaintext: \n";
    std::getline(std::cin, ptIn, '\n');
    std::cout << std::endl;

    // print the key converted to numbers
    std::cout << std::endl;
    std::vector<int> convertedKey = ConvertToNumVector(keyIn);
    std::cout << "Here is the converted key: \n";
    for (auto b = convertedKey.begin(); b != convertedKey.end(); b++)
    {
        std::cout << *b << " ";
    }
    std::cout << std::endl;

    // print the encrypted text
    std::cout << std::endl;
    std::cout << "Here is the encrypted text: " << std::endl;
    std::vector<int> convertedPT = ConvertToNumVector(ptIn);
    std::vector<int> encryptedInt = EncryptInt(convertedKey, convertedPT);
    std::vector<char> encryptedText = ToString(encryptedInt);
    for (auto d = encryptedText.begin(); d != encryptedText.end(); d++)
    {
        std::cout << *d;
    }
    std::cout << std::endl;

    // print the decrypted text
    std::cout << std::endl;
    std::vector<int> decryptedInt = DecryptInt(convertedKey, encryptedInt);
    std::vector<char> decryptedText = ToString(decryptedInt);
    std::cout << "Here is the decrypted text: " << std::endl;
    for (auto f = decryptedText.begin(); f != decryptedText.end(); f++)
    {
        std::cout << *f;
    }
    std::cout << std::endl;
}

std::vector<int> ConvertToNumVector(std::string input)
{
    std::vector<int> output;
    std::vector<char> newIn;

    for(int i = 0; i < input.length(); ++i) 
    {
        newIn.push_back(input[i]);
    }
    for (auto a = newIn.begin(); a != newIn.end(); ++a) 
    {   
        output.push_back(*a);
    }
    return output;
}

std::vector<int> EncryptInt(std::vector<int> key, std::vector<int> plain)
{
    std::vector<int> cipher;
    int temp;
    for (int i = 0; i < plain.size(); i++)
    {
        temp = plain.at(i) - key.at(i) % 10;
        cipher.push_back(temp);
    }
    return cipher;
}

std::vector<int> DecryptInt(std::vector<int> key, std::vector<int> cipher)
{
    std::vector<int> plain;
    int temp;
    for (int i = 0; i < cipher.size(); i++)
    {
        temp = cipher.at(i) + key.at(i) % 10;
        plain.push_back(temp);
    }
    return plain;
}

std::vector<char> ToString(std::vector<int> text) 
{
    std::vector<char> plain;
    for (auto a = text.begin(); a != text.end(); ++a)
    {
        plain.push_back(*a);
    }
    return plain;
}
