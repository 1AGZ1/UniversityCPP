//Exercise 3

#include<iostream>
#include<cmath>

using namespace std;

void table(int a, int b){
    float Step = (float)(b - a) / 10;
    for(float i = (float) a; i <= (float) b; i += Step){
        cout << "|" << i << "|";
        if(i <= 0){
            cout << "|" << 7*i + 5*sin(i) << "|";
        }else if((i > 0) && (i <= 1)){
            cout << "|" << 0 << "|";
        }else{ 
            cout << "|"  << i*i - 2*i + 1 << "|";
        }
        cout << endl;
    }    
}

int main(){
    
    table(-1,4);  

    system("pause");
    return 0;
}
