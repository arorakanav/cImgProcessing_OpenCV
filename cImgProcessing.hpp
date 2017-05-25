/*SU-function cImgProcessing
*Day01
*Kanav Arora & Ahmed Abid
*14thFebruary
*/

#ifndef CIMGPROCESSING_HPP
#define CIMGPROCESSING_HPP

//system include files
#include <opencv2/opencv.hpp>
#include <opencv/cv.h>
#include <iostream>
#include <string>

#include "cImgProcessing.hpp"

using namespace std;
using namespace cv;

class cImgProcessing
{
	private:
		Mat image;
		Mat grayImg;
			
	public:
		cImgProcessing(String _filename);
		cImgProcessing (Mat input_matrix);
		void display(String _title);
		uint32_t getWidth();
		uint32_t getHeight();
		uint8_t getPixelSize();
		Mat toGray();
		void save(String _filename);
		uint32_t getPixelAvg(uint32_t,uint32_t);
	
};

#endif
