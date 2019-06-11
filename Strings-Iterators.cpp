
#include<iostream>
#include<string.h>
using namespace std;
int main()
{
 string str="KushagraUpadhyay",str2,str5;
 int k;
 getline(cin,str5);
 k=str.capacity();     // finds the size of the string
 cout<<k<<endl;
 std::string::iterator it1;    //forward iterator
 std::string::reverse_iterator it2;    //reverse iterators
 for(it1=str.begin();it1<str.end();it1++)
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
  printf("%c \n",a[i]);
}
string str4;
str.swap(str4);
cout<<str4<<endl;
 return 0;
}
// int i;
// string str1,str2,str3;
// getline(cin,str1);
// getline(cin,str2);
// cout<<str1.size()<<"\n";
// //str1.resize(4);
// str1.shrink_to_fit();
// cout<<str1.capacity();
