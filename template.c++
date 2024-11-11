#include <iostream>
using namespace std;

template <typename T>
class Stack
{
private:
    T *arr;
    int top;
    int capacity;

public:
    Stack(int size)
    {
        capacity = size;
        arr = new T[capacity];
        top = -1;
    }

    ~Stack()
    {
        delete[] arr;
    }

    bool isEmpty()
    {
        return top == -1;
    }

    bool isFull()
    {
        return top == capacity - 1;
    }

    void push(T val)
    {
        if (!isFull())
        {
            arr[++top] = val;
        }
    }

    void pop()
    {
        if (!isEmpty())
        {
            top--;
        }
    }

    T peek()
    {
        if (!isEmpty())
        {
            return arr[top];
        }
        return T();
    }
};

int main()
{
    Stack<int> s(5);

    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top Element: " << s.peek() << endl;
    s.pop();
    cout << "Top Element after pop: " << s.peek() << endl;
    s.pop();
    s.pop();

    if (s.isEmpty())
    {
        cout << "Stack is empty" << endl;
    }

    return 0;
}
