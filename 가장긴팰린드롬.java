class Solution
{
    static int getAns(char[] st, int start, int end){
        for(int i = 0; i < (end - start + 1) / 2; i++){
            if(st[start + i] != st[end - i])
                return 0;
        }
        return 1;
    }
    public int solution(String s)
    {
        int answer = 0;
        char[] st = s.toCharArray();
        
        for(int start = 0; start <= s.length()/2; start++){
            if(s.length() - start <= answer) return answer;
           
            for(int end = s.length() - 1; start <= end; end--){
                if(end - start + 1 < answer) break;
                
                if(getAns(st, start, end) == 1 && answer < end - start + 1) {
                    answer = end - start + 1;
                    break;
                }
            }
        }
        return answer;
    }
}
