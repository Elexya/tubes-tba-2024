#include "header.h"
#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <sstream>

// Implementation of Recognize_K class
Recognize_K::Recognize_K() {
    final_state = 100;
    transitions.resize(18);  // Adjust size as needed

    transitions[0]['d'] = 1;
    transitions[1]['i'] = 2;
    transitions[2][' '] = 3;
    transitions[3]['r'] = 4; transitions[3]['k'] = 5;
    transitions[4]['u'] = 6;
    transitions[5]['o'] = 9; transitions[5]['a'] = 10;
    transitions[6]['m'] = 7;
    transitions[7]['a'] = 8;
    transitions[8]['h'] = 100;
    transitions[9]['s'] = 100;
    transitions[10]['n'] = 11; transitions[10]['m'] = 14;
    transitions[11]['t'] = 12;
    transitions[12]['i'] = 13;
    transitions[13]['n'] = 100;
    transitions[14]['a'] = 15; transitions[14]['p'] = 16;
    transitions[15]['r'] = 100;
    transitions[16]['u'] = 17;
    transitions[17]['s'] = 100;
}

bool Recognize_K::recognize(const std::string& word) {
    int curr_state = 0;
    for (char letter : word) {
        if (transitions[curr_state].count(letter)) {
            curr_state = transitions[curr_state][letter];
        } else {
            curr_state = -1;
        }
    }
    return curr_state == final_state;
}

// Implementation of Recognize_O class
Recognize_O::Recognize_O() {
    final_state = 100;
    transitions.resize(21);  // Adjust size as needed

    transitions[0]['g'] = 1; transitions[0]['b'] = 4; transitions[0]['p'] = 7; transitions[0]['f'] = 12; transitions[0]['m'] = 15;
    transitions[1]['a'] = 2;
    transitions[2]['m'] = 3;
    transitions[3]['e'] = 100;
    transitions[4]['u'] = 5;
    transitions[5]['k'] = 6;
    transitions[6]['u'] = 100;
    transitions[7]['i'] = 8;
    transitions[8]['a'] = 9;
    transitions[9]['n'] = 11;
    transitions[11]['o'] = 100;
    transitions[12]['i'] = 13;
    transitions[13]['l'] = 14;
    transitions[14]['m'] = 100;
    transitions[15]['a'] = 16;
    transitions[16]['k'] = 17;
    transitions[17]['a'] = 18;
    transitions[18]['n'] = 19;
    transitions[19]['a'] = 20;
    transitions[20]['n'] = 100;
}

bool Recognize_O::recognize(const std::string& word) {
    int curr_state = 0;
    for (char letter : word) {
        if (transitions[curr_state].count(letter)) {
            curr_state = transitions[curr_state][letter];
        } else {
            curr_state = -1;
        }
    }
    return curr_state == final_state;
}

// Implementation of Recognizer_P class
Recognizer_P::Recognizer_P() {
    final_state = 100;
    transitions.resize(27);  // Adjust size as needed

    transitions[0]['b'] = 1; transitions[0]['m'] = 7;
    transitions[1]['e'] = 2;
    transitions[2]['r'] = 3; transitions[2]['l'] = 9;
    transitions[3]['m'] = 4;
    transitions[4]['a'] = 5;
    transitions[5]['i'] = 6;
    transitions[6]['n'] = 100;  // "bermain"
    transitions[7]['e'] = 8;
    transitions[8]['m'] = 16; transitions[8]['n'] = 22;
    transitions[9]['a'] = 10;
    transitions[10]['j'] = 11;
    transitions[11]['a'] = 12;
    transitions[12]['r'] = 100;  // "belajar"
    transitions[16]['b'] = 17;
    transitions[17]['a'] = 18;
    transitions[18]['c'] = 19;
    transitions[19]['a'] = 100;  // "membaca"
    transitions[22]['o'] = 23;
    transitions[23]['n'] = 24;
    transitions[24]['t'] = 25;
    transitions[25]['o'] = 26;
    transitions[26]['n'] = 100;  // "menonton"
}

bool Recognizer_P::recognize(const std::string& word) {
    int curr_state = 0;
    for (char letter : word) {
        if (transitions[curr_state].count(letter)) {
            curr_state = transitions[curr_state][letter];
        } else {
            curr_state = -1;
        }
    }
    return curr_state == final_state;
}

bool Recognizer_P::is_predikat(const std::string& word) {
    return recognize(word);
}

// Implementation of Recognizer_S class
Recognizer_S::Recognizer_S() {
    final_state = 100;
    transitions.resize(14);  // Adjust size as needed

    transitions[0]['s'] = 1; transitions[0]['k'] = 4; transitions[0]['a'] = 7; transitions[0]['d'] = 10;
    transitions[1]['a'] = 2;
    transitions[2]['y'] = 3;
    transitions[3]['a'] = 100;  // "saya"
    transitions[4]['a'] = 5; transitions[4]['i'] = 12;
    transitions[5]['m'] = 6;
    transitions[6]['i'] = 100;  // "kami"
    transitions[7]['n'] = 8;
    transitions[8]['d'] = 9;
    transitions[9]['a'] = 100;  // "anda"
    transitions[10]['i'] = 11;
    transitions[11]['a'] = 100;  // "dia"
    transitions[12]['t'] = 13;
    transitions[13]['a'] = 100;  // "kita"
}

bool Recognizer_S::recognize(const std::string& word) {
    int curr_state = 0;
    for (char letter : word) {
        if (transitions[curr_state].count(letter)) {
            curr_state = transitions[curr_state][letter];
        } else {
            curr_state = -1;
        }
    }
    return curr_state == final_state;
}

bool Recognizer_S::is_subject(const std::string& word) {
    return recognize(word);
}

// Implementation of TokenRecognizer class
std::vector<std::string> TokenRecognizer::set_token(const std::string& sentence) {
    std::vector<std::string> tokens;
    std::stringstream ss(sentence);
    std::string word;
    while (ss >> word) {
        std::transform(word.begin(), word.end(), word.begin(), ::tolower);
        Recognizer_S recognizer_s;
        Recognizer_P recognizer_p;
        Recognize_O recognize_o;
        Recognize_K recognize_k;

        if (recognizer_s.is_subject(word)) {
            tokens.push_back("S");
        } else if (recognizer_p.is_predikat(word)) {
            tokens.push_back("P");
        } else if (recognize_o.recognize(word)) {
            tokens.push_back("O");
        } else {
            bool found_keterangan = false;
            for (size_t i = 0; i < word.size(); ++i) {
                std::string phrase = word.substr(0, i + 1);
                if (recognize_k.recognize(phrase)) {
                    tokens.push_back("K");
                    found_keterangan = true;
                    break;
                }
            }
            if (!found_keterangan) {
                tokens.push_back("UNKNOWN");
            }
        }
    }
    return tokens;
}

// Implementation of Stack class
void Stack::push(const std::string& item) {
    stack.push_back(item);
}

void Stack::pop() {
    if (!stack.empty()) {
        stack.pop_back();
    }
}

std::string Stack::top() {
    return stack.empty() ? "" : stack.back();
}

bool Stack::is_empty() {
    return stack.empty();
}

// Implementation of Validation class
Validation::Validation(Stack& stack) : stack(stack), current_state("q0") {}

void Validation::transition(const std::string& token) {
    if (current_state == "q1") {
        if (token == "S") {
            stack.push("S");
            current_state = "q2";
        }
    } else if (current_state == "q2") {
        if (token == "P") {
            stack.pop();
            current_state = "q3";
        }
    } else if (current_state == "q3") {
        if (token == "O") {
            current_state = "q4";
        } else if (token == "K") {
            current_state = "q5";
        } else {
            current_state = "invalid";
        }
    } else if (current_state == "q4") {
        if (token == "K") {
            current_state = "q5";
        } else {
            current_state = "invalid";
        }
    } else if (current_state == "q5") {
        current_state = "invalid";
    }
}

void Validation::parse(const std::vector<std::string>& tokens) {
    stack.push("#");
    current_state = "q1";
    for (const std::string& token : tokens) {
        transition(token);
        if (current_state == "invalid") {
            break;
        }
    }
    stack.pop();
    if (current_state == "q3" || current_state == "q4" || current_state == "q5") {
        current_state = "q6";
    }
}

bool Validation::validate(const std::vector<std::string>& tokens) {
    parse(tokens);
    return stack.is_empty() && current_state == "q6";
}
