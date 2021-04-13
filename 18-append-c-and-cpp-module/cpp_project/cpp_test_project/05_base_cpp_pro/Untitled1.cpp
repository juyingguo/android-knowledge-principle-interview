#include"opencv2/opencv.hpp"
using namespace cv;
int main(void)
{
	Mat image=imread("C:\\Users\\Administrator.USER-20180727ZC\\Desktop\\aa.jpg");
	imshow("Hellow world",image);
	waitKey(0);
}
