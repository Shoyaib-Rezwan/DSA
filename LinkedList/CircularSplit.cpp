// source:https://www.geeksforgeeks.org/split-a-circular-linked-list-into-two-halves/
// suppose you have a circular linked list. You have to divide it into two equal halves. If it contains odd elements then the 1st half will contain extra more element
#include <iostream>
#include <cmath>
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
        *head = new Node(data);
        (*head)->next = *head;
    }
    else
    {
        Node *temp = *head;
        while (temp->next != *head)
        {
            temp = temp->next;
        }
        temp->next = new Node(data, *head);
    }
}
void print(Node *head)
{
    if (!head)
        cout << "The list is empty!\n";
    else
    {
        Node *temp = head;
        while (temp->next != head)
        {
            cout << temp->data << '\t';
            temp = temp->next;
        }
        cout << temp->data;
        cout << '\n';
    }
}
Node **split(Node *head)
{
    Node *temp = head;
    int cnt = 0;
    while (temp->next != head)
    {
        cnt++;
        temp = temp->next;
    }
    cnt++;
    // keep temp at the last node of the list because oit will serve as a tail node at the end of this function
    //  find the middle
    cnt = ceil((double)cnt / 2);
    Node *prev = new Node(0, head);
    Node *curr = head;
    while (cnt--)
    {
        prev = curr;
        curr = curr->next;
    }
    prev->next = head; // creating the 1st half list as a circular list
    temp->next = curr; // linking tail will the second half's head curr node
    Node **arr = new Node *[2];
    arr[0] = head;
    arr[1] = curr;
    return arr;
}
int main()
{
    Node *head = nullptr;
    for (int i = 0; i < 9; i++)
    {
        append(&head, i + 1);
    }
    Node **arr = split(head);
    print(arr[0]);
    print(arr[1]);
}