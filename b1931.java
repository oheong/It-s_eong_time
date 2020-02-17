import java.util.Arrays;
import java.util.Comparator;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class b1931 {
	static int N;

	static class HE {
		int s;
		int e;

		HE() {
		}

		HE(int s, int e) {
			this.s = s;
			this.e = e;
		}
	}

	static Queue<HE> q;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		q = new LinkedList<HE>();
		HE[] tempArr = new HE[N];
		for (int n = 0; n < N; n++) {
			HE h = new HE();
			h.s = sc.nextInt();
			h.e = sc.nextInt();
			tempArr[n] = h;
		}

		// 배열 정렬하기
		Arrays.sort(tempArr, new Comparator<HE>() {
			@Override
			public int compare(HE o1, HE o2) {
				// TODO Auto-generated method stub
				return o1.e == o2.e ? o1.s - o2.s : o1.e - o2.e;
				// 미친 이거 생각 어떻게함?ㅠ
			}
		});
		// 큐에 넣고
		for (int i = 0; i < N; i++) {
			q.add(tempArr[i]);
		}
		int ans = 0;
		// 뺴면서 하나하나 보기
		while (!q.isEmpty()) {
			int ss = q.peek().s;
			int ee = q.peek().e;
			q.remove();
			ans++;
			while (true) {
				if (q.isEmpty())
					break;
				if (q.peek().s < ee) {
					q.remove();
				} else
					break;
			}
		}
		System.out.println(ans);
	}
}
