#include "header.h"

// void showMenu() {
//     std::cout << "1. Input Sentence\n";
//     std::cout << "2. About Us\n";
//     std::cout << "3. Exit\n";
//     std::cout << "Select an option: ";
// }

// void processInputSentence(PDAHTMLParser& parser) {
//     std::cin.ignore(); // To clear the newline character from the input buffer
//     std::string sentence;
//     std::cout << "Enter your sentence: ";
//     std::getline(std::cin, sentence);

//     auto result = parser.parse(sentence);
//     std::cout << "Result: " << result.first << "\n";
//     std::cout << "Sentence Structure: ";
//     for (const auto& token : result.second) {
//         std::cout << token << "-";
//     }
//     std::cout << "\n";
// }

void showAboutUs() {
    // Fill this section with your details
    std::cout << "Anggota Kelompok:\n";
    std::cout << "- Alexander Raditya Nugrahatama\n";
    std::cout << "- Fatah Fadhlur Rohman\n";
    std::cout << "- Rafhiromadoni Sopandi\n";
}