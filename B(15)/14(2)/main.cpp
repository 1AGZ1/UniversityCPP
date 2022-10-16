#include<iostream>

using namespace std;

int n;
float b[70];

void ReCalculate(float b[]){
    int fr = 1;
    for(int i = 0; i < n; i++){
        fr *= i + 1;
        b[i] += fr;
    }
}

int main(){
    
    cout<<"Enter N as number of elements in array b: "<<endl;
    cin>>n;

    for(int i = 0; i < n; i++){
        cout<<"Enter \""<<i+1<<"\" element of array b:"<<endl;
        cin>>b[i];
    }

    ReCalculate(b);

    for (int i = 0; i < n; i++) {
        cout << b[i] << " ";
    }

    return 0;
}