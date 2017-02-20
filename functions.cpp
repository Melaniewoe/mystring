// FILE: functions.cpp
//
// Implementation of functions.h
// Please see functions.h for documentation

#include <iostream>
#include <vector>
#include <cassert>
#include <fstream>
#include "functions.h"
#include "mystring.h"
using namespace std;

namespace data{
    
        //test if the program can open/read the file
      ifstream Open_Input(int& exist_test, char** filename){
     
     if (exist_test < 2){
     cout << "There was no file specified at run time, the default file 'data.txt will be used'\n";
     ifstream InFile("data.txt");
     if (!InFile.is_open()){
     cout << "The file data.txt or specified file was not found. Please put data.txt\n"
     << "in the default directory or specify a file at run time EX: namexxx thisfile.txt\n";
     return InFile;
     }
     }
     
     ifstream InFile(filename[1]);
     if (!InFile.is_open()){
     cout << "The file " << filename[1] << " was not found.\n"
     << "Please check the filename and try again.\n";
     return InFile;
     }
     return InFile;
     }
     
    int Get_Width(){
        int text_width;
        char input[25] = "n"; // this will check if the user has enter the number
        while (!isdigit(input[0]) || atoi(input) < 1){ // loop until no of column is entered
            cout << "How many columns wide should the output be?\n";
            cin >> input;
            if (isdigit(input[0]) && atoi(input) > 0){
                text_width = atoi(input); // atoi will convert to a int value
                return text_width;
            }
            cout << "Please enter a width as a number greater than 0 EX: 50\n";
        }
        return 0;
    }
    
    void Format_Input(ifstream& InFile, const int& text_width, vector<hw4::my_string>& lines){
        assert(InFile.is_open()); // check a valid open input file.
        hw4::my_string incomming; // this is for in and out text
        hw4::my_string housing; // houses intermediate my_string
        unsigned place = 0;
        int width = text_width; // set width equals to text_width
        bool first = true;
        
        housing.reserve(1000); // reserves space to prevent re-sizing
        incomming.reserve(1000); // reserves space to prevent resizing
        
        //this will get all lines from the file
        for (int i = 0; !InFile.eof(); i++){
            getline(InFile, incomming);
            housing += incomming + " ";
        }
        incomming = "";
        
        
        while (place < housing.length() - 1){
            for (int loop = 0; loop < width && place < housing.length() - 1; loop++){ //for loop control lines written to vector.
                if (first == true && housing[place] == ' '){ width++; } // determines if the charictor is first on a line and also a space, if so increase the width and skip the write.
                else{ incomming += housing[place]; } // if it is not the first and not a space, then apend the char to the string for output
                first = false;// set first = false, as we are through the loop once
                ++place; // increment the place in the original string regardless of space status.
            }
            if (housing[place - 1] != ' ' && housing[place - 1] != '.'){
                
                incomming += '-'; // if the word is seperated in new line, uses -

            }
            
            lines.push_back(incomming); // edited lines are push back into vector
            incomming = ""; // clear the incomming my_string
            width = text_width; // ensure width = proper length regardless of first char space status
            first = true; // set first back to true, to start the loop back on first char.
        }
        
    }
    
    //display output to screen
    void Display_Output(vector<hw4::my_string>& text){
        cout << "The formated text is:\n";
        for (unsigned i = 0; i < text.size(); i++){
            cout << text[i] << endl;
        }
    }
    void Save_Output(vector<hw4::my_string>& text){
        ofstream OutFile("data.out");
        if (!OutFile.is_open()){
            cout << "output.dat did not open\n";
            return;
        }
        for (unsigned i = 0; i < text.size(); i++){ // send output to file
            OutFile << text[i];
            OutFile << endl;
        }
        OutFile.close(); // close file
    }
}