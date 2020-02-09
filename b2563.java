import java.util.Scanner;

public class b2563 {
	static int[][] map = new int[102][102];
	static int y, x;
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N=sc.nextInt();
		int ans=0;
		for(int n=0;n<N;n++) {
			x=sc.nextInt();
			y=sc.nextInt();
			
			for(int i=y;i<y+10;i++) {
				for(int j=x;j<x+10;j++) {
					if(map[i][j]==0) {
						map[i][j]=1;
						ans++;
					}
				}
			}
		}
		System.out.println(ans);
	}
}
