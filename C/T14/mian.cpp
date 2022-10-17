// Задача 14.
// Даны два предложения. Найти самое короткое из слов первого предложения, которого нет во втором предложении.

// Task 14.
// Two sentences are given. Find the shortest of the words of the first sentence that is not in the second sentence.

#include<iostream>
#include<cstring>

using namespace std;
//---------------------------------------------
bool CompareWords(char* Word1, char* Word2)
{   
    for (int i = 0; i < strlen(Word1); i++) if (Word1[i] != Word2[i])return false;
    
    return true;
}

//
int main()
{   
    const int STR_SIZE = 255;

    char *Str1 = new char[STR_SIZE];
    char *Str2 = new char[STR_SIZE];

    char *res = new char[20];

    int min = INT_MAX;

    char **Arr = new char*[30];
    int count = 0;

    char *delimiters = new char[6];
    strcpy(delimiters," ,.:;-");

    //enter a sentences------------------------------------------------
    cout<<"Enter a first sentence: \n";
    cin.getline(Str1, STR_SIZE);

    cout<<"Enter a second sentence: \n";
    cin.getline(Str2, STR_SIZE);

    //------------------------------------------------
    Str2 = strtok(Str2, delimiters);
    while (Str2 != NULL)
    {
        if (count > 0)
        {
            bool Switch = false;
            for (int i = 0; i < count; i++)
            {
                if (strlen(Str2) != strlen(Arr[i]))continue;
 
                else if (CompareWords(Str2, Arr[i]))
                {
                    Switch =true;
                    break;
                }

            }

            if (!Switch)
            {
                Arr[count]=Str2;

                count++;
            }

        }
        else
        {
            Arr[count]=Str2;

            count++;
        }

        Str2 = strtok(NULL, delimiters);
    }

    //------------------------------------------------
    Str1 = strtok(Str1, delimiters);
    while (Str1 != NULL)
    {
        bool Switch = true;
        for (int i = 0; i < count; i++)
        {
            if (strlen(Str1) != strlen(Arr[i])) Switch = false;
    
            else if (CompareWords(Str1, Arr[i]))
            {
                Switch = true;
                break;
            }
            
        }

        if (!Switch && min > strlen(Str1))
        {
            min = strlen(Str1);
            res = Str1;
        }
        
        Str1 = strtok(NULL, delimiters);
    }

    cout << "The shortest of the words:\t" << res << endl;

    system("pause");
    return 0;
}