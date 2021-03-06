#include "Fbasic.h"
void to_lower(std::string &str){
	std::transform(str.begin(),str.end(),str.begin(),::tolower);
}


std::string Int_to_String(int i){
	std::string fnum;
	std::stringstream num;

	num << i;
	num >> fnum;
	return(fnum);
}

std::string Int_to_String_descrip(int i){
	std::string fnum;
	std::string fdescrip[6]= {"leading","second","third","fourth","fifth","sixth"};

	fnum = fdescrip[i];
	return(fnum);
}

std::string NameHistogram(std::string signal_name, std::string class_name, std::string observable_name, int i){

	std::string Final_Name;
	std::string fnum;

	fnum=std::to_string(i);
	Final_Name=signal_name+"_"+class_name+"_"+observable_name+"_"+fnum;

	return(Final_Name);
}

std::string NameDescrip(std::string class_name, std::string observable_name, int i){

	std::string Final_Name;
	std::string desnum;

	desnum=Int_to_String_descrip(i);
	Final_Name=desnum+"_"+class_name+"_"+observable_name;

	return(Final_Name);
}

std::string GetUnit(std::string observe_name){
	std::string unit_name;
	if(observe_name == "pt"){
		unit_name="GeV";
	}
	else if(observe_name == "mass"){
		unit_name="";
	}
	else{unit_name="";}

	return(unit_name);
}



void CountNumber(int variable, int tot_num, int slot,std::string  Message){
	if(tot_num>slot*100){
		if(variable%slot == 0 && variable!=0){
			ShowMessage(2,Message,variable);
		}
	}
	else if(tot_num<=slot*100 && tot_num >100){
		if(variable%(tot_num/100) == 0 && variable!=0){
			ShowMessage(2,Message,variable/(tot_num/100),"%");
		}
	}
	else{
		ShowMessage(2,Message,variable/(tot_num),"%");		
	}

}
