#include <iostream>
using namespace std;
class Node
{
public:
    char data;
    Node *next;
    Node(char data = '/')
    {
        this->data = data;
        next = nullptr;
    }
};
class List
{
public:
    Node *head;
    List() { head = nullptr; }
    void append(char data)
    {
        Node *item = new Node(data);
        if (!head)
        {
            head = item;
        }
        else
        {
            Node *temp = new Node;
            temp = head;
            while (temp->next)
            {
                temp = temp->next;
            }
            temp->next = item;
            temp = nullptr;
            delete temp;
        }
    }
    void display()
    {
        Node *temp = new Node;
        temp = head;
        while (temp)
        {
            cout << temp->data << ' ';
            temp = temp->next;
        }
        cout << '\n';
        temp = nullptr;
        delete temp;
    }
    void operator=(List &L)
    {
        Node *p2 = new Node;
        p2 = L.head;
        while (p2)
        {
            append(p2->data);
            p2 = p2->next;
        }
    }
    void reverse()
    {
        Node *prev = new Node;
        Node *current = new Node;
        Node *Next = new Node;
        prev = nullptr;
        current = head;
        Next = head->next;
        while (current)
        {
            current->next = prev;
            prev = current;
            current = Next;
            if (Next)
                Next = Next->next;
        }
        head = prev;
    }
};
bool operator==(List &L1, List &L2)
{
    Node *p1 = new Node;
    p1 = L1.head;
    Node *p2 = new Node;
    p2 = L2.head;
    while (p1 && p2)
    {
        if (p1->data == p2->data)
        {
            p1 = p1->next;
            p2 = p2->next;
        }
        else
            return false;
    }
    if (p1 || p2)
        return false;
    return true;
}
int main()
{
    List L;
    List L2;
    int m;
    cin >> m;
    char ch;
    while (m--)
    {
        cin >> ch;
        L.append(ch);
    }
    L2 = L;
    L2.reverse();
    if (L == L2)
        cout << "Yes";
    else
        cout << "NO";
}