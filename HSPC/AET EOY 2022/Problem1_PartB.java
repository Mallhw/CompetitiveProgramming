public class Problem1_PartB {

    private static String downShift = "<T*O HNM=LRGIPCVEZDBSYFXAWJ UQK ";
    private static String upShift = ">5@9 %,.+)4&80:;3\\$?#6!/-2' 71( ";
     public static String decode(String input) {
        StringBuilder output = new StringBuilder();
        boolean curShift = true;

        for (int i = 1; i <= input.length()/5; i++) {
            String curBinary = input.substring((i-1) * 5, i * 5);
            char curChar;
            if (curBinary.equals("11011")) {
                curShift = true;
                continue;
            } else if (curBinary.equals("11111")) {
                curShift = false;
                continue;
            }
            if (curShift) {
                curChar = downShift.charAt(binaryToDecimal(Integer.parseInt(curBinary)));
            } else {
                curChar = upShift.charAt(Integer.parseInt(curBinary, 2));
            }
            output.append(curChar);
        }
        return output.toString();
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

    public static void main(String[] args) {
         long start = System.nanoTime();
        //example test cases
        //(You should try more of your own)
        //Should be DIAL:911
        System.out.println(decode("100100110011000010011111101110000111110111101"));

        //Should be NOV 5, 8AM
        System.out.println(decode("001100001101111001001111100001001100010001100110111100000111"));
        long dif = System.nanoTime() - start;
        System.out.println(dif);

    }
}
