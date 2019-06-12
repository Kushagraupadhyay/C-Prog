// all oprations of string function
#include<iostream>
#include<string.h>
using namespace std;
// give a strring as input all other inpputs are already present 
int main()
{
 string str="KushagraUpadhyay",str2,str5,str6;
 int k,l,m;
 getline(cin,str5); // can be inputted using cin>> also but cin terminates at blank space
 k=str.capacity(); // finds the size of the string
 l=str.size();    // finds length
 m=str.length(); // multiple methods for finding length of the string
 cout<<k<<" "<<l<<" "<<m<<endl;
 str6=str;
 str6.resize(8);        // will resize the steing to size 8
 cout<<str6<<endl;
 cout<<str6.capacity()<<" "<<str6.length()<<endl;
 str6.shrink_to_fit();  // as we shrinked the size of the string its capacity remains the same so we use shrink to fit function to resize
 cout<<str6.capacity()<<" "<<str6.length()<<endl;
 std::string::iterator it1;    //forward iterator
 std::string::reverse_iterator it2;    //reverse iterators
 for(it1=str.begin();it1<str.end();it1++)  // iterator uses pointer
 {
   cout<<*it1;   //begin function returns the iterator to the beginning of the string
 }               // end returns iterator at the end of the string
 cout<<endl;     // use r with begin and end to reverse their roles
 for(it2=str.rbegin();it2<str.rend();it2++)
{
  cout<<*it2;
}
char a[100];
str.copy(a,10,0);  //copy function works on an array
int i;
cout<<endl;
for(i=0;i<10;i++)
{
  printf("%c ",a[i]);   // printing using array
}
printf("\n");
string str4="Yoooooooooooooooo";
//cin>>str4;
str4.swap(str);   // swap function
cout<<str<<endl;
int x;
x=str.length();
printf("Printing using array\n");
for(i=0;i<x;i++)
{
  cout<<str.at(i); // using array to print the string
}
printf("\n");
cout<<str.front()<<" "<<str.back()<<endl; //Prints the front and back element of the string
str.append("HI");
cout<<str<<endl;
string str7="KushagraUpadhyay";
str.append(str7,7,8);  // from 7th place it will append 8 elements of the string
cout<<str<<endl;
cout<<str.substr(15,3)<<endl; // first argument is the postion and second is the numeber if characters you want to printf
str.erase(2,10); // same way of using as above functions
cout<<str<<endl;
str.erase(str.begin()+5,str.end()-2);
cout<<str<<endl;
str.replace(5,8,"Relacepart"); //replaces 8 characters from5 index
cout<<str<<endl;
str.clear();  // completely erases the string
cout<<str;

string last="This is the last one !!",find1="last",find2="z";
int found=last.find(find1);
cout<<found<<endl;  // will return the position of found element if founnd
found=last.find(find2);
cout<<found<<endl;  // returns -1 when not found also called as string::npos
last="agadjajhfvhhvjvljhbhvbvherkl";
found=-1;
char c='a';
// found=last.find(c,0,10)  // can also give the range for the search
while(1)
{
  found=last.find(c,found+1); // next iterating will search for for next occurence from position found+1
  if(found == -1)
  {
    break;
  }
  else
  {
    printf("%3d",found);
  }
}
 return 0;
}
