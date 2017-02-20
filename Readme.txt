*******************************************************
*  Description of the program
*******************************************************

The program “my_string” implement a text formatting program. It takes 
a text file called “data.txt” as an input file. The file has a few lines 
of text (column). The program will ask the user the number of column 
and format the text file according to the number that was asked. When 
the word needs to change line in the middle of it, it will use (-) 
to connect a word between lines.

*******************************************************
*  Source files
*******************************************************

Name:  main.cpp
   Main program. It contains a program utilizing the class my_string. 
   It takes input file of data.txt. The program then takes the column 
   that the user enter and then format that input text into a vector. 
   And also print the output to the screen.

Name:  mystring.h
   Contains the definition for the class my_string.  

Name: mystring.cpp
   Defines and implements the my_string class. 

Name: functions.h
   It contains the function for Hw4

Name: functions.cpp
   Defines and implements of functions.h

*******************************************************
*  Circumstances of programs
*******************************************************

   The program runs successfully.  
   
   The program was developed and tested on Xcode. It was 
   compiled, run, and tested on gcc ouray.cudenver.edu.


*******************************************************
*  How to build and run the program
*******************************************************

1. Uncompress the homework.  The homework file is compressed.  
   To uncompress it use the following commands 
       % unzip [WoeHW3]

   Now you should see a directory named homework with the files:
        main.cpp
        mystring.h
        mystring.cpp
	functions.h
	functions.cpp
        makefile
        Readme.txt

2. Build the program.

    Change to the directory that contains the file by:
    % cd [WoeHW3] 

    Compile the program by:
    % make

3. Run the program by:
   % ./[mystring]

4. Delete the obj files, executables, and core dump by
   %./make clean
