#include "header.h"

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

void clearConsole() {
    #ifdef _WIN32
    system("cls");
    #else
    system("clear");
    #endif
}

int main() {
    PDAHTMLParser parser;

    showAboutUs();
    std::cout << std::endl;
    printAccepted();

    std::string sentence;
    while (true) {
        std::cout << "> ";
        std::getline(std::cin, sentence);

        if (sentence == "]") {
            std::cout << "Exiting...\n";
            break;
        }

        clearConsole();
        showAboutUs();
        printAccepted();

        auto result = parser.parse(sentence);
        std::cout << "> " << sentence << "\n";
        std::cout << "Result: " << result.first << "\n";
        std::cout << "Sentence Structure: ";
        for (const auto& token : result.second) {
            std::cout << token << "-";
        }
        std::cout << "\n";
    }

    return 0;
}
