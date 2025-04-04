#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
};
Node *CreateLinkedList(int size)
{
    Node *head = new Node();
    head = nullptr;
    for (int i = 0; i < size; i++)
    {
        Node *newNode = new Node();
        newNode->data = i + 1;
        newNode->next = nullptr;
        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            Node *temp = head;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
    return head;
}
void displayList(Node *head)
{
    if (head == nullptr)
        cout << "This is an empty list." << "\n";
    else
    {
        do
        {
            cout << head->data << "\n";
            head = head->next;
        } while (head != nullptr);
    }
}
void freeList(Node *head)
{
    Node *temp;
    while (head != nullptr)
    {
        temp = head;
        head = head->next;
        delete temp;
    }
    head = nullptr;
}
// 1st inserting function
void insertBeginning(Node **head, int data) // here **head is the address of head
{
    Node *newNode = new Node;
    newNode->data = data;
    newNode->next = *head; // dereferencing head will give us the head node
    *head = newNode;
}
// if you don't want to use double pointer as a parameter then you can use the following function
// second inserting function
Node *insertBeginning2(Node *head, int data)
{
    Node *newNode = new Node();
    newNode->data = data;
    newNode->next = head;
    head = newNode;
    return head;
}
// insertion at the end
void insertEnd(Node *head, int data) // incase of insertion at the end we don't have to alter the head of the main linked list as a result we don't need to pass the head's address
{
    Node *newNode = new Node();
    newNode->next = nullptr;
    newNode->data = data;
    while (head->next != nullptr)
        head = head->next;
    head->next = newNode;
}
int main()
{
    Node *head = CreateLinkedList(10);
    cout << "Initially the linked list ::\n";
    displayList(head);
    // pusing 10 at the beginning using 1st insert function
    insertBeginning(&head, 10); // passing address of head
    // pushing 20 at the beginning using second inserting function
    head = insertBeginning2(head, 20);
    cout << "List after insertion::\n";
    // inserting -20 at the end of the linked list
    insertEnd(head, -20);
    displayList(head);
}