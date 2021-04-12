#include <opencv2\opencv.hpp>  
#include <iostream>

int main()
{
    IplImage *src;
    src = cvLoadImage("mao.jpg",-1);
    cvNamedWindow("mao.jpg",0);
    cvShowImage("mao.jpg",src);

    cvWaitKey(0);
    cvDestroyWindow("mao.jpg");
    cvReleaseImage(&src);

    return 0;
}
