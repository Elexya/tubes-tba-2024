#include "header.h"
#include <iostream>
#include <vector>
#include <string>

int main() {
    std::string sentence;
    std::cout << "Enter a sentence to tokenize and validate: ";
    std::getline(std::cin, sentence);

    Stack token_stack;
    TokenRecognizer token_recognizer;
    Validation validator(token_stack);

    std::vector<std::string> tokens = token_recognizer.set_token(sentence);
    std::cout << "Tokens: ";
    for (const std::string& token : tokens) {
        std::cout << token << " ";
    }
    std::cout << std::endl;

    bool is_valid = validator.validate(tokens);
    if (is_valid) {
        std::cout << "'" << sentence << "' is valid." << std::endl;
    } else {
        std::cout << "'" << sentence << "' is not valid." << std::endl;
    }

    return 0;
}
