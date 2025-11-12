#include <iostream>
#include <string>
using namespace std;

void fix_spaces(string& text) {
    size_t pos = text.find("  ");
    while (pos != string::npos) {
        text.erase(pos, 1);
        pos = text.find("  ");
    }
    for (size_t i = 1; i < text.size(); ++i) {
        if ((text[i] == ',' || text[i] == '.') && text[i - 1] == ' ') {
            text.erase(i - 1, 1);
            i--;
        }
    }
    for (size_t i = 0; i < text.size(); ++i) {
        if (text[i] == ',') {
            if (i + 1 < text.size() && text[i + 1] != ' ') {
                text.insert(i + 1, " ");
            }
        }
    }
}

int main() {
    string text = "Puno   razmaka ,i tocka .";
    fix_spaces(text);
    cout << text << endl;
    return 0;
}
