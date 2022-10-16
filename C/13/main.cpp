// Задача 13.
// Найти самое длинное общее слово двух заданных предложений.

// Task 13.
// Find the longest common word of two given sentences.


#include<iostream>
#include<cstring>

using namespace std;

//Global variables init
char *s1 = new char[256];
char *s2 = new char[256];

char *delimiters = new char[6];



//Main part of program
int main(){
    strcpy(s1,"Standard sentence with some words.");
    strcpy(s2,"Another sentence with some words.");

    strcpy(delimiters," ,.:;-");

    char *result = new char[30];
    strcpy(result, "");

    char *tmp1 = s1;

    tmp1 = strtok(tmp1, delimiters);

    int i = 0;
    char **Arr = new char* [30];
    while(tmp1 != NULL)
    {
        Arr[i] = new char [strlen(tmp1)-1];
        strcpy(Arr[i], tmp1);

        i++;
        tmp1 = strtok(NULL, delimiters);
    }

    for (int j = 0; j < i; j++)
    {
        if(strlen(Arr[j])>strlen(result))
        {
            char *tmp2 = new char[strlen(s2)];
            strcpy(tmp2, s2);
            tmp2 = strtok(tmp2, delimiters);

            while (tmp2 != NULL)
            {
                if(strcmp(Arr[j], tmp2) == 0){

                    strcpy(result, Arr[j]);
                    break;
                
                }
                tmp2 = strtok(NULL, delimiters);
            }

        }
        
    }
    cout << "\nres = " << result << endl;


    system("pause");
    return 0;
}