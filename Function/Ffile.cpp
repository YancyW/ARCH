#include "Function/Ffile.h"


void CreateFolder(std::string folder_name){
	boost::filesystem::path dir(folder_name);
	if(boost::filesystem::create_directory(folder_name)){
		std::cerr<<"Directory Created:  " << folder_name << std::endl;
	} 
}

void CreateFileFolder(std::string file_name){
	boost::filesystem::path dir(file_name);
	boost::filesystem::path parent_path = dir.parent_path();
	if(boost::filesystem::create_directory(parent_path)){
		std::cerr<<"Directory Created:  " << parent_path << std::endl;
	} 
}
bool Is_File_Exist(const std::string& fname){
	struct stat buffer;
	return(stat(fname.c_str(),& buffer)==0);
}


void Is_File_Exist_And_Exit(const std::string& fname){
	if(!Is_File_Exist(fname)){ShowMessage(2,"Error: the file is not exist:",fname);exit(EXIT_FAILURE);}
}
