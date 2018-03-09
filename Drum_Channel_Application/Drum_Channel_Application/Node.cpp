#include "stdafx.h"
#include "Node.h"


Node::Node()
{
	name = "Default";
	units = 0;
	year = 0;
	studentID = "xxxx-xxxx-xxxx";
	gpa = 0.0;
}

Node::Node(string N, int U, int Y, string S, double G)
{
	name = N;
	units = U;
	year = Y;
	studentID = S;
	gpa = G;
}

Node::~Node()
{
}

string Node::getName()
{return name;}

void Node::setName(string x)
{name = x;}

int Node::getUnits()
{return units;}

void Node::setUnits(int x)
{units = x;}

int Node::getYear()
{return year;}

void Node::setYear(int x)
{year = x;}

string Node::getStudentID()
{return studentID;}

void Node::setStudentID(int x)
{studentID = x;}

double Node::getGPA()
{return gpa;}

void Node::setGPA(double x)
{gpa = x;}