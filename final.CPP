/*
Username      : 123
Password      : 123
Database File : bill.dat
*/

#include <iostream.h>
#include <dos.h>
#include <conio.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 100
#define MAX 100
#define cls clrscr

struct bills
{
   char code[5];
   char name[35];
   int present;
   int previous;
   float bill;
}bills_var[SIZE];

void save(void), load(void), list(void), bo(int x1, int y1,int x2,int y2);
void lin(int x1, int y1, int x2);
void lin2(int x1, int y1, int x2);
void ver(int x1, int y1, int y2);
void bo2(int x1, int y1, int x2, int y2);
int ctr, x=7, y=9;

main()
{
  // Variable Declarations

  char name1[10][35],ans;
  char name11[35], code11[5];
  char code1[10][5];
  float bill1,grandtot=0;
  int present1, previous1;
  int rec, kwh;


  float gen, dist, vat, vdist, voth, oth, uni;

  register int i=0;
  int choice=0,num=0,s=0,test,guard=0;
  int j, k;
  char sik[10];
  char pass[5], user[6];
// start of the splash screen
  clrscr();
  textcolor(15);
  gotoxy(30,7);cout << "Electricity Billing System";
  bo(10,5,75,23);
  lin(10,18,75);
  gotoxy(38,18);cout << " LOADING ";
  lin(10,9,75);
  for(j=1;j<=3;j++)
  {
    if(j==1)
    {gotoxy(32,21);cout << "Checking Files...";}
    if(j==2)
    {gotoxy(32,21);cout << "Checking Folders...";}
    if(j==3)
    {gotoxy(32,21);cout << "Loading System...";}
    for(k=12;k<74;k++)
    {
      gotoxy(k,20);cout<<"º";
    }
    for(k=12;k<74;k++)
    {
      gotoxy(k,20);putch(219);
      delay(400);
    }

  }
/*end of the splash*/
/*start of username & password*/
  do
  {
    cls();
    gotoxy(30,7);cout<<"Electricity Billing System";
    bo(20,5,65,23);
    lin(20,9,65);
    bo(30,13,55,16);
    gotoxy(32,14);cout<<"Username: ______";
    gotoxy(32,15);cout<<"Password: _____";
    lin(20,19,65);
    gotoxy(35,19);cout<<" Notification ";
    gotoxy(42,14);gets(user);
    gotoxy(42,15);gets(pass);
    gotoxy(42,15);cout<<"*****";
    if(strcmp(user,"123")!=0 && strcmp(pass,"123")!=0)
    {gotoxy(22,21);cout<<"The username and password did not match!";getch();}
  }while(strcmp(user,"123")!=0 && strcmp(pass,"123")!=0);
  gotoxy(35,20);cout <<"Loading to Menu...";
  for(k=22;k<64;k++)
  {
    gotoxy(k,21);cout<<"º";
  }
  for(k=22;k<64;k++)
  {
    gotoxy(k,21);putch(219);
    delay(300);
  }
/*end of username & password*/
  ctr=1;
  load();
  guard=ctr;
  do
  {
    clrscr();
    test=0;
    textcolor(15);
    bo(25,3,55,5);
    bo(20,6,60,24);
    gotoxy(27,4);cout <<"Electricity Billing System";
    gotoxy(34,6);
    cout<<" MAIN MENU ";
    gotoxy(22,8);
    cout<<"[1] Add Record ";
    gotoxy(22,10);
    cout<<"[2] Modify Record ";
    gotoxy(22,12);
    cout<<"[3] Delete Record";
    gotoxy(22,14);
    cout <<"[4] View One Record";
    gotoxy(22,16);
    cout <<"[5] View All Records";
    gotoxy(22,18);cout<<"[6] Exit Program";
    lin(20,20,60);
    gotoxy(22,22);
    cout <<"Choose an option(1,2,3,4,5,6): ";
    scanf("%d",&choice);
    switch(choice)
    {
	case 1:
	{
	  num=i;
	  guard++;
	  clrscr();
	  bo(25,3,55,5);
	  bo(18,6,62,24);
	  bo2(20,7,60,23);
	  lin2(20,19,60);
	  gotoxy(26,4);cout<<"Electricity Billing System";
	  gotoxy(22,7);cout<<" Add Record ";

	  gotoxy(23,9);cout<<"Code:";
	  gotoxy(23,11);cout<<"Customer's Name:";
	  gotoxy(23,13);cout<<"Present Reading:";
	  gotoxy(23,15);cout<<"Previous Reading:";
	  gotoxy(37,19);cout<<" NOTE ";
	  gotoxy(25,21);cout<<"Use underscore for spaces...";
	  gotoxy(29,9);scanf("%s",&code11);
	  strcpy(code1[i],code11);
	  strcpy(bills_var[i].code,code1[i]);

	  gotoxy(40,11); scanf("%s",&name11);
	  strcpy(name1[i],name11);
	  strcpy(bills_var[i].name,name1[i]);

	  gotoxy(40,13);scanf("%d",&present1);
	  bills_var[i].present=present1;

	  gotoxy(41,15);scanf("%d",&previous1);
	  bills_var[i].previous=previous1;

	  gotoxy(25,21);cout <<"Press any key to continue...";
	  getch();
	  /* formula for the billing system */
	  kwh=present1-previous1;
	  gen=6.4545*kwh;
	  dist=(1.857*kwh)+5;
	  vat=0.5198*kwh;
	  oth=-0.4441*kwh;
	  vdist=dist*.12;
	  voth=oth*.12;
	  uni=0.0398*kwh;
	  bill1=gen+dist+vat+oth+vdist+voth+uni;

	  bills_var[i].bill=bill1;
	  i=i+1;
	  break;
	}
	case 2:
	{
	  test=0;
	  clrscr();
	  bo(25,3,55,5);   /*box 4 system name*/
	  bo(5,6,75,24);   /*2 lined box*/
	  bo2(7,7,73,23);  /*1 lined box*/
	  lin2(7,21,73);
	  bo2(32,7,46,9); /*box 4 code*/
	  ver(39,9,21);
	  gotoxy(34,8);cout<<"CODE: ";
	  gotoxy(26,4);cout<<"Electricty Billing System";
	  gotoxy(33,6);cout<<" Edit Record ";
	  gotoxy(15,7);cout<<" CURRENT ";
	  gotoxy(55,7);cout<<" UPDATED ";
	  gotoxy(25,5);gotoxy(40,8);scanf("%s",&sik);
	  gotoxy(18,22);cout<<"NOTE: You may use underscore for spacing...";
	  for(s=0;s<=num || s<=ctr;s++)
	  {
	    if(!strcmp(bills_var[s].code,sik))
	    {
		test=1;

		gotoxy(9,11);
		printf("Customer's Name: ");puts(bills_var[s].name);
		gotoxy(9,13);
		printf("Present Reading: %d",bills_var[s].present);
		gotoxy(9,15);
		printf("Previous Reading: %d",bills_var[s].previous);
		gotoxy(9,17);
		printf("Total Bill: %.2f",bills_var[s].bill);
		getch();

		gotoxy(41,11); cout <<"Customer's Name: ";
		gotoxy(41,13); cout <<"Present Reading: ";
		gotoxy(41,15); cout <<"Previous Reading: ";
		gotoxy(41,17); cout <<"Total Bill: ";

		gotoxy(58,11);scanf("%s",&name1[s]);
		strcpy(bills_var[s].name,name1[s]);

		gotoxy(58,13);scanf("%d",&present1);
		bills_var[s].present=present1;

		gotoxy(59,15);scanf("%d",&previous1);
		bills_var[s].previous=previous1;

		/* formula for the billing system */
		kwh=present1-previous1;
		gen=6.4545*kwh;
		dist=(1.857*kwh)+5;
		vat=0.5198*kwh;
		oth=-0.4441*kwh;
		vdist=dist*.12;
		voth=oth*.12;
		uni=0.0398*kwh;
		bill1=gen+dist+vat+oth+vdist+voth+uni;

		bills_var[s].bill=bill1;

		gotoxy(41,17); printf("Total Bill: %.2f",bills_var[s].bill);
		getch();
		break;
	    }
	  }
	  if(test!=1)
	  {
	    gotoxy(18,22);printf("NOTE: The customer code %s is not in the list...",sik);
	    getch();
	  }
	  break;
	}
	case 3:
	{
	  clrscr();
	  bo(25,3,55,5);
	  bo(18,6,62,24);
	  bo2(20,7,60,23);
	  lin2(20,19,60);
	  gotoxy(26,4); cout <<"Electricity Billing System";
	  gotoxy(22,7); cout <<"Delete Record ";
	  gotoxy(23,21);cout <<"Enter Customer's Code: ";
	  scanf("%s",&sik);
	  for(s=0;s<=i || s<=ctr;s++)
	  {
	    if(!strcmp(bills_var[s].code,sik))
	    {
		test=1;

		gotoxy(23,9);
		printf("Customer's Name: ");puts(bills_var[s].name);
		gotoxy(23,11);
		printf("Present Reading: %d",bills_var[s].present);
		gotoxy(23,13);
		printf("Previous Reading: %d",bills_var[s].previous);
		gotoxy(23,15);
		printf("Total Bill: %.2f",bills_var[s].bill);
		gotoxy(23,21);
		cout <<"Delete this record?(y/n): ";
		scanf("%s",&ans);

		if(ans=='n')
		{
			 break;
		}
		if(ans=='y')
		{
		  for(s=0;s<=num||s<=ctr;s++)
		  {
		    if(!strcmp(bills_var[s].code,sik))
		    {
		      test=1;

		      bills_var[s].code[0]='\0';
		      bills_var[s].name[0]='\0';
		      bills_var[s].present='\0';
		      bills_var[s].previous='\0';
		      bills_var[s].bill='\0';
		      guard=guard-1;
		    }
		  }

		  gotoxy(23,21);
		  cout << "NOTE: Deleted!!!!              ";
		  getch();
		  break;
		}
	    }
	  }
	  if(test!=1 && ans=='y');
	  {
	    gotoxy(21,21);printf("The customer code %s is not in the list.",sik);
	    getch();
	  }
	break;
	}
	case 4:
	{
	  test=0;
	  clrscr();
	  bo(25,3,55,5);
	  bo(18,6,62,24);
	  bo2(20,7,60,23);
	  lin2(20,19,60);
	  gotoxy(26,4);cout <<"Electricity Billing System";
	  gotoxy(22,7);cout <<" View Record ";
	  gotoxy(23,21);cout<<"Customer Code: ";
	  scanf("%s",&sik);

	  for(s=0;s<=num || s<=ctr;s++)
	  {
	    if(!strcmp(bills_var[s].code,sik))
	    {
		test=1;
		bo2(34,8,47,10);
		gotoxy(36,9);printf("CODE: %s",bills_var[s].code);
		gotoxy(23,11);
		printf("Customer's Name:%s",bills_var[s].name);
		gotoxy(23,13);
		printf("Present Reading: %d",bills_var[s].present);
		gotoxy(23,15);
		printf("Previous Reading: %d",bills_var[s].previous);
		gotoxy(23,17);
		printf("Total Bill: %.2f",bills_var[s].bill);
		gotoxy(33,19);
		cout <<" Notification ";
		gotoxy(23,21);
		cout <<"Press any key to continue...";
		getch();
		break;
	    }
	  }
	  if(test!=1)
	  {
	    printf("\nThe customer code %s is not in the list.",sik);
	    getch();
	  }
	  break;
	}
	case 5:
	{
	  grandtot=0;
	  if(guard!=0)
	  {
	    y=9;
	    clrscr();
	    bo(25,1,55,3);
	    bo(2,4,78,24);
	    bo2(4,5,77,23);
	    gotoxy(26,2);cout <<"Electricity Billing System";
	    gotoxy(7,5);cout <<" View Records ";
	    gotoxy(7,7);
	    cout <<"Code";
	    gotoxy(15,7);
	    cout <<"Name";
	    gotoxy(35,7);
	    cout <<"Present";
	    gotoxy(48,7);
	    cout <<"Previous";
	    gotoxy(64,7);
	    cout <<"Total Bill";
	    for(i=0;i<=num||i<=ctr;i++)
	    {
		if(bills_var[i].code[0]!='\0')
		{
		  gotoxy(x,y);
		  printf("%s",bills_var[i].code);
		  gotoxy(x+8,y);
		  printf("%s",bills_var[i].name);
		  gotoxy(x+28,y);
		  printf("%d",bills_var[i].present);
		  gotoxy(x+41,y);
		  printf("%d",bills_var[i].previous);
		  gotoxy(x+57,y);
		  printf("%.2f",bills_var[i].bill);
		  y=y+1;

		  /*compute grand total amount*/
		  grandtot=grandtot+bills_var[i].bill;
		}
	    }
	    /*display grand total amount*/
	    gotoxy(55,20);
	    printf("Grand Total: %.2f",grandtot);
	    getch();
	    break;
	  }
	  else
	  {
	    clrscr();
	    gotoxy(25,5);
	    cout << "No Record in the Database!";
	    gotoxy(25,7);
	    cout << "Press Any Key....";
	    getch();
	    break;
	  }
	}
	case 6:
	{
	  save();
	  cls();
    gotoxy(31,7);cout <<"Electricity Billing System";
    bo(20,5,65,23);
    lin(20,9,65);
    bo(30,13,55,16);

   gotoxy(38,14);
   cout <<"Created By";
   gotoxy(33,15);
   cout << "Ms. Dylene Cultura";

  gotoxy(35,20);cout <<"EXITING SYSTEM";
  for(k=22;k<64;k++)
  {
    gotoxy(k,21);cout <<"º";
  }
  for(k=22;k<64;k++)
  {
    gotoxy(k,21);putch(219);
    delay(200);
  }
	  break;
	}
	default:
	{
	  clrscr();
	  gotoxy(25,5);
	  printf("Invalid Entry!");
	  getche();
	  break;
	}
    }
  }while(choice!=6);
}
void list(void)
{
  register int t;

  for(t=0; t<SIZE; t++)
  {
    *bills_var[t].code ='\0';
  }
}
void load(void)
{
  FILE *fp;

  register int i;

  if((fp=fopen("bill.dat","rb"))==NULL)
  {
    cout <<"Cannot Open File\n";
    getche();
    return;
  }

  list();

  for(i=0;i<SIZE;i++)
  {
     if(fread(&bills_var[i],sizeof(struct bills),1,fp)!=1)
     {
       if(feof(fp))
       {
	 fclose(fp);
	 return;
       }
       printf("File read error\n");
     }
     ctr=ctr+1;
  }
}
void save(void)
{
  FILE *fp;

  register int i;

  if((fp=fopen("bill.dat","wb"))==NULL)
  {
    printf("cannot open file\n");
    getche();
    return;
  }
  for(i=0;i<SIZE;i++)
  {
    if(*bills_var[i].code)
    {
      if(fwrite(&bills_var[i],sizeof(struct bills),1,fp)!=1)
      {
	cout <<"file write error\n";
	getche();
      }
    }
  }
  fclose(fp);
}
void bo(int x1, int y1, int x2, int y2)
{
	int x;
	gotoxy(x1,y1);putch(201);gotoxy(x2,y1);putch(187);
	gotoxy(x1,y2);putch(200);gotoxy(x2,y2);putch(188);
	for(x=x1+1;x<x2;x++) {gotoxy(x,y1);putch(205);gotoxy(x,y2);putch(205);}
	for(x=y1+1;x<y2;x++) {gotoxy(x1,x);putch(186);gotoxy(x2,x);putch(186);}
/*
  196 Ä
  217 Ù
  218 Ú
  191 ¿
  192 À
  179 ³
*/
}
void bo2(int x1, int y1, int x2, int y2)
{
  int x;
  gotoxy(x1,y1);putch(218);gotoxy(x2,y1);putch(191);
  gotoxy(x1,y2);putch(192);gotoxy(x2,y2);putch(217);
  for(x=x1+1;x<x2;x++) {gotoxy(x,y1);putch(196);gotoxy(x,y2);putch(196);}
  for(x=y1+1;x<y2;x++) {gotoxy(x1,x);putch(179);gotoxy(x2,x);putch(179);}
}
void lin(int x1,int y1,int x2)
{
  int k;
  gotoxy(x1,y1);putch(204);gotoxy(x2,y1);putch(185);
  for(k=x1+1;k<x2;k++) {gotoxy(k,y1);putch(205);}
}
void lin2(int x1, int y1, int x2)
{
  int k;
  /*
    180 ´
    195 Ã
  */
  gotoxy(x1,y1);putch(195);gotoxy(x2,y1);putch(180);
  for(k=x1+1;k<x2;k++) {gotoxy(k,y1);putch(196);}
}
void ver(int x1, int y1, int y2)
{
  int k;
  /*
   194 Â
   179 ³
   193 Á
   */
  gotoxy(x1,y1);putch(194);gotoxy(x1,y2);putch(193);
  for(k=y1+1;k<y2;k++) {gotoxy(x1,k);putch(179);}
}
/* End of Code */
