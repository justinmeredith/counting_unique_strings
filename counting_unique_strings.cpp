#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct UniqueString {
    string unique_string;
    int number_of_appearances;
};

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
    UniqueString all_words[50];
    for (int i = 0; i < 50; i++) {
        all_words[i].unique_string = "";
        all_words[i].number_of_appearances = 0;
    }

    // Keeps track of whether the current line is unique or previously stored
    bool unique_instance_of_string = false;

    // Steps through each line in the text file and stores it in current_line
    for (int index = 0; index < 50; index++) {
        getline(input_file, current_line);
        //current_line = tolower(current_line);

        // Checks if the current_line is unique or has previously been stored in all_words
        for (int nested_index = 0; nested_index < 50; nested_index++) {
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

    for (int i = 0; i < 50; i++) {
        if (all_words[i].unique_string == "") {
            break;
        } else {
            cout << all_words[i].unique_string << " " << all_words[i].number_of_appearances << endl;
        }
    }
    return 0;
}