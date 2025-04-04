// you are given a singly linked list. You have to delete a certain node but only a pointer to the to be delted node will be given as function parameter. It's ensured that you will not be told to delete the last node.
#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int data = 0)
    {
        this->data = data;
        next = nullptr;
    }
};
void append(Node **head, int data)
{
    if (!*head)
    {
        *head = new Node(data);
    }
    else
    {
        Node *temp = *head;
        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = new Node(data);
    }
}
void print(Node *head)
{
    while (head)
    {
        cout << head->data << '\t';
        head = head->next;
    }
    cout << '\n';
}
void deleteNode(Node **current)
{
    swap((*current)->data, (*current)->next->data);
    Node *temp = (*current)->next;
    (*current)->next = temp->next;
    delete temp;
}
int main()
{
    Node *head;
    head = nullptr;
    for (int i = 0; i < 10; i++)
    {
        append(&head, i + 1);
    }
    deleteNode(&(head->next));
    print(head);
}