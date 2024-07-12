//Adbvance Pattern
#include<iostream>
using namespace std;

int main(){

    int n;
    cout<<"Enter the number: ";
    cin>>n;

    //Inverted Pattern
    // 1 2 3 4 5
    // 1 2 3 4
    // 1 2 3
    // 1 2
    // 1
    // for(int i=n; i>=1; i--)
    // {
    //     for(int j=1;j<=i;j++){    // for(int j=1;j<=(n+1-row))
    //         cout<<j<<" ";
    //     }
    //     cout<<endl;
    // }

    //0 1 Pattern
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=i;j++){
    //         if((i+j)%2==0){
    //             cout<<" 1";
    //         }
    //         else{
    //             cout<<" 0";
    //         }
    //     }
    //     cout<<endl;
    // }

    //Rhombus Pattern 
    //     * * * *
    //    * * * *
    //   * * * *
    //  * * * *
    // * * * *

    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=(n-i);j++){
    //         cout<<" ";
    //     }
    //     for(int j=1;j<=n;j++){
    //         cout<<"* ";
    //     }
    //     cout<<endl;
    // }

    //Number Pattern
    //     1
    //    1 2
    //   1 2 3
    //  1 2 3 4
    // 1 2 3 4 5

    for(int i=1;i<=n;i++){
        for(int j=1;j<=(n-i);j++){
            cout<<" ";
        }
        for(int j=1;j<=i;j++){
            cout<<j<<" ";
        }
        cout<<endl;
    }

    return 0;
}