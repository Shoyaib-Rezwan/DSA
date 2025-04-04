#include <bits/stdc++.h>
using namespace std;
struct Node
{
    char character;
    int frequency;
    Node *left;
    Node *right;
    Node(char character, int frequency)
    {
        this->character = character;
        this->frequency = frequency;
        left = right = nullptr;
    }
};
struct compare
{
    bool operator()(Node *first, Node *second)
    {
        return first->frequency > second->frequency;
    }
};
// code for building the Huffman Tree
Node *buildHuffmanTree(map<char, int> &frequencyMap)
{
    priority_queue<Node *, vector<Node *>, compare> minHeap;
    // push each characters with their
    for (pair<char, int> entry : frequencyMap)
    {
        minHeap.push(new Node(entry.first, entry.second));
    }
    while (minHeap.size() > 1)
    {
        Node *left = minHeap.top();
        minHeap.pop();
        Node *right = minHeap.top();
        minHeap.pop();
        Node *mergedNode = new Node('\0', left->frequency + right->frequency);
        mergedNode->left = left;
        mergedNode->right = right;
        minHeap.push(mergedNode);
    }
    return minHeap.top();
}
// determines huffman code for each character
void getHuffmanCodes(Node *root, map<char, string> &huffmanCodes, string code)
{
    if (!root)
        return;
    if (!root->left && !root->right)
        huffmanCodes.insert({root->character, code});
    else
    {
        getHuffmanCodes(root->left, huffmanCodes, code + '0'); // the huffman tree is always a full binary tree.. so it must have 2 children or no children
        getHuffmanCodes(root->right, huffmanCodes, code + '1');
    }
}
// encodes the message according to the huffman codes
string encodeMessage(map<char, string> &huffmanCodes, string &message)
{
    string encodedMessage;
    for (char x : message)
    {
        encodedMessage += huffmanCodes[x];
    }
    return encodedMessage;
}
int main()
{
    // MESSAGE TO ENCODE
    string message = "BCCABBDDAECCBBAEDDCC";
    // STORE FREQUENCIES
    map<char, int> frequencyMap;
    // inialize the map
    for (int i = 0; i < message.size(); i++)
    {
        if (frequencyMap.find(message[i]) != frequencyMap.end())
        {
            frequencyMap[message[i]]++;
        }
        else
        {
            frequencyMap.insert({message[i], 1});
        }
    }
    // now build the huffman tree from it
    Node *root = buildHuffmanTree(frequencyMap);
    map<char, string> huffmanCodes;
    getHuffmanCodes(root, huffmanCodes, "");
    for (pair<char, string> entries : huffmanCodes)
    {
        cout << entries.first << ": " << entries.second << '\n';
    }
}