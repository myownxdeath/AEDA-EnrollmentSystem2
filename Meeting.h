#pragma once

#ifndef MEETING_H
#define MEETING_H


#include "Date.h"
#include <vector>

class Student;
class Tutor;

class Meeting {
private:
	//VARIABLES
	Date date;
	unsigned int hour, minute;
	Student* student;
	Tutor* professor;
	vector<string> topics;
	string description;


public:
	//CONSTRUCTORS
	Meeting(Date d, Student* st, Tutor* t, vector<string> &top, unsigned int hour, unsigned int minute);

	//GETS
	Date getDate() const { return date; }
	
	//SETS
	void setDescription(string des) { description = des; }

	//FUNCTIONS
	bool hasOccured() const;
	void show() const;
	friend bool operator<(const Meeting &m1, const Meeting &m2);
	friend bool operator==(const Meeting &m1, const Meeting &m2);
	ofstream& Meeting::operator<<(ofstream& file);
};

#endif