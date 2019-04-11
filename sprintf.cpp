#include<opencv2/opencv.hpp>


int main()
{
	int _frameIdx = 0;
	char imgd[200] = "G://CPro//faceswap//yanimage//colorImage//";
	char num[10] = "";
	sprintf(num, "%d", _frameIdx);
	strcat(num, ".jpg");
	cv::Mat dep = cv::imread(strcat(imgd, num), CV_8UC1);
	cv::namedWindow("Dep", CV_WINDOW_AUTOSIZE);
	imshow("Dep", dep);
	cv::waitKey(10000);
	return 0;
	
}
