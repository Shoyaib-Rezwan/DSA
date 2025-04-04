// source: https://neetcode.io/problems/lru-cache

// implement the Least Recently Used(LRU)
// cache class LRUCache.The class should support the following operations

// LRUCache(int capacity) Initialize the LRU cache of size capacity.int get(int key) Return the value cooresponding to the key if the key exists,
//     otherwise return -1. void put(int key, int value) Update the value of the key if the key exists.Otherwise, add the key - value pair to the cache.If the introduction of the new pair causes the cache to exceed its capacity, remove the least recently used key.A key is considered used if a get or a put operation is called on it.

//                                                                                                                                                                                                                                                                                                           Ensure that get and put each run in O(1) O(1) average time complexity.

//                                                                                                                                                                                                                                                                                                           Example 1 :

//     Input : [ "LRUCache", [2], "put", [ 1, 10 ], "get", [1], "put", [ 2, 20 ], "put", [ 3, 30 ], "get", [2], "get", [1] ]

//             Output : [ null, null, 10, null, null, 20, -1 ]

//                      Explanation : LRUCache lRUCache = new LRUCache(2);
// lRUCache.put(1, 10); // cache: {1=10}
// lRUCache.get(1);     // return 10
// lRUCache.put(2, 20); // cache: {1=10, 2=20}
// lRUCache.put(3, 30); // cache: {2=20, 3=30}, key=1 was evicted
// lRUCache.get(2);     // returns 20
// lRUCache.get(1);     // return -1 (not found)
// Constraints :

//     1 <= capacity <= 100 0 <= key <= 1000 0 <= value <= 1000
#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int key;
    int value;
    Node *next;
    Node *prev;
    Node(int key = 0, int value = 0)
    {
        this->key = key;
        this->value = value;
        next = nullptr;
        prev = nullptr;
    }
};
class LRUCache
{
    Node *left;
    Node *right;
    map<int, Node *> m;
    int size;
    int capacity;

public:
    LRUCache(int capacity)
    {
        left = new Node;
        right = new Node;
        size = 0;
        this->capacity = capacity;
        left->next = right;
        right->prev = left;
    }
    void moveAtRight(Node *node)
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        right->prev->next = node;
        node->prev = right->prev;
        right->prev = node;
        node->next = right;
    }
    int get(int key)
    {
        if (m.find(key) != m.end())
        {
            Node *result = m.find(key)->second;
            if (result == nullptr)
                return -1;
            moveAtRight(result);
            return result->value;
        }
        else
            return -1;
    }
    void removeFromLeft()
    {
        Node *temp = left->next;
        left->next = temp->next;
        temp->next->prev = left;
        delete temp;
    }
    void put(int key, int value)
    {

        if (m.find(key) != m.end())
        {
            Node *result = m.find(key)->second;
            if (!result)
            {
                result = new Node;
                result->next = right;
                result->prev = right->prev;
                right->prev = result;
                result->prev->next = result;
                m[key] = result;
            }
            result->value = value;
            moveAtRight(result);
        }
        else
        {

            if (size == capacity)
            {
                m[left->next->key] = nullptr;
                removeFromLeft();
                size--;
            }

            Node *newNode = new Node(key, value);
            cout << "J\n";
            right->prev->next = newNode;
            newNode->next = right;
            newNode->prev = right->prev;
            right->prev = newNode;
            m[key] = newNode;
            size++;
        }
    }
};

int main()
{
    int capacity;
    cin >> capacity;
    LRUCache cache(capacity);
    int func;
    cin >> func;
    while (func)
    {
        if (func == 1)
        {
            int key;
            cin >> key;
            cout << cache.get(key) << '\n';
        }
        else if (func == 2)
        {
            int key, value;
            cin >> key >> value;
            cache.put(key, value);
        }
        else
            break;
        cin >> func;
    }
}