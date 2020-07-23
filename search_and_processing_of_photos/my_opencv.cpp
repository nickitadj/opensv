
#include "my_opencv.h"

// Function for Face Detection 
std::vector<cv::Rect> detectFace(cv::Mat& img)
{
	// Load Face cascade (.xml file)
	cv::CascadeClassifier cascade;
	cascade.load("haarcascade_frontalface_alt.xml");

	// vector with coordinate of faces
	std::vector<cv::Rect> faces;

	//Converts an image to gray
	cv::Mat gray;
	cv::cvtColor(img, gray, cv::COLOR_BGR2GRAY);

	//Equalizes the histogram of a grayscale image.
	cv::equalizeHist(gray, gray);

	//Detects objects of different sizes in the input image
	cascade.detectMultiScale(gray, faces,
		1.1, 2, 0
		//|CASCADE_FIND_BIGGEST_OBJECT
		//|CASCADE_DO_ROUGH_SEARCH
		| cv::CASCADE_SCALE_IMAGE,
		cv::Size(30, 30));

	//return a vector of face coordinate and quantity of face 
	//printf("File is detect\n");
	//printf("Number of faces = %i\n", faces.size());
	return faces;
}
