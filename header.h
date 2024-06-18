#ifndef HEADER_H
#define HEADER_H

#include <string>
#include <vector>
#include <unordered_map>


class Recognize_K {
public:
    Recognize_K();
    bool recognize(const std::string& word);
private:
    std::vector<std::unordered_map<char, int>> transitions;
    int final_state;
};

class Recognize_O {
public:
    Recognize_O();
    bool recognize(const std::string& word);
private:
    std::vector<std::unordered_map<char, int>> transitions;
    int final_state;
};

class Recognizer_P {
public:
    Recognizer_P();
    bool recognize(const std::string& word);
    bool is_predikat(const std::string& word);
private:
    std::vector<std::unordered_map<char, int>> transitions;
    int final_state;
};

class Recognizer_S {
public:
    Recognizer_S();
    bool recognize(const std::string& word);
    bool is_subject(const std::string& word);
private:
    std::vector<std::unordered_map<char, int>> transitions;
    int final_state;
};

class TokenRecognizer {
public:
    std::vector<std::string> set_token(const std::string& sentence);
};

class Stack {
public:
    void push(const std::string& item);
    void pop();
    std::string top();
    bool is_empty();
private:
    std::vector<std::string> stack;
};

class Validation {
public:
    Validation(Stack& stack);
    void transition(const std::string& token);
    void parse(const std::vector<std::string>& tokens);
    bool validate(const std::vector<std::string>& tokens);
private:
    Stack& stack;
    std::string current_state;
};

#endif // HEADER_H