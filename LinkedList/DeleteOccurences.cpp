// you are given a linked list and a key. Delete all the occurences of key from the linked list
// Input: 2 -> 2 -> 1 -> 8 -> 2 ->  3 -> 2 -> 7
// Key to delete = 2 Output : 1->8->3->7
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
Node *deleteOccurences(Node *head, int key)
{
    Node *prev = new Node;
    prev->next = head;
    Node *current = head;
    while (current)
    {
        if (current->data == key)
        {
            prev->next = current->next;
            Node *temp = current;
            if (current == head) // modify head if necessary
                head = prev->next;
            current = prev->next;
            delete temp;
        }
        else
        {
            prev = current;
            current = current->next;
        }
    }
    return head;
}
int main()
{
    Node *head = new Node;
    head = nullptr;
    int n, data;
    cin >> n;
    while (n--)
    {
        cin >> data;
        append(&head, data);
    }
    print(head);
    head = deleteOccurences(head, 9);
    print(head);
}