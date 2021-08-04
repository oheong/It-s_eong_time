class Solution {
    static int[] visited;
    static int min=2123456789;
    static int diff(String a, String b){
        int cnt=0;
        int size=a.length();
        for(int i=0;i<size;i++){
            if(a.charAt(i)==b.charAt(i)) continue;
            cnt++;
        }
        return cnt;
    }
    static void dfs(int d, String temp, String target, String[] words){
        if(d > words.length)return;
        if(temp.contains(target)) {
            if(d<min)
                min=d;
            return;
        }
        
        for(int i=0;i<words.length;i++){
            if(visited[i]==0&&diff(temp, words[i])==1){
                visited[i]=1;
                dfs(d+1, words[i], target, words);
                visited[i]=0;
            }
        }
    }
    public int solution(String begin, String target, String[] words) {
        visited = new int[words.length];
        dfs(0, begin, target, words);
        if(min==2123456789)min=0;
        return min;
    }
}
