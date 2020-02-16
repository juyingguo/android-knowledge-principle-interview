#include"opencv2/opencv.hpp"
using namespace cv;
int main(void)
{
	Mat image=imread("meinv.jpg");
	imshow("Hello world",image);
	waitKey(0);
}