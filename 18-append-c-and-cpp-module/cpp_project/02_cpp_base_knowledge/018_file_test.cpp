#include <fstream>
#include <iostream>
using namespace std;
 
int main ()
{
    
   char data[100];
 
   // ��дģʽ���ļ�
   ofstream outfile;
   outfile.open("afile.dat",ios::out);
 
   cout << "Writing to the file" << endl;
   cout << "Enter your name: "; 
   cin.getline(data, 100);
 
   // ���ļ�д���û����������
   outfile << data << endl;
 
   cout << "Enter your age: "; 
   cin >> data;
   cin.ignore();
   
   // �ٴ����ļ�д���û����������
   outfile << data << endl;
 
   // �رմ򿪵��ļ�
   outfile.close();
 
   // �Զ�ģʽ���ļ�
   ifstream infile; 
   infile.open("afile.dat",ios::in); 
 
   cout << "Reading from the file" << endl; 
   infile >> data; 
 
   // ����Ļ��д������
   cout << data << endl;
   
   // �ٴδ��ļ���ȡ���ݣ�����ʾ��
   infile >> data; 
   cout << data << endl; 
 
   // �رմ򿪵��ļ�
   infile.close();
 
   return 0;
}
