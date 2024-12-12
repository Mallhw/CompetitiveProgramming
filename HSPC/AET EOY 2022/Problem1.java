import java.util.ArrayList;
import java.util.HashMap;

//Baudot Code
public class Problem1 {

    //Arrays of up and down shift characters
    //private static Character[] downShift = {'<','T','*','O',' ','H','N','M','=','L','R','G','I','P','C','V','E','Z','D','B','S','Y','F','X','A','W','J',' ','U','Q','K',' '};
    //private static Character[] upShift = {'>','5','@','9',' ','%',',','.','+',')','4','&','8','0',':',';','3','\'','$','?','#','6','!','/','-','2','\'',' ','7','1','(',' '};

    private static String[] downShift = {"<","T","*","O"," ","H","N","M","=","L","R","G","I","P","C","V","E","Z","D","B","S","Y","F","X","A","W","J"," ","U","Q","K"," "};
    private static String[] upShift = {">","5","@","9"," ","%",",",".","+",")","4","&","8","0",":",";","3","\"","$","?","#","6","!","/","-","2","'"," ","7","1","("," "};
    HashMap<Character,Integer> jim;

    //input = String of bits
    //output = decoded message
    public static String decode(String input) {
        boolean s = true;
        String output = "";
        for(int i = 1; i <= input.length()/5; i++) {
            String curBinary = (input.substring((i-1)*5, i*5));
            int curVal = binaryToDecimal(Integer.parseInt(curBinary));
            //
            //int curVal = Integer.parseInt(curBinary, 2);
            if(s) {
                if(curVal == 27) {
                    s = true;
                } else if (curVal == 31) {
                    s = false;
                } else {
                    output += downShift[curVal];
                }
            } else {
                if(curVal == 27) {
                    s = true;
                } else if (curVal == 31) {
                    s = false;
                } else {
                    output += upShift[curVal];
                }

            }

        }

        return output; //placeholder
    }

    public static int binaryToDecimal(int binary) {
        int decimal = 0;
        int n = 0;
        while(true){
            if(binary == 0){
                break;
            } else {
                int cur = binary%10;
                decimal += cur * Math.pow(2, n);
                binary = binary/10;
                n++;
            }
        }
        return decimal;
    }

    //Measure-Command { java .\src\Problem1_PartB.java }
    //Measure-Command { java .\src\Problem1.java }
    //Measure-Command { java .\src\Problem3.java }
    // Measure-Command { java .\src\Problem3_Optimized.java }
    // Measure-Command { java .\src\Problem2.java }
    public static void main(String[] args) {
        //example test cases
        //(You should try more of your own)
         long startTime = System.currentTimeMillis();
        //Should be DIAL:911
        System.out.println(decode("100100110011000010011111101110000111110111101"));

        //Should be NOV 5, 8AM
        System.out.println(decode("001100001101111001001111100001001100010001100110111100000111"));
         long endTime = System.currentTimeMillis();
         long total = endTime - startTime;

         System.out.println(total);
        System.out.println("Total time: " + (endTime - startTime));
    }
}