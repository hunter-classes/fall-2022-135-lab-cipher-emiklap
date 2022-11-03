#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "funcs.h"

std::string star_lyrics = "Starlight, starlight, With you shining in my mind (ooh, ah), Shine our light all through the night, Close to me, you are all of me, I'm seeing star lights, star lights, Us against the sunrise (sunrise), Shine our light all through the night, Close to me, you are all o f me";
std::string cpp_textbook = "With a variable, you can access a value at a fixed location. With a pointer, the location can vary. This capability has many useful applications. Pointers can be used to share values among different parts of a program. Point­ers allow allocation of values on demand. Furthermore, as you will see in Chapter 10, pointers are neces­ sary for implementing programs that manipulate objects of multiple related types. In the first half of this chapter, you will learn how to define pointers and access the values to which they point.";

std::string ref_string_1 = fileToString("little-women.txt");
std::vector<float> ref_freq_1 = createFreq(ref_string_1);

std::string ref_string_2 = fileToString("words.txt");
std::vector<float> ref_freq_2 = createFreq(ref_string_2);


// add new tests!!!!
TEST_CASE("Previous Task: Caesar Cipher")
{
    CHECK(encryptCaesar("Way to Go!", 5) == "Bfd yt Lt!");
    CHECK(encryptCaesar("Hello, World!", 10) == "Rovvy, Gybvn!");
    CHECK(encryptCaesar("Jackdaws love my big sphinx of quartz", 12) == "Vmowpmie xahq yk nus ebtuzj ar cgmdfl");
}

TEST_CASE("Current Task: Solve decryption")
{
    CHECK( solve( encryptCaesar(star_lyrics, 5), ref_freq_1) == star_lyrics );
    CHECK( solve( encryptCaesar(cpp_textbook, 24), ref_freq_1) == cpp_textbook );
    CHECK( solve( encryptCaesar(star_lyrics, 18), ref_freq_2) == star_lyrics );
    CHECK( solve( encryptCaesar(cpp_textbook, 7), ref_freq_2) == cpp_textbook );
    CHECK( solve( encryptCaesar(cpp_textbook, 0), ref_freq_2) == cpp_textbook );

}
