import java.util.*;

public class Main{
    static int N, K;
    static int[] card, visited;
    static HashSet<String> hs;
    
    static void dfs(int d, String str){
        if(d==K){
            if(!hs.contains(str))
                hs.add(str);
            return;
        }
        for(int i=0;i<N;i++){
            if(visited[i]==0){
                visited[i]=1;
                dfs(d+1, str+Integer.toString(card[i]));
                visited[i]=0;
            }
        }
    }
    
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        
        N=sc.nextInt();
        K=sc.nextInt();
        hs=new HashSet<String>();
        
        card=new int[N];
        visited=new int[N];
        
        for(int i=0;i<N;i++){
            card[i]=sc.nextInt();
        }
        dfs(0,"");
        
        System.out.println(hs.size());
    }
}
