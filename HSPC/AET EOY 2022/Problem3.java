//Warring Brothers

import java.lang.reflect.Array;
import java.util.ArrayList;

public class Problem3 {

    //given a matrix representing the kingdom, the number of heirs, and the number of battles
    //return what the kingdom will look like after the battles

    public static int[][] simulateWar(int[][] kingdom, int heirs, int numBattles) {
        boolean[][] attacked = new boolean[kingdom.length][kingdom[0].length];
        /*
        int[][] nRulers = new int[kingdom.length][kingdom[0].length];
        for(int r = 0; r < kingdom.length; r++) {
            for(int c = 0; c < kingdom[0].length; c++) {
                nRulers[r][c] = kingdom[r][c];
            }
        }

         */
        for(int i = 0; i < numBattles; i++) {
            ArrayList<Integer> conqRuler = new ArrayList<>();
            ArrayList<Integer> rows = new ArrayList<>();
            ArrayList<Integer> columns = new ArrayList<>();
            // Calculate the attacks
            for(int r = 0; r < kingdom.length; r++) {
                for (int c = 0; c < kingdom[0].length; c++) {
                    // Checks right and left columns
                    if (c - 1 >= 0 && (kingdom[r][c] + 1) % heirs == kingdom[r][c - 1]) {
                        conqRuler.add(kingdom[r][c]);
                        rows.add(r);
                        columns.add(c-1);
                        //                        nRulers[r][c - 1] = kingdom[r][c];
                        attacked[r][c-1] = true;
                    }
                    if (c + 1 < kingdom[0].length && (kingdom[r][c] + 1) % heirs == kingdom[r][c + 1]) {
                        //nRulers[r][c + 1] = kingdom[r][c];
                        conqRuler.add(kingdom[r][c]);
                        rows.add(r);
                        columns.add(c+1);
                        attacked[r][c+1] = true;
                    }

                    // Check top and bottoms rows
                    if (r - 1 >= 0 && (kingdom[r][c] + 1) % heirs == kingdom[r - 1][c] ) {
                        conqRuler.add(kingdom[r][c]);
                        rows.add(r-1);
                        columns.add(c);
                        attacked[r-1][c] = true;
                    }
                    if (r + 1 < kingdom.length && (kingdom[r][c] + 1) % heirs == kingdom[r + 1][c]) {
                        conqRuler.add(kingdom[r][c]);
                        rows.add(r+1);
                        columns.add(c);
                        attacked[r+1][c] = true;
                    }
                }
            }
            for(int a = 0; a < conqRuler.size(); a++) {
                kingdom[rows.get(a)][columns.get(a)] = conqRuler.get(a);
            }
        }
        System.out.println("Hello Matthew!");
        return kingdom;
    }

    public static void main(String[] args) {
        long start = System.nanoTime();


        //example test case
        //(You should try more of your own)

        /* Result after 1 battle:
         * 0 0 0
         * 0 0 1
         * 2 1 1
         *
         * Result after 2 battles:
         * 0 0 0
         * 2 0 0
         * 1 0 1
         */
        long startTime = System.currentTimeMillis();
        int[][] test1 = {{0,0,1}, {0,1,1}, {0,2,2}};
        test1 = simulateWar(test1, 3, 2);
        printArray(test1);

        int[][] test9 = {{2, 1}, {1,1}, {2,0}};
        test9 = simulateWar(test9, 3, 2);
        printArray(test9);
        /* Result after all 3 battles:
         * 3 3 3 0 0
         * 3 3 0 0 0
         * 3 0 0 0 0
         * 0 0 0 0 0
         * 0 0 0 0 0
         *
         * Brother 0 is very happy!
         */
        int[][] test2 = {{3,1,2,0,1}, {1,0,2,0,2}, {0,1,2,0,1}, {0,1,2,2,1}, {0,1,2,1,1}};
        test2 = simulateWar(test2, 4, 3);
        printArray(test2);

        long endTime = System.currentTimeMillis();
        long total = endTime - startTime;

        System.out.println(total);
        long dif = System.nanoTime() - start;
        System.out.println(dif);
    }
    //Measure-Command { java .\src\Problem1.java }
    //Measure-Command { java .\src\Problem3.java }
    // Measure-Command { java .\src\Problem2.java }
    public static void printArray(int[][] arr){
        for(int i=0; i<arr.length; i++){
            for(int j=0; j<arr[0].length; j++){
                System.out.print(arr[i][j]+"\t");
            }
            System.out.println();
        }
        System.out.println();
    }

}