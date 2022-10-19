//C++ program for activity selection problem when unsorted.
#include <bits/stdc++.h>
using namespace std;
 
//Each activity has a start time and finish time.
struct Activitiy{
    int start, finish;
}temp;
 
//Prints the maximum set of activities that can be done by a single person, one at a time.
void ActivitySelection(Activitiy arr[], int n){
    //Sort activities according to finish time
    for(int i=0; i<n-1; i++){
    	for(int j=i+1; j<n; j++){
    		if(arr[i].finish > arr[j].finish){
	    		temp = arr[i];
	    		arr[i] = arr[j];
	    		arr[j] = temp;
			}	
		}
	}
 
    cout << "Selected Activities:\n";
 
    //The first activity always gets selected
    int i = 0;
    cout << "(" << arr[i].start << ", " << arr[i].finish << ")";
 
    //Consider rest of the activities
    for (int j=1; j<n; j++){
        //If the activity has start time greater than or equal to the finish time of previously selected
        //activity, then select it
        if (arr[j].start >= arr[i].finish){
            cout << ", (" << arr[j].start << ", " << arr[j].finish << ")";
            i = j;
        }
    }
}
 
//Main code
int main(){
    Activitiy arr[] = {{ 7, 8 }, { 0, 2 }, { 6, 8 }, { 2, 5 }, { 6, 7 }, { 10, 13 }};
    int n = sizeof(arr) / sizeof(arr[0]);
 
    //Function call
    ActivitySelection(arr, n);
    
    return 0;
}
