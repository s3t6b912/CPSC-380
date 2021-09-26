#include <stdio.h>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>

using namespace std;

void initialize(FILE* file){
	string records[100] = {};
	for(int i=0; i<100; i++){
		records[i] = "RECORDS-" + to_string(i);
		cout << records[i];
	}
	for(int i=0; i<100; i++){
		fwrite(records[i].c_str(), sizeof(records[i].c_str()), 1, file);
	}
	//fwrite(records, sizeof(records), 1, file);
}

int main(int argc, char *argv[]){
	FILE* file = fopen("records.dat", "wb");
	initialize(file);
	std::istream is(std::cin.rdbuf());
	std::ostream os(std::cout.rdbuf());
	char index1[16];
	is.getline(index1, 16);
	char index2[16];
	is.getline(index2, 16);
	int i1;
	int i2;
	try{
		i1 = stoi(index1);
	} catch(exception &err){
		os.write("Invalid input", 256);
		return 1;
	}
	try{
		i2 = stoi(index2);
	} catch(exception &err){
		os.write("Invalid input", 256);
		return 1;
	}
	if(i1>99){
		os.write("Invalid index", 256);
		return 1;
	}
	
	//fseek(file , 7 , i1);
	//fputs(index2, file);
	char output[5000];
	fgets(output, 5000, file);
	os.write(output, 5000);
	fclose(file);
	return 0;
}
