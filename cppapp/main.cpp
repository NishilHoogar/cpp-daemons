#include <iostream>
#include <string>
#include <conio.h>
#include <stdlib.h>

using namespace std;

void view()
{
	//to view items alailable 
}

void add()
{
	//add new items
}

void delete_item()
{
	//to delete items
}

void sort_bynm()
{
	//to sort all files or only main (items available) file by name all call view fn
}
void sort_byexp()
{
	//to sort all files or only main (items available) file by expiry and call view fn
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
		cout <<"\t\t\t4.Sort data according to Name \n";
		cout <<"\t\t\t8.Sort data according to Expiry \n";
		cout <<"\t\t\t6.Send expired medicines to bin file\n";
		cout <<"\t\t\t7.Sell item \n";
		cout <<"\t\t\t8.Calculate items sold \n";
		cout <<"\t\t\t9.Calculate expired items lost \n";
		cout <<"\t\t\t0.EXIT\n";
		cout<<"\t\t--------------------------------------------------\n";
		cout<<"Enter your choice: ";
		cin>>ch;
		switch(ch)
		{
			case 1: view(); break;
			case 2: add();break;
			case 3: delete_item();break;
			case 4: sort_bynm();break;
			case 5: sort_byexp(); break;
			case 6: bin(); break;
			case 7: sell(); break;
			case 8: profit(); break;
			case 9: loss(); break;
			default: cout<<"Enter 0 to exit\n";
			}
			system("pause");
			system("cls");
	}while(ch!=0);
	
}