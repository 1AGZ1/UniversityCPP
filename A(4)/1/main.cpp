#include<iostream>

using namespace std;

int mod(int n){
    if(n > 0){
        return n;
    }else{
        return -n;
    }
}

int maxF(int a,int b){
    if(a > b){
        return a;
    }else{
        return b;
    }
}

int minF(int a, int b){
    if(a < b){
        return a;
    }else{
        return b;
    }
}

int main(){
    int x;
    int y;
    int t;

    cout << "Enter X as int: " << endl;
    cin >> x;

    cout << "Enter y as int: " << endl;
    cin >> y;

    cout << "Enter t as int: " << endl;
    cin >> t;

    cout << "\nAnswers : " << endl; 
    cout << "a) y = " << mod(x) << endl; 
    cout << "б) y = " << mod(1 - mod(1 + x)) << endl; 
    cout << "в) z = " << maxF(x, t)<< endl; 
    cout << "г) z = " << maxF(x, maxF(t, y)) << endl; 
    cout << "д) z = " << minF(x, maxF(t, y)) << endl;

    system("pause");
    return 0;
}