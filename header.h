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

#endif // HEADER_H