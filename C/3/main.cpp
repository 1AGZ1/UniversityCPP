// Задача 3.
// Перечислить все слова заданного предложения, которые состоят из тех же букв, что и первое слово предложения.

// Task 3.
// List all the words of a given sentence that consist of the same letters as the first word of the sentence.

#include<iostream>
#include<cstring>

using namespace std;

//main part of program
int main(){
    setlocale(LC_ALL, "ru");

//variables init
    char *s = new char[255];
    char *ArrOfChar = new char[20];
    int count = 0;

    char *delimiters = new char[6];
    strcpy(delimiters," ,.:;-");

    cin.getline(s, 255);

//-----------------------------------------------
    s = strtok(s,   delimiters);

    for (int i = 0; i < strlen(s); i++)
    {
        if (count>0)
        {
            for (int j = 0; j < count; j++)
            {
                if (s[i] == ArrOfChar[j])
                {
                    break;
                }
                else if(j == count-1)
                {
                    ArrOfChar[count] = s[i];
                    count++;
                    break;
                }
                
            }

        }
        else
        {
            ArrOfChar[count] = s[i];
            count++;
        }
        
    }

 //-----------------------------------------------   
    s = strtok(NULL,   delimiters);

    while (s != NULL)
    {
        bool Switch = false;

        for (int i = 0; i < strlen(s); i++)
        {   
            //checking the letter in ArrOfChar
            for (int j = 0; j < count; j++)
            {
                if (s[i] == ArrOfChar[j])
                {
                    Switch = true;
                    break;
                }
                else if (j == count-1)Switch = false;
            }
            
            if(!Switch)break;
        }

        if(Switch)cout<<s<<"\n";

        s = strtok(NULL,   delimiters);
    }

//-----------------------------------------------
    system("pause");
    return 0;
}