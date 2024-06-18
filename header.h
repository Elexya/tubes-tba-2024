#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <sstream>
#include <iterator> // Include this for std::istream_iterator
#include <iomanip>


class DFATokenRecognizer {
public:
    DFATokenRecognizer() {
        accepting_states = {
            {"aku", "S"}, {"kamu", "S"}, {"dia", "S"}, {"kami", "S"}, {"mereka", "S"},
            {"makan", "P"}, {"minum", "P"}, {"tidur", "P"}, {"bermain", "P"}, {"bekerja", "P"},
            {"nasi", "O"}, {"air", "O"}, {"roti", "O"}, {"bola", "O"}, {"buku", "O"},
            {"di-rumah", "K"}, {"di-sekolah", "K"}, {"di-kantor", "K"}, {"pada-malam-hari", "K"}, {"dengan-cepat", "K"}
        };
    }

    std::string recognize(const std::string& token) {
        auto it = accepting_states.find(token);
        if (it != accepting_states.end()) {
            return it->second;
        }
        return "";
    }

private:
    std::unordered_map<std::string, std::string> accepting_states;
};

class PDAHTMLParser {
public:
    PDAHTMLParser() : token_recognizer() {}

    std::pair<std::string, std::vector<std::string>> parse(const std::string& sentence) {
        std::istringstream iss(sentence);
        std::vector<std::string> tokens{std::istream_iterator<std::string>{iss}, std::istream_iterator<std::string>{}};
        std::vector<std::string> structure;

        for (const auto& token : tokens) {
            std::string token_type = token_recognizer.recognize(token);
            if (token_type.empty()) {
                return {"Rejected: " + token, structure};
            }
            structure.push_back(token_type);
        }

        std::vector<std::vector<std::string>> valid_structures = {
            {"S", "P", "O", "K"},
            {"S", "P", "K"},
            {"S", "P", "O"},
            {"S", "P"}
        };

        for (const auto& valid_structure : valid_structures) {
            if (structure == valid_structure) {
                return {"Accepted", structure};
            }
        }
        return {"Rejected", structure};
    }

private:
    DFATokenRecognizer token_recognizer;
};

void showMenu();
void processInputSentence(PDAHTMLParser& parser);
void showAboutUs();
void printAccepted();


#endif // HEADER_H