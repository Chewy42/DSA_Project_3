#include "MonoStack.h"
#include <iostream>
#include <string>
using namespace std;

/*
Name Of Function: MonoStack class constructor

Description of Value Returned: None

Description of Parameters: None

Description of exceptions thrown: None
*/
template <typename T>
MonoStack<T>::MonoStack(){
  top = -1;
  count = 0;
  max = 0;
  stackArr = NULL;
}

/*
Name Of Function: MonoStack class overloaded constructor

Description of Value Returned: None

Description of Parameters: int iSize which is the initial size of the stack and char monotonicDirection
which is the direction of the stack (increasing or decreasing)

Description of exceptions thrown: None
*/
template <typename T>
MonoStack<T>::MonoStack(int iSize, char monotonicDirection){
  top = -1;
  count = 0;
  max = iSize;
  this->monotonicDirection = monotonicDirection;
  stackArr = new T[max];
}

/*
Name Of Function: MonoStack class destructor

Description of Value Returned: None

Description of Parameters: None

Description of exceptions thrown: None
*/
template <typename T>
MonoStack<T>::~MonoStack(){
  delete[] stackArr;
}

/*
Name Of Function: size

Description of Value Returned: integer of the count of the stack

Description of Parameters: None

Description of exceptions thrown: None
*/
template <typename T>
int MonoStack<T>::size(){
  return count;
}

/*
Name Of Function: isEmpty

Description of Value Returned: boolean to see if the stack is empty

Description of Parameters: None

Description of exceptions thrown: None
*/
template <typename T>
bool MonoStack<T>::isEmpty(){
  return (count==0);
}

/*
Name Of Function: isFull

Description of Value Returned: boolean to check if stack is full

Description of Parameters: None

Description of exceptions thrown: None
*/
template <typename T>
bool MonoStack<T>::isFull(){
  return (count==max);
}

/*
Name Of Function: push

Description of Value Returned: None

Description of Parameters: type T value c which is what is getting pushed into the stack along with the template type

Description of exceptions thrown: None
*/
template <typename T>
void MonoStack<T>::push(T c){
  if(isFull()){
    T* temp = new T[2 *max];
    for(int i = 0; i < max; ++i){
      temp[i] = stackArr[i];
    }
    max *= 2;
    delete[] stackArr;
    stackArr = temp;
  }

  if(monotonicDirection == 'd'){
    if(!isEmpty()){
      if(stackArr[top] < c){
        stackArr[++top] = c;
      }
    }else{
      while(stackArr[top] < c && !isEmpty()){
          pop();
        }
        stackArr[++top] = c;
    }
  }else{
    if(!isEmpty()){
      if(stackArr[top] > c){
        stackArr[++top] = c;
      }
    }else{
      while(stackArr[top] > c && !isEmpty()){
          pop();
        }
        stackArr[++top] = c;
    }
  }
  count++;
}

/*
Name Of Function: pop

Description of Value Returned: template type of what was popped

Description of Parameters: None

Description of exceptions thrown: None
*/
template <typename T>
T MonoStack<T>::pop(){
  --count;
  return stackArr[--top];
}

/*
Name Of Function: peek

Description of Value Returned: template type of the top of the stack

Description of Parameters: None

Description of exceptions thrown: None
*/
template <typename T>
T MonoStack<T>::peek(){
  return stackArr[top];
}

/*
Name Of Function: getStackArr

Description of Value Returned: Template type pointer array of the stack array

Description of Parameters: None

Description of exceptions thrown: None
*/
template <typename T>
T* MonoStack<T>::getStackArr(){
  return stackArr;
}

/*
Name Of Function: getTopCount

Description of Value Returned: integer of the number of items are in the stack

Description of Parameters: None

Description of exceptions thrown: None
*/
template <typename T>
int MonoStack<T>::getTopCount(){
  return top;
}