#include "Class/file.h"

void CPath::Create_Folder(){
     ::Create_Folder(this->data_folder);
     ::Create_Folder(this->event_folder);
     ::Create_Folder(this->single_plot);
     ::Create_Folder(this->combine_plot);
}
