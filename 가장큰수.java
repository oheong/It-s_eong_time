import java.util.*;
class Solution {
    static ArrayList<String> num1, num2, num3;
    static String num4;
    static String robot(String answer){
        for(int i = 9; 0 <= i; i--){
            
            if(num4 != null && num4.charAt(0) -'0' == i)
                answer += num4;
            
            while( 0 < num1.size() && (num1.get(0).charAt(0) - '0' == i) && 0 < num2.size() && (num2.get(0).charAt(0) - '0' == i)){
                if(num1.get(0).charAt(0) < num2.get(0).charAt(1)){
                    answer+=num2.get(0);
                    num2.remove(0);
                }
                else {
                    answer+=num1.get(0);
                    num1.remove(0);
                }
            }
            
            while( 0 < num1.size() && (num1.get(0).charAt(0) - '0' == i) && 0 < num3.size() && (num3.get(0).charAt(0) - '0' == i)){
                if(num1.get(0).charAt(0) < num3.get(0).charAt(1)){
                    answer+=num3.get(0);
                    num3.remove(0);
                }
                else {
                    answer+=num1.get(0);
                    num1.remove(0);
                }
            }

            while( 0 < num2.size() && (num2.get(0).charAt(0) - '0' == i) && 0 < num3.size() && (num3.get(0).charAt(0) - '0' == i)){

                if(num2.get(0).charAt(1) < num3.get(0).charAt(1)){
                    answer+=num3.get(0);
                    num3.remove(0);
                }
                else {
                    answer+=num2.get(0);
                    num2.remove(0);
                }
            }
                                                 
            while(num1.size() != 0 && (num1.get(0).charAt(0) - '0' == i)){
                answer += num1.get(0);
                num1.remove(0);
            }
            
            while(0 < num3.size() && (num3.get(0).charAt(0) - '0' == i)){
                answer+=num3.get(0);
                num3.remove(0);
            }
            
            while(0 < num2.size() && (num2.get(0).charAt(0) - '0' == i)){
                answer+=num2.get(0);
                num2.remove(0);
            }

        }
        
        
        return answer;
    }
    
    public String solution(int[] numbers) {
        String answer = "";
        
        num1 = new ArrayList<String>();
        num2 = new ArrayList<String>();
        num3 = new ArrayList<String>();
        
        int sum = 0;
        for(int i = 0; i < numbers.length; i++){
            sum+=numbers[i];
            if(numbers[i] / 10 < 1)
                num1.add(Integer.toString(numbers[i]));
            else if(numbers[i] / 100 < 1)
                num2.add(Integer.toString(numbers[i]));
            else if(numbers[i] / 1000 < 1)
                num3.add(Integer.toString(numbers[i]));
            else 
                num4=Integer.toString(numbers[i]);
        }

        if(sum == 0) return Integer.toString(0);
        
        // 오름차순 정렬
        Collections.sort(num1);
        Collections.sort(num2);
        Collections.sort(num3);
        // 역으로 (내림차순)
        Collections.reverse(num1);
        Collections.reverse(num2);
        Collections.reverse(num3);

        // 비교들 해서 끼워넣기
        return robot(answer);
    }
}
