class A                   //AΪ����
{public:
  void f1( );
  int i;
 protected:
  void f2();
  int j;
 private:
  int k;
};

class B: public A            //BΪA�Ĺ���������
{public:
  void f3( );
 protected:
  int m;
 private:
  int n;
};

class C: public B              //CΪB�Ĺ���������
{public:
  void f4();
 private:
  int p;
};

int main()
{A a1;                         //a1�ǻ���A�Ķ���
 B b1;                         //b1��������B�Ķ���
 C c1;                         //c1��������C�Ķ���
 return 0;
}
