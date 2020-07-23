//#include "boost/filesystem.hpp"
#include "boost/filesystem/operations.hpp"
#include "boost/filesystem/path.hpp"
#include <iostream>

namespace fs = boost::filesystem;

/**
  * @brief  Search  file in directory.
  * @note   This function is detect fase on image.
  * @param  img: image on which to find faces.
  * @reternval vector of tipe cv::Rect
  */
std::vector<fs::path> search_File(fs::path input_path); 