#include<iostream>

using namespace std;


//Filling Array
void FillArray(float* *Arr, int M, int N){
	for(int i = 0;i<M;i++){
		Arr[i] = new float [N];
		for(int j=0;j<N;j++){
			cout<<"Arr["<<i+1<<"]["<<j+1<<"] = "<<endl;
			cin>>Arr[i][j];
		}
	}
}

//Printing Array
void PrintArray(float* *Arr, int M, int N){
	for(int i = 0;i<M;i++){
		for(int j = 0;j<N;j++){
			cout<<Arr[i][j]<<"\t";
		}
		cout<<"\n";
	}
}

//Finding Max element and print it's position in the Array
void FindMAX(float* *Arr, int M, int N){
	int a=0,b=0;

	for(int i = 0;i<M;i++){
		for(int j = 0;j<N;j++){
			if(Arr[a][b]<Arr[i][j]){
				a=i;
				b=j;
			}
		}
	}
	cout<<"Max element of arr: "<< Arr[a][b]<<" at row "<<a+1<<", column "<<b+1<<endl;
}

//Clearing dynamic RAM
void DelArr(float* *arr, int m){
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
	float **arr = new float* [m];
	FillArray(arr,m,n);

	PrintArray(arr,m,n);
	
	FindMAX(arr,m,n);

	DelArr(arr,m);

	system("pause");
	return 0;
}