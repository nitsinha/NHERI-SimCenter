// Problem 2
#include<iostream>
#include<fstream>
#include<iomanip>
#include <string>
#include <vector>
using namespace std;

 //Print product array for a given array of size n excluding self

void getSpecialProducts(int InputVector[], int length)
{

    ofstream outfile;
/* Allocate  the SpecialProduct array */
	double *Specialprod = new double[sizeof(int)*length];
	Specialprod[0] = 1;

	for(int i = 1; i < length; i++)
	//multiplying all the index left of i-1 to input vector,
	//gives the product of elements left of i
     Specialprod[i] = InputVector[i - 1] * Specialprod[i - 1];

    // right will have product of all the element right of i
    int right = 1;
     for (int i=length-1; i>=0; i--)
     {
      Specialprod[i] = Specialprod[i]*right;
      right = InputVector[i]*right ;
     }
    //Printing Product

    outfile.open ("out.txt");
	for (int i = 0; i < length; i++)
		{cout << Specialprod[i] << " ";
         outfile << Specialprod[i]  << " ";
		}
    outfile.close();
	cout << endl;
	return;
}

int main(int argc, char** argv) 
{
  ifstream infile;
  int temp;
  int count = 0; // count must start at 0
  vector<int> array;
    if (argc < 2) {
	cout << "Please provide a file name" << endl;
    } else if (argc >2) {
	cout << "Please provide only one file name" << endl;
    } else {
    string filename = argv[1];
  infile.open(filename);
 //counting and pushing element in an array
   while(infile >> temp)
    {
     count++;
     array.push_back(temp);
     //cout << count << "    " << array[count-1] << "\n" ;
    }
    infile.close();
    int InputVector[count];
    for(  int i = 0; i < count; i++)
           InputVector[i] = array[i];
    // cout << i << "    " << InputVector[i] << "\n" ;

	cout << "The Special Product vector is: \n";
    getSpecialProducts(InputVector, count);
    }
}
