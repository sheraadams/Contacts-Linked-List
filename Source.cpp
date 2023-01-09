#include <string>
#include <iostream>
#include <string>
#include <iostream>
#include <string>

using namespace std;

// using typedef to create a new pointer type
typedef

class ContactNode
{

private:

    string contactName;
    string contactPhone;
    ContactNode* next;

public:
    // contstructor
    ContactNode(string nameEntry, string phoneEntry)
    {
        contactName = nameEntry;
        contactPhone = phoneEntry;
 
        next = NULL;
    }

    string GetPhoneNumber() 
    { 
        return(contactPhone); 
    }
    string GetName() 
    {
        return(contactName); 
    }
    ContactNode* GetNext() 
    { 
        return(next); 
    }
    void InsertAfter(ContactNode* nodePtr) 
    { 
        ContactNode* tmpNext = nullptr;
        tmpNext = next;   
        next = nodePtr;   
        nodePtr->next = tmpNext;  
    }

    void PrintContactNode(string* stringUserEntry = NULL);

} *myContactNode;

typedef

class ContactList
{
private:
   
    myContactNode head;
    myContactNode tail;
    myContactNode cur;

    int count;

public:
  
    ContactList()
    {
        head = tail = NULL;
        count = 0;
    }
    int GetCount() 
    {
        return(count); 
    }
    void InsertFirst() 
    { 
        cur = head; 
    }
    void InsertLast() 
    { 
        cur = tail; 
    }
    void InsertNext()
    {
        if (cur == tail)
        {
            cur = head;
        }
        else
        {
            cur = cur->GetNext();
        }
    }
    ContactNode& Get()
    {
        return(*cur);
    }
    void InsertAddNew(string nameEntry, string Phone);
   
    ~ContactList();

} *myContactList;

// function to print contact node
void ContactNode::PrintContactNode(string* stringUserEntry)
{
    if (stringUserEntry != NULL)
    {
        cout << *stringUserEntry << endl;
    }
    cout << "Name: " << contactName  << endl;
    cout << "Phone number: " << contactPhone << endl;
}
// function to insert contact node after x node
void ContactList::InsertAddNew(string nameEntry, string Phone)
{
    myContactNode newNode = new ContactNode(nameEntry, Phone);
    if (count == 0)
    {
        head = tail = newNode;
    }
    else
    {
        tail->InsertAfter(newNode);
        tail = tail->GetNext();
    }
    count++;
}

// next contact to front of the list
ContactList::~ContactList()
{
    myContactNode tempNodePtr = head;
    for (int i = 0; i < count; i++)
    {
        head = head->GetNext();
        delete(tempNodePtr);
        tempNodePtr = head;
    }
}

// get contacts. variable n is declared and defines the size of the contact list
int main(int argc, char** argv)
{
    
    ContactList contactList;
    string contactName;
    string contactPhone;
   
    int n = 3;

    for (int i = 0; i < n; i++)
    {
        cout << "Contact Name:" << endl;
        getline (cin, contactName);
        cout << "Contact Phone:" << endl;
        cin >> contactPhone;

        cout << "Person " << i + 1<< ": " << contactName << ", " << contactPhone << endl;

        cin.ignore();

        contactList.InsertAddNew(contactName, contactPhone);
    }
    
    cout << endl;

    // Print contact list loop
    cout << "CONTACT LIST" << endl;

    contactList.InsertFirst();
    for (int i = 0; i < n; i++)
    {
        ContactNode curContact = contactList.Get();
        curContact.PrintContactNode();

        contactList.InsertNext();

        cout << endl;
    }
    return 0;
}