//#include<iostream>

//#include<opencv2/core/core.hpp>
//#include<opencv2/highgui/highgui.hpp>
#include <iostream>
#include "opencv2/opencv.hpp" //或者使用这行，代替上面两行
using namespace cv;   
using namespace std;   
int main() 

{ 
	//Mat img = imread("meinv.jpg");//读入一张图片
   //Mat img = imread("meinv.jpg",0);//读入一张图片,grayscale
	Mat img = imread("meinv.jpg",-1);//读入一张图片,IMREAD_UNCHANGED(<0)表示加载原图，不做任何改变

	//namedWindow("Test");      //创建一个名为Test窗口
	   
   if(img.empty()){
		 cout << "img is empty" << endl;
		 return -1;
	}

	imshow("Test",img);   //窗口中显示图像

	waitKey(0);            //等待5000ms后窗口自动关闭
	return 0;

} 