#include <stdio.h>
#include "cImgProcessing.hpp"
#include "cMask.hpp"

int main(int argc, char **argv)
{
	Mat grayImg; 
	cImgProcessing img1("Image.jpeg");
	img1.display("Color Picture");
	grayImg=img1.toGray();
	cMask gMask(25,25);
	gMask.gaussian(1);
	gMask.display("Gausian Matrix");
	
	gMask.convolution(grayImg);
	waitKey(0);
	return 0;
	
}
