#include <iostream>
#include <vector>
#include "funcs.h"

int main()
{
      std::vector<float> ref_freq;
      std::vector<float> encrypted_freq;
      std::string ref_string = fileToString("frankenstein.txt");
      ref_freq = createFreq(ref_string);

      std::cout << " Welcome to the demonstration of the cipher lab! \n";
      std::cout << "Here are the refrence frequencies using the novel Frakeenstein: \n";
      for (int i = 0; i < ref_freq.size(); i++)
      {
            std::cout << char(i+65) << ": " << ref_freq.at(i) << std::endl;
      }

      //sample text from Moby-Dick
      std::string string = "Chief among these motives was the overwhelming idea of the great whale himself. Such a portentous and mysterious monster roused all my curiosity. Then the wild and distant seas where he rolled his island bulk; the undeliverable, nameless perils of the whale; these, with all the attending marvels of a thousand Patagonian sights and sounds, helped to sway me to my wish. With other men, perhaps, such things would not have been inducements; but as for me, I am tormented with an everlasting itch for things remote. I love to sail forbidden seas, and land on barbarous coasts. Not ignoring what is good, I am quick to perceive a horror, and could still be social with it—would they let me—since it is but well to be on friendly terms with all the inmates of the place one lodges in.";
      std::string encrypted = encryptCaesar(string, 12);
      encrypted_freq = createFreq(encrypted);


      std::cout << "\nHere is the encrypted string: \n" << encrypted << std::endl;
      std::cout << "\nHere is the decrypted string: \n" << solve(encrypted, ref_freq);

      return 0;
}
