//#include<iostream>

//#include<opencv2/core/core.hpp>
//#include<opencv2/highgui/highgui.hpp>
#include "opencv2/opencv.hpp" //或者使用这行，代替上面两行
using namespace cv;   

int main() 

{ 

    Mat img=imread("meinv.jpg");//读入一张图片

	//namedWindow("Test");      //创建一个名为Test窗口

	imshow("Test",img);   //窗口中显示图像

	waitKey();            //等待5000ms后窗口自动关闭
	return 0;

} 