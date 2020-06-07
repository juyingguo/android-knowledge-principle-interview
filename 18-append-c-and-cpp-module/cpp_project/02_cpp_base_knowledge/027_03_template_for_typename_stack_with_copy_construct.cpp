#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <stdexcept>

using namespace std;

template <typename T>
class Stack {
  private:
    vector<T> elems;     // 元素

  public:
    inline Stack<T>(){ }// 当下面一行添加拷贝构造函数是，必须显式的定义默认构造函数。
    template<typename U> Stack(U* other);

    void push(T const&);  // 入栈
    void pop();               // 出栈
    T top() const;            // 返回栈顶元素
//    template <typename U>U top() const;            // 返回栈顶元素
    bool empty() const{       // 如果为空则返回真。
        return elems.empty();
    }
};

/**
*拷贝构造函数，定义模板类型。
*/
template<typename T> template<typename U>
Stack<T>::Stack(U* other)
{
    elems = other.elems;
}

template <typename T>
void Stack<T>::push (T const& elem)
{
    // 追加传入元素的副本
    elems.push_back(elem);
}

template <typename T>
void Stack<T>::pop ()
{
    if (elems.empty()) {
        throw out_of_range("Stack<>::pop(): empty stack");
    }
    // 删除最后一个元素
    elems.pop_back();
}

template <typename T>
T Stack<T>::top () const
{
    if (elems.empty()) {
        throw out_of_range("Stack<>::top(): empty stack");
    }
    // 返回最后一个元素的副本
    return elems.back();
}

int main()
{
    try {
        Stack<int>         intStack;  // int 类型的栈
        Stack<string> stringStack;    // string 类型的栈

        // 操作 int 类型的栈
        intStack.push(2000);
        intStack.push(1500);
        cout << intStack.top() <<endl;

        // 操作 string 类型的栈
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
