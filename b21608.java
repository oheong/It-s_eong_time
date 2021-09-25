import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;

/*
 * 
 * @author Oheong
 * 
 * 1. 비어있는 칸 중에서 좋아하는 학생이 인접한 칸에 가장 많은 칸으로 자리를 정한다 => 비어있는 칸 중에서, 내가 좋아하는 애들이 가장 많은 곳으로 앉아야 함
 * 2. 1을 만족하는 칸이 여러개이면, 인접한 칸 중에서 비어있는 칸이 가장 많은 칸으로 간다. => 근데 그런게 여러개이면 주위에 비어있는 칸이 가장 많은 곳으로
 * 3. 2를 만족하는 칸도 여러개인 경우에는 행의 번호가 가장 작은 칸으로, 그러한 칸도 여러개이면 열의 번호가 가장 작은 칸으로 간다.
 *
 */
public class b21608 {
	static int N;
	static int[] by = { -1, 0, 1, 0 }, bx = { 0, 1, 0, -1 };
	static int[][] student, map;

	static List<int[]> con1(int a, int b, int c, int d) {
		List<int[]> list = new ArrayList<int[]>(); // 좋아하는 학생이 가장 많은 칸들의 리스트
		int max = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (map[i][j] != 0)
					continue;

				int[] tempList = { i, j };
				int temp = 0;

				for (int dir = 0; dir < 4; dir++) {
					int ny = i + by[dir];
					int nx = j + bx[dir];
					if (0 <= ny && ny < N && 0 <= nx && nx < N) {
						if (map[ny][nx] == a || map[ny][nx] == b || map[ny][nx] == c || map[ny][nx] == d) {
							temp++;
						}
					}
				}

				if (max < temp) {
					max = temp;
					int size = list.size();
					for (int index = 0; index < size; index++)
						list.remove(0);

				}

				else if (max > temp)
					continue;

				list.add(tempList);
			}
		}

		return list;
	}

	static int getNum(int a) {
		if (a == 1)
			return 1;
		else if (a == 2)
			return 10;
		else if (a == 3)
			return 100;
		else if (a == 4)
			return 1000;
		return 0;
	}

	static int ans() {
		int sum = 0;

//		print();

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {

				for (int index = 0; index < student.length; index++) {
					if (student[index][0] == map[i][j]) {
						int temp = 0;
						for (int dir = 0; dir < 4; dir++) {
							int ny = i + by[dir];
							int nx = j + bx[dir];
							if (0 <= ny && ny < N && 0 <= nx && nx < N) {
								if (map[ny][nx] == student[index][1] || map[ny][nx] == student[index][2]
										|| map[ny][nx] == student[index][3] || map[ny][nx] == student[index][4])
									temp++;

							}
						}
						sum += getNum(temp);
					}
				}
			}
		}
		return sum;
	}

	static void print() {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				System.out.print(map[i][j] + " ");
			}
			System.out.println();
		}
		System.out.println("====================");
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		N = sc.nextInt();
		map = new int[N][N];
		student = new int[N * N][5];

		for (int i = 0; i < N * N; i++) {
			for (int j = 0; j < 5; j++) {
				student[i][j] = sc.nextInt();
			}
		}

		for (int cnt = 0; cnt < N * N; cnt++) {

//			print();

			// 학생 수 만큼 횟수 진행
			List<int[]> l1 = con1(student[cnt][1], student[cnt][2], student[cnt][3], student[cnt][4]);

			if (l1.size() <= 1) // 1보다 작은 조건이 들어올까,,,?ㅠ
				map[l1.get(0)[0]][l1.get(0)[1]] = student[cnt][0]; // 걍 한 자리 밖에 없으면 바로 그 자리를 줘라

			else { // 2. 그런 자리가 여러개 있으면 빈 자리가 가장 많은 곳으로 줘라

				int max = 0;
				List<int[]> l2 = new ArrayList<int[]>();

				for (int i = 0; i < l1.size(); i++) {
					// 빈 자리 체크
					int ty = l1.get(i)[0];
					int tx = l1.get(i)[1];
					int temp = 0;

					int[] tempList = { ty, tx };

					for (int dir = 0; dir < 4; dir++) {
						int ny = ty + by[dir];
						int nx = tx + bx[dir];
						if (0 <= ny && ny < N && 0 <= nx && nx < N && map[ny][nx] == 0) {
							temp++;
						}
					}

					if (max < temp) {
						max = temp;
						int size = l2.size();
						for (int index = 0; index < size; index++)
							l2.remove(0);

					}

					else if (max > temp)
						continue;

					l2.add(tempList);
				}

				// con3
//				if (l2.size() <= 1)
//					map[l2.get(0)[0]][l2.get(0)[1]] = student[cnt][0];
//
//				else {
//					// l2정렬
//					Collections.sort(l2, new Comparator<int[]>() {
//						@Override
//						public int compare(int[] o1, int[] o2) { // o1내 o2니
//							if (o1[0] < o2[0])
//								return -1; // 외우기
//							else if (o1[0] == o2[0]) {
//								if (o1[1] < o2[1])
//									return -1;
//								else
//									return 1;
//							}
//							return 1;
//						}
//
//					});

					// 정렬 후
					map[l2.get(0)[0]][l2.get(0)[1]] = student[cnt][0];
//				}
			}
		}

		System.out.println(ans());

	}
	// End main
}
