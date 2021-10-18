
class Solution {
    static int[] answer;
    
    static void ans(int brown, int yellow, int b){
        System.out.println("x y");
        for(int y = 1; y <= brown; y++){ // 짧
            for(int x = brown; 0 <= x; x--){ // 긴
                if(x * y == yellow && 2*x + 2*y + 4 == b){
                    System.out.println(x+" "+y);
                    answer[0] = x + 2;
                    answer[1] = y + 2;
                    return;
                }
            }
        }
    }
    public int[] solution(int brown, int yellow) {
        answer = new int[2];
        
        ans((brown - 4)/2, yellow, brown);

        return answer;
    }
}
