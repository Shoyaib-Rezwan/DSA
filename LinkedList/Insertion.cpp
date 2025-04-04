#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        next = nullptr;
    }
};
void createLinkedlist(Node **head, int size)
{
    *head = nullptr;
    for (int i = 0; i < size; i++)
    {
        Node *newNode = new Node();
        newNode->data = i + 1;
        if (*head == nullptr)
            *head = newNode;
        else
        {
            Node *temp;
            temp = *head;
            while (temp->next != nullptr)
                temp = temp->next;
            temp->next = newNode;
        }
    }
}
void displayList(Node *head)
{
    while (head != nullptr)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << "\n";
}
// this function works well except when the index is 0 because it doesn't modify the head.We can solve it by the following function::
void insertAtIndex(Node **head, int index, int data)
{
    if (index < 0)
    {
        throw out_of_range("The index is neative.");
    }
    Node *newNode = new Node();
    newNode->data = data;
    // handle case seperately when inserting at head
    if (index == 0)
    {
        newNode->next = *head;
        *head = newNode;
    }
    else
    {
        Node *temp = *head;
        while (--index) // reach the index-1 node
        {
            temp = (temp)->next;
            if (temp == nullptr)
                throw out_of_range("The index is out of range.");
        }
        newNode->next = (temp)->next;
        (temp)->next = newNode;
    }
}
int main()
{
    Node *head = new Node;
    createLinkedlist(&head, 10);
    // we are going to insert at index 2 in the linked list using function 2.
    insertAtIndex(&head, 10, -25);
    displayList(head);
}