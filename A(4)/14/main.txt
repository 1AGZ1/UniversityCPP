#include<iostream>
#include<cmath>

using namespace std;

class Sum{
	private:
		
		float X_Class;
		
		int Num;
	
	public:
		int fract(int n){
			int Fr=1;
			if(n!=0){
				for(int i = 1; i <= n; i++){
					Fr *= i;
				}
			}
			return Fr;
		}
		
		float SumerTime(){			
			float a = (-1)/(X_Class*fract(Num-1));
			 
			float Su = a;
			
			for(int i=2; i<=Num; i++){
				a *= (Num-i+1)*(-1)*(2*i-1)*(2*i-2)/X_Class;
				Su += a;
			}
			return Su;
		}
		
		Sum(float x, int n){
			X_Class = x;
			Num = n;
		}
		
};




int main(){
	
	float x;
	
	int n;
	
	cout<<"Enter x as float:"<<endl;
	cin>>x;
	
	cout<<"Enter N+ as float:"<<endl;
	cin>>n;
	
	Sum Obj1(x,n);
	
	float y = Obj1.SumerTime();
	
	cout<<"Answer: \n"<<y<<endl;
	
	
	system("pause");
	return 0;
}