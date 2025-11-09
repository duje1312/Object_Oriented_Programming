#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

void reverse_strings(std::vector<std::string>& words) {
    for (auto& w : words) {
        std::reverse(w.begin(), w.end());
    }
}

int main() {
    std::vector<std::string> words = { "hello", "world", "c++" };

    std::cout << "Prije okretanja: ";
    for (const auto& w : words) std::cout << w << " ";
    std::cout << std::endl;

    reverse_strings(words);

    std::cout << "Nakon okretanja: ";
    for (const auto& w : words) std::cout << w << " ";
    std::cout << std::endl;

    return 0;
}
