// #include <iostream>
// using namespace std;
// // creating node structure
// struct Node
// {
//     int data;
//     Node *next;
// };
// void displayList(Node *head)
// {
//     if (head == nullptr)
//         cout << "This is an empty list." << "\n";
//     else
//     {
//         do
//         {
//             cout << head->data << "\n";
//             head = head->next;
//         } while (head != nullptr);
//     }
// }
// int main()
// {
//     // creating head
//     Node *head = new Node(); // dynamically initializing a Node structure
//     head = nullptr;          // initializing head as a null pointer
//     // creating total 5 nodes in the linked list
//     for (int i = 0; i < 5; i++)
//     {
//         Node *newNode = new Node;
//         newNode->data = i + 1;
//         newNode->next = nullptr;
//         // linking the created node with the main linked list
//         if (head == nullptr)
//         {
//             // it means the list is empty
//             head = newNode; // assigning the new node to head
//         }
//         else
//         {
//             Node *temp = head;
//             while (temp->next != nullptr)
//             {
//                 temp = temp->next;
//             }
//             temp->next = newNode;
//         }
//     }
//     // display the list
//     displayList(head);
//     // free up memory
//     while (head != nullptr)
//     {
//         Node *temp = head;
//         head = head->next;
//         delete temp;
//     }

//     return 0;
// }
/******************************************************** */
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
Node *CreateLinkedList(int num)
{
    int i = 0;
    Node *head = new Node;
    head = nullptr;
    while (num--)
    {
        Node *node = new Node(++i);
        if (!head) // when the list is empty the modify head
        {
            head = node;
        }
        else
        {
            Node *current = new Node;
            current = head;
            while (current->next)
            {
                current = current->next;
            }
            current->next = node;
            current = nullptr;
            delete current; // you can't directly delete current without assigning nullptr to it because it may lead to the deletion of some items of the list
        }
    }
    return head;
}
void DisplayList(Node *head)
{
    if (!head)
    {
        cout << "The list is empty!!\n";
    }
    else
    {
        Node *current = head;
        while (current)
        {
            cout << current->data << '\t';
            current = current->next;
        }
        cout << "\n";
    }
}
int main()
{
    Node *head = CreateLinkedList(10);
    DisplayList(head);
}
