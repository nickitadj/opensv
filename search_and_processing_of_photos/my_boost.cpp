
#include "my_boost.h"


// Function for search  file in directory.

std::vector<fs::path> search_File(fs::path input_path)
{
	std::vector<fs::path> files_names;

	if (fs::is_directory(input_path)) // т.к. это дирректория то нужно зайти
	{
		fs::directory_iterator end_iter;
		for (fs::directory_iterator dir_itr(input_path);
			dir_itr != end_iter;
			++dir_itr)
		{
			try
			{
				if (fs::is_directory(*dir_itr))
				{
					std::vector<fs::path> files_name_local;

					fs::path next_path(dir_itr->path());

					files_name_local = search_File(next_path);

					for (int i = 0; i < files_name_local.size(); i++)
					{
						files_names.push_back(files_name_local[i]);
					}


				}
				else
				{

					files_names.push_back(dir_itr->path());
				}
			}
			catch (const std::exception & ex)
			{
				std::cout << dir_itr->path().filename() << " " << ex.what() << std::endl;
			}
		}
	}
	return files_names;
}