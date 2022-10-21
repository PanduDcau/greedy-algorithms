//Java program to print Egyptian fractions
public class EgyptianFractions{
    //Prints the Egyptian fractions
    public static void egyptianFraction(int n, int d){
        //Returns when both Numerator and denominator becomes zero
        if(d==0 || n==0)
            return;

        //Finds the ceiling of the d/n
        if(d%n == 0){
            System.out.print("1/" + d/n);
            return;
        }

        if(n%d == 0){
            System.out.print(n/d);
            return;
        }

        if(n > d){
            System.out.print(n/d + " + ");
            egyptianFraction(n%d, d);
            return;
        }

        int x = d/n + 1;
        System.out.print("1/" + x + " + ");
        egyptianFraction(n*x-d, d*x);
    }

    //Main code
    public static void main(String [] args){
        int numerator = 12, denominator = 13;

        System.out.print("The Egyptian Fraction representation of " + numerator + "/" + denominator + ": ");

        //Function call
        egyptianFraction(numerator, denominator);
    }
}
