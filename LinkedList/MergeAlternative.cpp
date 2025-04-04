/*Given two linked lists, insert nodes of second list into first list at alternate positions of first list.
For example, if first list is 5->7->17->13->11 and second is 12->10->2->4->6, the first list should become 5->12->7->10->17->2->13->4->11->6 and second list should become empty. The nodes of second list should only be inserted when there are positions available. For example, if the first list is 1->2->3 and second list is 4->5->6->7->8, then first list should become 1->4->2->5->3->6 and second list to 7->8.

Use of extra space is not allowed (Not allowed to create additional nodes), i.e., insertion must be done in-place. Expected time complexity is O(n) where n is number of nodes in first list.

mergeList() will return a vector containing two modified heads

*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

void printList(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << ' ';
        temp = temp->next;
    }
    cout << '\n';
}

// } Driver Code Ends
/*
structure of the node of the linked list is
struct Node
{
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/
// Function to merge two linked lists
class Solution
{
public:
    vector<Node *> mergeList(struct Node **head1, struct Node **head2)
    {
        // Code Here
        Node *current1 = new Node(0);
        Node *current2 = new Node(0);
        Node *next1 = new Node(0);
        Node *next2 = new Node(0);
        current1 = *head1;
        current2 = *head2;
        next1 = (*head1)->next;
        next2 = (*head2)->next;
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
        *head2 = current2;
        current1 = current2 = next1 = next2 = nullptr;
        delete current1;
        delete current2;
        delete next1;
        delete next2;
        vector<Node *> ret;
        ret.push_back(*head1);
        ret.push_back(*head2);
        return ret;
    }
};

//{ Driver Code Starts.

// Driver program to test above functions
int main()
{
    int T;
    cin >> T;
    cin.ignore();
    while (T--)
    {
        int n1, n2, tmp;
        Node *head1 = nullptr, *tail1 = nullptr;
        Node *head2 = nullptr, *tail2 = nullptr;
        string input1, input2;

        getline(cin, input1); // Read the entire line for the LL1 elements
        stringstream ss1(input1);
        while (ss1 >> tmp)
        {
            Node *new_node = new Node(tmp);
            if (head1 == nullptr)
            {
                head1 = new_node;
                tail1 = new_node;
            }
            else
            {
                tail1->next = new_node;
                tail1 = new_node;
            }
        }

        getline(cin, input2); // Read the entire line for the LL2 elements
        stringstream ss2(input2);
        while (ss2 >> tmp)
        {
            Node *new_node = new Node(tmp);
            if (head2 == nullptr)
            {
                head2 = new_node;
                tail2 = new_node;
            }
            else
            {
                tail2->next = new_node;
                tail2 = new_node;
            }
        }

        Solution obj;
        vector<Node *> new_heads = obj.mergeList(&head1, &head2);
        printList(new_heads[0]);
        printList(new_heads[1]);
    }
    return 0;
}

// } Driver Code Ends