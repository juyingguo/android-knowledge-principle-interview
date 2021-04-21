#include"opencv2/opencv.hpp"
using namespace cv;
int main(void)
{
	Mat image=imread("‪meinv.jpg");
	imshow("Hellow world",image);
	waitKey(0);
	//system("pause");
	return 0;
}