class A                   //A为基类
{public:
  void f1( );
  int i;
 protected:
  void f2();
  int j;
 private:
  int k;
};

class B: public A            //B为A的公用派生类
{public:
  void f3( );
 protected:
  int m;
 private:
  int n;
};

class C: public B              //C为B的公用派生类
{public:
  void f4();
 private:
  int p;
};

int main()
{A a1;                         //a1是基类A的对象
 B b1;                         //b1是派生类B的对象
 C c1;                         //c1是派生类C的对象
 return 0;
}
