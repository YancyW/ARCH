#include "Class/file.h"

void CPath::Create_Folder(){
	CreateFolder(this->output_file);
	CreateFileFolder(this->event_file);
	CreateFolder(this->single_plot);
	CreateFolder(this->combine_plot);
}
