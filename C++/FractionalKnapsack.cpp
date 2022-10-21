//Fractional Knapsack Problem
#include <bits/stdc++.h>
using namespace std;

//Each item stores weight and its value
struct Item{
	int value, weight;
}temp;

//Returns the maximum value using greedy approach
double fractionalKnapsack(int W, struct Item arr[], int N){
	//Sorts items based on their value/weight ratio
	for(int i=0; i<N-1; i++){
		for(int j=i+1; j<N; j++){
			if(arr[i].value/arr[i].weight < arr[j].value/arr[j].weight){
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}

	double finalVal = 0.0;

	//Traverses through all items
	for(int i=0; i<N; i++){
		//If the weight won't overflow after adding the item, then add the item fully
		if(arr[i].weight <= W){
			W -= arr[i].weight;
			finalVal += arr[i].value;
		}

		//If we can't add the full current item, then add a fractional part of it
		else{
			finalVal += arr[i].value * ((double)W / (double)arr[i].weight);
			break;
		}
	}

	//Returns the final knapsack value
	return finalVal;
}

//Main code
int main(){
	//Knapsack weight
	int W = 50;
	//Array of the items
	Item arr[] = {{ 100, 25 }, { 90, 15 }, { 140, 20 }};

	int N = sizeof(arr) / sizeof(arr[0]);

	//Function call
	cout << "The maximum value obtained = " << fractionalKnapsack(W, arr, N) << endl;
	
	return 0;
}

