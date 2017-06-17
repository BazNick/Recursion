#include <iostream>
#include <string>

using namespace std;

struct AddressBook
{
	string name;
	string surname;
	long long phone;
	AddressBook* next;
};


AddressBook* delPerson(AddressBook*& head, string pName)
{
	if (head == NULL)
	{
		cout << "There are no person with this name\n";
		return head;
	}
	if (head->name == pName)
	{
		AddressBook* temp = head;
		AddressBook* curr = NULL;
		if (temp == head)
		{
			head = head->next;
			delete temp;
			cout << pName << " was deleted from the book\n";
			return head;
		}
		else
		{
			curr->next = temp->next;
			delete temp;
			cout << pName << " was deleted from the book\n";
			return head;
		}
	}
		
	else
	{
		return delPerson(head->next, pName);
	}
}

AddressBook* display(AddressBook* head)
{
	if (head!= NULL)
	{
		cout << endl;
		cout << "Name: " << head->name << endl;
		cout << "Surname: " << head->surname << endl;
		cout << "Phone: " << head->phone << endl;
		return display(head->next);
	}
	return head;
}

AddressBook* search(AddressBook* head, string pName)
{
	if (head == NULL)
	{
		cout << pName << " isn't found in my book\n";
		return head;
	}
	if (head->name == pName)
	{
		cout << head->name << " is found\n\n";
		cout << "Name: " << head->name << endl;
		cout << "Surname: " << head->surname << endl;
		cout << "Phone: " << head->phone << endl;
		return head;
	}
	else
	{
		return search(head->next, pName);
	}
}

void delMemory(AddressBook* head)
{
	if (head != NULL)
	{
		delMemory(head->next);
	}
	delete head;
}


AddressBook* createAddressBook()
{
	AddressBook* bleah = new AddressBook; // bleah = new struct

	cin.get();
	cout << "Enter the name: ";
	getline(cin, bleah->name);
	cout << "Enter surname: ";
	getline(cin, bleah->surname);
	cout << "Enter phone: ";
	cin >> bleah->phone; 
	bleah->next = NULL;

	return bleah; // returning address of bleah, or what is bleah is pointing to
}

AddressBook*& findEnd(AddressBook*& head)
{
	if (head != NULL) // is head == NULL ? if no, then head = head -> next
	{
		return findEnd(head->next); // keep looking for the end
	}
	return head; // return the end, which is NULL
}

AddressBook* addPerson(AddressBook*& head)
{
	/* we assign what was returning from createAddressBook(), 
	which was new struct to what was returning from findEnd(head) - which was NULL
	and so we have got NULL = new struct, or head = bleah, bleah is pointing to a newly created struct
	*/
	findEnd(head) = createAddressBook(); // head = bleah

	return head;
}


int main()
{
	cout << "=============== My Address Book ===============\n\n";
	cout << "1. To add person\n";
	cout << "2. To display all\n";
	cout << "3. To delete person\n";
	cout << "4. To search person\n";
	cout << "5. Exit\n";

	AddressBook* head = NULL;
	string pName;
	int choice = 0;

	while (true)
	{
		cin >> choice;
		switch (choice)
		{
		case 1: addPerson(head);
			break;
		case 2: display(head);
			break;
		case 3: cin.get();
			cout << "Enter name of person: ";
			getline(cin, pName);
			delPerson(head, pName);
			break;
		case 4: cin.get();
			cout << "Enter name of person: ";
			getline(cin, pName);
			search(head, pName);
			break;
		case 5: return 0;
		default: return 0;
		}
		cout << "=============== My Address Book ===============\n\n";
		cout << "1. To add person\n";
		cout << "2. To display all\n";
		cout << "3. To delete person\n";
		cout << "4. To search person\n";
		cout << "5. Exit\n";
		cout << endl;
	}
	delMemory(head);

	return 0;
}
