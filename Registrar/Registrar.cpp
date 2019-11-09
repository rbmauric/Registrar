#include <string>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include "Registrar.h"

using namespace std;

Registrar::Registrar() {
	reg = new Student[5000];
	numStudents = 0;
}

Registrar::Registrar(const Registrar& r) {
	reg = new Student[r.numStudents];
	numStudents = r.numStudents;

	for (int i = 0; i < numStudents; i++)
		reg[i] = r.reg[i];
}

Registrar& Registrar::operator = (const Registrar & r) {
	delete[] reg;
	reg = new Student[r.numStudents];
	numStudents = r.numStudents;

	for (int i = 0; i < numStudents; i++)
		reg[i] = r.reg[i];

	return *this;
}

Registrar::~Registrar() {
	delete[] reg;
	numStudents = 0;
}

// Load information from a text file with the given filename
// THIS FUNCTION IS COMPLETE
void Registrar::readTextfile(string filename) {
	ifstream myfile(filename);

	if (myfile.is_open()) {
		cout << "Successfully opened file " << filename << endl;
		string courseName;
		string cwid;
		char grade;
		while (myfile >> courseName >> cwid >> grade) {
			// cout << cwid << " " << grade << endl;
			addLine(courseName, cwid, grade);
		}
		myfile.close();
	}
	else
		throw invalid_argument("Could not open file " + filename);
}

// return Student object corresponding to a given CWID
// getStudent must throw an exception if cwid is invalid
Student& Registrar::getStudent(string cwid) const {
	for (int i = 0; i < numStudents; i++) {
		if (reg[i].getCWID() == cwid)
			return reg[i];
	}
	throw invalid_argument("CWID not found");
}

// process a line from the text file
void Registrar::addLine(string courseName, string cwid, char grade) {

	for (int i = 0; i < numStudents; i++) {
		if (reg[i].getCWID() == cwid) {
			getStudent(cwid).addCourseGrade(courseName, grade);
			return;
		}
	}

	Student st(cwid);
	st.addCourseGrade(courseName, grade);
	reg[numStudents] = st;
	numStudents++;
}

 