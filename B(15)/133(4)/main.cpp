#include<iostream>

using namespace std;


//Filling Array
void FillArray(int* *Arr, int M, int N){
    //creating two-dimensional array
	for(int i = 0;i<M;i++){
		Arr[i] = new int [N];
	}

//init variables
    int a=0,b=-1;//pointers to an array element
    int Zn = 1;//direction indicator
    int Natural = 1;//neutral numbers to fill the array

//Spiral filling
    while((N>0)){

        for(int i = 0;i<N;i++){
            b+=Zn;
            Arr[a][b] = Natural;
            Natural++;
        }
        //decrease turn on Rows
        N--;

        if(M-1>0){
            for(int i = 0;i<M-1;i++){
                a+=Zn;
                Arr[a][b]= Natural;
                Natural++;
            }
            //decrease turn on Columns
            M--;
        }
        //change direction
        Zn *= -1;
    }
}

//Printing Array
void PrintArray(int* *Arr, int M, int N){
	for(int i = 0;i<M;i++){
		for(int j = 0;j<N;j++){
			cout<<Arr[i][j]<<"\t";
		}
		cout<<"\n";
	}
}

//Clearing dynamic RAM
void DelArr(int* *arr, int m){
	for(int i = 0; i < m; i++){
		delete [] arr[i];
	}
	delete [] arr;
}

int main(){
	//declaring size of Array
	int m, n;

	//Enter number of Rows and Columns
	cout<<"Enter number of Rows and Columns:"<<endl;
	cin>>m>>n;
	
	//creating and filling Array
	int **arr = new int* [m];
	FillArray(arr,m,n);

	PrintArray(arr,m,n);
	
	DelArr(arr,m);

	system("pause");
	return 0;
}
