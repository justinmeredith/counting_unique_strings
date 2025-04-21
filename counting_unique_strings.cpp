#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct UniqueString {
    string the_unique_string;
    int number_of_appearances;
};

int main() {
    string file_name;
    cout << "Enter the name of your text file, including the file extension: ";
    cin >> file_name;
    ifstream input_file(file_name);
    string current_line;

    for (int index = 0; index < 50; index++) {
        getline(input_file, current_line);
        cout << current_line << endl;
    }
    return 0;
}