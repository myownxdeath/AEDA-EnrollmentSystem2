#pragma once
#ifndef STUDENT_H
#define STUDENT_H

#include "CollegeUser.h"
#include "Date.h"
#include <string>
#include <vector>
#include <map>

class Course;
class CourseUnit;
class CourseUnitClass;
class Tutor;

using namespace std;

class Student : protected CollegeUser
{
protected:
	//MEMBER VARIABLES
	Course* course;
	map<CourseUnit*, unsigned short int> completedCourseUnits;
	map<CourseUnit*, CourseUnitClass*> classesCurrentlyAtending;
	Tutor* tutor;
	unsigned short int year;
	string status; //REGULAR STUDENT, WORKING STUDENT, SPECIAL NEEDS

	virtual void assignEmail();
	virtual void assignID();
public:
	//MEMBER FUNCTIONS
	Student(string n, Date dob, Course* c);
	bool assignTutor();
	bool enrollCourseUnit(CourseUnit* courseUnit);
	bool enrollClass(CourseUnitClass* courseUnitClass);
	void completedClass(CourseUnit *courseUnit, unsigned short int grade);
	
	//SETS
	void setStatus(string s) { status = s; }

	//GETS
	Course* getCourse() const { return course; }
	map<CourseUnit*, unsigned short int> getCompletedCourseUnits() const {return completedCourseUnits;}
	map<CourseUnit*, CourseUnitClass*> getClassesCurrentlyAtending() const { return classesCurrentlyAtending; }
	unsigned short int getYear() const { return year; }
	string getStatus() const { return status; }
};

#endif
