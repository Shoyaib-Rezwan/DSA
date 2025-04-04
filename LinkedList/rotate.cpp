/*
Input: linked list = 10->20->30->40->50->60, k = 4
Output: 50->60->10->20->30->40.
Explanation: k is smaller than the count of nodes in a linked list so (k+1 )th node i.e. 50 becomes the head node and 60’s next points to 10

Input: linked list = 30->40->50->60, k = 2
Output: 50->60->30->40.

*/
#include <iostream>
#include <conio.h>
#include <cstdlib>
using namespace std;
struct Node
{
    int data;
    Node *next;
    Node(int data = 0)
    {
        this->data = data;
        next = nullptr;
    }
};
// in this implementation the head doesn't contai any data rather it's used as a flag of the initial point of the list
struct List
{
    Node *head;
    Node *tail;
    Node *curr;
    int cnt;
    List()
    {
        curr = head = tail = new Node;
        cnt = 0;
    }
    void append(int data)
    {
        tail->next = new Node(data);
        tail = tail->next;
        cnt++;
    }
    void print()
    {
        if (kbhit())
            exit(-1);
        Node *temp = new Node;
        temp = head->next;
        while (temp)
        {
            cout << temp->data << '\t';
            temp = temp->next;
        }
        cout << '\n';
    }
    bool rotate(int k)
    {
        Node *temp = new Node;
        if (k < 1 || k >= cnt)
            return false;
        temp = head;
        while (k--)
        {
            temp = temp->next;
        }
        tail->next = head->next;
        head->next = temp->next;
        temp->next = nullptr;
        return true;
    }
};
int main()
{
    List L;
    for (int i = 0; i < 10; i++)
    {
        L.append(i + 1);
    }
    L.print();
    if (L.rotate(2))
        L.print();
    else
        cout << "Get Lost!!!!!!!!!!!";
}