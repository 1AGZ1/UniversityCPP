// Задача 1.
// Для встречающихся в заданном тексте пар рядом расположенных символов указать, сколько раз встречается в тексте каждое из таких сочетаний.

// Task 1.
// For pairs of adjacent characters found in a given text, specify how many times each of these combinations occurs in the text.

#include<iostream>
#include<cstring>

using namespace std;

//Stack
class Stack{
    public:
        int count;
        char letter;
};

//Global variables init
char *s = new char[255];

int stackArrCount = 0;
Stack *stackArr = new Stack[30];

void add(char l){
    stackArr[stackArrCount].count = 1;
    stackArr[stackArrCount].letter = l;

    stackArrCount++;
}

int find(char l){
    for (int i = 0; i < stackArrCount; i++)
    {
        if(stackArr[i].letter == l)
        {
            stackArr[i].count++;
            return i;
        }
    }
    add(l);
    return 0;
}

//Main part of program
int main(){
    cout << "Enter the sentence: \n";
    cin.getline(s, strlen(s));

    for (int i = 0; i < strlen(s)-1; i++)
    {
        if(s[i]==s[i+1])
        {
            find(s[i]);
        }
    }

    for (int i = 0; i < stackArrCount; i++)
    {
        cout << stackArr[i].letter << " " << stackArr[i].count << "\n";
    }
    

    // system("pause");
    return 0;
}