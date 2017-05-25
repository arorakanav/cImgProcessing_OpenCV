/*SU-function cImgProcessing
*Day02
*Kanav Arora & Ahmed Abid
*15thFebruary
*/

#include "cMask.hpp"
#include "math.h"

using namespace std;
using namespace cv;

cMask::cMask(int row,int col)
{
		gMat.create(row,col,CV_32F);
}
void cMask::gaussian(float sigma)
{	pi=3.14159265358979;
	scale=0.;
		for(int i=0;i<gMat.rows;i++)
		{
				for(int j=0;j<gMat.cols;j++)
				{
					y=i-gMat.rows/2;
					x=j-gMat.cols/2;
					gMat.at<float>(i,j)=1./(2.*pi*sigma*sigma)*exp(-((x*x+y*y)/(2.*sigma*sigma)));
					scale+=gMat.at<float>(i,j);
					
				}
		}

}
void cMask::display(String _title)
{	
		for(int i=0;i<gMat.rows;i++)
		{
				for(int j=0;j<gMat.cols;j++)
				{	
					cout.precision(3);
					cout<<fixed<<gMat.at<float>(i,j)<<"\t";
				}
				cout<<endl;
		}
		cout<<"Scale="<<scale<<endl;
}

void cMask::convolution(Mat image)
{
	double s=0.;
	convImg.create(image.rows,image.cols,CV_8UC1);
	for(int i=gMat.rows/2; i<image.rows-gMat.rows/2; ++i)              // rows
	{
    for(int j=gMat.cols/2; j < image.cols-gMat.cols/2; ++j)          // columns
    {
		s=0.;
        for(int m=0; m < gMat.rows; ++m)     // kernel rows
        {
          

            for(int n=0; n < gMat.cols; ++n) // kernel columns
            {
				s += image.at<uchar>(i+m-gMat.rows/2,j+n-gMat.cols/2) * gMat.at<float>(m,n);
            }
        }
                    convImg.at<uchar>(i,j)=s/scale;
    }
}
	namedWindow( "Display windowConv", WINDOW_AUTOSIZE );// Create a window for display.
    imshow( "Display windowConv",convImg );
}
