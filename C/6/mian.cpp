// Задача 6.
// Найти самое длинное симметричное слово заданного предложения.

// Task 6.
// Find the longest symmetric word in a given sentence.

#include<iostream>
#include<cstring>

using namespace std;

//main part of programm
int main()
{
    //Variables init
    char *Str = new char[255];

    int count = 0;

    char *Result = new char[30];

    char *delimiters = new char[6];
    strcpy(delimiters," ,.:;-");

    //Get Str
    cout << "Enter a string: \n";
    cin.getline(Str, 255);

    Str = strtok(Str, delimiters);
    while (Str!=NULL)
    {
        bool Switch = false;

        if(strlen(Str)>count)
        {
            for (int i = 0; i < strlen(Str); i++)
            {       
                if ((Str[i] == Str[strlen(Str)-1-i])&&(i<strlen(Str)-i))
                {
                    Switch = true;
                }
                else if (!Switch)
                {
                    Switch = false;
                    break;
                }
                else
                {
                    break;
                }
                
                
            }
            if (Switch)
            {   
                count = strlen(Str);
                Result = Str;
            }
            
        }
        Str = strtok(NULL, delimiters);

    }
     
    cout << "The longest symmetric word:\t" << Result << endl;

    // system("pause");
    return 0;
}