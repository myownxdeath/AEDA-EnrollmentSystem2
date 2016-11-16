#pragma once
#ifndef UNIVERSITY_H
#define UNIVERSITY_H

#include <string>
#include <vector>
using namespace std;

class College;
class Course;
class OptionalCourseUnit;

class University
{
private:
	//MEMBER VARIABLES
	const string name, acronym, countryAcronym;
	vector<College*> collegesVector;
	unsigned long long int lastStudentID, lastProfessorID;

public:
	//MEMBER FUNCTIONS
	University(string n, string a, string ca) : name(n), acronym(a), countryAcronym(ca), lastProfessorID(0), lastStudentID(0) {}
	void incrementLastStudentID();
	void incrementLastProfessorID();
	void addCollege(College* c);
	bool removeCollege(College *c);
	
	//PRINT TO SCREEN
	void showAllOptional(string scientificArea, OptionalCourseUnit* arg) const;
				
	//GETS
	unsigned long long int getLastStudentID() { return lastStudentID; }
	unsigned long long int getLastProfessorID() { return lastProfessorID; }
	string getName() const { return name; }
	string getAcronym() const { return acronym; }
	string getCountryAcronym() const { return countryAcronym; }
	vector<College*> getColleges() const { return collegesVector; }

	//COMPARES
	friend bool compareUniversityByName(University* u1, University* u2);
	
	//OPERATORS
	friend ofstream& operator<<(ofstream &file, const University *uni);
};

#endif
