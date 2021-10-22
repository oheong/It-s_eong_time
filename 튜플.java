import java.util.*;

class Solution {
    static ArrayList<ArrayList<Integer>> list;
    static int getCnt(String s){
        int cnt = 0;
        for(int i = 0; i < s.length(); i++){
            if(s.charAt(i) == '{')
                cnt++;
        }
        return cnt;
    }
    static void getList(String s){
        
        int start = 0;
        int end = -1;
        for(int i=0;i<s.length();i++){
        
            if(s.charAt(i) == '{')
                start = i;
            else if(s.charAt(i) == '}')
                end=i;
            
            if(start<end){
                String tempS = s.substring(start + 1, end);
                
                String[] tempArr = tempS.split(",");
                
                ArrayList<Integer> tempList = new ArrayList<Integer>();
                
                for(int n=0;n<tempArr.length;n++){
                    tempList.add(Integer.parseInt(tempArr[n]));
                }
                list.add(tempList);
                start=end;
            }
        }
        
    }
    public int[] solution(String s) {
        
        s = s.substring(1, s.length() - 1);
        
        int[] answer = new int[getCnt(s)];
        
        list = new ArrayList<ArrayList<Integer>>();
        
        getList(s);

        Collections.sort(list, new Comparator<ArrayList<Integer>>(){ // 아오 진짜 개빢치네 외우기
            // new Comparator<객체>(){} tlqkftlqkf
            public int compare(ArrayList<Integer> l1, ArrayList<Integer> l2){
                return l1.size()-l2.size();
            }
        });
        
        int cnt = 0;
        while(list.size()!=0){
            int num = list.get(0).get(0);
            list.remove(0);
            for(int i=0;i<list.size();i++){
                int index = 0;
                for(int j=0;j<list.get(i).size();j++){
                    if(num == list.get(i).get(j)){
                        index = j;
                    }
                }
                list.get(i).remove(index);
            }
            answer[cnt++] = num;
        }
        
        
        return answer;
    }
}
