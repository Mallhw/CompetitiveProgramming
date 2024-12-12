import java.util.Scanner;

public class MineSweeper {

    public static void main(String[] args) {
        long start = System.nanoTime();



        String[][]input={
                {"*",".",".","."},
                {".",".",".","."},
                {".","*",".","."},
                {".",".",".","."}
        };


        String[][] output=mineSweeper(input);

        for(String []i:output){
            for(String j:i){
                System.out.print(j+" ");
            }
            System.out.println();
        }
        long dif = System.nanoTime() - start;
        System.out.println(dif);
    }

    public static String[][] mineSweeper(String[][] field) {
        int[][]mines = new int[field.length][field[0].length];

        for(int i=0;i<field.length;i++){
            for(int j=0;j<field[0].length;j++){
                if(field[i][j].equals("*")){
                    modifyMines(mines,i,j);
                }
            }
        }
        String[][] output=new String[field.length][field[0].length];
        for(int i=0;i<field.length;i++){
            for(int j=0;j<field[0].length;j++) {
                if(field[i][j].equals("*")){
                    output[i][j]="*";
                }else{
                    output[i][j]=String.valueOf(mines[i][j]);
                }
            }
        }


        return output;

    }

    public static void modifyMines(int[][]a, int r, int c){
        int minR=r-1;
        int minC=c-1;
        int maxR=r+1;
        int maxC=c+1;
        if(r==0){
            minR=0;
        }else if (r==a.length-1){
            maxR=r;
        }

        if(c==0){
            minC=0;
        }else if (c==a[0].length-1){
            maxC=c;
        }

        for(int i=minR;i<=maxR;i++){
            for(int j=minC;j<=maxC;j++){
                a[i][j]++;
            }
        }

    }


}
