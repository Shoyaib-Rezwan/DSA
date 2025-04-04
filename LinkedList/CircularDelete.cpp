// you are given a circular linked list. You have to delete element at certain index from the list

// the linked list whose trailing node is connected to its heading node is called a circular linked list
#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int data = 0, Node *nextval = nullptr)
    {
        this->data = data;
        next = nextval;
    }
};
void append(Node **head, int data)
{

    if (!*head)
    {
        *head = new Node(data); // you can't directly use *head=new Node(data,*head). Constructor will be executed at first and head's initial value is set to nullptr
        (*head)->next = *head;
    }
    else
    {
        Node *temp = new Node;
        temp = *head;
        while (temp->next != *head)
        {
            temp = temp->next;
        }
        temp->next = new Node(data, *head);
        temp = nullptr;
        delete temp;
    }
}
void print(Node *head)
{

    Node *temp = head;
    do
    {
        cout << temp->data << '\t';
        temp = temp->next;

    } while (temp != head);
    cout << '\n';
}
Node *createCircularList(int num)
{
    Node *head = new Node;
    head = nullptr;
    for (int i = 0; i < num; i++)
    {
        if (!head)
        {
            head = new Node(i + 1);
        }
        else
        {
            Node *temp = head;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = new Node(i + 1);
        }
    }
    Node *temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next = head;
    return head;
}
void Delete(Node **head, int index)
{
    if (index < 0)
    {
        return;
    }
    Node *curr = *head;
    Node *prev = nullptr;
    if (index == 0)
    {
        do
        {
            prev = curr;
            curr = curr->next;
        } while (curr != *head);
        prev->next = curr->next;
        *head = curr->next;
        delete curr;
    }
    else
    {
        while (index--)
        {
            prev = curr;
            curr = curr->next;
            if (curr == *head)
                return;
        }
        prev->next = curr->next;
        delete curr;
    }
}
int main()
{
    Node *head;
    head = nullptr;
    for (int i = 0; i < 10; i++)
    {
        append(&head, i + 1);
    }
    Delete(&head, 0);
    print(head);
    // cout << head->data;
    // print(createList(10));
}