#include<iostream>

using namespace std;

float MaxOfRow(float* *Arr, int m, int n){
	float Max = Arr[m][0];
	for(int i=1;i<n;i++){
		if(Max<Arr[m][i]){
			Max = Arr[m][i];
		}
	}
	return Max;
}

int main(){
	
	int m, n;
	
	cout<<"Enter  m and n as int: "<<endl;
	cin>>m>>n;
	
	float **Arr = new float* [m];
	for(int i=0;i<m;i++){
		Arr[i] = new float [n];
		for(int j=0; j<n;j++){
			cout<<"Arr["<<i<<"]["<<j<<"]"<<endl;
			cin>>Arr[i][j];
		}
	}
	
	cout<<"|B_Arr|"<<endl;
	for(int i = 0; i < m; i++){
		cout<<MaxOfRow(Arr, i, n)<<"\t";
	}
	cout<<endl;
	
	for(int i = 0; i<m;i++){
		delete[]Arr[i];
	}
	delete[]Arr;

	system("pause");
	return 0;
}
