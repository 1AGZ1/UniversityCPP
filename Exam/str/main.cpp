#include<iostream>
#include<cstring>

using namespace std;

class myClass
{
private:
    char *str;
public:
    myClass(char* s){
        str = s;
    }

    char* prn(){
        return str;
    }
};

char* plus_fun(char* a, char* b){
        int len1 = strlen(a);
        int len2 = strlen(b);

        char *tmp_str = new char[len1+len2];

        strcpy(tmp_str, a);

        for (int i = len1; i < (len1+len2); i++){
            tmp_str[i] = b[i-len1];
        }

        return tmp_str;
    }

char* subtr(char* src, char* src_) {
    char* t;
    
    do { 
        t= strstr (src, src_);
        if (t!=NULL) {
            char* t_= t + strlen(src_);
            strcpy (t, t_);
        }
        else return src;
    }while (true);

    return src; 
}

myClass operator + (myClass a, myClass b){
    return plus_fun(a.prn(), b.prn());
}

myClass operator - (myClass a, myClass b){
    return subtr(a.prn(), b.prn());
}


int main(){
    char *str1 = new char[255];
    char *str2 = new char[255];

    cout << "Enter the first sentences:\n";
    cin >> str1;

    cout << "Enter the second sentences:\n";
    cin >> str2;

    myClass obj1(str1);
    myClass obj2(str2);

    myClass obj3(obj1+obj2);
    cout << obj3.prn() << endl;

    myClass obj4(obj1-obj2);
    cout << obj4.prn() << endl;

    return 0;
}