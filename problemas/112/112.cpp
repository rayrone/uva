/* 112 - Tree Summing */

#include <iostream>
#include <stdlib.h>
#include <string>
#include <string.h>

using namespace std;

#define NODE_OPEN '('
#define NODE_CLOSE ')'

class Node
{
private:
    Node *_left;
    Node *_right;
    int _value;

public:
    Node(int value)
    {
        _left = NULL;
        _right = NULL;
        _value = value;
    }

    Node *left()
    {
        return _left;
    }

    void setLeft(Node *left)
    {
        _left = left;
    }

    Node *right()
    {
        return _right;
    }

    void setRight(Node *right)
    {
        _right = right;
    }

    int value()
    {
        return _value;
    }

    void setValue(int value)
    {
        _value = value;
    }

    bool hasLeft()
    {
        return _left != NULL;
    }

    bool hasRight()
    {
        return _right != NULL;
    }

    bool isLeaf()
    {
        return _left == NULL && _right == NULL;
    }
};

class BinaryTree
{
private:
    Node *_root;

    bool hasSumDFS(Node *node, int currentSum, int targetSum)
    {
        if (node == NULL)
            return false;

        currentSum += node->value();

        if (currentSum == targetSum && node->isLeaf())
            return true;

        bool foundSum = false;

        if (node->hasLeft())
            foundSum = foundSum || hasSumDFS(node->left(), currentSum, targetSum);

        if (node->hasRight())
            foundSum = foundSum || hasSumDFS(node->right(), currentSum, targetSum);

        return foundSum;
    }

public:
    BinaryTree(Node *root)
    {
        _root = root;
    }

    Node *root()
    {
        return _root;
    }

    void setRoot(Node *root)
    {
        _root = root;
    }

    bool hasSum(int targetSum)
    {
        return hasSumDFS(_root, 0, targetSum);
    }
};

int countCharacters(string str, char c)
{
    int count = 0;

    for (int i = 0; i < (int)str.length(); i++)
        if (str.at(i) == c)
            count++;

    return count;
}

string replace(string input, char old_ch)
{
    string output;
    int len = input.length();

    for (int i = 0; i < len; i++)
    {
        if (input[i] == old_ch)
        {
            output += " ";
            output += input[i];
            output += " ";
        }
        else
            output += input[i];
    }

    return output;
}

Node *readInput(char *token)
{
    if (token == NULL)
        return NULL;

    Node *node = NULL;

    if (token[0] == '(')
    {
        token = strtok(NULL, " ");

        if (token != NULL && token[0] != ')')
        {
            node = new Node(atoi(token));

            token = strtok(NULL, " ");
            node->setLeft(readInput(token));

            token = strtok(NULL, " ");
            node->setRight(readInput(token));

            token = strtok(NULL, " ");
        }
    }

    return node;
}

int main()
{
    int n;

    while (cin >> n)
    {
        string input, token;
        int countClosed = 0, countOpened = 0;

        while (cin >> token)
        {
            countOpened += countCharacters(token, NODE_OPEN);
            countClosed += countCharacters(token, NODE_CLOSE);
            input += token;

            if (countOpened == countClosed)
                break;
        }

        input = replace(input, NODE_OPEN);
        input = replace(input, NODE_CLOSE);

        char *strTok = strtok((char *)input.c_str(), " ");
        BinaryTree tree(readInput(strTok));

        if (tree.hasSum(n))
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }

    return 0;
}
