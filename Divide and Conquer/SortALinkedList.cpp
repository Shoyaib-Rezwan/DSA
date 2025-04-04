// you are given a linked list. You have to sort it uisng DnC
// this sorting procedure is bit like merge sort
#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        next = nullptr;
    }
};
ostream &operator<<(ostream &stream, Node *root)
{
    if (!root)
        return stream;
    while (!root)
    {
        stream << root->data << ' ';
        root = root->next;
    }
    return stream;
}
Node *addNode(Node *root, int data)
{
    if (!root)
        return new Node(data);
    Node *temp = root;
    while (temp->next)
    {
        temp = temp->next;
    }
    temp->next = new Node(data);
    return root;
}
// utility function to merge to sorted lls
Node *merge(Node *head1, Node *head2)
{
    Node *temp1 = head1;
    Node *temp2 = head2;
    while (temp1 && temp2)
    {
        if (temp1->data < temp2->data)
        {
            Node *temp = temp2->next;
            temp2->next = temp1->next;
            temp1->next = temp2;
            temp2 = temp;
        }
        else
        {
            Node *temp = temp1->next;
            temp1->next = temp2->next;
            temp2->next = temp1;
            temp1 = temp;
        }
    }
}
int main()
{
}