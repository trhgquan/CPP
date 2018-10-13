#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    std::ifstream inputfile("basic_file_string_input.inp"); // input file
    std::ofstream outputfile("basic_file_string_output.out"); // output file

    string input; // input string

    getline(inputfile, input); // read the input string

    outputfile << input.length(); // and print out the string's length


    return 1;
}
