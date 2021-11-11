
#include <iostream>
#include <string.h>
#include <unistd.h>

using namespace std;

class RefBase {
private:
	int count;

public:
	RefBase() : count(0) {}
	void incStrong(){ count++; }
	void decStrong(){ count--; }
	int getStrongCount(){ return count;}
};

template<typename T>
class sp {
private:
	T *p;

public:
	sp() : p(0) {
        cout<<"sp() this pointer="<<this<<endl;
	}

	sp(T *other)
	{
		cout<<"sp(T *other) this pointer="<<this<<endl;
		p = other;
		p->incStrong();
	}

	sp(const sp &other)
	{
		cout<<"sp(const sp &other) this pointer="<<this<<endl;
		p = other.p;
		p->incStrong();
	}

	~sp()
	{
		cout<<"~sp() this pointer="<<this<<endl;

		if (p)
		{
			p->decStrong();
			if (p->getStrongCount() == 0)
			{
				delete p;
				p = NULL;
			}
		}
	}
	// Assignment

    sp& operator = (T* other);
    sp& operator = (const sp<T>& other);

	T *operator->()
	{
		return p;
	}

	T& operator*()
	{
		return *p;
	}

};

template<typename T>
sp<T>& sp<T>::operator = (const sp<T>& other) {
    cout<<"sp<T>::operator = (const sp<T>& other) this pointer="<<this<<endl;
    T* otherPtr(other.p);
    if (otherPtr) otherPtr->incStrong();
    if (p) p->decStrong();
    p = otherPtr;
    return *this;
}

template<typename T>
sp<T>& sp<T>::operator = (T* other)
{
    cout<<"sp<T>::operator = (T* other) this pointer="<<endl;
    if (other) other->incStrong();
    if (p) p->decStrong();
    p = other;
    return *this;
}
class Person : public RefBase{
private:
	sp<Person> father;
	sp<Person> son;
public:
	Person() {
		cout <<"Pserson() this pointer="<<this<<endl;
	}


	~Person()
	{
		cout << "~Person() this pointer="<<this<<endl;
	}

	void setFather(sp<Person> &father)
	{
		this->father = father;
	}

	void setSon(sp<Person> &son)
	{
		this->son = son;
	}

	void printInfo(void)
	{
		cout<<"just a test function"<<endl;
	}
};

void test_func()
{
	/* 1. 对于 new Person()
	 * 1.1 Person对象里的father先被构造
	 * 1.2 Person对象里的son被构造
	 * 1.3 Person对象本身
	 * 2. Person对象的指针传给"sp<Person> father"
	 *    导致: sp(T* other) 被调用
	 *    它增加了这个Person对象的引用计数(现在此值等于1)
	 */
	sp<Person> father = new Person();


	/* 1. 对于 new Person()
	 * 1.1 Person对象里的father先被构造
	 * 1.2 Person对象里的son被构造
	 * 1.3 Person对象本身
	 * 2. Person对象的指针传给"sp<Person> son"
	 *    导致: sp(T* other) 被调用
	 *    它增加了这个Person对象的引用计数(现在此值等于1)
	 */
	sp<Person> son = new Person();

//	sp<Person> other = son;//直接调用sp(const sp &other)

	/* 它是一个"=" : this->son = son
	 * "="被重载, 它会再次增加该Person对象的引用计数
	 * 所以son对应的Person对象的引用计数增加为2
	 */
	father->setSon(son);

	/* 它是一个"=" : this->father = father
	 * "="被重载, 它会再次增加该Person对象的引用计数
	 * 所以father对应的Person对象的引用计数增加为2
	 */
//	son->setFather(father);


	/* 当test_func执行完时, father和son被析构
	 * 1. 先看father:
	 *    ~sp(): decStrong, 里面会将计数值减1 , father对应的Person的计数值等于1, 还没等于0, 所以没有delete
	 * 2. 对于son:
	 *    ~sp(): decStrong, 里面会将计数值减1 , son对应的Person的计数值等于1, 还没等于0, 所以没有delete
	 */

}

int main(int argc, char **argv)
{
	test_func();
	return 0;
}

