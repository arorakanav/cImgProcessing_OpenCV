/*SU-function cImgProcessing
*Day01
*Kanav Arora & Ahmed Abid
*14thFebruary
*/

#include "cImgProcessing.hpp"

using namespace std;
using namespace cv;


cImgProcessing::cImgProcessing(String _filename)
{
	image=imread(_filename,CV_LOAD_IMAGE_COLOR);
	
}

cImgProcessing::cImgProcessing(Mat input_matrix)
{
	input_matrix.copyTo(image);
}

void cImgProcessing::display(String _title)
{
	namedWindow(_title,WINDOW_AUTOSIZE);// Create a window for display.
    imshow(_title,image);
}

uint32_t cImgProcessing::getWidth()
{
		return image.cols;
}

uint32_t cImgProcessing::getHeight()
{
		return image.rows;
}

uint32_t cImgProcessing::getPixelAvg(uint32_t row, uint32_t col)
{
		return ((image.at<cv::Vec3b>(row,col)[0]+image.at<cv::Vec3b>(row,col)[1]+image.at<cv::Vec3b>(row,col)[2])/3);
}

Mat cImgProcessing::toGray()
{
	grayImg.create(getHeight(),getWidth(),CV_8UC1);
		for(uint32_t i=0;i<getHeight();i++){
			for(uint32_t j=0;j<getWidth();j++){
				 grayImg.at<uchar>(i,j)=getPixelAvg(i,j);	
			}
		}

	namedWindow( "Display windowGray", WINDOW_AUTOSIZE );// Create a window for display.
    imshow( "Display windowGray", grayImg );
	return grayImg;
}
