// Задача 5.
// Для каждого из слов заданного предложения указать, сколько раз оно встречается в предложении.

// Task 5.
// For each of the words of a given sentence, specify how many times it occurs in the sentence.

#include<iostream>
#include<cstring>

using namespace std;

//Class for storage data about words.
class ArrData
{
    public:
        int Count;
        char *S;
};

//main part of program
int main()
{
    //Variables init
    char *s = new char[255];

    ArrData *Arr = new ArrData[30];
    int count = 0;

    char *delimiters = new char[6];
    strcpy(delimiters," ,.:;-");

//--------------------------------------------------------------------
    cout<<"Enter a string: \n";
    cin.getline(s, 255);

//--------------------------------------------------------------------
    s = strtok(s, delimiters);

    while (s != NULL)
    {
        bool Switch = false;
        
        if (count>0)
        {
            //Array of class ArrData
            for (int j = 0; j < count; j++)
            {
                if (strlen(s) == strlen(Arr[j].S))
                {
                    //String in ArrData and String s
                    for (int z = 0; z < strlen(s); z++)
                    {
                        //checking a word in the Arr
                        if (Arr[j].S[z] == s[z])Switch = true;
                        else
                        {
                            Switch = false;     
                            break;
                        } 
                    
                    }

                    if(Switch)
                    { 
                        //increase Count of word
                        Arr[j].Count++;
                        break;
                    }
                    else if ((j == count-1)&&(!Switch))
                    {
                        //Add new word in Arr
                        Arr[count].S = new char[20];
                        Arr[count].S = s;
                        Arr[count].Count = 1;
                        
                        count++;
                        break;
                    }
                    
                }
                else if ((j == count-1)&&(!Switch))
                {
                    //Add new word in Arr
                    Arr[count].S = new char[20];
                    Arr[count].S = s;
                    Arr[count].Count = 1;
                    
                    count++;
                    break;
                }
                
            }
        }
        else
        {
            //Add new word in Arr
            Arr[count].S = new char[20];
            Arr[count].S = s;
            Arr[count].Count = 1;
            count++;
        }

        s = strtok(NULL, delimiters);
    }
    
    //Print Data
    for (int i = 0; i < count; i++)
    {
        cout<<"String: "<<Arr[i].S<<"\tQuantity: "<<Arr[i].Count<<"\n";
    }
    

    system("pause");
    return 0;
}