#include <iostream>
using namespace std;
int main()
 {void move(int *array,int n,int m);
  int number[20],n,m,i; 
  cout<<"how many numbers?";               // ѯ�ʹ��ж��ٸ��� 
  cin>>n;
  cout<<"input "<<n<<" numbers:"<<endl;    // Ҫ������n���� 
  for (i=0;i<n;i++)
    cin>>number[i];
  cout<<"how many places do you want move?";  // ѯ�ʺ��ƶ��ٸ�λ��
  cin>>m;
  move(number,n,m);                       //����move ���� 
  cout<<"Now,they are:"<<endl;
  for (i=0;i<n;i++)
    cout<<number[i]<<" ";
  cout<<endl;
  return 0;
}

void move(int *array,int n,int m)             //ʹѭ������һ�εĺ���
 {int *p,array_end;
  array_end=*(array+n-1);
  for (p=array+n-1;p>array;p--)
    *p=*(p-1);
  *array=array_end;
  m--;
  if (m>0) move(array,n,m); //�ݹ����,��ѭ������m����Ϊ0ʱ,ֹͣ���� 
 }

	
 

	
   


 
