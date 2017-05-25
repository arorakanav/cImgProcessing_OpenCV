/*SU-function cImgProcessing
*Day02
*Kanav Arora & Ahmed Abid
*15thFebruary
*/

#ifndef CMASK_HPP
#define CMASK_HPP

//system include files
#include <opencv2/opencv.hpp>
#include <opencv/cv.h>
#include <iostream>
#include <string>

// user include files
#include "cMask.hpp"

using namespace std;
using namespace cv;

class cMask{
	
private:
	int x;
	int y;
	double pi; 
	Mat gMat;
	Mat convImg;
	double scale;
	public:
		cMask(int row,int col);
		void gaussian(float sigma);
		void display(String _title);
		void convolution(Mat Img);
};
#endif
