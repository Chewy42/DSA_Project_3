#include "SpeakerView.h"
#include <sstream>
#include <iostream>

/*
Name Of Function: SpeakerView class constructor

Description of Value Returned: None

Description of Parameters: None

Description of exceptions thrown: None
*/
SpeakerView::SpeakerView(){
    m_columnLen = 0;
    m_rowLen = 0;
    m_speakerViewString = "";
}

/*
Name Of Function: SpeakerView class overloaded constructor

Description of Value Returned: None

Description of Parameters: std::string inputFileName which is the files name were inputting from. char monotonicDirection which is
either increasing or decerasing for the stack

Description of exceptions thrown: None
*/
SpeakerView::SpeakerView(std::string inputFileName, char monotonicDirection){
    fp = new FileProcessor(inputFileName);
    m_speakerViewString = fp->processFile();
    m_rowLen = fp->getNumLines();
    m_monotonicDirection = monotonicDirection;
    istringstream text(m_speakerViewString);
    string line;
    getline(text,line);
    int len = 0;
    for (int i = 0; i < line.size(); i++)
        if (line[i] == ' ') len++;
    m_columnLen = len + 1;
    
}

/*
Name Of Function: SpeakerView class destructor

Description of Value Returned: None

Description of Parameters: None

Description of exceptions thrown: None
*/
SpeakerView::~SpeakerView(){
    if(fp != NULL){
        delete fp;
    }
    if(stack != NULL){
        delete[] stack;
    }
}


/*
Name Of Function: ShowHeights 

Description of Value Returned: None

Description of Parameters: None

Description of exceptions thrown: None
*/
void SpeakerView::ShowHeights(){
    
    //Replaces all \n of textfile and replaces it with a space
    std::string toReplace("\n");
    for(int i = 0; i < m_rowLen; i++){
        size_t pos = m_speakerViewString.find(toReplace);
        m_speakerViewString.replace(pos, toReplace.length(), " ");
    }

    int startingIndex = 0;
    int currCol = 0;
    //Loop through each column
    for(int i = 0; i < m_columnLen; i++){
        //Prepare text for splitting
        istringstream text(m_speakerViewString);
        std::string del;

        //Initializes a new stack with size of row length and the direction
        //Goes through splitted string and
        int currentIndex = -1;
        stack = new MonoStack<double>(m_rowLen, m_monotonicDirection);
        while(getline(text, del, ' ')){
            currentIndex++;
            if(currentIndex > m_columnLen - 1){
                currentIndex = 0;
            }
            if(currentIndex != currCol){
                continue;
            }else if(currentIndex == currCol){
                stack->push(stod(del));
            }
        }

        //Print out heights with visibility
        cout << "There are: ";
        cout << stack->getTopCount() + 1;
        cout << " person(s) that can see in column: " + to_string(i) + ". Their heights are: ";
        int iterations = stack->getTopCount(); 
        if(stack->size() > 0){
            for(int j = 0; j < iterations + 1; j++){
                cout << stack->getStackArr()[j];
                cout << ", ";
            }
        }else{
            cout << to_string(stack->pop());
        }
        cout << "\n";

        currCol++;

        stack = NULL;
    }
}

/*
Name Of Function: PrintGrid - debugging purposes

Description of Value Returned: None

Description of Parameters: None

Description of exceptions thrown: None
*/
void SpeakerView::PrintGrid(){
    int line_length = 0;
    for (int i = 0; i < m_columnLen; i++)
    {
        for (int e = 0; e < m_rowLen; e++)
        {
            if (line_length < m_columnLen - 1)
            {
                cout << "[";
                cout << seats[i][e];
                cout << "]";
                line_length++;
            }
            else
            {
                cout << "[";
                cout << seats[i][e];
                cout << "]" << endl;
                line_length = 0;
            }
        }
    }
}