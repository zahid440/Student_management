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
			cout << "Roll NO. not found! \n\n";
			InsertAtMid(roll, name, gpa);
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
		
		if (head == NULL)
		{
			head = tail;
		}
		
		cout << "Data inserted at the END of the list! \n\n";
	}
	
	void ArrangedInsertion(int roll, string name, float gpa)
	{
		if (head == NULL)
		{
			cout << "List is empty. Therefore, ";
			InsertAtHead(roll, name, gpa);
			return;
		}
		
		current = head;
			
		temp = new Node;
		temp->ROLL = roll;
		temp->NAME = name;
		temp->GPA = gpa;
		
		while(current != NULL)
		{
			if (roll == current->ROLL)
			{
				cout << "\nROLL NO. Already exists. Data NOT registered!\n\n";
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
				temp->Link = head;
					
				cout << "Data inserted BEFORE ROLL NO. \"" << current->ROLL << "\" using Auto Arrange!\n\n";
				return;
			}
				
			else if (roll > tail->ROLL)
			{
				InsertAtTail(roll, name, gpa);
				return;
			}
			
			current = current->Link;
		}
	}
	
	void Delete(int roll)
	{
		current = head;
		Node* prev = NULL;
		
		if (current != NULL && current->ROLL == roll)
		{
			head = current->Link;
			delete current;
			
			cout << "Record deleted! \n\n";
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
					
					cout << "Record deleted! \n\n";
					
					return;
				}
				
				prev = current;
				current = current->Link;
			}
			
			if (current = NULL)
			{
				cout << "ROLL NO. not found!\n";
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
	}
	
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
				
				cout << current->ROLL << "\t";
				cout << current->NAME << "\t";
				cout << current->GPA << endl << endl;
			}
			
			current = current->Link;
		}
		
		if (!found)
		{
			cout << "ROLL NO. not found!\n";
		}
	}
};

main()
{
	LinkedList list;
	int select, roll, findRoll;
	float gpa;
	string name;
	bool after = false;
	
	cout << "WELCOME TO STUDENT DATA SYSTEM!\n\n";
	
	while (true)
	{
		cout << "Press 1 to enter new record.\n";
		cout << "Press 2 to search for a record. \n";
		cout << "Press 3 to display all records. \n";
		cout << "Press 4 to delete a record. \n\n";
		cin >> select;
		
		while (select != 1 && select != 2 && select != 3 && select != 4)
		{
			cout << "Wrong selection. Select again: ";
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
			
			while (select != 1 && select != 2 && select != 3 && select != 4)
			{
				cout << "Wrong selection. Select again: ";
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
	}
}
