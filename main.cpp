#include "header.h"


int main() {
    PDAHTMLParser parser;

    showAboutUs();

    std::string sentence;
    while (true) {
        std::cout << "> ";
        std::getline(std::cin, sentence);

        if (sentence == "]") {
            std::cout << "Exiting...\n";
            break;
        }

        auto result = parser.parse(sentence);
        std::cout << "Result: " << result.first << "\n";
        std::cout << "Sentence Structure: ";
        for (const auto& token : result.second) {
            std::cout << token << "-";
        }
        std::cout << "\n";
    }

    return 0;
}
