#include <iostream>
#include <vector>
#include <fstream>
#include "funcs.h"

int main()
{
  std::vector<float> ref_freq;
  std::vector<float> encrypted_freq;
  std::string ref_string = fileToString("frankenstein.txt");
  ref_freq = createFreq(ref_string);

  for (auto i = ref_freq.begin(); i != ref_freq.end(); i++) {
        std::cout << *i << std::endl;
  }

  std::cout << "\n\n";
  std::string encrypted = encryptCaesar("This is a regular english sentence. \nIt seems like a very simple example to use.", 12);
  encrypted_freq = createFreq(encrypted);

  for (auto i = encrypted_freq.begin(); i != encrypted_freq.end(); i++) {
        std::cout << *i << std::endl;
  }
  return 0;
}
