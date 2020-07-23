
#include "my_boost.h"
#include "my_opencv.h"
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>


namespace prtr = boost::property_tree;

int main()
{
	// Vector of all files in the given folder with subfolders
	std::vector<fs::path> files_name;
	
	std::cout << "Please, write path" << std::endl;

	// Enter a folder with images to be processed.
	std::string input_data = "AA";
	getline(std::cin, input_data);

	// Create folder class in boost
	fs::path full_path(input_data.c_str());

	// Check the folder for existence
	if (!fs::exists(full_path))
	{
		std::cout << "\nNot found: " << full_path.string() << std::endl;
		return 1;
	}

	// Search all files in folder and subfolders
	files_name = search_File(full_path);

	std::cout << "\n" << "Found files:" << std::endl;


	//Create varible for input image
	cv::Mat image;

	//List the paths of all found files
	for (int i = 0; i < files_name.size(); i++)
	{
		std::cout << files_name[i].string() << std::endl;
	}

	// Create ptree
	prtr::ptree pt;

	// The loop processes the files_name vector and stores the data in file.json

	for (int32_t i = 0; i < files_name.size(); i++)
	{
		// Create ptree
		prtr::ptree faces_param;
		//Input image
		image = cv::imread(files_name[i].string(), CV_LOAD_IMAGE_COLOR); //input image
		std::vector<cv::Rect> faces_v;
		// Detect faces
		faces_v = detectFace(image);
		std::cout << ("File: ") << files_name[i].filename() << (" have ") << faces_v.size() << (" faces.") << std::endl;

		// Create a ptree - coordinate
		prtr::ptree coordinate;
		for (int32_t j = 0; j < faces_v.size(); j++)
		{
			// Add the new nodes to the coordinate
			coordinate.put<int>("X", faces_v[0].x);
			coordinate.put<int>("Y", faces_v[0].y);
			coordinate.put<int>("Height", faces_v[0].height);
			coordinate.put<int>("Width", faces_v[0].width);
			faces_param.add_child("Face", coordinate);
		}
		// Add the new node to the pt
		pt.add_child((files_name[i].string()), faces_param);
		
	}
	
	prtr::json_parser::write_json("file.json", pt);
	std::cout << "file.json is made" << std::endl;

	cv::waitKey(0);
	return 0;
}









