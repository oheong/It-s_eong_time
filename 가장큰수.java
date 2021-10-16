import java.util.*;
class Solution {
    public String solution(int[] numbers) {
        String answer = "";
        
        String[] num = new String[numbers.length];
        
        for(int i = 0; i < numbers.length; i++){
            num[i] = Integer.toString(numbers[i]);
        }
        
        Arrays.sort(num, new Comparator<String>(){
            public int compare(String o1, String o2){
                return (o2+o1).compareTo(o1+o2);
            }
        });
        
        if(num[0].equals("0")) answer = "0";
        else{
            for(int i=0;i<num.length;i++){
                answer+=num[i];
            }
        }
        return answer;
    }
}