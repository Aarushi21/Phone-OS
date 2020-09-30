II. 	Header File <SHAMIN.H> 
#include<iostream.h> 
#include<conio.h> 
#include<dos.h> #include<stdlib.h> void rotate (int r1){ 
 	 	if(r1%4==0){cout<<"\\";}  	 	if(r1%4==1){cout<<"|";}  	 	if(r1%4==2){cout<<"/";}  	 	if(r1%4==3){cout<<"-";} 
	 	 	} 
union REGS in, out; void getcor(int &x,int &y){ 
 	in.x.ax = 0;  	int86(0X33,&in,&out);  	if(out.x.ax==0){  	 	cout<<"Mouse failed to initialize"; 
	 	 	} 
	 	else; 
 	in.x.ax = 1;  	int86(0X33,&in,&out);  	in.x.ax = 3;  	while(out.x.bx != 1){ 
 	 	int86(0X33,&in,&out);  	 	x = out.x.cx;  	 	y = out.x.dx;  	 	delay(200);} 
 
 
	 	in.x.ax = 2; 
int86(0X33,&in,&out); 
 
	 	} 
void loadspin(){  	for(int abc = 0;abc<7;abc++){ 
 	 	 	delay(100);  	 	 	clrscr(); 
 	 	 	cout<<"Loading |";  	 	 	delay(100);  	 	 	clrscr(); 
 	 	 	cout<<"Loading /";  	 	 	delay(100);  	 	 	clrscr(); 
 	 	 	cout<<"Loading -";  	 	 	delay(100);  	 	 	clrscr(); 
	 	 	 	cout<<"Loading \\"; 
 
	 	 	} 
	 	clrscr(); 
 
} void testcor(){ 
	 	while(!kbhit()){ 
   int x,y;    getcor(x,y);    cout<<x<<" "<<y; 
 
	 	} 
} void encrypt(char* a){ for(int i=0;a[i]!='\0';i++){  	 	if(i%8==0)  	 	 	a[i]+=11; 
 	 	if(i%8==1)  	 	 	a[i]+=21; 
 	 	if(i%8==2)  	 	 	a[i]+=31; 
 	 	if(i%8==3)  	 	 	a[i]+=41; 
 	 	if(i%8==4)  	 	 	a[i]+=51; 
 	 	if(i%8==5)  	 	 	a[i]+=61; 
 	 	if(i%8==6)  	 	 	a[i]+=71; 
 	 	if(i%8==7)  	 	 	a[i]+=81; 
	 	} 
} void decrypt(char* a){  	for(int i=0;a[i]!='\0';i++){ 
 	 	if(i%8==0)  	 	 	a[i]-=11;  	 	if(i%8==1)  	 	 	a[i]-=21;  	 	if(i%8==2)  	 	 	a[i]-=31;  	 	if(i%8==3)  	 	 	a[i]-=41;  	 	if(i%8==4)  	 	 	a[i]-=51; 
	 	if(i%8==5) 
 	 	 	a[i]-=61;  	 	if(i%8==6)  	 	 	a[i]-=71;  	 	if(i%8==7)  	 	 	a[i]-=81; 
	 	} 
} 
