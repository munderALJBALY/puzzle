#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<string>
#include<fstream>
#include<stdlib.h>
#include<windows.h>
using namespace std;
void gotoxy(short x, short y){
    COORD coord = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int main(){
int siz = 12;
fstream file;
string sec[64],str[8],user[8];
char ch,arr[siz][siz],chara[26];
int i=0,value_of_worlds=0,value=64,ran,three_state,a,b,coun,var,col,add,words,xx,num,ii=0,out=1,win=0,col_win=0,co=0;
for(char ar='a';ar<='z';ar++){
    chara[co]=ar;
    co++;
}
file.open("file.txt",ios::in);
if(!file){
    cout << "\n the File is not exist \n";
    goto OFF_Program;
}else{
    while(1){
   file >> ch;
   if(file.eof()){break;}
    if(ch == ','){ii++;}else if(ii == value){break;}else{sec[ii] += ch;}
    }
file.close();
}


while(out){

system("cls");
cout << endl ;
for(int p=0;p<8;p++){
     str[p] = sec[(rand() % 64)];
     cout << str[p];
     if(p != 7){cout<< " , ";}
}
cout << " : " << endl << endl;
for(int t=0;t < siz;t++){
for(int f=0;f < siz;f++){
    arr[t][f] = ' ';
    }
}

for(words=0;words < 8;words++){
K:
three_state = rand()%2;

if(three_state == 1){
// is ( | )
coun=0;
a = rand() % siz;//column
add=0;
var = rand() % (siz - str[words].size());//from
for(xx=var;xx < siz;xx++){
    if(arr[xx][a] == ' '){add++;}else{goto K;}
    if(add == (str[words].size())){break;}
}
col = str[words].size() + var; // to
 for(i=var;i < col;i++){
 arr[i][a] = str[words][coun];
 coun++;
 }
}else if(three_state == 0){
// is ( - )
coun=0;
b = rand() % siz;//row
add=0;
var = rand() % (siz - str[words].size()); // from
for(xx=var;xx < siz;xx++){
    if(arr[b][xx] == ' '){add++;}else{goto K;}
    if(add == (str[words].size())){break;}
}
col = str[words].size() + var; // to
 for(i=var;i < col;i++){
 arr[b][i] = str[words][coun];
 coun++;
 }
}
}

for(int ss=0;ss<siz;ss++){
    for(int zz=0;zz<siz;zz++){
       if(arr[ss][zz] == ' '){arr[ss][zz]= chara[(rand() % 27)];}
    }
}// inter random charactar to array for print 

gotoxy(20,2); // x,y

for(int t=0;t<siz;t++){
    for(int f=0;f<siz;f++){
        cout << " [ " << arr[t][f] << " ] ";
    }
    // cout << "\n";
    gotoxy(20,2+t);
  }// print the array

cout << "\n enter 8 values : \n";
for(int g=0;g<8;g++){
  cout <<"word ["<<g<<"] : ";cin >> user[g];
//   cout << " | ";
}
for(int ss=0;ss < 8;ss++){
    for(int zz=0;zz < 8;zz++){
       if(user[ss] == str[zz]){win++;str[zz]="";}
    }
}
col_win = win + col_win;
win = 0;

cout << "\n press zero to exit : ";
cin >> out;
cout << "\n";
} // end while

if( col_win != 0){
cout << "\n Number of wins : " << col_win;
cout << "\n";
}else{
cout << "\n Number of wins : " << col_win << endl;
cout << "you loser ^-^";
cout << "\n";
}

OFF_Program:

system("pause");
   return 0;
}
