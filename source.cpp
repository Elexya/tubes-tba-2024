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

void printAccepted() {
    std::unordered_map<std::string, std::string> accepting_states = {
        {"aku", "S"}, {"kamu", "S"}, {"dia", "S"}, {"kami", "S"}, {"mereka", "S"},
        {"makan", "P"}, {"minum", "P"}, {"tidur", "P"}, {"bermain", "P"}, {"bekerja", "P"},
        {"nasi", "O"}, {"air", "O"}, {"roti", "O"}, {"bola", "O"}, {"buku", "O"},
        {"di-rumah", "K"}, {"di-sekolah", "K"}, {"di-kantor", "K"}, {"pada-malam-hari", "K"}, {"dengan-cepat", "K"}
    };

    std::unordered_map<std::string, std::vector<std::string>> categorized_states = {
        {"S", {}}, {"P", {}}, {"O", {}}, {"K", {}}
    };

    for (const auto& pair : accepting_states) {
        categorized_states[pair.second].push_back(pair.first);
    }

    std::vector<std::string> categories = {"S", "P", "O", "K"};
    std::vector<std::string> titles = {"Subjek", "Predikat", "Objek", "Keterangan"};

    size_t max_size = 0;
    for (const auto& category : categories) {
        if (categorized_states[category].size() > max_size) {
            max_size = categorized_states[category].size();
        }
    }

    for (const auto& title : titles) {
        std::cout << std::left << std::setw(20) << title << "| ";
    }
    std::cout << std::endl;
    std::cout << std::string(84, '-') << std::endl;

    for (size_t i = 0; i < max_size; ++i) {
        for (size_t j = 0; j < categories.size(); ++j) {
            if (i < categorized_states[categories[j]].size()) {
                std::cout << std::left << std::setw(20) << categorized_states[categories[j]][i];
            } else {
                std::cout << std::left << std::setw(20) << " ";
            }
            if (j < categories.size() - 1) {
                std::cout << "| ";
            }
        }
        std::cout << std::endl;
    }
}



void showAboutUs() {
    // Fill this section with your details
    std::cout << "Anggota Kelompok:\n";
    std::cout << "- Alexander Raditya Nugrahatama\n";
    std::cout << "- Fatah Fadhlur Rohman\n";
    std::cout << "- Rafhiromadoni Sopandi\n";
}