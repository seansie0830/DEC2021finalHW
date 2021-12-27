//第9版 增加現在玩家名稱與修正錯誤提示
#include<iostream>
#include<windows.h>
#include <conio.h>
using namespace std;

void display(void);

void writeMarks(void);

int judge(void);

int player=-1 ;  //1代表O -1代表X
int map[3][3]={{0,0,0},{0,0,0},{0,0,0}};
int reference[9]={6,7,8,3,4,5,0,1,2};//map的編號


void writeMarks(void){
    int temp;
    int *pointer=&map[0][0];
    temp=getch();
    if(!(temp<58&&temp>48)) {
        cout<<"請按數字鍵"<<endl;
        system("pause");
        return ;
    }
    if(*(pointer+reference[temp-49])==0){
        player=player*(-1);
        *(pointer+reference[temp-49])=player;
    }
    else
    {
        cout<<"請下在沒有下過的地方"<<endl;
        system("pause");
        return ;
    }
    //cout<<"The program has change the value number"<<reference[temp-49]+1<<endl;
    //system("pause");
}

int main (){
    int ctr1,ctr2;//清除棋盤專用變數

    while(1){
        char i=0;

        display();
/* system("pause");*/  // cout<<"-----------------------------------"<<endl;
       // cout<<"the following is the result of input."<<endl;
        writeMarks();
        display();

        if(judge()==1)
        {
            cout <<"o贏了"<<endl<<"按e結束,r重新開始"<<endl;
            i=getch();
        }
        else if (judge()==-1)
        {
            cout <<"x贏了"<<endl<<"按e結束,r重新開始"<<endl;
            i=getch();
        }
        else if (judge()==9){
            cout <<"平手"<<endl<<"按e結束,r重新開始"<<endl;
            i=getch();
        }
        if(i=='e'||i=='E')
        {
            break;
        }
        else if(i=='r'||i=='R')
        {
            player=-1;
            for(/*int*/ ctr1=0;ctr1<3;ctr1++)
            {
                for(/*int*/ ctr2=0;ctr2<3;ctr2++)
                {
                    map[ctr1][ctr2]/*=*/=0;
                }

            }

            display();
        }
    }
    return 0;
}
void display(void){
    system("cls");
    char turnDisplay;
    if(player==-1)turnDisplay='O';
    else turnDisplay='X';
    cout<<"使用數字鍵選擇位置來下棋  現在是"<<turnDisplay<<endl;
    for(int i=0;i<3;i++)
    {
        for (int j=0;j<3 ;j++ )
        {
            // 1代表O  -1代表X  0代表空格  其他是 ?
            if(map[i][j]==1) cout<<" o ";
            else if (map[i][j]==-1) cout<<" x ";
            else if(map[i][j]==0) cout<<"   ";
            if(j<2)cout<<"|";
        }
        cout<<endl;
        if(i<2)cout<<"-----------\n";
    }
}

int judge(){
    int i;
    for(i=0;i<3;i++)//橫
    {
        if(map[i][0]==map[i][1]&&map[i][0]==map[i][2])
        {
            if(map[i][0]==1)
                return 1;
            else if(map[i][0]==-1)    return -1;
        }
    }
    for(i=0;i<3;i++)//直
    {
        if(map[0][i]==map[1][i]&&map[1][i]==map[2][i])
        {
            if(map[0][i]==1)
                return 1;
            else if(map[0][i]==-1)    return -1;
        }
    }
    if(map[0][0]==map[1][1]&&map[1][1]==map[2][2])//左上到右下
    {
        if(map[1][1]==1)
            return 1;
        else if(map[1][1]==-1)    return -1;
    }
    if(map[0][2]==map[1][1]&&map[1][1]==map[2][0])//右上到左下
    {
        if(map[1][1]==1)
            return 1;
        else if(map[1][1]==-1)    return -1;
    }
    int sum=0;
    for(i=0;i<9;i++) sum=sum+abs(*(&map[0][0]+i));
    /*
    .
    .
    以下=代表等價，跟左邊的用法一樣。
    map[0][0]=*(&map[0][0]+0) 位址:0x4ce040
    map[0][1]=*(&map[0][0]+1) 位址:0x4ce040+1(一維的索引值)*int佔的bytes數
    map[0][2]=*(&map[0][0]+2) 位址:0x4ce040+2(一維的索引值)*int佔的bytes數
    map[1][0]=*(&map[0][0]+3) 位址:0x4ce040+3(一維的索引值)*int佔的bytes數
    map[1][1]=*(&map[0][0]+4) 位址:0x4ce040+4(一維的索引值)*int佔的bytes數
               以此類推
               .
               .
               .
    &[變數,元素,資料....]  ->傳回該變數的位址
    *(位址) ->依照位址，將那個位置有的資料當成一個變數使用。
    */
    if(sum==9) return 9;
    return 0;
}
