/*
Name: Matt Favela
Student ID #: 2390407
Email: mfavela@chapman.edu
Course Number and Section: CPSC350-03
Assignment: PA3

Brief Overview:
This file defines the MonoStack class and its methods.
- Has all the needed methods for a monotonic stack with both increasing and decreasing

High Level Decisions Used:
Templating used for dynamic stack types
*/

#ifndef MONOSTACK_H
#define MONOSTACK_H
#include <cstdlib>
using namespace std;
template <typename T>
class MonoStack{
public:
  MonoStack();
  MonoStack(int iSize, char monotonicDirection);
  ~MonoStack();
  int size();
  bool isEmpty();
  void push(T c);
  T pop();
  T peek();
  T* getStackArr();
  int getTopCount();
private:
  T* stackArr;
  int count;
  int max;
  int top;
  char monotonicDirection;
  bool isFull();
};
#endif