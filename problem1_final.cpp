/*: Write a C or C++ program that accepts the name of a file as its first argument and
which prints to one line of a file the number of words, number of repeated words, number of
palindrome words in the set of repeated words, number of characters in the file, and number of
lines in the file. A word is defined as a string of characters that is delimited by spaces or periods,
a character is considered any byte in the file that is not a space or a newline character. A line is
defined as a set of strings that is delimited by newline characters.
*/
#include<iostream>
#include<fstream>
#include <cstring>
#include<iomanip>
#include <vector>

using namespace std;

int getPalindrome(char CurWord[], int len)
{
    int palindrome = 0;
    for(int k =0; k< len && len>1; k++)
    {
        if(CurWord[k] ==CurWord[len-k-1])
            if(k==len-1)
                palindrome++;
    }
    return palindrome;
}

int main(int argc, char** argv) 
{
    string filename;
    ifstream infile;
    ofstream outfile;
    //cout << "enter file name: ";
    //cin >> filename;
    if (argc < 2) {
	cout << "Please provide a file name" << endl;
    } else if (argc >2) {
	cout << "Please provide only one file name" << endl;
    } else {
    filename = argv[1];
    infile.open(filename);
    vector<string> word;
    string temp;
    int count= 0; // count must start at 0
    int s = 0;
    int repeated = 0;
    int numchar = 0;
    while(infile >> temp)    //counting and pushing element in an array
    {
        count++;
        word.push_back(temp);
        int len = word[count-1].size();  //word length
        numchar +=len;                  // total char length
	if (temp == "." || temp == "?"  || temp == "!" ) //number of lines
            s++;
    }
cout << "Total number of lines   " << s << "\n";
cout << "Total number of characters   " << numchar - s <<"\n";
cout << "Total number of words  " << count - s <<"\n";
int j = 1;
int Numpalindrome = 0;
int RepNumpalindrome = 0;
char CurWord[20], NxtWord[20], w[20]; // assuming max word length is 20

  //*******Looking for repeated words in the file ******
   for (int i=0; i<count; i++)
   {
        int len = word[i].size();
        strcpy(CurWord,word[i].c_str());
        Numpalindrome += getPalindrome(CurWord,len); // all Palindrome

        for(j=1; j<count && j< i; j++)
        {
            strcpy(NxtWord,word[j].c_str());
            if(strcmp(CurWord,NxtWord)==0)
                {repeated++ ;
                 RepNumpalindrome += getPalindrome(CurWord,len);
                }

        }
    }
    cout << "Total palindrome word   "<< Numpalindrome <<"\n";
    cout << "Total number of repeated words  " << (repeated-s) <<"\n";
    cout << "Total number of repeated palindrome words  " << RepNumpalindrome << endl ;
    outfile.open ("Program1.txt");
    outfile <<setw(5)<<(count - s)<<setw(5)<<repeated<<setw(5)<<RepNumpalindrome  ;
    outfile << setw(5) <<  (numchar - s)<< setw(5) << s ;

    outfile.close();
    }
return 0;

}
