//--------------------------------------【程序说明】-------------------------------------------
//		程序说明：《OpenCV3编程入门》OpenCV2版书本配套示例程序07
//		程序描述：使用VideoCapture类调用摄像头读入视频并显示
//		开发测试所用操作系统： Windows 7 64bit
//		开发测试所用IDE版本：Visual Studio 2010
//		开发测试所用OpenCV版本：	2.4.9
//		2014年03月 Created by @浅墨_毛星云
//		2014年11月 Revised by @浅墨_毛星云
//------------------------------------------------------------------------------------------------

//---------------------------------【头文件、命名空间包含部分】----------------------------
//		描述：包含程序所使用的头文件和命名空间
//-------------------------------------------------------------------------------------------------
#include <opencv2\opencv.hpp>  
using namespace cv;  

//-----------------------------------【main( )函数】--------------------------------------------
//		描述：控制台应用程序的入口函数，我们的程序从这里开始
//-------------------------------------------------------------------------------------------------
int main( )  
{  
	//【1】从摄像头读入视频
	VideoCapture capture(0);

	//【2】循环显示每一帧
	while(1)  
	{  
		Mat frame;  //定义一个Mat变量，用于存储每一帧的图像
		capture>>frame;  //读取当前帧
		imshow("读取视频",frame);  //显示当前帧
		waitKey(30);  //延时30ms
	}  
	return 0;     
}  
