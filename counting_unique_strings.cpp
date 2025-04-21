#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct UniqueString {
    string unique_string;
    int number_of_appearances;
};

string convertToLowercase(string input_string) {
    for (int i = 0; i < input_string.length(); i++) {
        input_string[i] = tolower(input_string[i]);
    }

    return input_string;
}

const int MAX_WORDS = 50;
int main() {
    string file_name;

    // Gets the file name from the user and stores it in a variable
    cout << "Enter the name of your text file, including the file extension: ";
    cin >> file_name;
    ifstream input_file(file_name);

    // Reads the current line in the file
    string current_line;

    // An array that will contain each unique string found using the UniqueString structure
    // Fills each position with null values so that the program knows when to stop searching
    // for existing string appearances later in the code
    UniqueString all_words[MAX_WORDS];
    for (int i = 0; i < MAX_WORDS; i++) {
        all_words[i].unique_string = "";
        all_words[i].number_of_appearances = 0;
    }

    // Steps through each line in the text file and stores it in current_line
    for (int index = 0; index < MAX_WORDS; index++) {
        getline(input_file, current_line);

        // Converts current_line to lowercase to avoid unwanted duplicates
        current_line = convertToLowercase(current_line);

        // Checks if the current_line is unique or has previously been stored in all_words
        for (int nested_index = 0; nested_index < MAX_WORDS; nested_index++) {
            if (all_words[nested_index].unique_string == current_line) {
                all_words[nested_index].number_of_appearances += 1;
                break;
            } else if (all_words[nested_index].unique_string == "") {
                all_words[nested_index].unique_string = current_line;
                all_words[nested_index].number_of_appearances += 1;
                break;
            }
        }
        
    }

    // Prints the value of each filled value in the format requested by the project parameters
    for (int i = 0; i < MAX_WORDS; i++) {
        if (all_words[i].unique_string == "") {
            break;
        } else {
            cout << all_words[i].unique_string << " " << all_words[i].number_of_appearances << endl;
        }
    }
    return 0;
}