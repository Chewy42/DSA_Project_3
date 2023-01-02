#include "FileProcessor.h"
#include <fstream>

using namespace std;

/*
Name Of Function: FileProcessor class constructor

Description of Value Returned: None

Description of Parameters: None

Description of exceptions thrown: None
*/
FileProcessor::FileProcessor(){
    m_fileName = "";
}

/*
Name Of Function: FileProcessor class overloaded constructor

Description of Value Returned: None

Description of Parameters: std::string inputFileName is the file namme of our input

Description of exceptions thrown: None
*/
FileProcessor::FileProcessor(std::string inputFileName){
    m_fileName = inputFileName;
}

/*
Name Of Function: FileProcessor class destructor

Description of Value Returned: None

Description of Parameters: None

Description of exceptions thrown: None
*/
FileProcessor::~FileProcessor(){
    
}

/*
Name Of Function: processFile

Description of Value Returned: std::string of the text in the input file

Description of Parameters: None

Description of exceptions thrown: None
*/
std::string FileProcessor::processFile(){
    std::fstream inputFile;
    std::string text;
    inputFile.open(m_fileName, ios::in);
    for(std::string line; getline(inputFile, line);){
        text += line + "\n";
    }
    inputFile.close();
    return text;
}

/*
Name Of Function: getNumLines

Description of Value Returned: integer of the number of lines in the input file

Description of Parameters: None

Description of exceptions thrown: None
*/
int FileProcessor::getNumLines(){
    std::fstream inputFile;
    int count = 0;
    inputFile.open(m_fileName, ios::in);
    for(std::string line; getline(inputFile, line);){
        count++;
    }
    inputFile.close();
    return count;
}