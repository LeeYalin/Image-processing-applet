#include<opencv2\highgui\highgui.hpp>
#include<opencv2\core\core.hpp>

using namespace std;
using namespace cv;
/*
char savefile12[200];
char savefile13[200];
char savefile14[200];
char savefile15[200];
char savefile16[200];
char savefileout[200];

int num1 = 100;
int num2 = 100;
int num3 = 100;

int main(void)
{
	Mat Res;
	int frameCount = 1;
	while (true)
	{
		sprintf(savefile12, "F:/work/StandSeated/stand12/%06d.bmp", frameCount);
		sprintf(savefile13, "F:/work/StandSeated/stand13/%06d.bmp", frameCount);
		sprintf(savefile14, "F:/work/StandSeated/stand14/%06d.bmp", frameCount);
		sprintf(savefile15, "F:/work/StandSeated/stand15/%06d.bmp", frameCount);
		sprintf(savefile16, "F:/work/StandSeated/stand16/%06d.bmp", frameCount);
		sprintf(savefileout, "F:/work/StandSeated/standout/%06d.bmp", frameCount);

		Mat image12 = imread(savefile12);
		if (! image12.cols)
		{
			frameCount++;
			continue;
		}
		Mat image13 = imread(savefile13);
		Mat image14 = imread(savefile14);
		Mat image15 = imread(savefile15);
		Mat image16 = imread(savefile16);

		Size size(image12.cols + image13.cols + image14.cols + image15.cols + image16.cols, image12.rows);
		Res.create(size, CV_MAKETYPE(image12.depth(), 3));
		Res = Scalar::all(0);
		Mat outImg0 = Res(Rect(0, 0, image12.cols, image12.rows));
		Mat outImg1 = Res(Rect(image12.cols, 0, image12.cols, image12.rows));
		Mat outImg2 = Res(Rect(image12.cols*2, 0, image12.cols, image12.rows));
		Mat outImg3 = Res(Rect(image12.cols*3, 0, image12.cols, image12.rows));
		Mat outImg4 = Res(Rect(image12.cols*4, 0, image12.cols, image12.rows));

		image12.copyTo(outImg0);
		image13.copyTo(outImg1);
		image14.copyTo(outImg2);
		image15.copyTo(outImg3);
		image16.copyTo(outImg4);

		/*namedWindow("joint", 0);
		imshow("joint", Res);
		imwrite(savefileout, Res);
		//waitKey(1);
		frameCount++;
		if (frameCount > 501)
			break;
	}
	return 0;
}
*/

char savefile[200];
char savefile1[200];

Mat mirror(Mat src)
{
	Mat result;
	result.create(src.size(), src.type());
	for (int i = 0; i < src.rows; i++)
	{
		for (int j = 0; j < src.cols; j++)
		{
			result.at<Vec3b>(i, j)[0] = src.at<Vec3b>(i, src.cols - 1 - j)[0];
			result.at<Vec3b>(i, j)[1] = src.at<Vec3b>(i, src.cols - 1 - j)[1];
			result.at<Vec3b>(i, j)[2] = src.at<Vec3b>(i, src.cols - 1 - j)[2];
		}
	}
	return result;
}
int main(void)
{
	
	int frameCount = 22531;
	while (true)
	{
		sprintf(savefile, "G:/yth/bodyImg/bodyImg/%06d.bmp", frameCount);
		sprintf(savefile1, "G:/yth/bodyImg/bodyImgOut/%06d.bmp", frameCount);


		Mat image = imread(savefile);
		/*if (!image12.cols)
		{
			frameCount++;
			continue;
		}*/
		Mat Res = mirror(image);
		

		/*namedWindow("Res", 0);
		imshow("Res", Res);*/
		imwrite(savefile1, Res);
		/*waitKey(1);*/
		frameCount++;
		}
		return 0;
}
