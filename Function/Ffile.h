#pragma once
#ifndef FFILE_H
#define FFILE_H
#include <string> 
#include <sys/stat.h> 
#include <iostream>
#include "TSystem.h"
#include "boost/filesystem.hpp"
#include "Lib/MessageFormat.h"



void CreateFolder(std::string folder_name);
void CreateFileFolder(std::string file_name);
bool Is_File_Exist(const std::string& fname);
void Is_File_Exist_And_Exit(const std::string& fname);
#endif
