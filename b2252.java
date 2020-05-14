import java.util.ArrayList;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.Scanner;

public class b2252 {
	static int N, M;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		M = sc.nextInt();
		ArrayList<Integer>[] list = new ArrayList[N + 1];
		for (int i = 0; i <= N; i++) {
			list[i] = new ArrayList<>();
		}
		int[] indegree = new int[N + 1];
		for (int i = 0; i < M; i++) {
			int temp = sc.nextInt();
			int temp2 = sc.nextInt();
			list[temp].add(temp2);
			indegree[temp2]++;

		}
		Queue<Integer> line = new PriorityQueue<>();
		for (int i = 1; i <= N; i++) {
			if (indegree[i] == 0) {
				line.offer(i);
			}
		}
		if (line.size() == 0) {
			System.out.println("cycle");
			return;
		}
		ArrayList<Integer> result = new ArrayList<>();
		Integer cur;
		while (!line.isEmpty()) {
			cur = line.poll();
			result.add(cur);
			for (int idx : list[cur]) {
				indegree[idx]--;
				if (indegree[idx] == 0) {
					line.offer(idx);
				}
			}
		}
		// System.out.println(result);
		if (result.size() != N) {
			System.out.println("사이클 존재");
			return;
		}
		for (Integer idx : result) {
			System.out.print(idx + " ");
		}
		System.out.println();
	}// main
}

//
//// 이새끼 메모리초과 미쳤음? 다른게뭐지 아 열받네
//import java.util.ArrayList;
//import java.util.LinkedList;
//import java.util.List;
//import java.util.Scanner;
//import java.util.Queue;
//
//public class Main {
//	static int N, M;
//
//	public static void main(String[] args) {
//		Scanner sc = new Scanner(System.in);
//		N = sc.nextInt();
//		M = sc.nextInt();
//		ArrayList<Integer>[] list = new ArrayList[N + 1];
//		for (int i = 1; i <= N; i++) {
//			list[i] = new ArrayList<>();
//		}
//		// 진입차수 관리 (map)
//		int[] indegree = new int[N + 1];
//		for (int i = 0; i < M; i++) {
//			int small = sc.nextInt();
//			int big = sc.nextInt();
//			list[small].add(big);
//			indegree[big]++;
//		}
//
//		// 진입차수가 0인것들 큐에 삽입
//		Queue<Integer> queue = new LinkedList<>();
//
//		for (int i = 1; i <= N; i++) {
//			if (indegree[i] == 0) {
//				queue.offer(i);
//			}
//		}
//		if (queue.size() == 0) {
//			System.out.println("사이클 존재");
//			return;
//		}
//
//		// 큐에서 하나 빼서 연결된 애들 진입차수 1씩 감소, 다시 0 인것들은 큐에 삽임
//		// 큐에서 하나씩 뺼때 그 내용들을 리스트로 정리
//        ArrayList<Integer> result = new ArrayList<>();
//        Integer cur;
//        while(!queue.isEmpty()){
//            cur = queue.poll();
//            result.add(cur);
//            for(int idx:list[cur]){
//                indegree[idx]--;
//                if(indegree[idx]==0){
//                    queue.offer(idx);
//                }
//            }
//        }
//		if (result.size() != N) {
//			System.out.println("사이클이 존재");
//			return;
//		}
//		for (Integer idx : result) {
//			System.out.println(result+" ");
//		}
//		System.out.println();
//	}
//}
//// 8퍼?