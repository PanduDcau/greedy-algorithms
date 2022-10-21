public class ActivitySelectionUnsorted{
    //Java program for activity selection problem when unsorted.

    //Prints the maximum set of activities that can be done by a single person, one at a time.
    public static void ActivitySelection(int arr[][], int n){
        int temp[];

        //Sort activities according to finish time
        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                if(arr[i][1] > arr[j][1]){
                    temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }

        System.out.println("Selected Activities:");

        //The first activity always gets selected
        int i = 0;
        System.out.print("(" + arr[i][0] + ", " + arr[i][1] + ")");

        //Consider rest of the activities
        for(int j=1; j<n; j++){
            //If the activity has start time greater than or equal to the finish time of previously selected
            //activity, then select it
            if(arr[j][0] >= arr[i][1]){
                System.out.print(", (" + arr[j][0] + ", " + arr[j][1] + ")");
                i = j;
            }
        }
    }

    //Main code
    public static void main(String [] args){
        int arr[][] = {{ 7, 8 }, { 0, 2 }, { 6, 8 }, { 2, 5 }, { 6, 7 }, { 10, 13 }};
        int n = arr.length;

        //Function call
        ActivitySelection(arr, n);
    }
}
