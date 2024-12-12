import java.nio.file.LinkPermission;
import java.util.Arrays;

//MineSweeper
public class MineSweeperB {

    /* Given a String Matrix representing a minesweeper field
     * Return a String Matrix representing a field with the hints
     * . = safe square and * = mine
     */
    public static String[][]input={
            {"*",".",".","."},
            {".",".",".","."},
            {".","*",".","."},
            {".",".",".","."}
    };
    public static String[][] mineSweeper(String[][] field) {
        int[][] nums = new int[field.length][field[0].length];
        String[][] output = new String[field.length][field[0].length];
        for(int r = 0; r < field.length; r++) {
            for(int c = 0; c < field[0].length; c++) {
                if(field[r][c].equals("*")) {
                    if(c + 1 < field.length) {
                        nums[r][c+1]++;
                        if(r + 1 < field.length)
                        nums[r+1][c+1]++;
                        nums[r-1][c+1]++;

                    }
                    if(c - 1 >= 0) {
                        nums[r][c-1]++;

                        nums[r+1][c-1]++;
                        nums[r-1][c-1]++;

                    }

                    nums[r+1][c]++;
                    nums[r-1][c]++;
                }
            }
        }
        for(int r = 0; r < field.length; r++) {
            for(int c = 0; c < field[0].length; c++) {
                if(field[r][c].equals("*")) {
                    output[r][c] = "*";
                } else {
                    output[r][c] = nums[r][c] + "";
                }
            }
        }
        return null; //placeholder
    }

    public static void main(String[] args) {
        mineSweeper(input);

        //example test case
        //(You should try more of your own)

    }
}