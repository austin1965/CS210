// Begin Guard 
#ifndef PYTHONWRAPPER_H
#define PYTHONWRAPPER_H

// Dependencies
#include <iostream>
#include <Python.h>
#include <string>
#pragma warning(disable : 4996)

// Namespace
using namespace std;

/*
 * Class used to manage calling Python. 
 */
class PythonWrapper {

public:

	// Function declarations. Definitions in PythonWrapper.cpp
	void CallProcedure(string pName); // Calls a python function with no arguments and no returns.
	int callIntFunc(string proc, string param); // Calls a python function with a string argument and integer return.
	int callIntFunc(string proc, int param); // Calls a python function with an integer argument and integer return.
};

// End Guard
#endif // !PYTHONWRAPPER_H

