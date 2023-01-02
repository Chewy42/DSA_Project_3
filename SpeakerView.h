/*
Name: Matt Favela
Student ID #: 2390407
Email: mfavela@chapman.edu
Course Number and Section: CPSC350-03
Assignment: PA3

Brief Overview:
This file defines the SpeakerView class and its methods

High Level Decisions Used:
N/A
*/

#ifndef SPEAKERVIEW_H
#define SPEAKERVIEW_H
#include "MonoStack.cpp"
#include "FileProcessor.h"

using namespace std;

class SpeakerView{
    public:
    SpeakerView();
    SpeakerView(std::string inputFileName, char monotonicDirection);
    virtual ~SpeakerView();
    void ShowHeights();
    void CheckHeightDifferences();

    private:
    FileProcessor* fp;
    MonoStack<double>* stack;
    std::string m_speakerViewString;
    int m_columnLen;
    int m_rowLen;
    char m_monotonicDirection;
    double** seats;
    void splitString(std::string str, std::string delimiter);
    int getColumnLength();
    void PrintGrid();
};

#endif