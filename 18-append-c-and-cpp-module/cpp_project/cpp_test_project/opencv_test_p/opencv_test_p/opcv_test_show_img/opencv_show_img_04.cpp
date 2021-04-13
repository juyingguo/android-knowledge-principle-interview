

#include "cv.h"   //openv基本的头文件
#include <highgui.h> // opencv 图像显示的头文件
 
int main()
{
	IplImage  * src;   //定义一个IplImage 的指针变量 src
	src = cvLoadImage("‪mao.jpg", 0);  //获取图片 第二个参数选择 -1 0 1 会有不同的效果
	cvNamedWindow("mao.jpg", CV_WINDOW_AUTOSIZE); //设置显示名字与图片大小
	cvShowImage("mao.jpg",src); //显示图片
	cvWaitKey(0);  //无限等待  
	cvSaveImage("mao1.jpg", src); //保存图片 
	cvDestroyWindow("mao.jpg");  //销毁窗口
	cvReleaseImage(&src);
    return 0;
}
