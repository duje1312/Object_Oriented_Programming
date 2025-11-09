#include <iostream>
#include <string>

std::string word_to_pig_latin(const std::string& word) {
    if (word.empty()) {
        return "";
    }

    char first = std::tolower(word[0]);
    std::string vowels = "aeiou";

    if (vowels.find(first) != std::string::npos) {
        return word + "hay";
    }
    else {
        return word.substr(1) + word[0] + "ay";
    }
}

int main() {
    std::cout << word_to_pig_latin("apple") << std::endl; 
    std::cout << word_to_pig_latin("hello") << std::endl; 

    return 0;
}
