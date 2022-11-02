#include <iostream>
#include <vector>
#include <fstream>
#include "funcs.h"

std::string fileToString(std::string file)
{
    std::ifstream instr;
	instr.open(file);
    std::string str = "";
    std::string line = "";
    int counter = 0;

    while (getline(instr, line)) {
        str += line;
        counter++;
    }
    instr.close();
    return str;
}

std::vector<float> createFreq(std::string str)
{
    std::vector<float> ref;
    int char_num = 0;
    int char_count = 0;

    for (int i = 1; i <= 26; i++)
    {
        ref.push_back(0);
    }

    for (int i = 0; i < str.length(); i++)
    {
        char_num = (int)str[i];
        if(islower(str[i]))
        {
            ref.at(char_num - 97) += 1;
            char_count++;
        }
        else if (isupper(str[i]))
        {
            ref.at(char_num - 65) += 1;
            char_count++;
        }
    }

    for (int i = 0; i < ref.size(); i++) {
        ref[i] = ref.at(i) / char_count;
    }
    return ref;
}

std::string solve(std::string encrypted_string)
{
    return "";
}

//previous functions
/**
 * A helper function to shift one character by rshift
 */
char shiftChar(char c, int rshift) {
    int num = int(c);
    //for characters that are uppercase
    if (num >= 65 && num <= 90) {
        num = num - 65;
        num = (num + rshift) % 26;
        num += 65;
    }
    //for characters that are lower case
    else if (num >= 97 && num <= 122) {
        num = num - 97;
        num = (num + rshift) % 26;
        num += 97;
    }
    return (char)num;
}

/**
 * Caesar cipher encryption
 */
std::string encryptCaesar(std::string plaintext, int rshift){
    std::string returnStr = "";
    for (int i = 0; i < plaintext.length(); i++) {
        if (isalpha(plaintext[i])) {
            returnStr += shiftChar(plaintext[i], rshift);
        } else {
            returnStr += plaintext[i];
        }
    }
    return returnStr;
}
