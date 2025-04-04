#include <iostream>
#define THROW                                            \
    {                                                    \
        throw out_of_range("The index is out of range"); \
    }
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        next = nullptr;
    }
};
Node *createLinkedList(int size)
{
    int i;
    Node *head = new Node;
    head = nullptr;
    for (i = 0; i < size; i++)
    {
        Node *newNode = new Node;
        newNode->data = i + 1;
        if (head == nullptr)
            head = newNode;
        else
        {
            Node *temp = head;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
    return head;
}
void display(Node *head)
{
    if (head == nullptr)
        cout << "The list is empty.";
    else
    {
        while (head != nullptr)
        {
            cout << head->data << " ";
            head = head->next;
        }
        cout << "\n";
    }
}
void freeList(Node **head)
{
    while (*head != nullptr)
    {
        Node *temp = *head;
        *head = (*head)->next;
        delete temp;
    }
}
void DeleteNode(Node **head, int index)
{
    Node *temp;
    if (index < 0)
        THROW;
    // handle the case separatey when deleting the head node
    if (index == 0)
    {
        temp = *head;
        *head = (*head)->next;
        delete temp;
    }
    else
    {
        temp = *head;
        while (--index) // reaching the node index-1;
        {
            temp = temp->next;
            if (temp->next == nullptr) // throw error if given range indicates outside the list
                THROW;
        }
        Node *ptr = temp->next;
        temp->next = (temp->next)->next;
        delete ptr;
    }
}
int main()
{
    Node *head = createLinkedList(1);
    display(head);
    // freeList(&head);
    DeleteNode(&head, 1);
    display(head);
}