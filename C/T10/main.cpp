// Задача 10.
// Из слов заданного текста составить цепочку слов максимальной длины, в которой каждое последующее слово начинается с буквы, на которую заканчивается предыдущее.

// Task 10.
// From the words of a given text, make a chain of words of maximum length, in which each subsequent word begins with the letter that the previous one ends with.

#include<iostream>
#include<cstring>

using namespace std;

//Class of word's data---------------------------------------------------------------------
class WordData
{
    public:
        char *Word;
        bool Used;
};



//functions part of program---------------------------------------------------------------------

//Compare letters of words
bool CompareLetters(char* Word1, char* Word2)
{   
    if (Word1[strlen(Word1)-1] != Word2[0]) return false;
    
    return true;   
}

//Compare two words
bool CompareWords(char* Word1, char* Word2)
{   
    for (int i = 0; i < strlen(Word1); i++) if (Word1[i] != Word2[i])return false;
    
    return true;
}

//Recursive word search
int RecursiveFind(WordData* Arr, int a, int count, int len, char* Word)
{
    for (int i = 0; i < count; i++)
    {
        if (!Arr[i].Used && CompareLetters(Arr[a].Word, Arr[i].Word))
        {
            Arr[i].Used = true;
            strcat(Word, Arr[i].Word);
            strcat(Word, " ");
            return RecursiveFind(Arr, i, count, len++, Word);

        }
        
    }

    //Clear .Used
    for (int i = 0; i < count; i++) if (Arr[i].Used) Arr[i].Used = false;

    return len;
}

//result
char *FindMaxStr(WordData* Arr, int count)
{
    int maxLen = 1;

    char *tmpRes = new char[255];
    strcpy(tmpRes, "");
    
    for (int i = 0; i < count; i++)
    {
        char *Word = new char[255];
        strcpy(Word, Arr[i].Word);
        strcat(Word, " ");

        Arr[i].Used = true;

        int tmpLen = RecursiveFind(Arr, i, count, 1, Word);
        if (maxLen < tmpLen) 
        {
            maxLen = tmpLen;
            tmpRes = Word;
        }
        else if ( (maxLen == tmpLen) && (strlen(tmpRes) < strlen(Word)) )tmpRes = Word;   
    }
    
    return tmpRes;
}

//main part of program---------------------------------------------------------------------
int main()
{   
    //init Variables=================
    char *Str = new char[255];

    WordData *ArrOfwords = new WordData[30];
    int count = 0;

    char *delimiters = new char[6];
    strcpy(delimiters," ,.:;-");

    //enter a sentence================
    cout<<"Enter a string: \n";
    cin.getline(Str, 255);

    //Add words in Arr=================
    Str = strtok(Str, delimiters);
    while (Str != NULL)
    {
        if (count > 0)
        {
            bool Switch = false;
            for (int i = 0; i < count; i++)
            {
                if (strlen(Str) != strlen(ArrOfwords[i].Word))continue;
 
                else if (CompareWords(Str, ArrOfwords[i].Word))
                {
                    Switch =true;
                    break;
                }

            }

            if (!Switch)
            {
                ArrOfwords[count].Word=Str;
                ArrOfwords[count].Used=false;

                count++;
            }

        }
        else
        {
            ArrOfwords[count].Word=Str;
            ArrOfwords[count].Used=false;

            count++;
        }

        Str = strtok(NULL, delimiters);
    }

    //output=================
    cout << "result = \'" << FindMaxStr(ArrOfwords, count) << "\'" << endl;

    system("pause");
    return 0;
}