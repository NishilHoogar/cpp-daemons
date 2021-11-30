#include <iostream>
#include<fstream>
#include <string>
#include <conio.h>
#include <stdlib.h>

#define s 10

using namespace std;

void view()
{
	//to view items alailable 
	int i=0;
	char a[s];
	char exp[s];
	char qua[s],pri[s],srno[s];
	cout<<"elements present : \n";
	
	ifstream obj0("srno.txt");
	ifstream obj("main.txt");
	ifstream obj1("quantity.txt");
	ifstream obj2("price.txt");
	ifstream obj3("expiry.txt");
	
	while(!obj3.eof())
	{
		
	obj0.getline(srno,s);
	fflush(stdin);
	cout<<srno<<'\t';
	
	obj.getline(a,s);
	fflush(stdin);
	cout<<a<<'\t';
	
	
	obj1.getline(qua,s);
	fflush(stdin);
	cout<<qua<<'\t';
	
	
	obj2.getline(pri,s);
	fflush(stdin);
	cout<<pri<<'\t';
	
	
	obj3.getline(exp,s);
	fflush(stdin);
	cout<<exp<<endl;
	
	
	}
	obj0.close();
	obj.close();
	obj1.close();
	obj2.close();
	obj3.close();
	cout<<"display ended \n";
	
}

void add()
{
	//add new items
	
	string a,exp;
	int qua,pri,srno;
	
	fflush(stdin);
	
	cout<<"enter the serial number :\n";
	cin>>srno;
	fflush(stdin);
	cout<<"enter the name :\n";
	getline(cin,a);
	fflush(stdin);
	cout<<"enter the quantity :\n";
	cin>>qua;
	fflush(stdin);
	cout<<"enter the price :\n";
	cin>>pri;
	fflush(stdin);
	cout<<"enter the expiry date :\n";
	getline(cin,exp);
	fflush(stdin);
	
	ofstream myfile0("srno.txt",ios::app);
	myfile0<<srno;
	myfile0<<"\n";
	myfile0.close();
	
	ofstream myfile("main.txt",ios::app);
	//myfile.open("main.dat");
	myfile<<a;
	myfile<<"\n";
	myfile.close();
	
	ofstream myfile1("quantity.txt",ios::app);
	myfile1<<qua;
	myfile1<<"\n";
	myfile1.close();
	
	ofstream myfile2("price.txt",ios::app);
	myfile2<<pri;
	myfile2<<"\n";
	myfile2.close();
	
	ofstream myfile3("expiry.txt",ios::app);
	myfile3<<exp;
	
	myfile3<<"\n";
	myfile3.close();
	cout<<"data added\n";
	
	
}

void delete_item()
{
	//to delete items
}

void bin() 
{
	//to send expire files to bin file 
}
void sell()
{
	//to sell items, send data from availabe to sold file calculate total and call receipt function   
}
void receit()
{
	//display receipt and total 
}
void profit()
{
	//display sold items and calculate price of all items sold
}
void loss()
{
	//display all expired items and  calculate price of all items lost 
}
int main()
{
	int ch;
	do{
		cout << "\t\t\t\tPharamacy System\t\t\t\t\n\n";
		cout<<"\t\t==================================================\n\n";
		cout<<"\t\t--------------------------------------------------\n";
		cout <<"\t\t\t1.View stored data \n";
		cout <<"\t\t\t2.Add new item \n";
		cout <<"\t\t\t3.Delete an item \n";
		cout <<"\t\t\t4.Send expired medicines to bin file\n";
		cout <<"\t\t\t5.Sell item \n";
		cout <<"\t\t\t6.Calculate items sold \n";
		cout <<"\t\t\t7.Calculate expired items lost \n";
		cout <<"\t\t\t0.EXIT\n";
		cout<<"\t\t--------------------------------------------------\n";
		cout<<"Enter your choice: ";
		cin>>ch;
		switch(ch)
		{
			case 1: view(); break;
			case 2: add();break;
			case 3: delete_item();break;
			case 4: bin(); break;
			case 5: sell(); break;
			case 6: profit(); break;
			case 7: loss(); break;
			default: cout<<"Enter 0 to exit\n";
			}
			system("pause");
			system("cls");
	}while(ch!=0);
	
}