#include<iostream>
#include<opencv2/core/core.hpp>
#include<opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main()
{
	Mat a = imread("timg.jpg");
	Mat b = Mat::zeros(a.cols, a.rows, CV_8UC1);
	cvtColor(a, b, CV_BGR2GRAY);
	Mat mask = Mat::zeros(a.cols, a.rows, CV_8UC1);
	/*imshow("gray", b);
	waitKey(0);*/
	std::cout << b << endl;
	for (uint16_t i = 0; i < a.rows; i++)
		for (uint16_t j = 0; j < a.cols; j++)
			if (b.at<uchar>(i, j) == 255)
				mask.at<uchar>(i, j) = 255;
			else
				mask.at<uchar>(i, j) = 0;
	cout << mask << endl;
	//resize()
}
