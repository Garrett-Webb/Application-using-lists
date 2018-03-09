#pragma once
#include <string>
#include <vector>

using namespace std;


class Node
{
private:
	string name, studentID;
	int units, year;
	double gpa;

public:
	Node(string, int, int, string, double);
	string getName();
	void setName(string);
	int getUnits();
	void setUnits(int);
	int getYear();
	void setYear(int);
	string getStudentID();
	void setStudentID(int);
	double getGPA();
	void setGPA(double);
	Node();
	~Node();
};

