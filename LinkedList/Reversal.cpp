#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int data = 0) // using default arguments in case of creating temporary node pointers
    {
        this->data = data;
        next = nullptr;
    }
};
Node *CreateLinkedList(int num)
{
    int i = 0;
    Node *head = new Node;
    head = nullptr;
    while (num--)
    {
        Node *node = new Node(++i);
        if (!head) // when the list is empty the modify head
        {
            head = node;
        }
        else
        {
            Node *current = new Node;
            current = head;
            while (current->next)
            {
                current = current->next;
            }
            current->next = node;
            current = nullptr;
            delete current; // you can't directly delete current without assigning nullptr to it because it may lead to the deletion of some items of the list
        }
    }
    return head;
}
void DisplayList(Node *head)
{
    if (!head)
    {
        cout << "The list is empty!!\n";
    }
    else
    {
        Node *current = head;
        while (current)
        {
            cout << current->data << '\t';
            current = current->next;
        }
        cout << "\n";
    }
}
void reverse(Node **head)
{
    Node *prev = new Node;
    Node *current = new Node;
    Node *next = new Node;
    prev = nullptr;
    current = *head;
    next = (*head)->next;
    while (current)
    {
        current->next = prev;
        prev = current;
        current = next;
        if (next) // don't move next if it's allready at the nullptr
            next = next->next;
    }
    *head = prev;
    prev = next = current = nullptr;
    delete prev;
    delete next;
    delete current;
}
int main()
{
    Node *head = CreateLinkedList(10);
    reverse(&head);
    DisplayList(head);
}