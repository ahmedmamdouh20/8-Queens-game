#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int const Size = 8 ;
int visited[Size][Size];
char grid [Size][Size] ;

void print_grid ()
{
    for (int i =0 ; i < Size ; i++)
    {
        for (int j = 0 ; j < Size ; j++)
        {
            cout << grid [i][j]<< " " ;
        }
        cout << endl;
    }

}
void grid_intialize ()
{
    for (int i =0 ; i < Size ; i++)
    {
        for (int j = 0 ; j < Size ; j++)
        {
            grid[i][j]='*';
        }
    }
    print_grid();
}
void adjacency_matrix() //initialize 2d matrix
{
    for(int i=0; i<Size; i++)
    {
        for(int j=0; j<Size; j++)
        {
            visited[i][j]=0;
        }
    }
}
bool check_valid(int i, int j) //check validation of row and column
{
    if (i >= 0 && i < Size && j >= 0 && j < Size)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void visit_cells(int row,int col) // to store in matrix adajacent of each inserted cell by 1
{
    int temp; // variable to increment or decrement with loop
    if(col!=Size-1)
    {
        for(int i=col+1; i<Size; i++)
        {
            visited[row][i]=1;
        }
    }
    if(col!=0)
    {
        for(int i=col-1; i>=0; i--)
        {
            visited[row][i]=1;
        }
    }
    if(row!=Size-1)
    {
        for(int i=row+1; i<Size; i++)
        {
            visited[i][col]=1;
        }
    }
    if(row!=0)
    {
        for(int i=row-1; i>=0; i--)
        {
            visited[i][col]=1;
        }
    }
    if(row!=Size-1 && col!=Size-1)
    {
        temp=row+1;
        for(int i=col+1; i<Size; i++)
        {
            visited[temp][i]=1;
            if(i==Size-1||temp==Size-1) // to break if row or col reach size
            {
                break;                  // (5,2) (6,3) (7,4) case of reach max row before col
            }                           // (2,5)  (3,6) (4,7) case of reach max col before row
            temp++;
        }
    }
    if(row!=0 && col!=0)
    {
        temp=row-1;
        for(int i=col-1; i>=0; i--)
        {
            visited[temp][i]=1;
            if(i==0||temp==0) // to break if row or col reach 0
            {
                break;       // (5,2) (4,1) (3,0) case of reach 0 col before row
            }                // (2,5) (1,4) (0,3) case of reach 0 row before col
            temp--;

        }
    }
    if(row!=0 && col!=Size-1)
    {
        temp=row-1;
        for(int i=col+1; i<Size; i++)
        {
            visited[temp][i]=1;
            if(i==Size-1||temp==0)
            {
                break;        //(2,3) (1,4) (0,5) case of reach 0 row before col 7
            }                 //(3,5) (2,6) (1,7) case of reach col 7 before row 0
            temp--;
        }
    }
    if(row!=Size-1 && col!=0 )
    {
        temp=col-1;
        for(int i=row+1; i<Size; i++)
        {
            visited[i][temp]=1;
            if(i==Size-1||temp==0)
            {                     //(5,3) (6,2) (7,1)
                break;            //(4,2)  (5,1) (6,0)
            }
            temp--;
        }
    }
}
bool check_matrix() //to check if all position unavailable
{
    for (int i =0 ; i < Size ; i++)
    {
        for (int j = 0 ; j < Size ; j++)
        {
            if(visited [i][j]==0)
            {
                return false;
            }
        }
    }
    return true;
}
bool check_Queen_position(int row,int col) //to check if queen can insert in position or not
{
    if(visited[row][col]==0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void play_game()
{
    int r, c;
    cout<<"enter index of Queen:";
    cin>>r>>c;
    while(!check_valid(r,c)||!check_Queen_position(r,c))
    {
        cout<<"Invalid position,enter valid position:";
        cin>>r>>c;
    }
    visit_cells(r,c);
    visited[r][c]=1;
    grid[r][c]='Q';
}

int main()
{
    char s;
    while(s!='n')
    {
        cout<<"-------------------------8 Queens Game-------------------------------"<<endl;
        grid_intialize();
        adjacency_matrix();
        int queens=0;
        while(queens<8)
        {
            play_game();
            print_grid();
            queens++;
            if(check_matrix()&&queens<8) // all position unavailable and queens less 8
            {
                cout<<"Sorry No positions to play"<<endl;
                break;
            }
        }
        if(queens==8)
        {
            cout<<"Congratulation you won"<<endl;
        }
        cout<<"Do you want to play again y/n"<<endl;
        cin>>s;

    }
    cout<<"Thanks for playing game";

    return 0;
}
