//COMPUTER PROJECT PHONE OS 
#include<fstream.h> 
#include<conio.h> 
#include<stdio.h> 
#include<dos.h> 
#include<shamin.h> 
#include<string.h> #include<ctype.h>
 void homescreen(void); 


void game(void); 
void tictactoe(void); void flappybd(void); void contact(void);
 void phone(void); 
void printbox(void); void contactview(void); void contactdel(void); void compscreen(); 
void word(); 
void excel(); 
void filesave(char);
 void fileopen(); 
void typesheet();
 void sheetopen(); 
 
void sheetopen(){ 
clrscr(); cout<<"Enter the name of the sheet\n --> "; char filename[20]; 
 	gets(filename);  	ifstream inf(filename);  	int loop;  	char str[2500];  	for(loop = 0; loop<2500; loop++){ 
 	 	str[loop]=' ';  	 	inf>>str[loop]; 
 	} 
 	decrypt(str);  	int i=0;  	int gotox=1,gotoy=3;  	gotoxy(gotox,gotoy);  	while(str[i]!='~'&&i<=2499){  	 	if(str[i]=='\t'){ 
 	 	 	gotox+=8; 
 	 	 	

gotoxy(gotox,gotoy); 
 	 	} 
 	 	else if(str[i]=='`'){ 
 	 	 	gotoy+=1;  	 	 	gotox=1; 
 	 	 	gotoxy(gotox,gotoy); 
 	 	} 
 	 	else cout<<str[i]; 
	 	i++; 
	 	} 
inf.close(); getch(); compscreen(); } void filesave(char str[]){ 
 	encrypt(str);  	cout<<"Enter the file name with extension";  	char filename[20];  	gets(filename);  	ofstream outf(filename);  	for(int loop = 0; loop<2500; loop++){ 
 	 	outf<<str[loop]; 
 	} 
 	outf.close();  	cout<<"File saved";  	getch();  	compscreen(); 
} void typesheet(){ 
 	clrscr();  	int gotox = 1,gotoy=3;  	char str[2500];int i=0UL;  	for(int x=0;x<=2499;x++){ 
 	 	
str[x]=' '; 
 	 	} 
 	cout<<"Enter your spreadsheet. tab for next cell. ` for next line . Enter ~ to quit  \n"; 
 	gotoxy(gotox,gotoy);  	while(str[i-1]!='~'&&i<=2499){ 
 	 	str[i]=getche(); 
	 	if(str[i]=='\t'){ 
	 	 	gotox+=8; 
	 	gotoxy(gotox,gotoy); 
} if(str[i]=='`'){  	gotoy+=1;  	gotox=1; 
	 	gotoxy(gotox,gotoy); 
 	 	} 
 	 	i++; 
 	 	} 
 	cout<<"\n\n\tWould you like to save? (Y/N)\n\t\t--> "; 
 	char inp;  	cin>>inp;  	if(inp=='Y')  	 	filesave(str);  	else  	 	compscreen(); 
} void fileopen(){ 
 	clrscr(); 
 	cout<<"Enter the name of the file \n --> ";  	char filename[20];  	gets(filename);  	ifstream inf(filename);  	int loop;  	char tempvar[2500];  	for(loop = 0; loop<2500; loop++){ 
 	 	
tempvar[loop]=' ';  	 	inf>>tempvar[loop]; 
 	} 
decrypt(tempvar); for(loop = 0; loop<2500; loop++){ if(tempvar[loop]=='*') 
	 	break; 
cout<<tempvar[loop]; 
} inf.close(); getch(); 
 	compscreen(); 
 	} 
void excel(){ 
 	labelnew1:  	clrscr();  	gotoxy(27,5);  	cout<<"Create new / Open Old  ";  	int x,y;  	getcor(x,y);  	if(x>=210&&x<=292&&y>=32&&y<=38)  	 	typesheet(); 
 	else if(x>=310&&x<=390&&y>=32&&y<=38) 
 	 	sheetopen(); 
 	else goto labelnew1; 
}; void typefile(){ 
 clrscr();  char str[2500];int i=0;  for(int x=0;x<=2499;x++){ 
 	 	str[x]=' '; 
 	 	} 
 	cout<<"Enter a string. Press space twice to put a fullstop. Press * to exit. \n --> ";  	while(str[i-1]!='*'&&i<=2499){  	str[i]=getche();  	if(i==0){ 
 	str[i]=toupper(str[i]);  	cout<<"\b"<<str[i]; 
} 
if(str[i]==' '&&str[i-1]==' '){ 
 	str[i]='.';  	cout<<"\b\b. "; 
 	 	} 
 	 	if(str[i-1]=='.'){  	 	 	str[i]=toupper(str[i]);  	 	 	cout<<"\b"<<str[i]; 
 	 	} 
 	 	if(str[i-1]=='i'&&str[i]==' '&&str[i-2]==' '){ 
 	 	 	str[i-1]='I'; 
 	 	 	cout<<"\b\b"<<str[i-1]<<" "; 
 	 	} 
 	 	 i++; 
 	 	} 
 	cout<<"\n\n\tWould you like to save? (Y/N)\n\t\t--> "; 
 	char inp;  	cin>>inp;  	if(inp=='Y')  	 	filesave(str);  	else  	 	compscreen(); 
} void word(){ 
 	labelnew:  	clrscr();  	gotoxy(27,5); 
cout<<"Create new / Open Old  "; 
int x,y; getcor(x,y); 
if(x>=210&&x<=292&&y>=32&&y<=38) 
typefile(); 
else if(x>=310&&x<=390&&y>=32&&y<=38)  	fileopen(); 
else goto labelnew; 
} 
 
void compscreen(){ 
 	clrscr();  	cout<<"WELCOME TO COMPUTER MODE...\n\n\n\n";  	cout<<"\t\t\t\tWORD PROCESSOR\n";  	cout<<"\t\t\t\tEXCEL SHEET\n";  	cout<<"\t\t\t\tBACK TO PHONE MODE\n";  	int x,y;  	getcor(x,y);  	if(x>=260&&x<=363&&y>=32&&y<=38) 
 	 	word(); 
 	else if(x>=260&&x<=340&&y>=42&&y<=48) 
 	 	excel(); 
 	else if(x>=260&&x<=400&y>=50&&y<=58) 
 	 	homescreen(); 
 	else compscreen(); 
} void printbox(){ 
 	int i=0;  	for(i=23;i<=53;i++){ 
 	 	gotoxy(i,2);  	 	cout<<"-"; 
 	gotoxy(i,23);  	cout<<"-"; 
} for(i=2;i<=23;i++){ gotoxy(23,i); cout<<"|"; gotoxy(53,i); cout<<"|"; 
 	} 
} int j=39,i,h=7,h2=7,score=0,k=53; void printout(int x1, int y1){ 
 	gotoxy(x1,y1-1);  	cout<<"**";  	gotoxy(x1,y1);  	cout<<"**";  	for(i=0;i<=h;i++){ 
 	 	 	gotoxy(j,i+4);  	 	 	cout<<"*"; 
 
 	 	} 
 	for(i+=5;i<18;i++){ 
 	 	 	gotoxy(j,i+4);  	 	 	cout<<"*"; 
 	 	} 
 	for(i=0;i<=h2;i++){ 
 	 	 	gotoxy(k,i+4);  	 	 	cout<<"*"; 
 
 	 	} 
 	for(i+=5;i<18;i++){ 
 	 	gotoxy(k,i+4);  	 	cout<<"*"; 
	 	} 
printbox(); gotoxy(24,3); cout<<"   "; gotoxy(24,3); cout<<score; 
 	} 
void printclr(int xa, int ya){ 
 	gotoxy(xa,ya);  	cout<<"  ";  	gotoxy(xa,ya-1);  	cout<<"  "; 
} int random1(){ 
 randomize();  int abc = (rand()%12);  return abc; 
} char arr[9]; void printgrid(){ 
 	gotoxy(25,5); 
 	cout<<arr[0]<<" | "<<arr[1]<<" | "<<arr[2]<<"\n";  	gotoxy(25,6);  	cout<<"--|---|--";  	gotoxy(25,7); 
 	cout<<arr[3]<<" | "<<arr[4]<<" | "<<arr[5]<<"\n";  	gotoxy(25,8);  	cout<<"--|---|--";  	gotoxy(25,9); 
 	cout<<arr[6]<<" | "<<arr[7]<<" | "<<arr[8]<<"\n";  	printbox(); 
} int keylistener(){ int retval; 
int x,y; label2: 
getcor(x,y); 
 	 	 	if(x>=190&&x<210&&y>=30&&y<=40){ 
 	 	 	 	retval = 1;} 
 	 	 	else if(x>=210&&x<240&&y>=30&&y<=40){ 
 	 	 	 	retval = 2;} 
 	 	 	else if(x>=240&&x<280&&y>=30&&y<=40){ 
 	 	 	 	retval = 3;} 
 	 	       else if(x>=190&&x<210&&y>=42&&y<=55){ 
 	 	 	 	retval = 4;} 
 	 	 	else if(x>=210&&x<240&&y>=42&&y<=55){ 
 	 	 	 	retval = 5;} 
 	 	 	else if(x>=240&&x<280&&y>=42&&y<=55){ 
 	 	 	 	retval = 6;} 
 	 	 	else if(x>=190&&x<210&&y>=55&&y<=70){ 
 	 	 	 	retval = 7;} 
 	 	 	else if(x>=210&&x<240&&y>=55&&y<=70){ 
 	 	 	 	retval = 8;} 
 	 	 	else if(x>=240&&x<280&&y>=55&&y<=70){ 
 	 	 	 	retval = 9;} 
 	 	 	else goto label2; 
 	return retval; 
} void tictactoe(){ 
 	clrscr(); 
printbox(); switchlabel1: int loopcont=0,scorea=0,scoreb=0,doloop; char n1[20]; char check[9]; 
gotoxy(24,4); cout<<"Enter the name of the player"; gotoxy(24,5); 
 	cin>>n1;  	char n2[]="CPU"; 
 
 	loopcont=0; 
 	for(int l = 0;l<9;l++){ 
 	 	int xa = l+49;  	 	arr[l] = xa;  	 	check[l] = 'a'; 
 	 	} 
 	clrscr(); 
 
 	do{ 	label:  	 	clrscr();  	 	printgrid();  	 	int input1,input2;  	 	input1=keylistener(); 
 	 	input1--; 
 	 	if(check[input1]=='a'){  	 	arr[input1] = 'O';  	 	check[input1]='b';} 
 	 	else 
 	 	{cout<<"Please enter an unused value"; 
 	 	getch(); 
goto label;} clrscr(); if(arr[0]==arr[1]&&arr[1]==arr[2]&&arr[2]=='X'){ 
	 	loopcont=9;} 
if(arr[0]==arr[1]&&arr[1]==arr[2]&&arr[2]=='O'){ 
	 	loopcont=10;} 
if(arr[0]==arr[3]&&arr[3]==arr[6]&&arr[6]=='X'){ 
 	loopcont=9;}  	 	if(arr[0]==arr[3]&&arr[3]==arr[6]&&arr[6]=='O'){ 
 	 	 	loopcont=10;} 
 	 	if(arr[0]==arr[4]&&arr[4]==arr[8]&&arr[8]=='X'){ 
 	 	 	loopcont=9;} 
 	 	if(arr[0]==arr[4]&&arr[4]==arr[8]&&arr[8]=='O'){ 
 	 	 	loopcont=10;} 
 	 	if(arr[3]==arr[4]&&arr[4]==arr[5]&&arr[5]=='X'){ 
 	 	 	loopcont=9;} 
 	 	if(arr[3]==arr[4]&&arr[4]==arr[5]&&arr[5]=='O'){ 
 	 	 	loopcont=10;} 
 	 	if(arr[6]==arr[7]&&arr[7]==arr[8]&&arr[8]=='X'){ 
 	 	 	loopcont=9;} 
 	 	if(arr[6]==arr[7]&&arr[7]==arr[8]&&arr[8]=='O'){ 
 	 	 	loopcont=10;} 
 	 	if(arr[1]==arr[4]&&arr[4]==arr[7]&&arr[7]=='X'){ 
 	 	 	loopcont=9;} 
 	 	if(arr[1]==arr[4]&&arr[4]==arr[7]&&arr[7]=='O'){ 
 	 	 	loopcont=10;} 
 	 	if(arr[2]==arr[5]&&arr[5]==arr[8]&&arr[8]=='X'){ 
 	 	 	loopcont=9;} 
 	 	if(arr[2]==arr[5]&&arr[5]==arr[8]&&arr[8]=='O'){ 
 	 	 	loopcont=10;} 
 	 	if(arr[2]==arr[4]&&arr[4]==arr[6]&&arr[6]=='X'){  	loopcont=9;} 
if(arr[2]==arr[4]&&arr[4]==arr[6]&&arr[6]=='O'){ 
	 	loopcont=10;} 
if(loopcont==4){break;} if(loopcont==9){  	clrscr();  	gotoxy(24,4);  	cout<<n2<<" wins \n";scoreb++; 
 	 	 	printgrid(); 
 	 	 	break;} 
 	 	if(loopcont==10){ 
 	 	 	clrscr();  	 	 	gotoxy(24,4); 
 	 	 	cout<<n1<<" wins \n";scorea++; 
 	 	 	printgrid(); 
 	 	 	break; 
 	 	} 
 	 	back: 
 	 	printgrid(); 
 	 	if(arr[4]=='5'){arr[4]='X'; 
 	 	check[4]='b';} 
 	 	else if(arr[0]==arr[1]&&arr[1]=='X'&&check[2]=='a'){ 
 	 	 	arr[2]='X';  	 	 	check[2]='b';} 
 	 	else if(arr[0]==arr[2]&&arr[2]=='X'&&check[1]=='a'){ 
 	 	 	arr[1]='X';  	 	 	check[1]='b';} 
 	 	else if(arr[1]==arr[2]&&arr[2]=='X'&&check[0]=='a'){ 
 	 	 	arr[0]='X';  	 	 	check[0]='b';} 
 	 	else if(arr[0]==arr[3]&&arr[3]=='X'&&check[6]=='a'){  	arr[6]='X';  	check[6]='b';} 
else if(arr[0]==arr[6]&&arr[6]=='X'&&check[3]=='a'){ 
 	arr[3]='X';  	check[3]='b';} else if(arr[3]==arr[6]&&arr[6]=='X'&&check[0]=='a'){ 
 	arr[0]='X';  	check[0]='b';}  	 	else if(arr[0]==arr[4]&&arr[4]=='X'&&check[8]=='a'){ 
 	 	 	arr[8]='X';  	 	 	check[8]='b';} 
 	 	else if(arr[0]==arr[8]&&arr[8]=='X'&&check[4]=='a'){ 
 	 	 	arr[4]='X';  	 	 	check[4]='b';} 
 	 	else if(arr[4]==arr[8]&&arr[8]=='X'&&check[0]=='a'){ 
 	 	 	arr[0]='X';  	 	 	check[0]='b';} 
 	 	else if(arr[4]==arr[5]&&arr[5]=='X'&&check[3]=='a'){ 
 	 	 	arr[3]='X';  	 	 	check[3]='b';} 
 	 	else if(arr[4]==arr[3]&&arr[3]=='X'&&check[5]=='a'){ 
 	 	 	arr[5]='X';  	 	 	check[5]='b';} 
 	 	else if(arr[3]==arr[4]&&arr[4]=='X'&&check[5]=='a'){ 
 	 	 	arr[5] ='X';  	 	 	check[5]='b';} 
 	 	else if(arr[6]==arr[7]&&arr[7]=='X'&&check[8]=='a'){ 
 	 	 	arr[8]='X';  	 	 	check[8]='b';} 
 	 	else if(arr[6]==arr[8]&&arr[8]=='X'&&check[7]=='a'){ 
 	 	 	arr[7]='X'; 
	 	check[7]='b';} 
else if(arr[7]==arr[8]&&arr[8]=='X'&&check[6]=='a'){ 
 	arr[6]='X';  	check[6]='b';} 
else if(arr[1]==arr[4]&&arr[4]=='X'&&check[7]=='a'){ 
 	arr[7]='X';  	check[7]='b';} 
else if(arr[1]==arr[7]&&arr[7]=='X'&&check[4]=='a'){ 
 	 	 	arr[4]='X';  	 	 	check[4]='b';} 
 	 	else if(arr[4]==arr[7]&&arr[7]=='X'&&check[1]=='a'){ 
 	 	 	arr[1]='X';  	 	 	check[1]='b';} 
 	 	else if(arr[5]==arr[8]&&arr[8]=='X'&&check[2]=='a'){ 
 	 	 	arr[2]='X';  	 	 	check[2]='b';} 
 	 	else if(arr[5]==arr[2]&&arr[2]=='X'&&check[8]=='a'){ 
 	 	 	arr[8]='X';  	 	 	check[8]='b';} 
 	 	else if(arr[2]==arr[8]&&arr[8]=='X'&&check[5]=='a'){ 
 	 	 	arr[5]='X';  	 	 	check[5]='b';} 
 	 	else if(arr[2]==arr[4]&&arr[4]=='X'&&check[6]=='a'){ 
 	 	 	arr[6]='X';check[6]='b';} 
 	 	else if(arr[2]==arr[6]&&arr[6]=='X'&&check[4]=='a'){ 
 	 	 	arr[4]='X';  	 	 	check[4]='b';} 
 	 	else if(arr[4]==arr[6]&&arr[6]=='X'&&check[2]=='a'){ 
 	 	 	arr[2]='X';  	 	 	check[2]='b';} 
 
else if(arr[0]==arr[1]&&arr[1]=='O'&&check[2]=='a'){ 
 	arr[2]='X';  	check[2]='b';} 
else if(arr[0]==arr[2]&&arr[2]=='O'&&check[1]=='a'){ 
	 	arr[1]='X'; 
	 	check[1]='b';} 
else if(arr[1]==arr[2]&&arr[2]=='O'&&check[0]=='a'){ 
	 	arr[0]='X'; 
 	 	 	check[0]='b';} 
 	 	else if(arr[0]==arr[3]&&arr[3]=='O'&&check[6]=='a'){ 
 	 	 	arr[6]='X';  	 	 	check[6]='b';} 
 	 	else if(arr[0]==arr[6]&&arr[6]=='O'&&check[3]=='a'){ 
 	 	 	arr[3]='X';  	 	 	check[3]='b';} 
 	 	else if(arr[3]==arr[6]&&arr[6]=='O'&&check[0]=='a'){ 
 	 	 	arr[0]='X';  	 	 	check[0]='b';} 
 	 	else if(arr[0]==arr[4]&&arr[4]=='O'&&check[8]=='a'){ 
 	 	 	arr[8]='X';  	 	 	check[8]='b';} 
 	 	else if(arr[0]==arr[8]&&arr[8]=='O'&&check[4]=='a'){ 
 	 	 	arr[4]='X';  	 	 	check[4]='b';} 
 	 	else if(arr[4]==arr[8]&&arr[8]=='O'&&check[0]=='a'){ 
 	 	 	arr[0]='X';  	 	 	check[0]='b';} 
 	 	else if(arr[4]==arr[5]&&arr[5]=='O'&&check[3]=='a'){ 
 	 	 	arr[3]='X';  	 	 	check[3]='b';} 
 	 	else if(arr[4]==arr[3]&&arr[3]=='O'&&check[5]=='a'){  	arr[5]='X';  	check[5]='b';} 
else if(arr[3]==arr[4]&&arr[4]=='O'&&check[5]=='a'){ 
 	arr[5] ='X';  	check[5]='b';} else if(arr[6]==arr[7]&&arr[7]=='O'&&check[8]=='a'){ 
 	arr[8]='X';  	check[8]='b';}  	 	else if(arr[6]==arr[8]&&arr[8]=='O'&&check[7]=='a'){ 
 	 	 	arr[7]='X';  	 	 	check[7]='b';} 
 	 	else if(arr[7]==arr[8]&&arr[8]=='O'&&check[6]=='a'){ 
 	 	 	arr[6]='X';  	 	 	check[6]='b';} 
 	 	else if(arr[1]==arr[4]&&arr[4]=='O'&&check[7]=='a'){ 
 	 	 	arr[7]='X';  	 	 	check[7]='b';} 
 	 	else if(arr[1]==arr[7]&&arr[7]=='O'&&check[4]=='a'){ 
 	 	 	arr[4]='X';  	 	 	check[4]='b';} 
 	 	else if(arr[4]==arr[7]&&arr[7]=='O'&&check[1]=='a'){ 
 	 	 	arr[1]='X';  	 	 	check[1]='b';} 
 	 	else if(arr[5]==arr[8]&&arr[8]=='O'&&check[2]=='a'){ 
 	 	 	arr[2]='X';  	 	 	check[2]='b';} 
 	 	else if(arr[5]==arr[2]&&arr[2]=='O'&&check[8]=='a'){ 
 	 	 	arr[8]='X';  	 	 	check[8]='b';} 
 	 	else if(arr[2]==arr[8]&&arr[8]=='O'&&check[5]=='a'){ 
 	 	 	arr[5]='X'; 
	 	check[5]='b';} 
else if(arr[2]==arr[4]&&arr[4]=='O'&&check[6]=='a'){ 
 	arr[6]='X';  	check[6]='b';} 
else if(arr[2]==arr[6]&&arr[6]=='O'&&check[4]=='a'){ 
 	arr[4]='X';  	check[4]='b';} 
else if(arr[4]==arr[6]&&arr[6]=='O'&&check[2]=='a'){ 
 	 	 	arr[2]='X';  	 	 	check[2]='b';} 
 	 	else if(arr[0]=='1'&&check[0]=='a'){arr[0] = 'X'; 
 	 	 	 	 	check[0]='b';} 
 	 	else if(arr[2]=='3'&&check[2]=='a'){arr[2] = 'X'; 
 	 	check[2]='b';} 
 	 	else if(arr[6]=='7'&&check[6]=='a'){arr[6] = 'X'; 
 	 	check[6]='b';} 
 	 	else if(arr[8]=='9'&&check[8]=='a'){arr[8] = 'X'; 
 	 	check[8]='b';}  	 	else{cout<<"Check code."; 
 	 	getch();  	 	clrscr();  	 	goto back;} 
 	 	if(arr[0]==arr[1]&&arr[1]==arr[2]&&arr[2]=='X'){ 
 	 	 	loopcont=9;} 
 	 	if(arr[0]==arr[1]&&arr[1]==arr[2]&&arr[2]=='O'){ 
 	 	 	loopcont=10;} 
 	 	if(arr[0]==arr[3]&&arr[3]==arr[6]&&arr[6]=='X'){ 
 	 	 	loopcont=9;} 
 	 	if(arr[0]==arr[3]&&arr[3]==arr[6]&&arr[6]=='O'){ 
 	 	 	loopcont=10;} 
 	 	if(arr[0]==arr[4]&&arr[4]==arr[8]&&arr[8]=='X'){  	loopcont=9;} 
if(arr[0]==arr[4]&&arr[4]==arr[8]&&arr[8]=='O'){ 
	 	loopcont=10;} 
if(arr[3]==arr[4]&&arr[4]==arr[5]&&arr[5]=='X'){ 
 	loopcont=9;} if(arr[3]==arr[4]&&arr[4]==arr[5]&&arr[5]=='O'){ 
	 	loopcont=10;} 
if(arr[6]==arr[7]&&arr[7]==arr[8]&&arr[8]=='X'){ 
 	 	 	loopcont=9;} 
 	 	if(arr[6]==arr[7]&&arr[7]==arr[8]&&arr[8]=='O'){ 
 	 	 	loopcont=10;} 
 	 	if(arr[1]==arr[4]&&arr[4]==arr[7]&&arr[7]=='X'){ 
 	 	 	loopcont=9;} 
 	 	if(arr[1]==arr[4]&&arr[4]==arr[7]&&arr[7]=='O'){ 
 	 	 	loopcont=10;} 
 	 	if(arr[2]==arr[5]&&arr[5]==arr[8]&&arr[8]=='X'){ 
 	 	 	loopcont=9;} 
 	 	if(arr[2]==arr[5]&&arr[5]==arr[8]&&arr[8]=='O'){ 
 	 	 	loopcont=10;} 
 	 	if(arr[2]==arr[4]&&arr[4]==arr[6]&&arr[6]=='X'){ 
 	 	 	loopcont=9;} 
 	 	if(arr[2]==arr[4]&&arr[4]==arr[6]&&arr[6]=='O'){ 
 	 	 	loopcont=10;} 
 	 	if(loopcont == 9){ 
 	 	 	clrscr();  	 	 	gotoxy(24,4); 
 	 	 	cout<<n2<<" wins \n";scoreb++; 
 	 	 	printgrid(); 
 	 	 	} 
 	 	if(loopcont==10){ 
 	 	 	clrscr(); 
 	gotoxy(24,4);  	cout<<n1<<" wins \n";scorea++;  	printgrid(); 
} loopcont++; }while(loopcont<=4); if(loopcont==4){ 
	 	printbox(); 
 	 	 	gotoxy(24,4);  	 	 	cout<<"Tie Game";}  	 	cout<<"\n";  	 	getch();  	 	clrscr();  	 	printbox();  	 	gotoxy(24,4); 
 	 	cout<<n1<<" scored --> "<<scorea; 
 	 	gotoxy(24,5); 
 	 	cout<<"CPU scored --> "<<scoreb; 
 	 	getch();  	 	homescreen(); 
} class contacts{ public: 
 	char name[20];  	char phno[10];  	contacts(){  	 	strcpy(name,"");  	 	strcpy(phno,"0000000000"); 
 	} 
}cont[20]; void dial(){ printbox(); gotoxy(37,10); cout<<"Dialing..."; delay(2000); phone(); 
} void phone(){ 
 	clrscr();  	printbox();  	gotoxy(32,14);  	cout<<"-------------";  	gotoxy(32,15); 
 	cout<<"| 1 | 2 | 3 |";  	gotoxy(32,16);  	cout<<"-------------";  	gotoxy(32,17); 
 	cout<<"| 4 | 5 | 6 |";  	gotoxy(32,18);  	cout<<"-------------";  	gotoxy(32,19); 
 	cout<<"| 7 | 8 | 9 |";  	gotoxy(32,20);  	cout<<"-------------";  	gotoxy(32,21); 
 	cout<<"    | 0 |Dial";  	int x=0,y=0; 
 	char noinput[11] = "          \0";  	for(int i = 0;i<10;i++){ 
 
 	 	label1: 
 	 	getcor(x,y); 
if(x>=250&&x<=280&&y>=105&&y<=124){  	noinput[i] = '1'; 
} 
else if(x>=280&&x<=320&&y>=105&&y<=124){  noinput[i] = '2'; 
} 
else if(x>=320&&x<=350&&y>=105&&y<=124){  noinput[i] = '3'; 
 	 	} 
  else if(x>=250&&x<=280&&y>=125&&y<=135){    noinput[i] = '4'; 
 	 	} 
  else if(x>=280&&x<=320&&y>=125&&y<=135){    noinput[i] = '5'; 
 	 	} 
  else if(x>=320&&x<=350&&y>=125&&y<=135){    noinput[i] = '6'; 
 	 	} 
  else if(x>=250&&x<=280&&y>=135&&y<=155){    noinput[i] = '7'; 
 	 	} 
  else if(x>=280&&x<=320&&y>=135&&y<=155){    noinput[i] = '8'; 
 	 	} 
  else if(x>=320&&x<=350&&y>=135&&y<=155){    noinput[i] = '9'; 
 	 	} 
  else if(x>=280&&x<=320&&y>=155&&y<=175){    noinput[i] = '0'; 
 	 	} 
 	 	else if(x>=320&&x<=350&&y>=155&&y<=175){ 
	 	 	dial(); 
	 	} 
	 	else goto label1; 
gotoxy(32,5); puts(noinput); } gotoxy(32,7); cout<<"Save contact? "; 
 	 	gotoxy(32,8);  	 	cout<<"YES \\ NO"; 
 	 	label2: 
 	 	getcor(x,y);  	 	if(x>=250&&x<=270&&y>=55&&y<=65){  	 	 	for(int loop = 0;loop<20;loop++){  	 	 	 	if(!strcmp(cont[loop].name,"")){ 
 	 	 	 	 	break; 
 	 	 	 	} 
 	 	 	} 
 	 	 	gotoxy(32,8);  	 	 	if(loop == 20){  	 	 	 	cout<<"SLOTS FULL";  	 	 	 	goto phoneend; 
 	 	 	} 
 	 	 	strcpy(cont[loop].phno,noinput); 
 	 	 	clrscr();  	 	 	printbox();  	 	 	gotoxy(32,8);  	 	 	cout<<cont[loop].phno;  	 	 	gotoxy(32,9); 
 	 	 	cout<<"Enter the name : "; 
 	 	 	gotoxy(32,10); 
 	gets(cont[loop].name);  	gotoxy(32,11);  	cout<<"Contact Saved ";  	delay(1000);  	phoneend: 
	 	contact(); 
} 
else if(x>=295&&x<=310&&y>=55&&y<=65) homescreen(); 
 	 	else goto label2; 
 
 
} void contact(){ 
 	cmenustart:  	clrscr();  	printbox();  	gotoxy(34,6);  	cout<<"View / Delete";  	int x,y;  	getcor(x,y);  	if(x>=265&&x<=300&&y>=40&&y<=50){  	 	contactview(); 
 	} 
 	else if(x>=320&&x<=370&&y>=40&&y<=50){  	 	contactdel(); 
 	} 
 	else goto cmenustart; 
} void contactdel(){ 
 	clrscr();  	printbox(); 
gotoxy(27,6); cout<<"Enter the phone no. "; gotoxy(32,14); cout<<"-------------"; gotoxy(32,15); 
cout<<"| 1 | 2 | 3 |"; gotoxy(32,16); cout<<"-------------"; 
 	gotoxy(32,17); 
 	cout<<"| 4 | 5 | 6 |";  	gotoxy(32,18);  	cout<<"-------------";  	gotoxy(32,19); 
 	cout<<"| 7 | 8 | 9 |";  	gotoxy(32,20);  	cout<<"-------------";  	gotoxy(32,21);  	cout<<"    | 0 |";  	int x=0,y=0; 
 	char noinput[11] = "          \0";  	for(int i = 0;i<10;i++){ 
 
 	 	label1: 
 	 	getcor(x,y);  	 	if(x>=250&&x<=280&&y>=105&&y<=124){  	 	 	noinput[i] = '1'; 
 	 	} 
  else if(x>=280&&x<=320&&y>=105&&y<=124){    noinput[i] = '2'; 
 	 	} 
 	 	else if(x>=320&&x<=350&&y>=105&&y<=124){ 
	 	noinput[i] = '3'; 
} 
else if(x>=250&&x<=280&&y>=125&&y<=135){  noinput[i] = '4'; 
} 
else if(x>=280&&x<=320&&y>=125&&y<=135){  noinput[i] = '5'; 
} 
  else if(x>=320&&x<=350&&y>=125&&y<=135){    noinput[i] = '6'; 
 	 	} 
  else if(x>=250&&x<=280&&y>=135&&y<=155){    noinput[i] = '7'; 
 	 	} 
  else if(x>=280&&x<=320&&y>=135&&y<=155){    noinput[i] = '8'; 
 	 	} 
  else if(x>=320&&x<=350&&y>=135&&y<=155){    noinput[i] = '9'; 
 	 	} 
  else if(x>=280&&x<=320&&y>=155&&y<=175){    noinput[i] = '0'; 
 	 	} 
 	 	else goto label1;  	 	gotoxy(32,5);  	 	puts(noinput); 
 	 	} 
 	int loop = 0;  	for(loop = 0; loop<20; loop++){ 
 
 if(cont[loop].phno[0]==noinput[0]&&cont[loop].phno[1]==noinput[1]&&cont[loop].phno[2]==noinput[2]&&co nt[loop].phno[3]==noinput[3]&&cont[loop].phno[4]==noinput[4]&&cont[loop].phno[5]==noinput[5]&&cont[loop].ph no[6]==noinput[6]&&cont[loop].phno[7]==noinput[7]&&cont[loop].phno[8]==noinput[8]&&cont[loop].phno[9]==noi nput[9]) 
	 	 	break; 
} if(loop ==20){ 
 	gotoxy(34,6); 
 
 	} 
 	else{ 	cout<<"Contact Doesnt Exist"; 
 	 	for(;loop<19;loop++){ 
 	 	       if(!strcmp(cont[loop+1].phno," 000000000")) 
 	 	 	 	break; 
 	 	       cont[loop]=cont[loop+1]; 
 	 	} 
 	 	strcpy(cont[loop].phno," 000000000"); 
 	 	strcpy(cont[loop].name," "); 
 	} 
 	getch();  	homescreen(); 
} void contactview(){  	int scrl = 0;  	contactstart:  	clrscr();  	int loop;  	printbox(); 
 	for(loop = 0; loop <= 5; loop ++){ 
 	 	gotoxy(24,4+loop*2);  	 	cout<<cont[loop+scrl].name;  	 	gotoxy(24,5+loop*2); 
 	for(int loop1=0;loop1<10;loop1++){  	 	cout<<cont[loop+scrl].phno[loop1]; 
	 	} 
} gotoxy(51,4); cout<<"/\\"; gotoxy(51,23); cout<<"\\/"; 
 	int x,y;  	getcor(x,y);  	if(x>=400&&x<=420&&y>=25&&y<=35){  	 	if(scrl>1); 
 	 	 	scrl-=2; 
 	 	goto contactstart; 
 	} 
 	if(x>=400&&x<=420&&y>=175&&y<=185){  	 	if(scrl<19); 
 	 	 	scrl+=2; 
 	 	goto contactstart; 
 	} 
 	homescreen(); 
 	} 
void game(){ 
 	clrscr();  	printbox();  	gotoxy(27,5);  	cout<<"FLAPPY BIRD/ TICTACTOE ";  	int x,y;  	getcor(x,y);  	if(x>=210&&x<=292&&y>=32&&y<=38) 
 	 	flappybd(); 
 	else if(x>=310&&x<=390&&y>=32&&y<=38)  	 	tictactoe(); 
 	homescreen(); 
} 
void flappybd(){ 
 	 	clrscr(); 
 	 	j=39,i,h=7,h2=7,score=0,k=53;  	 	char a = ' ';  	 	int b = 28,c=20;  	 	long q = 0UL;  	 	while(a!='q'){  	 	      if(j==24){ 
 	 	 	h= random1(); 
 	 	 	j=53;  	 	 	score++; 
 	 	      } 
 	 	      if(k==24){ 
 	 	 	h2 = random1(); 
 	 	 	k=53; 
 	 	 	score++; 
 	 	      }  	 	      q++;  	 	      if(b==j){  	 	 	if(c<h+4||c>(h+9)){ 
 	 	 	 	break; 
 	 	 	} 
 	 	      } 
 	 	      if(b==k)  	 	 	if(c<h2+4||c>(h2+9)){ 
	 	 	 	break; 
	 	 	} 
 	      if(kbhit()){  	      a=getche(); 
	 	      } 
 	      else a=' ';  	      if(q%25==0){j--;k--;}  	      if(q%25==0)c++;  	 	      if( a =='w') 
 	 	 	c-=3; 
 	 	      else if( a == 's') 
 	 	 	c++; 
 	 	      else if( a == 'a') 
 	 	 	b--; 
 	 	      else if( a == 'd'){ 
 	 	 	b++; 
 	 	 	} 
 	 	      if(b>77)b=1;  	 	      if(c>24)c=2;  	 	      if(b<1)b=77;  	 	      if(c<2)c=24;  	 	      printclr(b,c);  	 	      clrscr();  	 	      printout(b,c);  	 	      delay(6);  	 	      flushall(); 
 	 	} 
 	delay(500);  	getch();  	homescreen(); 
 	} 
void homescreen(){ 
clrscr(); printbox(); struct  time t; gettime(&t); gotoxy(35,8); cout<<(int)t.ti_hour<<":"<<(int)t.ti_min; gotoxy(28,20); 
 	cout<<"PHN  CNTCT  GAME  PCMODE";  	gotoxy(28,22);  	cout<<"         EXIT";  	int x,y;  	label:  	getcor(x,y);  	if(x>=215&&x<=245&&y>=150&&y<=160) 
 	 	phone(); 
 	else if(x>=255&&x<=305&&y>=150&&y<=160) 
 	 	contact(); 
 	else if(x>=310&&x<=350&&y>=150&&y<=160) 
 	 	game(); 
 	else if(x>=355&&x<=425&&y>=150&&y<=160) 
 	 	compscreen(); 
 else if(x>=285&&x<=335&&y>=160&&y<=180);  else goto label; 
} 
 
void main(){ 
 	textcolor(WHITE);  	textbackground(BLUE);  	int a123;  	for(a123 = 0; a123<=12;a123++){  	clrscr();  	gotoxy(1+(2*a123),1+a123);  	cout<<"*"; 
 	gotoxy(1+(2*a123),25-a123);  	cout<<"*";  	gotoxy(80-(2*a123),1+a123);  	cout<<"*"; 
	 	gotoxy(80-(2*a123),25-a123); 
 	 	cout<<"*"; 
 
 	 	delay(200);} 
 	for(int b123=25;b123<=40;b123++){ 
 	 	clrscr();  	 	gotoxy(b123,a123);  	 	cout<<"*"; 
 	 	gotoxy(80-b123,a123); 
 	 	cout<<"*";  	 	delay(200); 
 	 	} 
 	for(int x123 = 1; x123<19;x123++){ 
 	 	clrscr(); 
  for(int x3123=(13-x123);x3123>0;x3123--)cout<<"\n";   for(int x4123=(18-x123);x4123>0;x4123--)cout<<"  ";   rotate(x123);rotate(x123);rotate(x123);rotate(x123);rotate(x123);   for(int x1123=0;x1123<x123;x1123++){rotate(x123);rotate(x123);rotate(x123);rotate(x123);} 
 	 	cout<<"\n"; 
  for(x4123=(18-x123);x4123>0;x4123--)cout<<"  ";   for(int x2123=0;x2123<x123;x2123++){ 
 	 	 	rotate(x123); 
 	 	 	for(int x21123=0;x21123<=x1123;x21123++){ 
 	 	 	cout<<"    "; 
 	 	 	} 
 	 	rotate(x123);  	 	cout<<endl; 
	 	 	for(x4123=(18-x123);x4123>0;x4123--)cout<<"  "; 
	 	 	} 
 	for(x1123=0;x1123<x123;x1123++){rotate(x123);rotate(x123);rotate(x123);rotate(x123);}  	rotate(x123);rotate(x123);rotate(x123);rotate(x123);rotate(x123); 
 	delay(200);}  	 	gotoxy(30,10);  	 	cout<<"Phone Os";  	 	gotoxy(30,11); 
 	 	cout<<"By-Shamin Chokshi, ";  	 	gotoxy(50,20);  	 	cout<<"Class 12 E";  	 	gotoxy(50,22); 
 	 	cout<<"Press Enter to continue"; 
/*Note : The variable names upto here have sufffix 123. This has been done, to avoid clash in variable names, since this portion of the program was developed after the remaining program.*/ 
 	getch(); 
 
 	clrscr();  	contacts dummy; 
 ifstream inf("phbook.txt");  int loop; 
 	for(loop = 0; loop<20; loop++){ 
 	 	inf>>cont[loop].name;  	 	inf>>cont[loop].phno;  	 	if(cont[loop].name[0]>=65){} 
 	 	else{ 
 	 	 	cont[loop]=dummy; 
 	 	} 
 	} 
 	inf.close(); 
 
 	homescreen(); 
 	ofstream outf("phbook.txt"); 
 	for(loop = 0; loop<20; loop++){  	 	outf<<cont[loop].name<<"\n";  	 	for(int loop1=0;loop1<10;loop1++){  	 	 	outf<<cont[loop].phno[loop1]; 
 	 	} 
 	 	outf<<"\n"; 
 	} 
 	outf.close(); 
} 
