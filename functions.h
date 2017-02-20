//
// FILE: functions.h
//


#ifndef FUNC_data
#define FUNC_data

#include <vector>
#include "mystring.h"
using namespace std;
namespace data{
    ifstream Open_Input(int& exist_test, char** filename);
    int Get_Width();
    void Format_Input(ifstream& InFile, const int& text_width, vector<hw4::my_string>& lines);
    void Display_Output(vector<hw4::my_string>& text);
    void Save_Output(vector<hw4::my_string>& text);
}
#endif