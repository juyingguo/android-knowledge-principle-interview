#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <stdexcept>

using namespace std;

template <class T>
class Stack {
  private:
    vector<T> elems;     // Ԫ��

  public:
    void push(T const&);  // ��ջ
    void pop();               // ��ջ
    T top() const;            // ����ջ��Ԫ��
    bool empty() const{       // ���Ϊ���򷵻��档
        return elems.empty();
    }
};

template <class T>
void Stack<T>::push (T const& elem)
{
    // ׷�Ӵ���Ԫ�صĸ���
    elems.push_back(elem);
}

template <class T>
void Stack<T>::pop ()
{
    if (elems.empty()) {
        throw out_of_range("Stack<>::pop(): empty stack");
    }
    // ɾ�����һ��Ԫ��
    elems.pop_back();
}

template <class T>
T Stack<T>::top () const
{
    if (elems.empty()) {
        throw out_of_range("Stack<>::top(): empty stack");
    }
    // �������һ��Ԫ�صĸ���
    return elems.back();
}

int main()
{
    try {
        Stack<int>         intStack;  // int ���͵�ջ
        Stack<string> stringStack;    // string ���͵�ջ

        // ���� int ���͵�ջ
        intStack.push(7);
        intStack.push(200);
        cout << intStack.top() <<endl;

        // ���� string ���͵�ջ
        stringStack.push("hello");
        stringStack.push("world!") ;
        cout << stringStack.top() << std::endl;
        stringStack.pop();
        stringStack.pop();
        stringStack.pop();
    }
    catch (exception const& ex) {
        cerr << "Exception: " << ex.what() <<endl;
        return -1;
    }
}
