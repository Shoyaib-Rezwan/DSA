// source::F :\shoyaib\BUET\Level1 Term2\Course Materials\Sessional\CSE 106\Linked List\CSE106_Jan23_LL(2).pdf
#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(char data = 0)
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
    void append(int data)
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

int operator+(List &L1, List &L2)
{
    int num1 = 0;
    while (L1.head)
    {
        num1 = num1 * 10 + L1.head->data;
        L1.head = L1.head->next;
    }
    int num2 = 0;
    while (L2.head)
    {
        num2 = num2 * 10 + L2.head->data;
        L2.head = L2.head->next;
    }
    return num1 + num2;
}
int main()
{
    List A;
    List B;
    int m, n;
    cin >> m >> n;
    int data;
    while (m--)
    {
        cin >> data;
        A.append(data);
    }
    while (n--)
    {
        cin >> data;
        B.append(data);
    }
    A.display();
    B.display();
    // A.append(10);
    // cout << A.head->data;
    cout << A + B;
}