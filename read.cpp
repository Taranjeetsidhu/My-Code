#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int main()
{
	float p1,p2,r,p3,p4;
	cout<<"\nEnter center coordinates\n";
	cin>>p1>>p2;
	cout<<"\nEnter radius\n";
	cin>>r;
	cout<<"\nEnter start and end angle\n";
	cin>>p3>>p4;

    //declare two files for reading
    
    ifstream read1( "header.txt");
    ofstream write1( "ar.txt");

	write1<<"ARC\n5\n46\n100\nAcDbEntity\n8\n0\n6\nByLayer\n62\n256\n370\n-1\n100\nAcDbCircle\n10\n"<<p1<<"\n20\n"<<p2<<"\n40\n"<<r<<"\n100\nAcDbArc\n50\n"<<p3<<"\n51\n"<<p4<<"\n0";
	write1.close();
    
	ifstream read2("ar.txt");
    ifstream read3("footer.txt");
    
    //declare file for writing
    ofstream write ("Arc.dxf");
    
    string line1;
    string line2;
    string line3;
    
    while ( getline ( read1, line1, '\n' ) )
    {
      write << line1 << endl;
    }

    while ( getline ( read2, line2, '\n' ) )
    {
      write << line2 << endl;
    }
    
  while ( getline ( read3, line3, '\n' ) )
    {
      write << line3 << endl;
    }
cout<<"All three files are written in output file"<<endl;

    read1.close();
    read2.close();
    read3.close();
    write.close();
    
}
