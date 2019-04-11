//#include "stdafx.h"
#include <opencv2/core/core.hpp>
#include "opencv2/imgproc/imgproc.hpp"
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
using namespace cv;
using namespace std;

bool T=true;
int m;
//int _tmain(int argc, _TCHAR* argv[])
int main(void)
{

	Mat image;
	image = imread("1.png", IMREAD_COLOR); // Read the file
	if (!image.data) // Check for invalid input
	{
		cout << "Could not open or find the image" << std::endl;
		return -1;
	}

	// threshold to get mask
	int threshold_value = 10;
	int max_BINARY_value = 256;
	Mat mask(1080,1920,CV_8UC1);
	//mask = imread("mask.jpg", 0);
	for (int i = 0; i < 1080; i++)
	{
		
		uchar *p = mask.ptr(i);
		for (int j = 0; j < 1920; j++)
		{
			if (T = true)
			{
				m = 0;
			}
			else
			{
				m = 1;
			}
			p[j] = m;
			T = -T;
		}
	}
	// mask image
	Mat img_masked;
	//img_masked=image.mul(mask);
	image.copyTo(img_masked, mask);
	imshow("image", image);
	imshow("mask", mask);
	imshow("img_masked", img_masked);
	waitKey(0); // Wait for a keystroke in the window
	return 0;
}
