#include <iostream>
using namespace std;
const int size=5;
void nextQueen (int myarray2 [size][size]);
void printArray (int myarray [size][size]);
void getMax (int myarray [size][size],int &mymax,int &myx,int &myy);
void addthezeros (int (&myarray) [size][size]);
int main() {
    if (size==2 ||size==3)
    {
        cout<<"No Solutions"<<endl;
        return 0;
    }
    int array [size][size];
    for(int i=0; i<size;i++)
    {
        for(int j=0; j<size;j++)
        {
            array[i][j]=-1;
        }
    }
    for (int i =0; i<size; i++)
    {
            array[i][0]=1;
            nextQueen(array);
            array[i][0]=-1;
    }
    return 0;
}
void nextQueen (int myarray2 [size][size])
{
    int myarray[size][size];
    for(int i=0; i<size;i++)
    {
        for(int j=0; j<size;j++)
        {
            myarray[i][j]=myarray2[i][j];
        }
    }
    addthezeros(myarray);
    int max=0,x=0,y=0;
    getMax(myarray,max,x,y);
    if(max>(size-1))
    {
        printArray(myarray);
        exit(0);
    }
    for (int i =0; i<size; i++)
    {
        if(myarray[i][max]== -1)
        {
            myarray[i][max]=max+1;
            nextQueen(myarray);
            myarray[i][max]=-1;
        }
    }
}
void getMax (int myarray [size][size],int &mymax,int &myx,int &myy)
{
    for(int i=0; i<size;i++)
    {
        for(int j=0; j<size;j++)
        {
            if(myarray[i][j]>mymax)
            {
                mymax=myarray[i][j];
                myx=i;
                myy=j;
            }
        }
    }
}
void addthezeros (int (&myarray) [size][size])
{
    int max=0,x=0,y=0;
    getMax(myarray,max,x,y);
    for(int i=0; i<size;i++)
    {
        for(int j=0; j<size;j++)
        {
            if(i==x ||j==y||(i+j)==(x+y)||(i-j)==(x-y))
            {
                myarray[i][j]=0;
            }
        }
    }
    myarray[x][y]=max;
}
void printArray (int myarray [size][size])
{
    for(int i=0; i<size;i++)
    {
        for(int j=0; j<size;j++)
        {
            if(myarray[i][j]==0)
                cout<<"_";
            else
                cout<<myarray[i][j];
            cout<<"\t";
        }
        cout<<endl<<endl;
    }
}