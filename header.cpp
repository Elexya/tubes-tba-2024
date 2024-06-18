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