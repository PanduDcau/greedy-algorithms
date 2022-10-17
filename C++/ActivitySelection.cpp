//C++ program for activity selection problem.
 
//Assuming that the activities are already sorted according to their finish time.

#include <bits/stdc++.h>
using namespace std;
 
//Prints the maximum set of activities that can be completed by a single person, one at a time.
void selectActivities(int s[], int f[], int n){
    int i=0, j;
 
    cout << "Selected Activities:" << endl;
 
    //The first activity always gets selected.
    cout << i << " ";
 
    //Consider rest of the activities.
    for (j = 1; j < n; j++){
        //If this activity has start time greater than or equal to the finish time of previously selected
        //activity, then select it.
        if (s[j] >= f[i]){
            cout << j << " ";
            i = j;
        }
    }
}
 
//Main code
int main(){
	//The array of start times.
    int s[] = { 1, 1, 3, 4, 6, 12 };
    //The array of finish times.
    int f[] = { 3, 4, 5, 8, 10, 14 };
    //The number of elements.
    int n = sizeof(s) / sizeof(s[0]);
 
    //Function call.
    selectActivities(s, f, n);
    return 0;
}
