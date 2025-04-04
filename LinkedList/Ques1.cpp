// source :: F :\shoyaib\BUET\Level1 Term2\Course Materials\Sessional\CSE 106\Linked List\CSE106_Jan23_LL.pdf
#include <iostream>
#include <cmath>
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
class list
{
public:
    Node *head;
    Node *head1;
    Node *head2;
    int length;
    list()
    {
        head = nullptr;
        length = 0;
    }
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
        length++;
    }
    void display(Node *head)
    {
        Node *temp = new Node;
        temp = head;
        cout << "< ";
        while (temp)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << ">";
        temp = nullptr;
        delete temp;
    }
    void split()
    {
        int middle = ceil((float)length / 2); // you must type cast length to float because if lenght=9 then  length/2=4 and ceil(length / 2)=4
        Node *temp = new Node;
        temp = head;
        while (--middle)
        {
            temp = temp->next;
        }
        head2 = temp->next;
        temp->next = nullptr;
        head1 = head;
        temp = nullptr;
        delete temp;
    }
    void reverse()
    {
        Node *prev = new Node;
        Node *current = new Node;
        Node *Next = new Node;
        prev = nullptr;
        current = head2;
        Next = head2->next;
        while (current)
        {
            current->next = prev;
            prev = current;
            current = Next;
            if (Next)
                Next = Next->next;
        }
        head2 = prev;
        Next = nullptr;
        delete Next;
        current = nullptr;
        delete current;
        prev = nullptr;
        delete prev;
    }
    void merge()
    {
        Node *current1 = new Node;
        Node *current2 = new Node;
        Node *next1 = new Node;
        Node *next2 = new Node;
        current1 = head1;
        current2 = head2;
        next1 = head1->next;
        next2 = head2->next;
        while (current1 && current2)
        {
            current1->next = current2;
            current2->next = next1;
            current1 = next1;
            current2 = next2;
            if (next1)
                next1 = next1->next;
            if (next2)
                next2 = next2->next;
        }
    }
};
int main()
{
    list L;
    int m;
    cin >> m;
    int data;
    for (int i = 0; i < m; i++)
    {
        cin >> data;
        L.append(data);
    }
    L.split();   // split the list into two halves from the middle
    L.reverse(); // reverse the second half
    // L.display(L.head2);
    L.merge(); // merging the two lists
    L.display(L.head);
}