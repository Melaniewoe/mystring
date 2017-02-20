// FILE: main.cpp
//
// WoeHw3
//

#include <iostream>
#include <fstream>
#include <vector>
#include "mystring.h"
#include "functions.h"

using namespace hw4;
using namespace std;

int main(int argc, char** argv){
    my_string test;
    int number_of_columns;
    vector<my_string> formatted_text; // vector to hold formated text.
    
    ifstream InFile("data.txt"); // open the input file
    if (!InFile.is_open())
        return 0;
    
    number_of_columns = data::Get_Width(); // get number of columns for output //
    
    data::Format_Input(InFile, number_of_columns, formatted_text); // do the work....
    
    InFile.close(); // close input file
    
    data::Display_Output(formatted_text); // Print the output to the screen
    
    data::Save_Output(formatted_text);
}

