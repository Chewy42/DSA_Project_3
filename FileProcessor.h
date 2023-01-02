/*
Name: Matt Favela
Student ID #: 2390407
Email: mfavela@chapman.edu
Course Number and Section: CPSC350-03
Assignment: PA3

Brief Overview:
This file defines the FileProcessor class and its methods
- Takes in an input file name
- Processes the file
- Gives all needed info to the SpeakerView class

High Level Decisions Used:
N/A
*/

#ifndef FILEPROCESSOR_H
#define FILEPROCESSOR_H

#include <string>
#include <iostream>

using namespace std;

class FileProcessor{
    public:
    FileProcessor();
    FileProcessor(std::string inputFileName);
    std::string processFile();
    int getNumLines();
    virtual ~FileProcessor();
    private:
    std::string m_fileName;
};

#endif