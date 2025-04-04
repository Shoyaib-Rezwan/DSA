/*Given a doubly - linked list, rotate the linked list counter - clockwise by N nodes.Here N is a given positive integer and is smaller than the count of nodes in linked list.
input: a<->b<->c<->d<->e   N=2
output:c<->d<->e<->a<->b
*/
#include <iostream>
using namespace std;
struct Node
{
    char data;
    Node *next;
    Node *prev;
    Node(char data = '/', Node *prev = nullptr, Node *next = nullptr)
    {
        this->data = data;
        this->next = next;
        this->prev = prev;
    }
};
void append(Node **head, char data)
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
        temp->next = new Node(data, temp, nullptr);
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
Node *rotate(Node *head, int N)
{
    // allocating memory for all nodes is must
    Node *tail = new Node;
    Node *curr = new Node;
    Node *Prev = new Node;
    tail = curr = head;
    Prev->next = head;
    while (tail->next)
    {
        tail = tail->next;
    }
    while (N--)
    {

        Prev = curr;
        curr = curr->next;
    }
    Prev->next = nullptr;
    curr->prev = nullptr;
    tail->next = head;
    head = curr;
    return head;
}
int main()
{
    Node *head = new Node;
    head = nullptr;
    for (int i = 0; i < 10; i++)
    {
        append(&head, 'a' + i);
    }
    print(head);
    head = rotate(head, 2);
    print(head);
}