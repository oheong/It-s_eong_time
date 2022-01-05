class Solution {
    static int getNum(int n, int m, int len, int[][] arr1, int[][] arr2){
        int sum = 0;
        for(int i = 0; i < len; i++){
            sum += (arr1[n][i]*arr2[i][m]);
        }
        return sum;
    }
    public int[][] solution(int[][] arr1, int[][] arr2) {
        int[][] answer = new int[arr1.length][arr2[0].length];
        for(int i = 0; i < arr1.length; i++){
            for(int j = 0; j < arr2[0].length; j++){
                answer[i][j] = getNum(i, j, arr1[0].length, arr1, arr2); 
            }
        }
        return answer;
    }
}
