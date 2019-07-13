#include <iostream> 
#include <cstdlib>
#include <string>
#include <fstream>
#include <vector>
using namespace std; 
  
int main(int argc, char** argv) 
{ 
  
    	
	vector <int> final_data;
	ofstream outfile;	
	outfile.open ("final.txt");
	for (int i = 1; i < argc; ++i) {
   		string str1 = "./problem1.out ";
		string str2 = argv[i];
		string final_arg = str1 + str2;	
		//std::system("./problem1.out " + to_string(argv[i]) );
		std::system(final_arg.c_str());
		ifstream infile;
		infile.open("Program1.txt");
		string data;
		while(infile >> data) {
			final_data.push_back(stoi(data));
			outfile <<setw(5)<<data;
		}
			
		infile.close();
	
	} 
   	outfile.close()	;
	string str1 = "./problem2.out ";
	string str2 = "final.txt";
	string final_arg = str1 + str2;
	std::system(final_arg.c_str());

	  
    return 0; 
} 




