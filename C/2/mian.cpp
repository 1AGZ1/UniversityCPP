// Задача 2.
// Для заданного текста определить длину содержащейся в нем максимальной последовательности символов, отличных от букв.

// Task 2.
// For a given text, determine the length of the maximum sequence of characters other than letters contained in it.

#include<iostream>
#include<cstring>

using namespace std;

int main(){
    setlocale(LC_ALL, "ru");
    //65 - 90 || 97 - 122
    
    //Variables init
    char *s = new char[255];
    int maxCount = 0;
    int Count = 0;

    cin.getline(s,255);

    for (int i = 0; i < strlen(s); i++) 
    {
        if (((int)s[i] > 64)&&((int)s[i] < 91)||((int)s[i] > 97)&&((int)s[i] < 122))
        {
            Count = 0;
        }
        else
        {   
            Count++;

            (maxCount < Count ? maxCount : Count ) = Count;
        }
        
    }
    
    cout << "Max sequence of characters :\t" << maxCount<<"\n";
    system("pause");
    return 0;
}