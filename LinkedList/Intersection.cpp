// you are given two sorted lists. Find the intersection of these two lists
/*Input: head1 = 1->2->3->4->6, head2 = 2->4->6->8
Output: 2 4 6
Explanation: For the given two linked list, 2, 4 and 6 are the elements in the intersection.

Input: head1 = 10->20->40->50, head2 = 15->40
Output: 40
*/
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
Node *intersection(Node *head1, Node *head2)
{
    Node *head = new Node;
    head = nullptr;
    while (head1 && head2)
    {
        if (head1->data == head2->data)
        {
            append(&head, head1->data);
            head1 = head1->next;
            head2 = head2->next;
        }
        else if (head1->data < head2->data)
        {
            head1 = head1->next;
        }
        else
        {
            head2 = head2->next;
        }
    }
    return head;
}
int main()
{
    Node *head1 = new Node;
    head1 = nullptr;
    Node *head2 = new Node;
    head2 = nullptr;
    int m, n, data;
    cin >> m >> n;
    while (m--)
    {
        cin >> data;
        append(&head1, data);
    }
    while (n--)
    {
        cin >> data;
        append(&head2, data);
    }
    Node *head = intersection(head1, head2);
    print(head);
}