#include <opencv2/opencv.hpp>
#include <iostream>
#include "Common.hpp"


using namespace cv;
using namespace std;

int main(int argc, char *argv[])
{
	Cell2i cell_ = Cell2i(40,40);
	string windowname = "occupancyGridMap";
	namedWindow(windowname.c_str(), CV_WINDOW_KEEPRATIO);
    //Mat occupancyGirdMap = Mat(cell_.x, cell_.y, CV_8UC1, Scalar::all(255));	
	Mat occupancyGirdMap = imread("lena.jpg");
	for(int i = 0; i < 1; i++)
    {
		imshow(windowname.c_str(), occupancyGirdMap);
		waitKey(0);	
	}
	return 0;
}
