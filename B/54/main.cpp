#include<iostream>
#include<cmath>

using namespace std;


//Filling Array
void FillArray(float* *Arr, int M){
	for(int i = 0;i<M;i++){
		Arr[i] = new float [M];
		for(int j=0;j<M;j++){
			cout<<"Arr["<<i+1<<"]["<<j+1<<"] = "<<endl;
			cin>>Arr[i][j];
		}
	}
}

//Printing Array
void PrintArray(float* *Arr, int M){
	for(int i = 0;i<M;i++){
		for(int j = 0;j<M;j++){
			cout<<Arr[i][j]<<"\t";
		}
		cout<<"\n";
	}
}

//Сondition for calculating the amount
bool BoolSUM(int a, int b, int M){

    float rad = (float)M/2;

    float sqRad = 2*pow(rad,2);

    //part 1 X1=0 Y1=0
    bool SUM1 = ((float)(pow(a,2)+pow(b,2)) <= sqRad);


    //part 2 X2=M Y2=M
    bool SUM2 = ((float)(pow((a-M),2)+pow((b-M),2)) <= sqRad);

    //Part3 = part1 OR part2
    return (SUM1||SUM2);
}


//Finding SUM of elements
float FindSUM(float* *Arr, int M){
    float Sum = 0;
	for(int i = 0;i<M;i++){
		for(int j = 0;j<M;j++){
			if(BoolSUM(i,j,M)){
				Sum += Arr[i][j];
			}
		}
	}
    return Sum;
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
	int m;

	//Enter number of Rows and Columns
	cout<<"Enter number of Rows and Columns:"<<endl;
	cin>>m;
	
	//creating and filling Array
	float **arr = new float* [m];
	FillArray(arr,m);

	PrintArray(arr,m);
	
	cout<<"Sum of elements = "<<FindSUM(arr,m)<<endl;

	DelArr(arr,m);

	system("pause");
	return 0;
}