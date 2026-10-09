//NAVYA GUPTA 25/DA/047
#include <iostream>
#include <queue>
using namespace std;

// Node of Huffman tree
struct Node
{   char data;
    int freq;
    Node *left, *right;
    Node(char d, int f)
    {    data = d;
        freq = f;
        left = right = NULL;
    }
};

// Compare nodes by frequency
struct Compare
{   bool operator()(Node* a, Node* b)
    {
        return a->freq > b->freq;
    }
};

// Print Huffman codes
void printCodes(Node* root, string code)
{
    if (root == NULL)
        return;

    // Leaf node contains a character
    if (root->left == NULL && root->right == NULL)
    {
        cout << root->data << " : " << code << endl;
    }

    printCodes(root->left, code + "0");
    printCodes(root->right, code + "1");
}

int main()
{   cout<<"NAVYA GUPTA ROLL NO 25/DA/047\n";
    cout<<"Huffman Coding for data compression\n";
    int n;
    char ch;
    int freq;

    cout << "Enter number of characters: ";
    cin >> n;

    priority_queue<Node*, vector<Node*>, Compare> pq;

    // Read characters and their frequencies
    for (int i = 0; i < n; i++)
    {
        cout << "Enter character and frequency: ";
        cin >> ch >> freq;

        pq.push(new Node(ch, freq));
    }

    // Build the Huffman tree
    while (pq.size() > 1)
    {
        Node* left = pq.top();
        pq.pop();

        Node* right = pq.top();
        pq.pop();

        Node* parent = new Node('$', left->freq + right->freq);
        parent->left = left;
        parent->right = right;

        pq.push(parent);
    }

    // Generate Huffman codes
    cout << "\nHuffman Codes:\n";
    printCodes(pq.top(), "");

    return 0;
}