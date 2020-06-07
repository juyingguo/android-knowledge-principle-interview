#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <stdexcept>

using namespace std;

template <typename T>
class Stack {
  private:
    vector<T> elems;     // Ԫ��

  public:
    void push(T const&);  // ��ջ
    void pop();               // ��ջ
    T top() const;            // ����ջ��Ԫ��
//    template <typename U>U top() const;            // ����ջ��Ԫ��
    bool empty() const{       // ���Ϊ���򷵻��档
        return elems.empty();
    }
};

template <typename T>
void Stack<T>::push (T const& elem)
{
    // ׷�Ӵ���Ԫ�صĸ���
    elems.push_back(elem);
}

template <typename T>
void Stack<T>::pop ()
{
    if (elems.empty()) {
        throw out_of_range("Stack<>::pop(): empty stack");
    }
    // ɾ�����һ��Ԫ��
    elems.pop_back();
}

template <typename T>
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
        intStack.push(2000);
        intStack.push(1500);
        cout << intStack.top() <<endl;

        // ���� string ���͵�ջ
        stringStack.push("hello");
        stringStack.push("world! love you") ;
//        cout << stringStack.top() << std::endl;
        cout << stringStack.top() <<endl;
        stringStack.pop();
        stringStack.pop();
    }
    catch (exception const& ex) {
        cerr << "Exception: " << ex.what() <<endl;
        return -1;
    }
}
