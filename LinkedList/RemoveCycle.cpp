// check whether you linked list contains a cycle or not. If yes then remove that cycle.
// example: 1->2->3->4->5->6->7->5
// use floyd's loop detecting algorithm or the hare and tortoise algorithm
#include <iostream>
// #include <unordered_set> //this is only for printing the list
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
// void print(Node *head)
// {
//     unordered_set<Node *> s;
//     s.insert(head);
//     cout << head->data << ' ';
//     head = head->next;
//     // while (head)
//     // {

//     //     else
//     //     {
//     //         break;
//     //     }
//     // }
//     while (s.find(head) != s.end())
//     {
//         s.insert(head);
//         cout << head->data << ' ';
//         head = head->next;
//         if (!head)
//             break;
//     }
// }
void print(Node *head)
{
    while (head)
    {
        cout << head->data << '\t';
        head = head->next;
    }
    cout << '\n';
}
bool remove_loop(Node *head)
{
    Node *hare, *tortoise;
    hare = tortoise = head;
    bool flag = false;
    // detect loop
    while (hare && tortoise && tortoise->next)
    {
        hare = hare->next;
        tortoise = tortoise->next->next;
        if (hare == tortoise)
        {
            flag = true;
            break;
        }
    }
    if (flag == true)
    {
        tortoise = head;
        while (tortoise != hare)
        {
            tortoise = tortoise->next;
            hare = hare->next;
        }
        while (tortoise->next != hare)
        {
            tortoise = tortoise->next;
        }
        tortoise->next = nullptr;
    }
    return flag;
}
int main()
{
    Node *head = new Node;
    head = nullptr;
    for (int i = 0; i < 7; i++)
    {
        append(&head, i + 1);
    }

    // create a loop
    Node *temp = head;
    while (temp->next)
    {
        temp = temp->next;
    }
    temp->next = head->next->next->next->next;
    remove_loop(head);
    print(head);
}