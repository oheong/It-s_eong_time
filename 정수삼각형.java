import java.util.*;
class Solution {
    
    static int[][] map, copy ;
    static void print(int n){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                System.out.print(map[i][j]+ " ");
            }
            System.out.println();
        }
    }
    public int solution(int[][] triangle) {
        int answer = 0;
        map = new int[triangle.length][triangle.length];
        copy = new int[triangle.length][triangle.length];
        
        for(int i=0;i<triangle.length;i++){
            for(int j=0;j<triangle[i].length;j++){
                copy[i][j]=triangle[i][j];
            }
        }
        
        map[0][0] = triangle[0][0];
        map[1][0] = triangle[1][0];
        for(int i = 1; i < triangle.length; i++){
            map[i][0] = triangle[i][0] + map[i - 1][0];
        }
        
        for(int i = 1; i < triangle.length; i++){
            for(int j = 1;j < triangle.length; j++){
                int temp1 = map[i - 1][j - 1] + copy[i][j];
                int temp2 = map[i - 1][j] + copy[i][j];
                
               if(temp1 < temp2)
                    map[i][j] = temp2;
                else 
                    map[i][j] = temp1;
                
                if(answer<map[i][j])
                    answer = map[i][j];
            }
        }
        
        return answer;
    }
}
