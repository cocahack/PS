import java.util.*;

public class Main {

    private static Stack<String> before = new Stack<>();
    private static Stack<String> after = new Stack<>();
    private static int n;

    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt();

        String tmp;

        for(int i=0; i<n; ++i) {
            tmp = scanner.next();
            before.push(tmp);
        }

        for(int i=0; i<n; ++i) {
            tmp = scanner.next();
            after.push(tmp);
        }

        int answer = 0;

        Set<String> overtakes = new HashSet<>();

        while (!before.empty() && !after.empty()) {

            if(after.peek().equals(before.peek())) {
                before.pop();
                after.pop();
            } else if (overtakes.contains(after.peek())) {
                after.pop();
            } else {
                answer++;
                overtakes.add(before.peek());
                before.pop();
            }

        }


        System.out.println(answer);
    }

}

