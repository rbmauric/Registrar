#include "Student.h"

#include <iostream>
#include <iomanip>
#define BUF_SIZE 30
Student::Student() {
	CWID_ = "";
	numCourses_ = 0;
}

Student::Student(const string &cwid) {
	CWID_ = cwid;
	numCourses_ = 0;
}

string Student::getCWID() {	return CWID_; }

void Student::addCourseGrade(const string &courseName, char grade) {
	course_[numCourses_] = courseName;
	grade_[numCourses_] = grade;
	numCourses_++;
}

double Student::getGPA() {
	double GPA = 0;
	int temp = numCourses_;

	while (temp >= 0) {
		switch (toupper(grade_[temp])) {
			case 'A': {
				GPA = GPA + 4;
				break;
			}
			case 'B': {
				GPA = GPA + 3;
				break;
			}
			case 'C': {
				GPA = GPA + 2;
				break;
			}
			case 'D': {
				GPA = GPA + 1;
				break;
			}
			case 'F': {
				GPA = GPA + 0;
				break;
			}
		}
		temp--;
	}
	
	return GPA / static_cast<double>(numCourses_);
}

// print transcript in this (sample) format:
// TRANSCRIPT FOR CWID=279750343
// CS 121		C
// CS 253		B
// CS 131		B
// GPA = 2.6667
void Student::printTranscript() {
	cout << "TRANSCRIPT FOR CWID=" << CWID_ << endl;
	for (int i = 0; i < numCourses_; i++) {
		cout << course_[i];
		cout << setw(BUF_SIZE- course_[i].length()) << grade_[i] << endl;
	}

	cout << "GPA = " << getGPA() << endl;
}

