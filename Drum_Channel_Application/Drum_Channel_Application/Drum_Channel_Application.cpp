// Drum_Channel_Application.cpp : Defines the entry point for the console application.
//

#include "stdafx.h" //stdafx.h has all the includes for this file

using namespace std;

void arrowLeft(unsigned int&);
void arrowRight(unsigned int&, list<Node>);
void PrintList(list<Node>, unsigned int);
Node newNodeUser();
void deleteNode(list<Node>&, unsigned int&);

int main()
{
	list<Node> List; //defining the list we will be using
	unsigned int currentNode = 0; //this will be used as an index into our list
	int buffer = 0; //this is where the keyboard ascii input is stored

	//adding some nodes to the list for demonstrative purposes
	List.push_back(Node("Jim", 18, 2, "4163-6923-8623", 3.25));
	List.push_back(Node("Nancy", 12, 4, "9353-9264-2946", 3.56));
	List.push_back(Node("James", 22, 3, "1295-1603-8252", 2.96));
	List.push_back(Node("Jorge", 14, 2, "1857-1297-0816", 3.26));


	PrintList(List, currentNode); //make sure we have something on screen before a button is pressed

	while ((int)buffer != 96)
	{
		
		buffer = _getch(); //since arrow keys give 2 ASCII values, the first one will be tested first
		if ((int)buffer == 0 || (int)buffer == 224)
		{
			switch (_getch()) //now for the second value
			{
			case 75: //left arrow
				arrowLeft(currentNode);
				break;
			case 77://right arrow
				arrowRight(currentNode, List);
				break;
			default:
				break;
			}
		}
		switch ((int)buffer) //if it is not an arrow key, the value will be compared here
		{
		case 8: //backspace
			deleteNode(List, currentNode);
			break;
		case 13://return
			List.push_back(newNodeUser());
			break;
		case 96://tilde (`)
			//will end the loop
			break;
		default:
			break;
		}
		PrintList(List, currentNode);
	}
    return 0;
}

void arrowLeft(unsigned int &x)
{
	if (x > 0) //if the position is greater than 0, we can go backwards
	{
		x--;
		return;
	}
	else // if the position is 0, we cannot, and it should never be negative
	{return;}
}

void arrowRight(unsigned int &x, list<Node> List)
{
	if (x < List.size()-1) //if the position is not at the end of the list, we can go farther
	{
		x++;
		return;
	}
	else // if the position is at the end of the list, do not go farther
	{return;}
	
}

void PrintList(list<Node> List, unsigned int x)
{
	if (List.size() > x) //sanity check, cannot output a field that does not exist
	{
		system("CLS"); //clear the screen for output
		list<Node>::iterator iter = List.begin(); //define iterator to advance in the list starting at the beginning
		advance(iter, x); //advance the iterator to the current position
		cout << "=================================================================" << endl <<
			"|| Previous: <- || next: -> || New: Enter || Remove: Backspace ||" << endl <<
			"=================================================================" << endl <<
			"= Student # " << (x + 1) << endl << //adjusting index outputted for easier readability
			"= Name: " << iter->getName() << endl << //iterator is a pointer to a Node in List, so it can be accessed using accessor functions in Node.cpp
			"= Student ID: " << iter->getStudentID() << endl <<
			"= Units: " << iter->getUnits() << endl <<
			"= Year: " << iter->getYear() << endl <<
			"= GPA: " << iter->getGPA() << endl <<
			"=================================================================" << endl;
	}
	else
	{
		cout << "ERROR OUT OF BOUNDS" << endl;
		//should not happen
	}
}

Node newNodeUser()
{
	string n, SID;
	int u, y;
	double GPA;
	cout << "New Student: " << endl <<
		"=======================" << endl <<
		"Name: ";
	cin >> n;
	cout << "Student ID: ";
	cin >> SID;
	cout << "Units: ";
	cin >> u;
	cout << "Year: ";
	cin >> y;
	cout << "GPA: ";
	cin >> GPA;
	Node temp = Node(n, u, y, SID, GPA); //take defined and initiated values by user and used in constructor
	return temp; //return the created node
}

void deleteNode(list<Node>& L, unsigned int& x)
{
	list<Node>::iterator iter = L.begin();
	advance(iter, x);
	L.erase(iter);
	if (x >= L.size())
	{
		x--;
		return;
	}
	else
		return;
}