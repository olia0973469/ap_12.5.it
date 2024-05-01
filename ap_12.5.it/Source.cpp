#include <iostream>
#include <fstream>
#include <string>
#include <stack>
using namespace std;

typedef char Info;

struct Elem
{
    Elem* link;
    Info info;
};

Elem* push(Elem* top, Info value)
{
    Elem* tmp = new Elem;
    tmp->info = value;
    tmp->link = top;
    top = tmp;
    return top;
}

Elem* pop(Elem* top, Info& value)
{
    if (top == NULL)
    {
        cout << "The stack is empty" << endl;
        return NULL;
    }
    else
    {
        Elem* tmp = top->link;
        value = top->info;
        delete top;
        top = tmp;
        return top;
    }
}

Elem* createStackFromFile(string filename)
{
    Elem* top = NULL;
    char value;
    ifstream inFile;
    inFile.open(filename);
    if (!inFile)
    {
        cerr << "Unable to open file " << filename << endl;
        exit(1);
    }
    while (inFile >> value)
    {
        top = push(top, value);
    }
    inFile.close();
    return top;
}

void printStack(Elem* top)
{
    if (top == NULL)
    {
        cout << "The stack is empty" << endl;
    }
    else
    {
        Elem* tmp = top;
        while (tmp != NULL)
        {
            cout << tmp->info << " ";
            tmp = tmp->link;
        }
        cout << endl;
    }
}

void sortStack(stack<Info>& inputStack)
{
    stack<Info> tmpStack;
    while (!inputStack.empty())
    {
        Info tmp = inputStack.top();
        inputStack.pop();
        while (!tmpStack.empty() && tmpStack.top() < tmp)
        {
            inputStack.push(tmpStack.top());
            tmpStack.pop();
        }
        tmpStack.push(tmp);
    }
    while (!tmpStack.empty())
    {
        inputStack.push(tmpStack.top());
        tmpStack.pop();
    }
}

int main()
{
    Elem* top = createStackFromFile("test.txt");

    cout << "Unsorted Stack: ";
    printStack(top);

    stack<Info> inputStack;
    Elem* tmp = top;
    while (tmp != NULL)
    {
        inputStack.push(tmp->info);
        tmp = tmp->link;
    }

    sortStack(inputStack);

    cout << "Sorted Stack: ";
    while (!inputStack.empty())
    {
        cout << inputStack.top() << " ";
        inputStack.pop();
    }
    cout << endl;

    return 0;
}
