#pragma once
#include <string>

using namespace std;

#define MAX 50

class Student {
public:
	Student(); // default constructor
	Student(const string &cwid); // constructor with parameter
	void addCourseGrade(const string &courseName, char grade); // add course name and grade to student's record
	double getGPA(); // calculate and return GPA
	void printTranscript(); // print transcript - see Student.cpp for the format
	string getCWID(); // return the CWID of this student
private:
	string CWID_;
	string course_[MAX];
	char grade_[MAX];
	int numCourses_;
	
};
