#include <iostream>
#include<cstdlib>
#include<ctime>
#include<iomanip>

using namespace std;

const int row=9,line=9;
void fieldPrint(int field[row][line]);
void surfacePrint(char field[row][line]);
void builtField(int mineField[row][line],int field[row][line]);
void fillBlank(int r,int l,int field[row][line],char surface[row][line]);

int main()
{
    int mineNum;
    cout<<"请输入雷数"<<endl;
    cin>>mineNum;
    int mineField[row][line]= {0};
    int field[row][line]= {0};
    char surface[row][line]= {' '};
    srand(time(NULL));
    for(int count=0; count<mineNum;)
    {
        int r=rand()%row;
        int l=rand()%line;
        if(mineField[r][l]==0)
        {
            mineField[r][l]=1;
            count++;
            //cout<<r<<"  "<<l<<endl;
        }
    }
    //fieldPrint(mineField);
    builtField(mineField,field);
    //fieldPrint(mineField);
    fieldPrint(field);
    cout<<"---------------------------------------------------------------------------"<<endl;
    surfacePrint(surface);
    cout<<"---------------------------------------------------------------------------"<<endl;

    bool flag=0;
    while(flag==0)
    {
        int r,l;
        cout<<"请输入排查的行列"<<endl;
        cin>>r>>l;
        if(field[r][l]==-1)
        {
            cout<<"失败！"<<endl;
            fieldPrint(field);
            break;
        }

        if(field[r][l]!=0)
        {
            surface[r][l]=field[r][l]+48;
            surfacePrint(surface);
            cout<<"---------------------------------------------------------------------------"<<endl;
        }

        if(field[r][l]==0)
        {
            fillBlank(r,l,field,surface);
            surfacePrint(surface);
            cout<<"---------------------------------------------------------------------------"<<endl;
        }
    }


    return 0;
}

void fieldPrint(int field[row][line])
{
    cout<<endl;
    cout<<" ";
    for(int i=0; i<line; i++)
    {
        cout<<setw(6)<<i;
    }
    cout<<endl<<endl;
    for(int i=0; i<row; i++)
    {
        cout<<i;
        for(int j=0; j<line; j++)
        {
            cout<<setw(6)<<field[i][j];
        }
        cout<<endl<<endl;
    }
    cout<<endl;
}

void builtField(int mineField[row][line],int field[row][line])
{
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<line; j++)
        {
            if(i-1>=0 && i-1<row && j-1>=0 && j-1<line)
                field[i][j]+=mineField[i-1][j-1];
            if(i-1>=0 && i-1<row && j>=0 && j<line)
                field[i][j]+=mineField[i-1][j];
            if(i-1>=0 && i-1<row && j+1>=0 && j+1<line)
                field[i][j]+=mineField[i-1][j+1];

            if(j-1>=0 && j-1<line)
                field[i][j]+=mineField[i][j-1];
            if(j+1>=0 && j+1<line)
                field[i][j]+=mineField[i][j+1];

            if(i+1>=0 && i+1<row && j-1>=0 && j-1<line)
                field[i][j]+=mineField[i+1][j-1];
            if(i+1>=0 && i+1<row && j>=0 && j<line)
                field[i][j]+=mineField[i+1][j];
            if(i+1>=0 && i+1<row && j+1>=0 && j+1<line)
                field[i][j]+=mineField[i+1][j+1];
        }
    }

    for(int i=0; i<row; i++)
    {
        for(int j=0; j<line; j++)
        {
            if(mineField[i][j]==1)
                field[i][j]=-1;
        }
    }

    /*
    field[0][0]=                 mineField[0][1]
                +mineField[1][0]+mineField[1][1];
    for(int i=1;i<line-1;i++)
    {
        field[0][i]=mineField[0][i-1]                 +mineField[0][i+1]
                    +mineField[1][i]+mineField[1][i+1]+mineField[1][i-1];
    }
    field[0][line-1]=mineField[0][line-2]
                    +mineField[1][line-2]+mineField[1][line-1];



    for(int i=0;i<row-1;i++)
    {
        field[i][0]=mineField[i-1][0]+mineField[i-1][1]
                                        +mineField[i][1]
                    +mineField[i+1][0]+mineField[i+1][1];
        for(int j=0;j<line-1;j++)
        {
            field[i][j]=mineField[i-1][j-1]+mineField[i-1][j]+mineField[i-1][j+1]
                        +mineField[i][j-1]                    +mineField[i][j+1]
                        +mineField[i+1][j-1]+mineField[i+1][j]+mineField[i+1][j+1];

        }
        field[i][line-1]=mineField[i-1][line-2]+mineField[i-1][line-1]
                                                +mineField[i][line-2]
                        +mineField[i+1][line-2]+mineField[i+1][line-1];
    }



    field[row-1][0]=mineField[row-2][0]+mineField[row-2][1]
                                        +mineField[row-1][1];
    for(int i=1;i<line-1;i++)
    {
        field[row-1][i]=mineField[row-2][i-1]+mineField[row-2][i]+mineField[row-2][i+1]
                    +mineField[row-1][i-1]                       +mineField[row-1][i+1];
    }
    field[0][line-1]=mineField[row-2][line-2]+mineField[row-2][line-1]
                    +mineField[row-1][line-2];
                    */
}

void surfacePrint(char field[row][line])
{
    cout<<endl;
    cout<<" ";
    for(int i=0; i<line; i++)
    {
        cout<<setw(6)<<i;
    }
    cout<<endl<<endl;
    for(int i=0; i<row; i++)
    {
        cout<<i;
        for(int j=0; j<line; j++)
        {
            cout<<setw(6)<<field[i][j];
        }
        cout<<endl<<endl;
    }
    cout<<endl;
}

void fillBlank(int r,int l,int _field[row][line],char surface[row][line])
{
    int blank[row+2][line+2]= {0};
    blank[r+1][l+1]=1;

    int field[row+2][line+2]= {0};
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<line; j++)
        {
            field[i+1][j+1] = _field[i][j];
        }
    }
    for(int i=0; i<row+2; i++)
    {
        field[0][i]=1;
        field[row+1][i]=1;
        field[i][0]=1;
        field[i][row+1]=1;
    }

    bool flag=true;
    while(flag)
    {
        flag=false;
        for(int i=1; i<row+1; i++)
        {
            for(int j=1; j<line+1; j++)
            {
                if(blank[i][j]==1)
                {
                    if(blank[i-1][j]==0 && field[i-1][j]==0)
                    {
                        blank[i-1][j]=1;
                        flag=true;
                    }
                    if(blank[i][j-1]==0 && field[i][j-1]==0)
                    {
                        blank[i][j-1]=1;
                        flag=true;
                    }
                    if(blank[i+1][j]==0 && field[i+1][j]==0)
                    {
                        blank[i+1][j]=1;
                        flag=true;
                    }
                    if(blank[i][j+1]==0 && field[i][j+1]==0)
                    {
                        blank[i][j+1]=1;
                        flag=true;
                    }
                }
            }
        }
    }

    for(int i=0; i<row; i++)
    {
        for(int j=0; j<line; j++)
        {
            if(blank[i+1][j+1]==1)
            {
                surface[i][j]='0';
            }
        }
    }
}



/*for(int i=0;i<row;i++)
    {
        for(int j=0;j<line;j++)
        {

        }
    }*/
