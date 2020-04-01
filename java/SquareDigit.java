import java.util.ArrayList;

public class SquareDigit {

    public static int squareDigits(int n) {
        String[] digits = String.valueOf(n).split("");
        ArrayList<Integer> squares = new ArrayList<Integer>(); 
        for (String s : digits) {
            squares.add(Integer.parseInt(s) * Integer.parseInt(s));
        }

        String result = "";
        for (Integer s : squares) {
            result += s.toString();
        }
            
        return Integer.parseInt(result);
    }

    public static void main(String[] args) {
        System.out.print(squareDigits(9119));
    }

}

