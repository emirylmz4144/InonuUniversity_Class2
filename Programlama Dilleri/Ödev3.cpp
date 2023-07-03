#include <iostream>
#include <fstream>
#include <string>
/*
Muhammed Emir Yılmaz
02220224570
*/

using namespace std;



int main() {
    ifstream input("screen.txt");
    string line;

printf("screen.txt adinda dosya okunmalidir");
    // Loop through the file and extract the methods and attributes for each class
    while (getline(input, line)) {
        if (line.find("class ") == 0) {
            // Found a class, extract its name
            size_t pos = line.find(" ");
            string class_name = line.substr(pos + 1, line.find("{") - pos - 1);
            cout << "Class: " << class_name << endl;

            // Loop through the class definition and extract its methods and attributes
            while (getline(input, line)) {
                if (line.find("};") == 0) {
                    // End of class definition
                    break;
                } else if (line.find("(") != string::npos && line.find(")") != string::npos) {
                    // Found a method
                    cout << "- " << line << endl;
                } else if (line.find(";") != string::npos) {
                    // Found an attribute
                    cout << "- " << line << endl;
                }
            }

            cout << endl; // Add a blank line between classes
        }
    }

    return 0;
}