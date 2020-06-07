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
    inline Stack<T>(){ }// ������һ����ӿ������캯���ǣ�������ʽ�Ķ���Ĭ�Ϲ��캯����
    template<typename U> Stack(U* other);

    void push(T const&);  // ��ջ
    void pop();               // ��ջ
    T top() const;            // ����ջ��Ԫ��
//    template <typename U>U top() const;            // ����ջ��Ԫ��
    bool empty() const{       // ���Ϊ���򷵻��档
        return elems.empty();
    }
};

/**
*�������캯��������ģ�����͡�
*/
template<typename T> template<typename U>
Stack<T>::Stack(U* other)
{
    elems = other.elems;
}

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

        stringStack.push("Today is a good day!I love my girl friend very much.");
        Stack<string> strStackThird = stringStack;

        cout << strStackThird.top() <<endl;

        stringStack.pop();
        stringStack.pop();
    }
    catch (exception const& ex) {
        cerr << "Exception: " << ex.what() <<endl;
        return -1;
    }
}
