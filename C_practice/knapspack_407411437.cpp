#include <stdio.h> 
  
int knapSpack(int C, int W[], int val[], int N, int total, int weight) {
	int total_val = total;//total_value
	int total_wt = weight;
	int max_val = 0;//max_value
	int wt;//max_value's weight
	int min_val = 999999;
	
	for(int i=0;i<N;i++){
		if(val[i]>max_val && C-W[i]>=0){//capacity>0 if minus the weight of item
			max_val = val[i];//get max value
			wt = W[i];
			
		}
	}
	//before find Max_value
	C = C - wt;
	total_wt = total_wt + wt;
	total_val = total_val + max_val;
	
	for(int j=0;j<N;j++){
		if(W[j]<min_val){
			min_val = W[j];
		}
	}
	
	for(int i=0;i<N;i++){
		if(wt==W[i] && max_val==val[i]){//capacity>0 if minus the weight of item
			printf("catch %c with ", i+65);
			printf("weight %d and value %d\n", W[i], val[i]);
		}
	}
	if(C-min_val>=0){
		
		knapSpack(C, W, val, N, total_val, total_wt);	
	}else{
		printf("total benifit value is : %d\n", total_val);
		printf("total weight is : %d", total_wt);
	}
	
} 
int knapSpack_V(int C, int W[], int val[], int N, int total, int weight, int V[]) {
	int total_val = total;//total_value
	int total_wt = weight;
	int max_val = 0;//max_value
	int wt;//max_value's weight
	int min_val = 999999;
	int max_ben = 0;
	
	for(int i=0;i<N;i++){
		if(V[i]>max_ben && C-W[i]>=0){//capacity>0 if minus the weight of item
			max_ben = V[i];//get max value
			wt = W[i];
			max_val = val[i];
		}
	}
	//before find Max_value
	C = C - wt;
	total_wt = total_wt + wt;
	total_val = total_val + max_val;
	
	for(int j=0;j<N;j++){
		if(W[j]<min_val){
			min_val = W[j];
		}
	}
	
	for(int i=0;i<N;i++){
		if(wt==W[i] && max_val==val[i]){//capacity>0 if minus the weight of item
			printf("catch %c with ", i+65);
			printf("weight %d and value %d\n", W[i], val[i]);
		}
	}
	if(C-min_val>=0){
		knapSpack_V(C, W, val, N, total_val, total_wt, V);	
	}else{
		printf("total benifit value is : %d\n", total_val);
		printf("total weight is : %d", total_wt);
	}
	
} 
void print_W(int C, int val[], int W[], int N, int total, int weight){
	
	printf("Original Data is Knapsack’s Capacity is %d\n", C);
	printf("Using Benefit only\n");
	knapSpack(C, W, val, N, total, weight);
	printf("\n\n");
}
void print_C(int C, int val[], int W[], int N, int total, int weight, int V[]){
	
	printf("Original Data is Knapsack’s Capacity is %d\n", C);
	printf("Using Cost only\n");
	knapSpack_V(C, W, val, N, total, weight, V);
	printf("\n\n");
}
int main() 
{ 
    int total,weight = 0;
	//case 1 翻轉教學題目 
	int C1 = 8;
    int val[] = { 4500, 5700, 2250, 1100, 6700 }; //benifit
    int W[] = { 4, 5, 2, 1, 6 }; //weight
    int V[] = {1125, 1140, 1125, 1100, 1116};//cost = benifit/weight
    int N = sizeof(val)/sizeof(val[0]);; //number of item
    //case 2 指定輸入 
    int C2 = 500;
    int val2[] = { 1000, 200, 600, 400 }; //benifit
    int W2[] = {300, 200, 400, 100}; //weight
    int V2[] = {3, 1, 1, 4};//cost = benifit/weight
	int N2 = sizeof(val2)/sizeof(val2[0]); //number of item
    //case 3 作業範例輸入 
    int C3 = 60;
    int val3[] = { 100, 280, 120 }; //benifit
    int W3[] = { 10, 40, 20 }; //weight
    int V3[] = { 10, 7, 6 };//cost = benifit/weight
	int N3 = sizeof(val3)/sizeof(val3[0]); //number of item
    
    //case 1 print
    print_W(C1, val, W, N, total,weight);
    print_C(C1, val, W, N, total,weight, V);
    total,weight = 0;
    //case 2 print
    print_W(C2, val2, W2, N2, total,weight);
    print_C(C2, val2, W2, N2, total,weight, V2);
    total,weight = 0;
    //case 3 print
    print_W(C3, val3, W3, N3, total,weight);
    print_C(C3, val3, W3, N3, total,weight, V3);

    return 0; 
} 
