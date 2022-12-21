#include<iostream>
using namespace std;

class Node
{
	public:
		int ROLL;
		string NAME;
		float GPA;
		
		Node *Link;
};

class LinkedList
{
	private:
		Node *head, *tail, *current, *temp;
		
	public:
		LinkedList()
		{
			head = NULL;
		}
	
	// By Sana Tahir
	void InsertAtHead(int roll, string name, float gpa)
	{
		if (head == NULL)
		{
			head = new Node;
			head->ROLL = roll;
			head->NAME = name;
			head->GPA = gpa;
			
			head->Link = NULL;
			tail = head;
			
			cout << "Data inserted at the START of the list! \n\n";
		}
		
		else
		{
			temp = new Node;
			temp->ROLL = roll;
			temp->NAME = name;
			temp->GPA = gpa;
			
			temp->Link = head;
			head = temp;
			
			cout << "Data inserted at the START of the list! \n\n";
		}
	}
	
	void InsertAtTail(int roll, string name, float gpa)
	{
		
		if (head == NULL)
		{
			cout << "List is empty. Therefore, ";
			InsertAtHead(roll, name, gpa);
			return;
		}
		
		temp = new Node;
		temp->ROLL = roll;
		temp->NAME = name;
		temp->GPA = gpa;
			
		temp->Link = NULL;
		tail->Link = temp;
		tail = temp;
		
		cout << "Data inserted at the END of the list! \n\n";
	} //End of section
	
	
	//By Enayat Ali
	void InsertAtMid(int roll, string name, float gpa)
	{
		if (head == NULL)
		{
			cout << "List is empty. Therefore, ";
			InsertAtHead(roll, name, gpa);
			return;
		}
			
		int beforeAfter, findRoll;
		bool found = false;
			
		cout << "Enter ROLL NO. next to which you want to place the new entry: ";
		cin >> findRoll;
			
		do
		{
			cout << "Do you want to insert the new entry BEFORE(1) or AFTER(2) ROLL NO. \"" << findRoll << "\"?: ";
			cin >> beforeAfter;
		}
		
		while (beforeAfter != 1 && beforeAfter != 2);
		
		current = head;
		Node* prev = NULL;
			
		temp = new Node;
		temp->ROLL = roll;
		temp->NAME = name;
		temp->GPA = gpa;
		
		while(current != NULL)
		{
			if (findRoll == current->ROLL)
			{
				found = true;
				
				if (beforeAfter == 2)
				{
					temp->Link = current->Link;
					current->Link = temp;
					
					cout << "Data inserted AFTER ROLL NO. \"" << findRoll << "\"!\n\n";
				}
					
				else if (beforeAfter == 1)
				{
					if (current == head)
					{
						temp->Link = head;
						head = temp;
					}
					
					else
					{
						temp->Link = current;
						prev->Link = temp;
					}
				
					cout << "Data inserted BEFORE ROLL NO. \"" << findRoll << "\"!\n\n";
				}
				
				return;
			}
			
			prev = current;
			current = current->Link;
		}
		
		if (!found)
		{
			cout << "\aRoll NO. not found! \n\n";
			InsertAtMid(roll, name, gpa);
		}
	}//End of section
	
	//By Ahmed Zahid
	void ArrangedInsertion(int roll, string name, float gpa)
	{
		if (head == NULL)
		{
			cout << "List is empty. Therefore, ";
			InsertAtHead(roll, name, gpa);
			return;
		}
		
		Node* prev = NULL;
		current = head;
			
		temp = new Node;
		temp->ROLL = roll;
		temp->NAME = name;
		temp->GPA = gpa;
		
		while(current != NULL)
		{
			if (roll == current->ROLL)
			{
				cout << "\a\nROLL NO. Already exists. Data NOT inserted!\n\n";
				return;
			}
			
			else if (roll < head->ROLL)
			{
				temp->Link = head;
				head = temp;
					
				cout << "Data inserted BEFORE ROLL NO. \"" << current->ROLL << "\" using Auto Arrange!\n\n";
				return;
			}
			
			else if (roll < current->ROLL)
			{
				temp->Link = current;
				prev->Link = temp;
					
				cout << "Data inserted BEFORE ROLL NO. \"" << current->ROLL << "\" using Auto Arrange!\n\n";
				return;
			}
				
			else if (roll > tail->ROLL)
			{
				InsertAtTail(roll, name, gpa);
				return;
			}
			
			prev = current;
			current = current->Link;
		}
	}//End of section
	
	//By Ali Abbas
	void Delete(int roll)
	{
		current = head;
		Node* prev = NULL;
		
		if (current != NULL && current->ROLL == roll)
		{
			head = current->Link;
			delete current;
			
			cout << "\nRecord deleted! \n\n";
			return;
		}
		
		else
		{
			while (current != NULL)
			{
				if (current->ROLL == roll)
				{
					prev->Link = current->Link;
					delete current;
					
					cout << "\nRecord deleted! \n\n";
					
					return;
				}
				
				prev = current;
				current = current->Link;
			}
			
			if (current == NULL)
			{
				cout << "\a\nROLL NO. not found!\n";
				return;
			}
		}
	}
	
	void Display()
	{
		current = head;
		
		cout << "ROLL\tNAME\tGPA" << endl;
		
		while(current != NULL)
		{
			cout << current->ROLL << "\t";
			cout << current->NAME << "\t";
			cout << current->GPA << endl;
			
			current = current->Link;
		}
		
		cout << endl;
	}//End of section
	
	//By Abdul Rehman
	void Search(int findRoll)
	{
		bool found = false;
		current = head;
		
		cout << endl;
		
		while (current != NULL)
		{
			if (findRoll == current->ROLL)
			{
				found = true;
				
				cout << "Roll No: " << current->ROLL << "\t";
				cout << "Name: " << current->NAME << "\t";
				cout << "GPA: " << current->GPA << endl << endl;
				break;
			}
			
			current = current->Link;
		}
		
		if (!found)
		{
			cout << "\a\nROLL NO. not found!\n\n";
		}
	}
	
	void Update (int findRoll)
	{
		int roll;
		float gpa;
		string name;
		bool found = false;
		current = head;
		
		cout << endl;
		
		while (current != NULL)
		{
			if (findRoll == current->ROLL)
			{
				found = true;
				
				cout << "Roll No: " << current->ROLL << "\t";
				cout << "Name: " << current->NAME << "\t";
				cout << "GPA: " << current->GPA << endl << endl;
				break;
			}
			
			current = current->Link;
		}
		
		if (!found)
		{
			cout << "\a\nRecord not found!\n\n";
		}
		
		else
		{
			cout << "Enter new ROLL NO: ";
			cin >> roll;
			cout << "Enter new NAME: ";
			cin >> name;
			cout << "Enter new GPA: ";
			cin >> gpa;
			
			current->ROLL = roll;
			current->NAME = name;
			current->GPA = gpa;
			
			cout << "Record updated successfully!\n\n";
		}
	}//End of section
};

main()
{
	LinkedList list;
	int select, roll, findRoll;
	float gpa;
	string name;
	
	cout << "WELCOME TO STUDENT DATA SYSTEM!\n\n";
	
	do
	{
		cout << "Press 1 to ADD NEW record.\n";
		cout << "Press 2 to SEARCH for a record.\n";
		cout << "Press 3 to DISPLAY all records.\n";
		cout << "Press 4 to DELETE a record.\n";
		cout << "Press 5 to UPDATE a record.\n";
		cout << "Press 6 to EXIT.\n\n";
		cin >> select;
		
		while (select < 1 || select > 6)
		{
			cout << "\aWrong selection. Select again: ";
			cin >> select;
		}
		
		if (select == 1)
		{
			cout << "Enter ROLL NO. of the sutdent: ";
			cin >> roll;
			cout << "Enter NAME of the student: ";
			cin >> name;
			cout << "Enter GPA of the student: ";
			cin >> gpa;
			cout << "\nDo you want to add the record at the START(1), MID(2), END(3) or AutoArrange(4)? ";
			cin >> select;
			
			while (select < 1 || select > 4)
			{
				cout << "\aWrong selection. Select again: ";
				cin >> select;
			}
			
			switch (select)
			{
				case 1:
					list.InsertAtHead(roll, name, gpa);
					break;
				case 2:	
					list.InsertAtMid(roll, name, gpa);
					break;
				case 3:
					list.InsertAtTail(roll, name, gpa);
					break;
				case 4:
					list.ArrangedInsertion(roll, name, gpa);
			}
		}
		
		else if (select == 2)
		{
			cout << "Enter ROLL NO. to search: ";
			cin >> findRoll;
			
			list.Search(findRoll);
		}
		
		else if (select == 3)
		{
			list.Display();
		}
		
		else if (select == 4)
		{
			cout << "Enter ROLL NO. to delete: ";
			cin >> roll;
			
			list.Delete(roll);
		}
		
		else if (select == 5)
		{
			cout << "Enter ROLL NO. of the record to update: ";
			cin >> findRoll;
			
			list.Update(findRoll);
		}
	}
	
	while (select != 6);
	
	cout << "\t\tGOODBYE!";
}
