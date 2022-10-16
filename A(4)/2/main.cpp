//Exercise 2

#include<iostream>
#include<cmath>

using namespace std;

void table(int a, int b){
    
    for(int i = a; i < (b + 1); i++){
        cout << "|" << i << "|";
        if(i < 2){
            cout << "|" << 0 << "|";
        }else if((i > 1) && (i < 11)){
            cout << "|" << (2*i-4) << "|";
        }else{ 
            cout << "|"  << (float)i - sin(i) << "|";
        }
        cout << endl;
    }    
}

int main(){

    int a = 0;
    int b = 20;

    table(a,b);  

    system("pause");
    return 0;
}
