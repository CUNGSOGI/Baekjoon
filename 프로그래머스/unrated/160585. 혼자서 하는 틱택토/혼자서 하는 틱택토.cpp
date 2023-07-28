#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<string> board) {
    int answer = -1;
    int i,j,o=0,x=0,L=0,W=0,W2=0;
    for(i=0;i<board.size();i++){
        for(j=0;j<board[i].size();j++){
            if(board[i][j]=='O') //O개수
                o++;
            else if(board[i][j]=='X') //X개수
                x++;
            if(board[j]=="OOO"&&board[0][i]=='O'&&board[1][i]=='O'&&board[2][i]=='O') //가로 세로 OOO겹칠때
                W2++; 
        }
        if(board[0][i]=='O'&&board[1][i]=='O'&&board[2][i]=='O')//OOO세로 세는거
            W++;
        else if(board[0][i]=='X'&&board[1][i]=='X'&&board[2][i]=='X')//XXX세로 세는거
            L++;
        
        if(board[i]=="OOO")//OOO가로 세는거
            W++;
        else if(board[i]=="XXX")//XXX가로 세는거
            L++;
        
        
        if((((board[0][i]=='O'&&board[1][i]=='O'&&board[2][i]=='O')||board[i]=="OOO")&&board[0][0]=='O'&&board[1][1]=='O'&&board[2][2]=='O')||(((board[0][i]=='O'&&board[1][i]=='O'&&board[2][i]=='O')||board[i]=="OOO")&&board[0][2]=='O'&&board[1][1]=='O'&&board[2][0]=='O')||((board[0][2]=='O'&&board[1][1]=='O'&&board[2][0]=='O')&&(board[0][0]=='O'&&board[1][1]=='O'&&board[2][2]=='O'))) //OOO가로 세로 기울기-1만날때랑 기울기 1이랑 만날때랑 기울기 -1과 1이 만날때
            W2++;
            
    }
    if(board[0][0]=='O'&&board[1][1]=='O'&&board[2][2]=='O')//OOO -1대각선 세는거
        W++;
    else if(board[0][0]=='X'&&board[1][1]=='X'&&board[2][2]=='X') //XXX -1대각선 세는거
        L++;
        
    if(board[0][2]=='O'&&board[1][1]=='O'&&board[2][0]=='O') //OOO 1대각선 세는거
        W++;
    else if(board[0][2]=='X'&&board[1][1]=='X'&&board[2][0]=='X')//XXX 1대각선 세는거
        L++;
    cout<<W<<L;
    if(o<x||o-x>=2)
        return 0;
    else if((W==1&&L==0&&o-x==1)||(W==0&&L==1&&x==o)||(W==0&&L==0)||(W2==1))
        return 1;
    else
        return 0;
}