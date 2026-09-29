#include <iostream>
#include <string>
#include <cctype> 

using namespace std;

int main() {
    string s;
    cout << "Unesi";
    getline(cin, s);

    for (char& c : s) {
        if (isalpha(c))
            c = toupper(c);
        else if (isdigit(c))
            c = '*';
        else if (isspace(c))
            c = '_';
    }

    cout << s << endl;
    return 0;
}
