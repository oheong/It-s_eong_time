import java.util.HashMap;
import java.util.LinkedList;
import java.util.Queue;

public class kakao_19_오픈채팅방 {
	static String input[] = { "Enter uid1234 Muzi", "Enter uid4567 Prodo", "Leave uid1234", "Enter uid1234 Prodo",
			"Change uid4567 Ryan" };

	public static String[] solution(String[] record) {
		String[] answer = {};
		HashMap<String, String> hashMap = new HashMap<String, String>();
		Queue<String> queue = new LinkedList<String>();
		// temp에 받아온 input들을 다 잘라서 넣음
		String[][] temp = new String[record.length][3];
		for (int i = 0; i < record.length; i++) {
			String[] t = record[i].split(" ");
			boolean flag = false;
			for (int j = 0; j < 3; j++) {
				temp[i][j] = t[j];
				if (temp[i][0].equals("Leave") && j == 1) {
					flag = true;
					break;
				}
			}
			if (flag == false) {
				if (hashMap.containsKey(temp[i][1]))
					hashMap.remove(temp[i][1]);
				hashMap.put(temp[i][1], temp[i][2]);
			}
		}
		for (int i = 0; i < temp.length; i++) {
			// 내려오면서 해쉬에 있는거면 걍 건너뛰고 없으면 추가해줌
			if (temp[i][0].contains("Leave")) {
//				System.out.println(hashMap.get(temp[i][1]) + "님이 나갔습니다.");
				queue.add(hashMap.get(temp[i][1]) + "님이 나갔습니다.");
			} else if (temp[i][0].contains("Enter")) {
//				System.out.println(hashMap.get(temp[i][1]) + "님이 들어왔습니다.");
				queue.add(hashMap.get(temp[i][1]) + "님이 들어왔습니다.");
			}
		}
		answer = new String[queue.size()];
		int cnt = 0;
		while (!queue.isEmpty()) {
			answer[cnt++] = queue.remove();
		}
		return answer;
	}

	public static void main(String[] args) {
		String temp[] = solution(input);
	}
}
