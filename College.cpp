#pragma once

#include "University.h"
#include "College.h"
#include "Utilities.h"


College::College(string n, string a, University& u): name(n), acronym(a), university(&u) {
	u.addCollege(*this);
}

void College::addCourse(Course& c)
{
	courses.push_back(&c);
}

bool College::removeCourse(Course& c)
{
	for (vector<Course *> ::const_iterator it = courses.begin();
		it != courses.end();
		it++)
	{
		if ((*it) == &c) 
		{
			courses.erase(it);
			return true;
		}
	}
	return false;
}

bool compareCollegeByName(College* c1, College* c2)
{
	return c1->name < c2->name;
}

void College::show() const
{
	cout << name
		<< setw(CONSOLE_WIDTH * 1.75 - name.size())
		<< acronym
		<< endl;
}

ofstream& College::operator<<(ofstream& file)
{
	file << this->university->getAcronym()
		<< ';'
		<< this->name
		<< ';'
		<< this->acronym
		<< endl;
	return file;
}
