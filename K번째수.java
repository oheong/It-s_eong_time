import java.util.*;
class Solution {
    public int[] solution(int[] array, int[][] commands) {
        int[] answer = new int[commands.length];
        for(int i = 0; i < commands.length; i++){
            int start = commands[i][0] - 1;
            int end = commands[i][1] - 1;
            int[] temp = new int[end - start + 1];
            for(int j = 0; j < end - start + 1; j++){
                temp[j] = array[j + start];
            }
        Arrays.sort(temp);
        answer[i] = temp[commands[i][2] - 1];
        }        
        return answer;
    }
}
