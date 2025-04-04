#include <iostream>
using namespace std;
template <typename E>
class Node
{
public:
    E element;
    Node *next;
    // constructor
    Node(E &elemval = 0, Link *nextval = nullptr)
    {
        this->element = elemval;
        this->next = nextval;
    }
};
template <class E>
class LList
{
    Node<E> *head;
    Node<E> *curr;
    Node<E> *tail;
    int cnt; // length of the list
public:
    LLIst()
    {
        head = curr = tail = new Node<E>;
        cnt = 0;
    }
    ~LList()
    {
        while (head)
        {
            curr = head;
            head = head->next;
            delete curr;
        }
    }
    void print() const
    {
        Node<E> *temp = new Node<E>;
        temp = head;
        cout << "< ";
        while (temp)
        {
            cout << temp->element << ' ';
            if (temp == curr)
                cout << "| ";
        }
        cout << ">\n";
        delete temp;
    }
    void insert(const E &it)
    {
        curr->next = new Node<E>(it, curr->next);
        if (curr == tail)
            tail = curr->next;
        cnt++;
    }
    void append(const E &it)
    {
        tail->next = new Node<E>(it);
        tail = tail->next;
        cnt++;
    }
    E remove()
    {
        if (curr == tail)
        {
            cout << "No elements\n";
        }
        else
        {
            Node<E> *ltemp = new Node<E>;
            ltemp = curr->next;
            curr->next = ltemp->next; // redirecting next pointer around the removing node;
            if (tail == ltemp)        // if the rmoved node is the tail
            {
                tail = curr;
            }
            E it = ltemp->element;
            delete ltemp;
            cnt--;
            return it;
        }
    }
    void moveToStart() { curr = head; }
    void moveToEnd() { curr = tail; }
    void moveToPos(int pos)
    {
        if (pos < 0 || pos >= cnt)
        {
            cout << "Out of range\n";
        }
        else
        {
            curr = head;
            while (pos--)
            {
                curr = curr->next;
            }
        }
    }
    void Next()
    {
        if (curr == tail)
            return;
        else
            curr = curr->next;
    };
    void prev()
    {
        if (curr == head)
            return;
        else
        {
            Node<E> *temp = new Node<E>;
            temp = head;
            while (temp->next != curr)
            {
                temp = temp->next;
            }
            curr = temp;
            temp = nullptr;
            delete temp;
        }
    }
    int length() const { return cnt; }
    void getValue()
    {
        if (curr->next == nullptr)
        {
            cout << "No value\n";
        }
        else
        {
            cout << curr->next->element << '\n';
        }
    }
};
int main()
{
}