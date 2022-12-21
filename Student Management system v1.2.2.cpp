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
			
			cout << "Data Inserted At the START of the List! \n\n";
		}
		
		else
		{
			temp = new Node;
			temp->ROLL = roll;
			temp->NAME = name;
			temp->GPA = gpa;
			
			temp->Link = head;
			head = temp;
			
			cout << "Data Inserted at the START of the List! \n\n";
		}
	}
	
	void InsertAtTail(int roll, string name, float gpa)
	{
		
		if (head == NULL)
		{
			cout << "\aList is Empty. Therefore, ";
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
		
		cout << "Data Inserted at the END of the List! \n\n";
	} //End of section
	
	
	//By Enayat Ali
	void InsertAtMid(int roll, string name, float gpa)
	{
		if (head == NULL)
		{
			cout << "\aList is Empty. Therefore, ";
			InsertAtHead(roll, name, gpa);
			return;
		}
			
		int beforeAfter, findRoll;
		bool found = false;
			
		cout << "Enter ROLL NO, Next to Which You Want to Place the New Entry: ";
		cin >> findRoll;
			
		do
		{
			cout << "Do You Want to Insert the New Entry BEFORE(1) or AFTER(2) ROLL NO. \"" << findRoll << "\"?: ";
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
					
					cout << "Data Inserted AFTER ROLL NO. \"" << findRoll << "\"!\n\n";
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
				
					cout << "Data Inserted BEFORE ROLL NO. \"" << findRoll << "\"!\n\n";
				}
				
				return;
			}
			
			prev = current;
			current = current->Link;
		}
		
		if (!found)
		{
			cout << "\nRoll NO Not Found! \n\n";
			InsertAtMid(roll, name, gpa);
		}
	}//End of section
	
	//By Ahmed Zahid
	void ArrangedInsertion(int roll, string name, float gpa)
	{
		if (head == NULL)
		{
			cout << "List is Empty. Therefore, ";
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
				cout << "\nROLL NO. Already Exists. Data NOT Registered!\n\n";
				return;
			}
			
			else if (roll < head->ROLL)
			{
				temp->Link = head;
				head = temp;
					
				cout << "Data Inserted BEFORE ROLL NO. \"" << current->ROLL << "\" Using Auto Arrange!\n\n";
				return;
			}
			
			else if (roll < current->ROLL)
			{
				temp->Link = head;
					
				cout << "Data Inserted BEFORE ROLL NO. \"" << current->ROLL << "\" Using Auto Arrange!\n\n";
				return;
			}
				
			else if (roll > tail->ROLL)
			{
				InsertAtTail(roll, name, gpa);
				return;
			}
			
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
			
			cout << "Record Deleted! \n\n";
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
					
					cout << "Record Deleted! \n\n";
					
					return;
				}
				
				prev = current;
				current = current->Link;
			}
			
			if (current = NULL)
			{
				cout << "\aROLL NO Not Found!\n";
				return;
			}
		}
	}
	
	void Display()
	{
		current = head;
		int sr=1;
		cout << "Sr. No\tROLL\tNAME\tGPA" << endl;
		
		while(current != NULL)
		{
			cout << sr << "\t";
			cout << current->ROLL << "\t";
			cout << current->NAME << "\t";
			cout << current->GPA << endl;
			
			current = current->Link;
			sr++;
		}
		
		cout << endl;
	}//End of section
	
	//By Abdul Rehman
	void Search(int findRoll)
	{
		bool found = false;
		current = head;
		int sr=1;
		cout << endl;
		
		while (current != NULL)
		{
			if (findRoll == current->ROLL)
			{
				found = true;
				cout << sr << "\t";
				cout << "Roll No: " << current->ROLL << "\t";
				cout << "Name: " << current->NAME << "\t";
				cout << "GPA: " << current->GPA << endl << endl;
				sr++;
				break;
			}
			
			current = current->Link;
		}
		
		if (!found)
		{
			cout << "ROLL NO Not Found!\n\n";
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
			cout << "\aRecord Not Found!\n\n";
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
			
			cout << "Record Updated Successfully!\n\n";
		}
	}//End of section
};

main()
{
	LinkedList list;
	int select, roll, findRoll;
	float gpa;
	string name;
	bool after = false;
	
	cout << "\aWELCOME TO STUDENT DATA SYSTEM!\n\n";
	
	while (true)
	{
		cout << "Press 1 to ADD NEW Record.\n";
		cout << "Press 2 to SEARCH for a Record. \n";
		cout << "Press 3 to DISPLAY All Records. \n";
		cout << "Press 4 to DELETE a Record. \n";
		cout << "Press 5 to UPDATE a Record. \n";
		cout << "Press 6 to EXIT. \n\n";
		cin >> select;
		
		while (select < 1 && select > 6)
		{
			cout << "Wrong Selection. Select Again: ";
			cin >> select;
		}
		
		if (select == 1)
		{
			cout << "Enter ROLL NO. of the Sutdent: ";
			cin >> roll;
			cout << "Enter NAME of the Student: ";
			cin >> name;
			cout << "Enter GPA of the Student: ";
			cin >> gpa;
			cout << "\nDo You Want to Add the Record at the START(1), MID(2), END(3) or AutoArrange(4)? ";
			cin >> select;
			
			while (select != 1 && select != 2 && select != 3 && select != 4)
			{
				cout << "Wrong Selection. Select Again: ";
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
			cout << "Enter ROLL NO. to Search: ";
			cin >> findRoll;
			
			list.Search(findRoll);
		}
		
		else if (select == 3)
		{
			list.Display();
		}
		
		else if (select == 4)
		{
			cout << "Enter ROLL NO. to Delete: ";
			cin >> roll;
			
			list.Delete(roll);
		}
		
		else if (select == 5)
		{
			cout << "Enter ROLL NO of the Record to Update: ";
			cin >> findRoll;
			
			list.Update(findRoll);
		}
		
		else if (select == 6)
		{
			int slct;
			cout << "Are You Sure You Want to Exit? Yes(1) -  No(2) \n";
			cin >> slct;
			while(slct > 2 && slct < 1)
			{
			cin >> slct;
			}
			if (slct == 1)
			{
			break;
			}
			if (slct == 2)
			{
				continue;
			}
		}
	}
}
