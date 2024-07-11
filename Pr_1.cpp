#include <iostream>
using namespace std;

int main()
{

    // int row,col;
    // cout<<"Enter the row:";
    // cin>>row;
    // cout<<"Enter the col:";
    // cin>>col;

    // Simple Rectangle
    // for(int i=0;i<5;i++)
    // {
    //     for(int j=0;j<4;j++)
    //     {
    //         cout<<"* ";
    //     }
    //     cout<<endl;
    // }

    // Hollow Rectangle Pattern
    // for(int i=1;i<=row;i++)
    // {
    //     for(int j=1;j<=col;j++)
    //     {
    //         if(i==1 || i==row || j==1 || j==col)
    //         {
    //             cout<<"*";
    //         }
    //         else{
    //             cout<<" ";
    //         }
    //     }
    //     cout<<endl;
    // }

    // Inverted Half Pyramid
    //  for(int i=1;i<=row;i++)
    //  {
    //      for(int j=i;j<=col;j++)
    //      {
    //          cout<<"* ";
    //      }
    //      cout<<endl;
    //  }

    // Half Pyramid After 180deg Rotaion
    //  for(int i=1;i<=row;i++)
    //  {
    //      for(int j=1;j<=col;j++){
    //          if(j<=col-i){
    //              cout<<"  ";
    //          }
    //          else{
    //              cout<<" *";
    //          }
    //      }
    //      cout<<endl;
    //  }

    // Half Pyramid Using Numbers
    //  for(int i=1;i<=row;i++)
    //  {
    //      for(int j=1;j<=i;j++){
    //          cout<<i<<" ";
    //      }
    //      cout<<endl;
    //  }

    // Floyd's Triangle
    //  int num=1;
    //  for(int i=1;i<=row;i++)
    //  {
    //      for(int j=1;j<=i;j++){
    //          cout<<num<<"";
    //          num+=1;
    //      }
    //      cout<<endl;
    //  }

    //=====================================================================================

    int n;
    cout << "Enter the number: ";
    cin >> n;

    //Upper Part of 
    // *      *
    // **    **
    // ***  ***
    // ********
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << "* ";
        }
        int space = 2 * n - 2 * i;
        for (int j = 1; j <= space; j++)
        {
            cout << "  ";
        }
        for (int j = 1; j <= i; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }

    //lower part
    // ********
    // ***  ***
    // **    **
    // *      *
    for (int i = n; i >= 1; i--)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << "* ";
        }
        int space = 2 * n - 2 * i;
        for (int j = 1; j <= space; j++)
        {
            cout << "  ";
        }
        for (int j = 1; j <= i; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }

    return 0;
}
