#pragma once
#include <string>
#include <stdexcept>
#include "Student.h"

using namespace std;


class Registrar {
public:
	Registrar();
	Registrar(const Registrar& r);
	Registrar& operator = (const Registrar & r);
	~Registrar();

	void readTextfile(string filename); // Load information from a text file with the given filename: THIS IS COMPLETE
	void addLine(string courseName, string cwid, char grade); // process a line from the text file
	Student& getStudent(string cwid) const; // return the Student object corresponding to a given CWID
	// getStudent must throw an exception if cwid is invalid
	// add constructors, destructors, assignment operators if needed

private:
	Student *reg;
	int numStudents;

	// Add private member variables for your class along with any 
	// other variables required to implement the public member functions
	// TO BE COMPLETED

};
