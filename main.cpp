#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <math.h>
#include <bits/stdc++.h>
//#include <ctime>

using namespace std;

struct Statespace{ 
    char board[8][8];
    int score;
    string path[12];
}; 

vector<string> Get_piece_positions_mj(char board[8][8],string player_color){
    int height=8,width=8,h=0,w=0,p=0;
    char piece;
    vector<string> positions( 12 , "O");
    //int positions[12][2];
    if(player_color=="BLACK"){
        piece='b';
    }else{
        piece='w';
    }
    while(h<height){
        if(board[w][h]==piece||board[w][h]==char(toupper(piece))){
            positions[p]=char(97+w)+to_string(h+1);
            //cout<<char(97+w)+to_string(h+1)<<endl;
            p++;
            
        }
        w++;
        //cout<<char(97+w-1)+to_string(h+1)<<" ";
        if(w==width){
            w=0;
            h++;
            //cout<<endl;
        }
    }
    return positions;
    
}

vector<vector<string>> All_valid_moves_multijump(char board[8][8],string player_color){
    int p=0,vm=0,x,y,m,n,i,j,k,a,b,t,c,d,e,f,counter,temp,io;
    vector<string> positions_mj( 12 , "O");
    vector<vector<string>> valid_moves( 80 , vector<string> (12, "O"));
    positions_mj = Get_piece_positions_mj(board, player_color);
    
    while(p<12&&positions_mj[p]!="O"){
        x=int(positions_mj[p][0])-97;
        y=int(positions_mj[p][1])-49;
        if(board[x][y]==char(player_color[0])){//for kings
            //taking jumps
            board[x][y]='.';
            if(y>1&&x<6&&board[x+2][y-2]=='.'){
                if(player_color=="BLACK"&&(board[x+1][y-1]=='w'||board[x+1][y-1]=='W')){
                    valid_moves[vm][0]=char(97+x)+to_string(y+1);
                    valid_moves[vm][1]=char(97+(x+2))+to_string((y-2)+1);
                    i=vm;
                    j=i;
                    while(i<=j){
                        k=0;temp=j;
                        while(valid_moves[i][k]!="O"){
                            k++;
                        }
                        a=int(valid_moves[i][k-1][0])-97;
                        b=int(valid_moves[i][k-1][1])-49;
                        if(b>1&&a<6&&board[a+2][b-2]=='.'&&(board[a+1][b-1]=='w'||board[a+1][b-1]=='W')){
                            t=0;
                            counter=0;
                            while(t<k-1){
                                c=int(valid_moves[i][t][0])-97;
                                d=int(valid_moves[i][t][1])-49;
                                e=int(valid_moves[i][t+1][0])-97;
                                f=int(valid_moves[i][t+1][1])-49;
                                if((c==a&&d==b&&e==(a+2)&&f==(b-2))||(c==(a+2)&&d==(b-2)&&e==a&&f==b)){
                                    counter+=1;
                                }
                                t++;
                            }
                            if(counter==0){
                                j++;
                                t=0;
                                while(t<k){
                                    valid_moves[j][t]=valid_moves[i][t];
                                    t++;
                                }
                                valid_moves[j][t]=char(97+(a+2))+to_string((b-2)+1);
                                
                            }
                        }
                        if(b>1&&a>1&&board[a-2][b-2]=='.'&&(board[a-1][b-1]=='w'||board[a-1][b-1]=='W')){
                            t=0;
                            counter=0;
                            while(t<k-1){
                                c=int(valid_moves[i][t][0])-97;
                                d=int(valid_moves[i][t][1])-49;
                                e=int(valid_moves[i][t+1][0])-97;
                                f=int(valid_moves[i][t+1][1])-49;
                                if((c==a&&d==b&&e==(a-2)&&f==(b-2))||(c==(a-2)&&d==(b-2)&&e==a&&f==b)){
                                    counter+=1;
                                }
                                t++;
                                
                            }
                            if(counter==0){
                                j++;
                                t=0;
                                while(t<k){
                                    valid_moves[j][t]=valid_moves[i][t];
                                    t++;
                                }
                                valid_moves[j][t]=char(97+(a-2))+to_string((b-2)+1);
                                
                            }
                        }
                        if(b<6&&a<6&&board[a+2][b+2]=='.'&&(board[a+1][b+1]=='w'||board[a+1][b+1]=='W')){
                            t=0;
                            counter=0;
                            while(t<k-1){
                                c=int(valid_moves[i][t][0])-97;
                                d=int(valid_moves[i][t][1])-49;
                                e=int(valid_moves[i][t+1][0])-97;
                                f=int(valid_moves[i][t+1][1])-49;
                                if((c==a&&d==b&&e==(a+2)&&f==(b+2))||(c==(a+2)&&d==(b+2)&&e==a&&f==b)){
                                    counter+=1;
                                }
                                t++;
                            }
                            if(counter==0){
                                j++;
                                t=0;
                                while(t<k){
                                    valid_moves[j][t]=valid_moves[i][t];
                                    t++;
                                }
                                valid_moves[j][t]=char(97+(a+2))+to_string((b+2)+1);
                                
                            }
                        }
                        if(b<6&&a>1&&board[a-2][b+2]=='.'&&(board[a-1][b+1]=='w'||board[a-1][b+1]=='W')){
                            t=0;
                            counter=0;
                            while(t<k-1){
                                c=int(valid_moves[i][t][0])-97;
                                d=int(valid_moves[i][t][1])-49;
                                e=int(valid_moves[i][t+1][0])-97;
                                f=int(valid_moves[i][t+1][1])-49;
                                if((c==a&&d==b&&e==(a-2)&&f==(b+2))||(c==(a-2)&&d==(b+2)&&e==a&&f==b)){
                                    counter+=1;
                                }
                                t++;
                                
                            }
                            if(counter==0){
                                j++;
                                t=0;
                                while(t<k){
                                    valid_moves[j][t]=valid_moves[i][t];
                                    t++;
                                }
                                valid_moves[j][t]=char(97+(a-2))+to_string((b+2)+1);
                                
                            }
                        }
                        if(j>temp){
                            for(io=i+1;io<=j;io++){
                                k=0;t=0;
                                while(valid_moves[io][k]!="O"){
                                    k++;
                                }
                                while(t<k){
                                    valid_moves[io-1][t]=valid_moves[io][t];
                                    t++;
                                }
                            }
                            t=0;
                            while(t<k){
                                valid_moves[j][t]="O";
                                t++;
                            }
                            j--;
                        }else{
                            i++;
                        }
                    }
                    vm=i;
                }
                else if(player_color=="WHITE"&&(board[x+1][y-1]=='b'||board[x+1][y-1]=='B')){
                    valid_moves[vm][0]=char(97+x)+to_string(y+1);
                    valid_moves[vm][1]=char(97+(x+2))+to_string((y-2)+1);
                    i=vm;
                    j=i;
                    while(i<=j){
                        k=0;temp=j;
                        while(valid_moves[i][k]!="O"){
                            k++;
                        }
                        a=int(valid_moves[i][k-1][0])-97;
                        b=int(valid_moves[i][k-1][1])-49;
                        if(b>1&&a<6&&board[a+2][b-2]=='.'&&(board[a+1][b-1]=='b'||board[a+1][b-1]=='B')){
                            t=0;
                            counter=0;
                            while(t<k-1){
                                c=int(valid_moves[i][t][0])-97;
                                d=int(valid_moves[i][t][1])-49;
                                e=int(valid_moves[i][t+1][0])-97;
                                f=int(valid_moves[i][t+1][1])-49;
                                if((c==a&&d==b&&e==(a+2)&&f==(b-2))||(c==(a+2)&&d==(b-2)&&e==a&&f==b)){
                                    counter+=1;
                                }
                                t++;
                                
                            }
                            if(counter==0){
                                j++;
                                t=0;
                                while(t<k){
                                    valid_moves[j][t]=valid_moves[i][t];
                                    t++;
                                }
                                valid_moves[j][t]=char(97+(a+2))+to_string((b-2)+1);
                                
                            }
                        }
                        if(b>1&&a>1&&board[a-2][b-2]=='.'&&(board[a-1][b-1]=='b'||board[a-1][b-1]=='B')){
                            t=0;
                            counter=0;
                            while(t<k-1){
                                c=int(valid_moves[i][t][0])-97;
                                d=int(valid_moves[i][t][1])-49;
                                e=int(valid_moves[i][t+1][0])-97;
                                f=int(valid_moves[i][t+1][1])-49;
                                if((c==a&&d==b&&e==(a-2)&&f==(b-2))||(c==(a-2)&&d==(b-2)&&e==a&&f==b)){
                                    counter+=1;
                                }
                                t++;
                                
                            }
                            if(counter==0){
                                j++;
                                t=0;
                                while(t<k){
                                    valid_moves[j][t]=valid_moves[i][t];
                                    t++;
                                }
                                valid_moves[j][t]=char(97+(a-2))+to_string((b-2)+1);
                                
                            }
                        }
                        if(b<6&&a<6&&board[a+2][b+2]=='.'&&(board[a+1][b+1]=='b'||board[a+1][b+1]=='B')){
                            t=0;
                            counter=0;
                            while(t<k-1){
                                c=int(valid_moves[i][t][0])-97;
                                d=int(valid_moves[i][t][1])-49;
                                e=int(valid_moves[i][t+1][0])-97;
                                f=int(valid_moves[i][t+1][1])-49;
                                if((c==a&&d==b&&e==(a+2)&&f==(b+2))||(c==(a+2)&&d==(b+2)&&e==a&&f==b)){
                                    counter+=1;
                                }
                                t++;
                                
                            }
                            if(counter==0){
                                j++;
                                t=0;
                                while(t<k){
                                    valid_moves[j][t]=valid_moves[i][t];
                                    t++;
                                }
                                valid_moves[j][t]=char(97+(a+2))+to_string((b+2)+1);
                                
                            }
                        }
                        if(b<6&&a>1&&board[a-2][b+2]=='.'&&(board[a-1][b+1]=='b'||board[a-1][b+1]=='B')){
                            t=0;
                            counter=0;
                            while(t<k-1){
                                c=int(valid_moves[i][t][0])-97;
                                d=int(valid_moves[i][t][1])-49;
                                e=int(valid_moves[i][t+1][0])-97;
                                f=int(valid_moves[i][t+1][1])-49;
                                if((c==a&&d==b&&e==(a-2)&&f==(b+2))||(c==(a-2)&&d==(b+2)&&e==a&&f==b)){
                                    counter+=1;
                                }
                                t++;
                                
                            }
                            if(counter==0){
                                j++;
                                t=0;
                                while(t<k){
                                    valid_moves[j][t]=valid_moves[i][t];
                                    t++;
                                }
                                valid_moves[j][t]=char(97+(a-2))+to_string((b+2)+1);
                                
                            }
                        }
                        if(j>temp){
                            for(io=i+1;io<=j;io++){
                                k=0;t=0;
                                while(valid_moves[io][k]!="O"){
                                    k++;
                                }
                                while(t<k){
                                    valid_moves[io-1][t]=valid_moves[io][t];
                                    t++;
                                }
                            }
                            t=0;
                            while(t<k){
                                valid_moves[j][t]="O";
                                t++;
                            }
                            j--;
                        }else{
                            i++;
                        }
                    }
                    vm=i;
                }
            }
            if(y>1&&x>1&&board[x-2][y-2]=='.'){
                if(player_color=="BLACK"&&(board[x-1][y-1]=='w'||board[x-1][y-1]=='W')){
                    valid_moves[vm][0]=char(97+x)+to_string(y+1);
                    valid_moves[vm][1]=char(97+(x-2))+to_string((y-2)+1);
                    i=vm;
                    j=i;
                    while(i<=j){
                        k=0;temp=j;
                        while(valid_moves[i][k]!="O"){
                            k++;
                        }
                        a=int(valid_moves[i][k-1][0])-97;
                        b=int(valid_moves[i][k-1][1])-49;
                        if(b>1&&a<6&&board[a+2][b-2]=='.'&&(board[a+1][b-1]=='w'||board[a+1][b-1]=='W')){
                            t=0;
                            counter=0;
                            while(t<k-1){
                                c=int(valid_moves[i][t][0])-97;
                                d=int(valid_moves[i][t][1])-49;
                                e=int(valid_moves[i][t+1][0])-97;
                                f=int(valid_moves[i][t+1][1])-49;
                                if((c==a&&d==b&&e==(a+2)&&f==(b-2))||(c==(a+2)&&d==(b-2)&&e==a&&f==b)){
                                    counter+=1;
                                }
                                t++;
                                
                            }
                            if(counter==0){
                                j++;
                                t=0;
                                while(t<k){
                                    valid_moves[j][t]=valid_moves[i][t];
                                    t++;
                                }
                                valid_moves[j][t]=char(97+(a+2))+to_string((b-2)+1);
                                
                            }
                        }
                        if(b>1&&a>1&&board[a-2][b-2]=='.'&&(board[a-1][b-1]=='w'||board[a-1][b-1]=='W')){
                            t=0;
                            counter=0;
                            while(t<k-1){
                                c=int(valid_moves[i][t][0])-97;
                                d=int(valid_moves[i][t][1])-49;
                                e=int(valid_moves[i][t+1][0])-97;
                                f=int(valid_moves[i][t+1][1])-49;
                                if((c==a&&d==b&&e==(a-2)&&f==(b-2))||(c==(a-2)&&d==(b-2)&&e==a&&f==b)){
                                    counter+=1;
                                }
                                t++;
                                
                            }
                            if(counter==0){
                                j++;
                                t=0;
                                while(t<k){
                                    valid_moves[j][t]=valid_moves[i][t];
                                    t++;
                                }
                                valid_moves[j][t]=char(97+(a-2))+to_string((b-2)+1);
                                
                            }
                        }
                        if(b<6&&a<6&&board[a+2][b+2]=='.'&&(board[a+1][b+1]=='w'||board[a+1][b+1]=='W')){
                            t=0;
                            counter=0;
                            while(t<k-1){
                                c=int(valid_moves[i][t][0])-97;
                                d=int(valid_moves[i][t][1])-49;
                                e=int(valid_moves[i][t+1][0])-97;
                                f=int(valid_moves[i][t+1][1])-49;
                                if((c==a&&d==b&&e==(a+2)&&f==(b+2))||(c==(a+2)&&d==(b+2)&&e==a&&f==b)){
                                    counter+=1;
                                }
                                t++;
                                
                            }
                            if(counter==0){
                                j++;
                                t=0;
                                while(t<k){
                                    valid_moves[j][t]=valid_moves[i][t];
                                    t++;
                                }
                                valid_moves[j][t]=char(97+(a+2))+to_string((b+2)+1);
                                
                            }
                        }
                        if(b<6&&a>1&&board[a-2][b+2]=='.'&&(board[a-1][b+1]=='w'||board[a-1][b+1]=='W')){
                            t=0;
                            counter=0;
                            while(t<k-1){
                                c=int(valid_moves[i][t][0])-97;
                                d=int(valid_moves[i][t][1])-49;
                                e=int(valid_moves[i][t+1][0])-97;
                                f=int(valid_moves[i][t+1][1])-49;
                                if((c==a&&d==b&&e==(a-2)&&f==(b+2))||(c==(a-2)&&d==(b+2)&&e==a&&f==b)){
                                    counter+=1;
                                }
                                t++;
                                
                            }
                            if(counter==0){
                                j++;
                                t=0;
                                while(t<k){
                                    valid_moves[j][t]=valid_moves[i][t];
                                    t++;
                                }
                                valid_moves[j][t]=char(97+(a-2))+to_string((b+2)+1);
                                
                            }
                        }
                        if(j>temp){
                            for(io=i+1;io<=j;io++){
                                k=0;t=0;
                                while(valid_moves[io][k]!="O"){
                                    k++;
                                }
                                while(t<k){
                                    valid_moves[io-1][t]=valid_moves[io][t];
                                    t++;
                                }
                            }
                            t=0;
                            while(t<k){
                                valid_moves[j][t]="O";
                                t++;
                            }
                            j--;
                        }else{
                            i++;
                        }
                    }
                    vm=i;
                }
                else if(player_color=="WHITE"&&(board[x-1][y-1]=='b'||board[x-1][y-1]=='B')){
                    valid_moves[vm][0]=char(97+x)+to_string(y+1);
                    valid_moves[vm][1]=char(97+(x-2))+to_string((y-2)+1);
                    i=vm;
                    j=i;
                    while(i<=j){
                        k=0;temp=j;
                        while(valid_moves[i][k]!="O"){
                            k++;
                        }
                        a=int(valid_moves[i][k-1][0])-97;
                        b=int(valid_moves[i][k-1][1])-49;
                        if(b>1&&a<6&&board[a+2][b-2]=='.'&&(board[a+1][b-1]=='b'||board[a+1][b-1]=='B')){
                            t=0;
                            counter=0;
                            while(t<k-1){
                                c=int(valid_moves[i][t][0])-97;
                                d=int(valid_moves[i][t][1])-49;
                                e=int(valid_moves[i][t+1][0])-97;
                                f=int(valid_moves[i][t+1][1])-49;
                                if((c==a&&d==b&&e==(a+2)&&f==(b-2))||(c==(a+2)&&d==(b-2)&&e==a&&f==b)){
                                    counter+=1;
                                }
                                t++;
                                
                            }
                            if(counter==0){
                                j++;
                                t=0;
                                while(t<k){
                                    valid_moves[j][t]=valid_moves[i][t];
                                    t++;
                                }
                                valid_moves[j][t]=char(97+(a+2))+to_string((b-2)+1);
                                
                            }
                        }
                        if(b>1&&a>1&&board[a-2][b-2]=='.'&&(board[a-1][b-1]=='b'||board[a-1][b-1]=='B')){
                            t=0;
                            counter=0;
                            while(t<k-1){
                                c=int(valid_moves[i][t][0])-97;
                                d=int(valid_moves[i][t][1])-49;
                                e=int(valid_moves[i][t+1][0])-97;
                                f=int(valid_moves[i][t+1][1])-49;
                                if((c==a&&d==b&&e==(a-2)&&f==(b-2))||(c==(a-2)&&d==(b-2)&&e==a&&f==b)){
                                    counter+=1;
                                }
                                t++;
                                
                            }
                            if(counter==0){
                                j++;
                                t=0;
                                while(t<k){
                                    valid_moves[j][t]=valid_moves[i][t];
                                    t++;
                                }
                                valid_moves[j][t]=char(97+(a-2))+to_string((b-2)+1);
                                
                            }
                        }
                        if(b<6&&a<6&&board[a+2][b+2]=='.'&&(board[a+1][b+1]=='b'||board[a+1][b+1]=='B')){
                            t=0;
                            counter=0;
                            while(t<k-1){
                                c=int(valid_moves[i][t][0])-97;
                                d=int(valid_moves[i][t][1])-49;
                                e=int(valid_moves[i][t+1][0])-97;
                                f=int(valid_moves[i][t+1][1])-49;
                                if((c==a&&d==b&&e==(a+2)&&f==(b+2))||(c==(a+2)&&d==(b+2)&&e==a&&f==b)){
                                    counter+=1;
                                }
                                t++;
                                
                            }
                            if(counter==0){
                                j++;
                                t=0;
                                while(t<k){
                                    valid_moves[j][t]=valid_moves[i][t];
                                    t++;
                                }
                                valid_moves[j][t]=char(97+(a+2))+to_string((b+2)+1);
                                
                            }
                        }
                        if(b<6&&a>1&&board[a-2][b+2]=='.'&&(board[a-1][b+1]=='b'||board[a-1][b+1]=='B')){
                            t=0;
                            counter=0;
                            while(t<k-1){
                                c=int(valid_moves[i][t][0])-97;
                                d=int(valid_moves[i][t][1])-49;
                                e=int(valid_moves[i][t+1][0])-97;
                                f=int(valid_moves[i][t+1][1])-49;
                                if((c==a&&d==b&&e==(a-2)&&f==(b+2))||(c==(a-2)&&d==(b+2)&&e==a&&f==b)){
                                    counter+=1;
                                }
                                t++;
                                
                            }
                            if(counter==0){
                                j++;
                                t=0;
                                while(t<k){
                                    valid_moves[j][t]=valid_moves[i][t];
                                    t++;
                                }
                                valid_moves[j][t]=char(97+(a-2))+to_string((b+2)+1);
                                
                            }
                        }
                        if(j>temp){
                            for(io=i+1;io<=j;io++){
                                k=0;t=0;
                                while(valid_moves[io][k]!="O"){
                                    k++;
                                }
                                while(t<k){
                                    valid_moves[io-1][t]=valid_moves[io][t];
                                    t++;
                                }
                            }
                            t=0;
                            while(t<k){
                                valid_moves[j][t]="O";
                                t++;
                            }
                            j--;
                        }else{
                            i++;
                        }
                    }
                    vm=i;
                }
            }
            if(y<6&&x<6&&board[x+2][y+2]=='.'){
                if(player_color=="BLACK"&&(board[x+1][y+1]=='w'||board[x+1][y+1]=='W')){
                    valid_moves[vm][0]=char(97+x)+to_string(y+1);
                    valid_moves[vm][1]=char(97+(x+2))+to_string((y+2)+1);
                    i=vm;
                    j=i;
                    while(i<=j){
                        k=0;temp=j;
                        while(valid_moves[i][k]!="O"){
                            k++;
                        }
                        a=int(valid_moves[i][k-1][0])-97;
                        b=int(valid_moves[i][k-1][1])-49;
                        if(b>1&&a<6&&board[a+2][b-2]=='.'&&(board[a+1][b-1]=='w'||board[a+1][b-1]=='W')){
                            t=0;
                            counter=0;
                            while(t<k-1){
                                c=int(valid_moves[i][t][0])-97;
                                d=int(valid_moves[i][t][1])-49;
                                e=int(valid_moves[i][t+1][0])-97;
                                f=int(valid_moves[i][t+1][1])-49;
                                if((c==a&&d==b&&e==(a+2)&&f==(b-2))||(c==(a+2)&&d==(b-2)&&e==a&&f==b)){
                                    counter+=1;
                                }
                                t++;
                                
                            }
                            if(counter==0){
                                j++;
                                t=0;
                                while(t<k){
                                    valid_moves[j][t]=valid_moves[i][t];
                                    t++;
                                }
                                valid_moves[j][t]=char(97+(a+2))+to_string((b-2)+1);
                                
                            }
                        }
                        if(b>1&&a>1&&board[a-2][b-2]=='.'&&(board[a-1][b-1]=='w'||board[a-1][b-1]=='W')){
                            t=0;
                            counter=0;
                            while(t<k-1){
                                c=int(valid_moves[i][t][0])-97;
                                d=int(valid_moves[i][t][1])-49;
                                e=int(valid_moves[i][t+1][0])-97;
                                f=int(valid_moves[i][t+1][1])-49;
                                if((c==a&&d==b&&e==(a-2)&&f==(b-2))||(c==(a-2)&&d==(b-2)&&e==a&&f==b)){
                                    counter+=1;
                                }
                                t++;
                                
                            }
                            if(counter==0){
                                j++;
                                t=0;
                                while(t<k){
                                    valid_moves[j][t]=valid_moves[i][t];
                                    t++;
                                }
                                valid_moves[j][t]=char(97+(a-2))+to_string((b-2)+1);
                                
                            }
                        }
                        if(b<6&&a<6&&board[a+2][b+2]=='.'&&(board[a+1][b+1]=='w'||board[a+1][b+1]=='W')){
                            t=0;
                            counter=0;
                            while(t<k-1){
                                c=int(valid_moves[i][t][0])-97;
                                d=int(valid_moves[i][t][1])-49;
                                e=int(valid_moves[i][t+1][0])-97;
                                f=int(valid_moves[i][t+1][1])-49;
                                if((c==a&&d==b&&e==(a+2)&&f==(b+2))||(c==(a+2)&&d==(b+2)&&e==a&&f==b)){
                                    counter+=1;
                                }
                                t++;
                                
                            }
                            if(counter==0){
                                j++;
                                t=0;
                                while(t<k){
                                    valid_moves[j][t]=valid_moves[i][t];
                                    t++;
                                }
                                valid_moves[j][t]=char(97+(a+2))+to_string((b+2)+1);
                                
                            }
                        }
                        if(b<6&&a>1&&board[a-2][b+2]=='.'&&(board[a-1][b+1]=='w'||board[a-1][b+1]=='W')){
                            t=0;
                            counter=0;
                            while(t<k-1){
                                c=int(valid_moves[i][t][0])-97;
                                d=int(valid_moves[i][t][1])-49;
                                e=int(valid_moves[i][t+1][0])-97;
                                f=int(valid_moves[i][t+1][1])-49;
                                if((c==a&&d==b&&e==(a-2)&&f==(b+2))||(c==(a-2)&&d==(b+2)&&e==a&&f==b)){
                                    counter+=1;
                                }
                                t++;
                                
                            }
                            if(counter==0){
                                j++;
                                t=0;
                                while(t<k){
                                    valid_moves[j][t]=valid_moves[i][t];
                                    t++;
                                }
                                valid_moves[j][t]=char(97+(a-2))+to_string((b+2)+1);
                                
                            }
                        }
                        if(j>temp){
                            for(io=i+1;io<=j;io++){
                                k=0;t=0;
                                while(valid_moves[io][k]!="O"){
                                    k++;
                                }
                                while(t<k){
                                    valid_moves[io-1][t]=valid_moves[io][t];
                                    t++;
                                }
                            }
                            t=0;
                            while(t<k){
                                valid_moves[j][t]="O";
                                t++;
                            }
                            j--;
                        }else{
                            i++;
                        }
                    }
                    vm=i;
                }
                else if(player_color=="WHITE"&&(board[x+1][y+1]=='b'||board[x+1][y+1]=='B')){
                    valid_moves[vm][0]=char(97+x)+to_string(y+1);
                    valid_moves[vm][1]=char(97+(x+2))+to_string((y+2)+1);
                    i=vm;
                    j=i;
                    while(i<=j){
                        k=0;temp=j;
                        while(valid_moves[i][k]!="O"){
                            k++;
                        }
                        a=int(valid_moves[i][k-1][0])-97;
                        b=int(valid_moves[i][k-1][1])-49;
                        if(b>1&&a<6&&board[a+2][b-2]=='.'&&(board[a+1][b-1]=='b'||board[a+1][b-1]=='B')){
                            t=0;
                            counter=0;
                            while(t<k-1){
                                c=int(valid_moves[i][t][0])-97;
                                d=int(valid_moves[i][t][1])-49;
                                e=int(valid_moves[i][t+1][0])-97;
                                f=int(valid_moves[i][t+1][1])-49;
                                if((c==a&&d==b&&e==(a+2)&&f==(b-2))||(c==(a+2)&&d==(b-2)&&e==a&&f==b)){
                                    counter+=1;
                                }
                                t++;
                                
                            }
                            if(counter==0){
                                j++;
                                t=0;
                                while(t<k){
                                    valid_moves[j][t]=valid_moves[i][t];
                                    t++;
                                }
                                valid_moves[j][t]=char(97+(a+2))+to_string((b-2)+1);
                                
                            }
                        }
                        if(b>1&&a>1&&board[a-2][b-2]=='.'&&(board[a-1][b-1]=='b'||board[a-1][b-1]=='B')){
                            t=0;
                            counter=0;
                            while(t<k-1){
                                c=int(valid_moves[i][t][0])-97;
                                d=int(valid_moves[i][t][1])-49;
                                e=int(valid_moves[i][t+1][0])-97;
                                f=int(valid_moves[i][t+1][1])-49;
                                if((c==a&&d==b&&e==(a-2)&&f==(b-2))||(c==(a-2)&&d==(b-2)&&e==a&&f==b)){
                                    counter+=1;
                                }
                                t++;
                                
                            }
                            if(counter==0){
                                j++;
                                t=0;
                                while(t<k){
                                    valid_moves[j][t]=valid_moves[i][t];
                                    t++;
                                }
                                valid_moves[j][t]=char(97+(a-2))+to_string((b-2)+1);
                                
                            }
                        }
                        if(b<6&&a<6&&board[a+2][b+2]=='.'&&(board[a+1][b+1]=='b'||board[a+1][b+1]=='B')){
                            t=0;
                            counter=0;
                            while(t<k-1){
                                c=int(valid_moves[i][t][0])-97;
                                d=int(valid_moves[i][t][1])-49;
                                e=int(valid_moves[i][t+1][0])-97;
                                f=int(valid_moves[i][t+1][1])-49;
                                if((c==a&&d==b&&e==(a+2)&&f==(b+2))||(c==(a+2)&&d==(b+2)&&e==a&&f==b)){
                                    counter+=1;
                                }
                                t++;
                                
                            }
                            if(counter==0){
                                j++;
                                t=0;
                                while(t<k){
                                    valid_moves[j][t]=valid_moves[i][t];
                                    t++;
                                }
                                valid_moves[j][t]=char(97+(a+2))+to_string((b+2)+1);
                                
                            }
                        }
                        if(b<6&&a>1&&board[a-2][b+2]=='.'&&(board[a-1][b+1]=='b'||board[a-1][b+1]=='B')){
                            t=0;
                            counter=0;
                            while(t<k-1){
                                c=int(valid_moves[i][t][0])-97;
                                d=int(valid_moves[i][t][1])-49;
                                e=int(valid_moves[i][t+1][0])-97;
                                f=int(valid_moves[i][t+1][1])-49;
                                if((c==a&&d==b&&e==(a-2)&&f==(b+2))||(c==(a-2)&&d==(b+2)&&e==a&&f==b)){
                                    counter+=1;
                                }
                                t++;
                                
                            }
                            if(counter==0){
                                j++;
                                t=0;
                                while(t<k){
                                    valid_moves[j][t]=valid_moves[i][t];
                                    t++;
                                }
                                valid_moves[j][t]=char(97+(a-2))+to_string((b+2)+1);
                                
                            }
                        }
                        if(j>temp){
                            for(io=i+1;io<=j;io++){
                                k=0;t=0;
                                while(valid_moves[io][k]!="O"){
                                    k++;
                                }
                                while(t<k){
                                    valid_moves[io-1][t]=valid_moves[io][t];
                                    t++;
                                }
                            }
                            t=0;
                            while(t<k){
                                valid_moves[j][t]="O";
                                t++;
                            }
                            j--;
                        }else{
                            i++;
                        }
                    }
                    vm=i;
                }
            }
            if(y<6&&x>1&&board[x-2][y+2]=='.'){
                if(player_color=="BLACK"&&(board[x-1][y+1]=='w'||board[x-1][y+1]=='W')){
                    valid_moves[vm][0]=char(97+x)+to_string(y+1);
                    valid_moves[vm][1]=char(97+(x-2))+to_string((y+2)+1);
                    i=vm;
                    j=i;
                    while(i<=j){
                        k=0;temp=j;
                        while(valid_moves[i][k]!="O"){
                            k++;
                        }
                        a=int(valid_moves[i][k-1][0])-97;
                        b=int(valid_moves[i][k-1][1])-49;
                        if(b>1&&a<6&&board[a+2][b-2]=='.'&&(board[a+1][b-1]=='w'||board[a+1][b-1]=='W')){
                            t=0;
                            counter=0;
                            while(t<k-1){
                                c=int(valid_moves[i][t][0])-97;
                                d=int(valid_moves[i][t][1])-49;
                                e=int(valid_moves[i][t+1][0])-97;
                                f=int(valid_moves[i][t+1][1])-49;
                                if((c==a&&d==b&&e==(a+2)&&f==(b-2))||(c==(a+2)&&d==(b-2)&&e==a&&f==b)){
                                    counter+=1;
                                }
                                t++;
                                
                            }
                            if(counter==0){
                                j++;
                                t=0;
                                while(t<k){
                                    valid_moves[j][t]=valid_moves[i][t];
                                    t++;
                                }
                                valid_moves[j][t]=char(97+(a+2))+to_string((b-2)+1);
                                
                            }
                        }
                        if(b>1&&a>1&&board[a-2][b-2]=='.'&&(board[a-1][b-1]=='w'||board[a-1][b-1]=='W')){
                            t=0;
                            counter=0;
                            while(t<k-1){
                                c=int(valid_moves[i][t][0])-97;
                                d=int(valid_moves[i][t][1])-49;
                                e=int(valid_moves[i][t+1][0])-97;
                                f=int(valid_moves[i][t+1][1])-49;
                                if((c==a&&d==b&&e==(a-2)&&f==(b-2))||(c==(a-2)&&d==(b-2)&&e==a&&f==b)){
                                    counter+=1;
                                }
                                t++;
                                
                            }
                            if(counter==0){
                                j++;
                                t=0;
                                while(t<k){
                                    valid_moves[j][t]=valid_moves[i][t];
                                    t++;
                                }
                                valid_moves[j][t]=char(97+(a-2))+to_string((b-2)+1);
                                
                            }
                        }
                        if(b<6&&a<6&&board[a+2][b+2]=='.'&&(board[a+1][b+1]=='w'||board[a+1][b+1]=='W')){
                            t=0;
                            counter=0;
                            while(t<k-1){
                                c=int(valid_moves[i][t][0])-97;
                                d=int(valid_moves[i][t][1])-49;
                                e=int(valid_moves[i][t+1][0])-97;
                                f=int(valid_moves[i][t+1][1])-49;
                                if((c==a&&d==b&&e==(a+2)&&f==(b+2))||(c==(a+2)&&d==(b+2)&&e==a&&f==b)){
                                    counter+=1;
                                }
                                t++;
                                
                            }
                            if(counter==0){
                                j++;
                                t=0;
                                while(t<k){
                                    valid_moves[j][t]=valid_moves[i][t];
                                    t++;
                                }
                                valid_moves[j][t]=char(97+(a+2))+to_string((b+2)+1);
                                
                            }
                        }
                        if(b<6&&a>1&&board[a-2][b+2]=='.'&&(board[a-1][b+1]=='w'||board[a-1][b+1]=='W')){
                            t=0;
                            counter=0;
                            while(t<k-1){
                                c=int(valid_moves[i][t][0])-97;
                                d=int(valid_moves[i][t][1])-49;
                                e=int(valid_moves[i][t+1][0])-97;
                                f=int(valid_moves[i][t+1][1])-49;
                                if((c==a&&d==b&&e==(a-2)&&f==(b+2))||(c==(a-2)&&d==(b+2)&&e==a&&f==b)){
                                    counter+=1;
                                }
                                t++;
                                
                            }
                            if(counter==0){
                                j++;
                                t=0;
                                while(t<k){
                                    valid_moves[j][t]=valid_moves[i][t];
                                    t++;
                                }
                                valid_moves[j][t]=char(97+(a-2))+to_string((b+2)+1);
                                
                            }
                        }
                        if(j>temp){
                            for(io=i+1;io<=j;io++){
                                k=0;t=0;
                                while(valid_moves[io][k]!="O"){
                                    k++;
                                }
                                while(t<k){
                                    valid_moves[io-1][t]=valid_moves[io][t];
                                    t++;
                                }
                            }
                            t=0;
                            while(t<k){
                                valid_moves[j][t]="O";
                                t++;
                            }
                            j--;
                        }else{
                            i++;
                        }
                    }
                    vm=i;
                }
                else if(player_color=="WHITE"&&(board[x-1][y+1]=='b'||board[x-1][y+1]=='B')){
                    valid_moves[vm][0]=char(97+x)+to_string(y+1);
                    valid_moves[vm][1]=char(97+(x-2))+to_string((y+2)+1);
                    i=vm;
                    j=i;
                    while(i<=j){
                        k=0;temp=j;
                        while(valid_moves[i][k]!="O"){
                            k++;
                        }
                        a=int(valid_moves[i][k-1][0])-97;
                        b=int(valid_moves[i][k-1][1])-49;
                        if(b>1&&a<6&&board[a+2][b-2]=='.'&&(board[a+1][b-1]=='b'||board[a+1][b-1]=='B')){
                            t=0;
                            counter=0;
                            while(t<k-1){
                                c=int(valid_moves[i][t][0])-97;
                                d=int(valid_moves[i][t][1])-49;
                                e=int(valid_moves[i][t+1][0])-97;
                                f=int(valid_moves[i][t+1][1])-49;
                                if((c==a&&d==b&&e==(a+2)&&f==(b-2))||(c==(a+2)&&d==(b-2)&&e==a&&f==b)){
                                    counter+=1;
                                }
                                t++;
                                
                            }
                            if(counter==0){
                                j++;
                                t=0;
                                while(t<k){
                                    valid_moves[j][t]=valid_moves[i][t];
                                    t++;
                                }
                                valid_moves[j][t]=char(97+(a+2))+to_string((b-2)+1);
                                
                            }
                        }
                        if(b>1&&a>1&&board[a-2][b-2]=='.'&&(board[a-1][b-1]=='b'||board[a-1][b-1]=='B')){
                            t=0;
                            counter=0;
                            while(t<k-1){
                                c=int(valid_moves[i][t][0])-97;
                                d=int(valid_moves[i][t][1])-49;
                                e=int(valid_moves[i][t+1][0])-97;
                                f=int(valid_moves[i][t+1][1])-49;
                                if((c==a&&d==b&&e==(a-2)&&f==(b-2))||(c==(a-2)&&d==(b-2)&&e==a&&f==b)){
                                    counter+=1;
                                }
                                t++;
                                
                            }
                            if(counter==0){
                                j++;
                                t=0;
                                while(t<k){
                                    valid_moves[j][t]=valid_moves[i][t];
                                    t++;
                                }
                                valid_moves[j][t]=char(97+(a-2))+to_string((b-2)+1);
                                
                            }
                        }
                        if(b<6&&a<6&&board[a+2][b+2]=='.'&&(board[a+1][b+1]=='b'||board[a+1][b+1]=='B')){
                            t=0;
                            counter=0;
                            while(t<k-1){
                                c=int(valid_moves[i][t][0])-97;
                                d=int(valid_moves[i][t][1])-49;
                                e=int(valid_moves[i][t+1][0])-97;
                                f=int(valid_moves[i][t+1][1])-49;
                                if((c==a&&d==b&&e==(a+2)&&f==(b+2))||(c==(a+2)&&d==(b+2)&&e==a&&f==b)){
                                    counter+=1;
                                }
                                t++;
                                
                            }
                            if(counter==0){
                                j++;
                                t=0;
                                while(t<k){
                                    valid_moves[j][t]=valid_moves[i][t];
                                    t++;
                                }
                                valid_moves[j][t]=char(97+(a+2))+to_string((b+2)+1);
                                
                            }
                        }
                        if(b<6&&a>1&&board[a-2][b+2]=='.'&&(board[a-1][b+1]=='b'||board[a-1][b+1]=='B')){
                            t=0;
                            counter=0;
                            while(t<k-1){
                                c=int(valid_moves[i][t][0])-97;
                                d=int(valid_moves[i][t][1])-49;
                                e=int(valid_moves[i][t+1][0])-97;
                                f=int(valid_moves[i][t+1][1])-49;
                                if((c==a&&d==b&&e==(a-2)&&f==(b+2))||(c==(a-2)&&d==(b+2)&&e==a&&f==b)){
                                    counter+=1;
                                }
                                t++;
                                
                            }
                            if(counter==0){
                                j++;
                                t=0;
                                while(t<k){
                                    valid_moves[j][t]=valid_moves[i][t];
                                    t++;
                                }
                                valid_moves[j][t]=char(97+(a-2))+to_string((b+2)+1);
                                
                            }
                        }
                        if(j>temp){
                            for(io=i+1;io<=j;io++){
                                k=0;t=0;
                                while(valid_moves[io][k]!="O"){
                                    k++;
                                }
                                while(t<k){
                                    valid_moves[io-1][t]=valid_moves[io][t];
                                    t++;
                                }
                            }
                            t=0;
                            while(t<k){
                                valid_moves[j][t]="O";
                                t++;
                            }
                            j--;
                        }else{
                            i++;
                        }
                    }
                    vm=i;
                }
            }
            //taking steps
            if(y>0&&x<7&&board[x+1][y-1]=='.'){
                valid_moves[vm][0]=char(97+x)+to_string(y+1);
                valid_moves[vm][1]=char(97+(x+1))+to_string((y-1)+1);
                vm++;
            }
            if(y>0&&x>0&&board[x-1][y-1]=='.'){
                valid_moves[vm][0]=char(97+x)+to_string(y+1);
                valid_moves[vm][1]=char(97+(x-1))+to_string((y-1)+1);
                vm++;
            }
            if(y<7&&x<7&&board[x+1][y+1]=='.'){
                valid_moves[vm][0]=char(97+x)+to_string(y+1);
                valid_moves[vm][1]=char(97+(x+1))+to_string((y+1)+1);
                vm++;
            }
            if(y<7&&x>0&&board[x-1][y+1]=='.'){
                valid_moves[vm][0]=char(97+x)+to_string(y+1);
                valid_moves[vm][1]=char(97+(x-1))+to_string((y+1)+1);
                vm++;
            }
            board[x][y]=char(player_color[0]);
        }
        else{//for regular pieces
            if(player_color=="BLACK"&&y>1){//jump
                if(x<6&&board[x+2][y-2]=='.'&&(board[x+1][y-1]=='w'||board[x+1][y-1]=='W')){
                    valid_moves[vm][0]=char(97+x)+to_string(y+1);
                    valid_moves[vm][1]=char(97+(x+2))+to_string((y-2)+1);
                    i=vm;
                    j=i;
                    while(i<=j){
                        k=0;temp=j;
                        while(valid_moves[i][k]!="O"){
                            k++;
                        }
                        a=int(valid_moves[i][k-1][0])-97;
                        b=int(valid_moves[i][k-1][1])-49;
                        if(b>1&&a<6&&board[a+2][b-2]=='.'&&(board[a+1][b-1]=='w'||board[a+1][b-1]=='W')){
                            j++;
                            t=0;
                            while(t<k){
                                valid_moves[j][t]=valid_moves[i][t];
                                t++;
                            }
                            valid_moves[j][t]=char(97+(a+2))+to_string((b-2)+1);
                        }
                        if(b>1&&a>1&&board[a-2][b-2]=='.'&&(board[a-1][b-1]=='w'|board[a-1][b-1]=='W')){
                            j++;
                            t=0;
                            while(t<k){
                                valid_moves[j][t]=valid_moves[i][t];
                                t++;
                            }
                            valid_moves[j][t]=char(97+(a-2))+to_string((b-2)+1);
                        }
                        if(j>temp){
                            for(io=i+1;io<=j;io++){
                                k=0;t=0;
                                while(valid_moves[io][k]!="O"){
                                    k++;
                                }
                                while(t<k){
                                    valid_moves[io-1][t]=valid_moves[io][t];
                                    t++;
                                }
                            }
                            t=0;
                            while(t<k){
                                valid_moves[j][t]="O";
                                t++;
                            }
                            j--;
                        }else{
                            i++;
                        }
                        
                    }
                    vm=i;
                }
                if(x>1&&board[x-2][y-2]=='.'&&(board[x-1][y-1]=='w'|board[x-1][y-1]=='W')){
                    valid_moves[vm][0]=char(97+x)+to_string(y+1);
                    valid_moves[vm][1]=char(97+(x-2))+to_string((y-2)+1);
                    i=vm;
                    j=i;
                    while(i<=j){
                        k=0;temp=j;
                        while(valid_moves[i][k]!="O"){
                            k++;
                        }
                        a=int(valid_moves[i][k-1][0])-97;
                        b=int(valid_moves[i][k-1][1])-49;
                        if(b>1&&a<6&&board[a+2][b-2]=='.'&&(board[a+1][b-1]=='w'||board[a+1][b-1]=='W')){
                            j++;
                            t=0;
                            while(t<k){
                                valid_moves[j][t]=valid_moves[i][t];
                                t++;
                            }
                            valid_moves[j][t]=char(97+(a+2))+to_string((b-2)+1);
                        }
                        if(b>1&&a>1&&board[a-2][b-2]=='.'&&(board[a-1][b-1]=='w'|board[a-1][b-1]=='W')){
                            j++;
                            t=0;
                            while(t<k){
                                valid_moves[j][t]=valid_moves[i][t];
                                t++;
                            }
                            valid_moves[j][t]=char(97+(a-2))+to_string((b-2)+1);
                        }
                        if(j>temp){
                            for(io=i+1;io<=j;io++){
                                k=0;t=0;
                                while(valid_moves[io][k]!="O"){
                                    k++;
                                }
                                while(t<k){
                                    valid_moves[io-1][t]=valid_moves[io][t];
                                    t++;
                                }
                            }
                            t=0;
                            while(t<k){
                                valid_moves[j][t]="O";
                                t++;
                            }
                            j--;
                        }else{
                            i++;
                        }
                    }
                    vm=i;
                }
            }
            if(player_color=="BLACK"&&y>0){//step
                if(x<7&&board[x+1][y-1]=='.'){
                    valid_moves[vm][0]=char(97+x)+to_string(y+1);
                    valid_moves[vm][1]=char(97+(x+1))+to_string((y-1)+1);
                    vm++;
                }
                if(x>0&&board[x-1][y-1]=='.'){
                    valid_moves[vm][0]=char(97+x)+to_string(y+1);
                    valid_moves[vm][1]=char(97+(x-1))+to_string((y-1)+1);
                    vm++;
                }
            }
            if(player_color=="WHITE"&&y<6){//jump
                if(x<6&&board[x+2][y+2]=='.'&&(board[x+1][y+1]=='b'||board[x+1][y+1]=='B')){
                    valid_moves[vm][0]=char(97+x)+to_string(y+1);
                    valid_moves[vm][1]=char(97+(x+2))+to_string((y+2)+1);
                    i=vm;
                    j=i;
                    while(i<=j){
                        k=0;temp=j;
                        while(valid_moves[i][k]!="O"){
                            k++;
                        }
                        a=int(valid_moves[i][k-1][0])-97;
                        b=int(valid_moves[i][k-1][1])-49;
                        if(b<6&&a<6&&board[a+2][b+2]=='.'&&(board[a+1][b+1]=='b'||board[a+1][b+1]=='B')){
                            j++;
                            t=0;
                            while(t<k){
                                valid_moves[j][t]=valid_moves[i][t];
                                t++;
                            }
                            valid_moves[j][t]=char(97+(a+2))+to_string((b+2)+1);
                        }
                        if(b<6&&a>1&&board[a-2][b+2]=='.'&&(board[a-1][b+1]=='b'||board[a-1][b+1]=='B')){
                            j++;
                            t=0;
                            while(t<k){
                                valid_moves[j][t]=valid_moves[i][t];
                                t++;
                            }
                            valid_moves[j][t]=char(97+(a-2))+to_string((b+2)+1);
                        }
                        if(j>temp){
                            for(io=i+1;io<=j;io++){
                                k=0;t=0;
                                while(valid_moves[io][k]!="O"){
                                    k++;
                                }
                                while(t<k){
                                    valid_moves[io-1][t]=valid_moves[io][t];
                                    t++;
                                }
                            }
                            t=0;
                            while(t<k){
                                valid_moves[j][t]="O";
                                t++;
                            }
                            j--;
                        }else{
                            i++;
                        }
                    }
                    vm=i;
                }
                if(x>1&&board[x-2][y+2]=='.'&&(board[x-1][y+1]=='b'||board[x-1][y+1]=='B')){
                    valid_moves[vm][0]=char(97+x)+to_string(y+1);
                    valid_moves[vm][1]=char(97+(x-2))+to_string((y+2)+1);
                    i=vm;
                    j=i;
                    while(i<=j){
                        k=0;temp=j;
                        while(valid_moves[i][k]!="O"){
                            k++;
                        }
                        a=int(valid_moves[i][k-1][0])-97;
                        b=int(valid_moves[i][k-1][1])-49;
                        if(b<6&&a<6&&board[a+2][b+2]=='.'&&(board[a+1][b+1]=='b'||board[a+1][b+1]=='B')){
                            j++;
                            t=0;
                            while(t<k){
                                valid_moves[j][t]=valid_moves[i][t];
                                t++;
                            }
                            valid_moves[j][t]=char(97+(a+2))+to_string((b+2)+1);
                        }
                        if(b<6&&a>1&&board[a-2][b+2]=='.'&&(board[a-1][b+1]=='b'||board[a-1][b+1]=='B')){
                            j++;
                            t=0;
                            while(t<k){
                                valid_moves[j][t]=valid_moves[i][t];
                                t++;
                            }
                            valid_moves[j][t]=char(97+(a-2))+to_string((b+2)+1);
                        }
                        if(j>temp){
                            for(io=i+1;io<=j;io++){
                                k=0;t=0;
                                while(valid_moves[io][k]!="O"){
                                    k++;
                                }
                                while(t<k){
                                    valid_moves[io-1][t]=valid_moves[io][t];
                                    t++;
                                }
                            }
                            t=0;
                            while(t<k){
                                valid_moves[j][t]="O";
                                t++;
                            }
                            j--;
                        }else{
                            i++;
                        }
                    }
                    vm=i;
                }
                
            }
            if(player_color=="WHITE"&&y<7){//step
                if(x<7&&board[x+1][y+1]=='.'){
                    valid_moves[vm][0]=char(97+x)+to_string(y+1);
                    valid_moves[vm][1]=char(97+(x+1))+to_string((y+1)+1);
                    vm++;
                }
                if(x>0&&board[x-1][y+1]=='.'){
                    valid_moves[vm][0]=char(97+x)+to_string(y+1);
                    valid_moves[vm][1]=char(97+(x-1))+to_string((y+1)+1);
                    vm++;
                }
                
            }
            
            
        }
        p++;
    }
    
    return valid_moves;
    
    
}

int evaluate(char board[8][8],string player_color,string current_color, vector<vector<string>> valid_moves){
    int height=8,width=8,h=0,w=0;
    int black_piece=0, white_piece=0, king_white_piece=0, king_black_piece=0, win_condition=0,last_black_piece=0,last_white_piece=0,row_black=0,row_white=0;
    if(player_color==current_color&&valid_moves[0][0]=="O"){
        win_condition-=2000;
    }
    else if(player_color!=current_color&&valid_moves[0][0]=="O"){
        win_condition+=2000;
    }
    while(h<height){
        if(board[w][h]=='b'||board[w][h]=='B'){
            black_piece+=1;
            
        }
        if(board[w][h]=='w'||board[w][h]=='W'){
            white_piece+=1;
            
        }
        if(board[w][h]=='B'){
            king_black_piece+=1;
        }
        if(board[w][h]=='W'){
            king_white_piece+=1;
        }
        if(board[w][h]=='b'){
            row_black+=8-h;
        }
        if(board[w][h]=='w'){
            row_white+=h+1;
        }
        if(board[w][h]=='b'&&h==7){
            last_black_piece+=1;
        }
        if(board[w][h]=='w'&&h==0){
            last_white_piece+=1;
        }
        w++;
        //cout<<char(97+w-1)+to_string(h+1)<<" ";
        if(w==width){
            w=0;
            h++;
            //cout<<endl;
        }
        
    }
    
    if(player_color=="BLACK"){
        return row_black-row_white+(25*black_piece)-(25*white_piece)+(12*king_black_piece)-(10*king_white_piece)+(2*last_black_piece)+win_condition;//+jump_points((5*black_piece)-(25*white_piece));//10*(king_black_piece-king_white_piece)+win_condition;//row_black;//+win_condition+last_black_piece+5*row_black;
    }
    else{
        return row_white-row_black+(25*white_piece)-(25*black_piece)+(12*king_white_piece)-(10*king_black_piece)+(2*last_white_piece)+win_condition;//+jump_points((5*white_piece)-(25*black_piece));//+10*(king_white_piece-king_black_piece)+win_condition;//row_white;//+win_condition+last_white_piece+5*row_white;
    }
    
}


struct Statespace minmax_multijump(struct Statespace node,string player_color,string current_color,int depth, vector<vector<string>> valid_moves,int alpha,int beta){
    int vm=0,height=8,width=8,h,w,m,n,x,y,k,t,flag;
    struct Statespace node2, node3, best_node;
    //int temp_jump_points;
    vector<vector<string>> valid_moves2( 80 , vector<string> (12, "O"));
    if (depth==0||valid_moves[0][0]=="O"){
        node.path[0]="O";
        node.score = evaluate(node.board,player_color,current_color,valid_moves);
        return node;
    }
    k=0;flag=0;
    while(k<80&&valid_moves[k][0]!="O"){

        m=int(valid_moves[k][0][0])-97;
        n=int(valid_moves[k][0][1])-49;
        x=int(valid_moves[k][1][0])-97;
        y=int(valid_moves[k][1][1])-49;
        if((m+2==x||m-2==x)&&(n+2==y||n-2==y)){
            flag=1;
            break;
        }
        k++;
    }
    if(player_color==current_color){//MAX_function
        best_node.score = INT_MIN;
        while(vm<80&&valid_moves[vm][0]!="O"){
            
            m=int(valid_moves[vm][0][0])-97;
            n=int(valid_moves[vm][0][1])-49;
            x=int(valid_moves[vm][1][0])-97;
            y=int(valid_moves[vm][1][1])-49;
            if(flag==1&&(m+1==x||m-1==x)&&(n+1==y||n-1==y)){
                vm++;
                continue;
            }
            
            h=0;w=0;
            //temp_jump_points=jump_points;
            while(h<height){
                node2.board[w][h]=node.board[w][h];
                w++;
                //cout<<char(97+w-1)+to_string(h+1)<<" ";
                if(w==width){
                    w=0;
                    h++;
                    //cout<<endl;
                }
            }
            
            
            if((m+1==x||m-1==x)&&(n+1==y||n-1==y)){
            
                node2.board[x][y]=node2.board[m][n];
                node2.board[m][n]='.';
            }else{
                //temp_jump_points+=depth;
                k=0;t=0;
                while(valid_moves[vm][k]!="O"){
                    k++;
                }
                while(t<k-1){
                    m=int(valid_moves[vm][t][0])-97;
                    n=int(valid_moves[vm][t][1])-49;
                    x=int(valid_moves[vm][t+1][0])-97;
                    y=int(valid_moves[vm][t+1][1])-49;
                    node2.board[x][y]=node2.board[m][n];
                    node2.board[m][n]='.';
                    node2.board[(m+x)/2][(n+y)/2]='.';
                    t++;
                }
                
            }
            if(y==0||y==7){
                node2.board[x][y]=char(toupper(node2.board[x][y]));
            }
            if(current_color=="BLACK"){
                valid_moves2 = All_valid_moves_multijump(node2.board,"WHITE");
                node3 = minmax_multijump(node2,player_color,"WHITE",depth-1,valid_moves2,alpha,beta);
                
            }else{
                valid_moves2 = All_valid_moves_multijump(node2.board,"BLACK");
                node3 = minmax_multijump(node2,player_color,"BLACK",depth-1,valid_moves2,alpha,beta);
                
            }
            node2.score=node3.score;
            if(node2.score>best_node.score){
                    best_node.score=node2.score;
                    h=0;w=0;t=0;
                    while(h<height){
                        best_node.board[w][h]=node2.board[w][h];
                        w++;
                        //cout<<char(97+w-1)+to_string(h+1)<<" ";
                        if(w==width){
                            w=0;
                            h++;
                            //cout<<endl;
                        }
                    }
                    while(t<12){
                        best_node.path[t]=valid_moves[vm][t];
                        t++;
                    }
                    //best_node.board=node2.board;
            }
            alpha = (alpha > best_node.score) ? alpha : best_node.score;
            if(alpha >= beta){
                break;
            }
            //cout<<valid_moves[vm][0]<<","<<valid_moves[vm][1]<<" Cost: "<<node3.score<<endl;
            vm++;
        }
        return best_node;
        
    }else{//MIN_function
        best_node.score = INT_MAX;
        while(vm<80&&valid_moves[vm][0]!="O"){
            
            m=int(valid_moves[vm][0][0])-97;
            n=int(valid_moves[vm][0][1])-49;
            x=int(valid_moves[vm][1][0])-97;
            y=int(valid_moves[vm][1][1])-49;
            if(flag==1&&(m+1==x||m-1==x)&&(n+1==y||n-1==y)){
                vm++;
                continue;
            }
            
            h=0;w=0;
            //temp_jump_points=jump_points;
            while(h<height){
                node2.board[w][h]=node.board[w][h];
                w++;
                //cout<<char(97+w-1)+to_string(h+1)<<" ";
                if(w==width){
                    w=0;
                    h++;
                    //cout<<endl;
                }
            }
            
            
            if((m+1==x||m-1==x)&&(n+1==y||n-1==y)){
            
                node2.board[x][y]=node2.board[m][n];
                node2.board[m][n]='.';
            }else{
                //temp_jump_points+=depth;
                k=0;t=0;
                while(valid_moves[vm][k]!="O"){
                    k++;
                }
                while(t<k-1){
                    m=int(valid_moves[vm][t][0])-97;
                    n=int(valid_moves[vm][t][1])-49;
                    x=int(valid_moves[vm][t+1][0])-97;
                    y=int(valid_moves[vm][t+1][1])-49;
                    node2.board[x][y]=node2.board[m][n];
                    node2.board[m][n]='.';
                    node2.board[(m+x)/2][(n+y)/2]='.';
                    t++;
                }
                
            }
            if(y==0||y==7){
                node2.board[x][y]=char(toupper(node2.board[x][y]));
            }
            if(current_color=="BLACK"){
                valid_moves2 = All_valid_moves_multijump(node2.board,"WHITE");
                node3 = minmax_multijump(node2,player_color,"WHITE",depth-1,valid_moves2,alpha,beta);
                
            }else{
                valid_moves2 = All_valid_moves_multijump(node2.board,"BLACK");
                node3 = minmax_multijump(node2,player_color,"BLACK",depth-1,valid_moves2,alpha,beta);
                
            }
            node2.score=node3.score;
            if(node2.score<best_node.score){
                    best_node.score=node2.score;
                    h=0;w=0;t=0;
                    while(h<height){
                        best_node.board[w][h]=node2.board[w][h];
                        w++;
                        //cout<<char(97+w-1)+to_string(h+1)<<" ";
                        if(w==width){
                            w=0;
                            h++;
                            //cout<<endl;
                        }
                        while(t<12){
                            best_node.path[t]=valid_moves[vm][t];
                            t++;
                        }
                    }
                    //best_node.board=node2.board;
            }
            beta = (beta < best_node.score) ? beta : best_node.score;
            if(alpha >= beta){
                break;
            }
            //cout<<valid_moves[vm][0]<<","<<valid_moves[vm][1]<<" Cost: "<<node3.score<<endl;
            vm++;
        }
        return best_node;
    }
}

int main()
{
    
    string game_type, player_color, play_type;
    int x=-1,y=-1,m=-1,n=-1,temp_x,temp_y, alpha=INT_MIN,beta=INT_MAX, no_of_moves_left,depth=6;//jump_points=0;
    float time_left,time_for_move=0.0;
    int height=8,width=8,h=7,w=0,t=0;
    //vector<vector<int>> positions( 12 , vector<int> (2, -1));
    vector<string> positions_mj( 12 , "O");
    //vector<vector<int>> valid_moves( 48 , vector<int> (4, -1));
    vector<vector<string>> valid_moves_mj( 80 , vector<string> (12, "O"));
    ifstream input_file("input.txt");
    ofstream output_file("output.txt");
    input_file>>game_type>>player_color>>time_left;
   
    struct Statespace node,best_node;
    while(h>=0){
        input_file>>node.board[w][h];
        //cout<<char(97+w)+to_string(h+1)<<" ";
        w++;
        
        if(w==width){
            w=0;
            h--;
            //cout<<endl;
        }
    }
    input_file.close();
   
    //cout<<"hello";
    valid_moves_mj = All_valid_moves_multijump(node.board,player_color);
    
    
    if(game_type=="SINGLE"){
        time_for_move=time_left;
    }else if(game_type=="GAME"){
        
        ifstream file("playdata.txt");
        if (file.is_open())
        {
            file>>no_of_moves_left;
            file.close();
            
        }else{
            no_of_moves_left=50;
            
        }
        ofstream file_play("playdata.txt");
        file_play<<(no_of_moves_left-1);
        file_play.close();
        
        if(no_of_moves_left<=0){
            time_for_move=-1;
        }else{
            time_for_move=time_left/no_of_moves_left;
        }
        
    }
    
    if(time_for_move>=6||time_for_move==-1){
        depth=6;
    }
    else if(time_for_move>=2.5&&time_for_move<6){
        depth=4;
    }
    else if(time_for_move>=0&&time_for_move<2.5){
        depth=2;
    }
    //depth=8;
    best_node=minmax_multijump(node,player_color,player_color,depth,valid_moves_mj,alpha,beta);
    
    
     /*         
    h=7;
    w=0;
    while(h>=0){
        cout<<best_node.board[w][h];
        w++;
        //cout<<char(97+w-1)+to_string(h+1)<<" ";
        if(w==width){
            w=0;
            h--;
            cout<<endl;
        }
    }
    cout<<endl;
     */
    if(best_node.path[0]!="O"){
        m=int(best_node.path[0][0])-97;
        n=int(best_node.path[0][1])-49;
        x=int(best_node.path[1][0])-97;
        y=int(best_node.path[1][1])-49;
        
        if((m+1==x||m-1==x)&&(n+1==y||n-1==y)){
            output_file<<"E "<<best_node.path[0]<<" "<<best_node.path[1]<<endl;
        }else{
            while(t<11&&best_node.path[t+1]!="O"){
                output_file<<"J "<<best_node.path[t]<<" "<<best_node.path[t+1]<<endl;
                t++;
            }
        }
    }
    output_file.close();
    
    
    
}