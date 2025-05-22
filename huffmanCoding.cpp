#include <iostream>
#include <unordered_map>
#include <queue>
#include <string>

using namespace std;

// Node structure for the Huffman Tree
struct Node
{
  char ch;
  int freq;
  Node *left, *right;

  Node(char c, int f)
  {
    ch = c;
    freq = f;
    left = right = nullptr;
  }
};

// Comparator for priority queue (min-heap)
struct compare
{
  bool operator()(Node *a, Node *b)
  {
    return a->freq > b->freq;
  }
};

// Function to build the Huffman Tree
Node *buildHuffmanTree(const unordered_map<char, int> &freqMap)
{
  priority_queue<Node *, vector<Node *>, compare> pq;

  for (auto pair : freqMap)
    pq.push(new Node(pair.first, pair.second));

  while (pq.size() > 1)
  {
    Node *left = pq.top();
    pq.pop();
    Node *right = pq.top();
    pq.pop();

    Node *sum = new Node('\0', left->freq + right->freq);
    sum->left = left;
    sum->right = right;
    pq.push(sum);
  }

  return pq.top(); // Root of Huffman Tree
}

// Recursive function to generate Huffman Codes
void generateCodes(Node *root, string code, unordered_map<char, string> &huffCodes)
{
  if (!root)
    return;

  if (!root->left && !root->right)
    huffCodes[root->ch] = code;

  generateCodes(root->left, code + "0", huffCodes);
  generateCodes(root->right, code + "1", huffCodes);
}

// Encode the input string
string encode(const string &text, const unordered_map<char, string> &huffCodes)
{
  string encoded = "";
  for (char ch : text)
    encoded += huffCodes.at(ch);
  return encoded;
}

// Decode the encoded string using Huffman Tree
string decode(const string &encoded, Node *root)
{
  string decoded = "";
  Node *curr = root;
  for (char bit : encoded)
  {
    if (bit == '0')
      curr = curr->left;
    else
      curr = curr->right;

    if (!curr->left && !curr->right)
    {
      decoded += curr->ch;
      curr = root;
    }
  }
  return decoded;
}

int main()
{
  string input;
  cout << "Enter a string to encode using Huffman Coding: ";
  getline(cin, input);

  // Count frequency of each character
  unordered_map<char, int> freqMap;
  for (char ch : input)
    freqMap[ch]++;

  // Build Huffman Tree
  Node *root = buildHuffmanTree(freqMap);

  // Generate Huffman Codes
  unordered_map<char, string> huffCodes;
  generateCodes(root, "", huffCodes);

  // Print Huffman Codes
  cout << "\nHuffman Codes:\n";
  for (auto pair : huffCodes)
    cout << pair.first << ": " << pair.second << "\n";

  // Encode
  string encoded = encode(input, huffCodes);
  cout << "\nEncoded string:\n"
       << encoded << "\n";

  // Decode
  string decoded = decode(encoded, root);
  cout << "\nDecoded string:\n"
       << decoded << "\n";

  return 0;
}
