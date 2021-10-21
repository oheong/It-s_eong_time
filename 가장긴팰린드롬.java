class Solution
{
    static int getAns(String str){
        for(int i = 0; i <= str.length() / 2;i++){
            if(str.charAt(i) != str.charAt(str.length() - i - 1))
                return 0;
        }
        return 1;
    }
    public int solution(String s)
    {
        int answer = 0;

        for(int start = 0; start <= s.length()/2; start++){
            if(s.length() - start <= answer) return answer;
            for(int end = s.length() - 1; start <= end; end--){
                if(end - start < answer) break;
                String str = s.substring(start, end + 1);
                if(getAns(str) == 1 && answer<str.length()) {
                    answer = str.length();
                    break;
                }
            }
        }
        return answer;
    }
}
