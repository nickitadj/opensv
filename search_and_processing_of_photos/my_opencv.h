#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <stdio.h>

/**
  * @brief  Face Detection.
  * @note   This function is detect fase on image.
  * @param  img: image on which to find faces.
  * @reternval vector of tipe cv::Rect
  */
std::vector<cv::Rect> detectFace(cv::Mat& img); 
