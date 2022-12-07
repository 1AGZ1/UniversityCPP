#include<iostream>
#include<cstring>

using namespace std;

bool count_fun(char* str){

    int len = strlen(str);
    int count = 0;

    for (int i = 0; i < len; i++)
    {
        if(str[i]=='(') count++;
        else if(str[i]==')')count--;

        if(count<0) return false;
        else if((count == 0)&&(i != len-1)) return false;
    }

    if (count !=0) return false;
    return true;    
}


int main(){
    char *str = new char(255);

    cout << "Enter the equation:\n";
    cin >> str;
    
    if(count_fun(str)) cout << "\nБаланс соблюдается!";
    else cout << "\nБаланс не соблюдается!\n";

    // system("pause");
    return 0;
}
