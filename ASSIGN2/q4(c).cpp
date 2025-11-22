#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char str[100], result[100];
    cout << "Enter a string: ";
    cin.getline(str, 100);

    int j = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i]!='a' && str[i]!='e' && str[i]!='i' && str[i]!='o' && str[i]!='u') {
            result[j] = str[i];
            j++;
        }
    }
    result[j] = '\0';

    cout << "String without vowels: " << result << endl;
    return 0;
}