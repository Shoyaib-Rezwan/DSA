#include <iostream>
#include <unordered_set>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int data = 0, Node *nextval = nullptr)
    {
        this->data = data;
        this->next = nextval;
    }
};
class List
{
public:
    Node *head; // here head is just a getway to the list not any data containing node
    Node *tail;
    List()
    {
        head = tail = new Node;
    }
    void append(int data)
    {
        tail->next = new Node(data);
        tail = tail->next;
    }
    void print() const
    {
        Node *temp = new Node;
        temp = head->next;
        while (temp)
        {
            cout << temp->data << ' ';
            temp = temp->next;
        }
        cout << '\n';
    }
    bool isCyclic()
    {
        unordered_set<Node *> s;
        Node *temp = new Node;
        temp = head->next;
        while (temp)
        {
            if (s.find(temp) != s.end())
                return true;
            else
            {
                s.insert(temp);
                temp = temp->next;
            }
        }
        return false;
    }
};
int main()
{
    List L;
    for (int i = 0; i < 10; i++)
    {
        L.append(i + 1);
    }
    L.tail->next = L.head->next->next->next; // creating cycle
    cout << L.isCyclic();
}