import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class Main {

    private static int n, e;
    private static List<List<Integer>> graph;
    private static List<Boolean> visited;

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        e = sc.nextInt();

        graph = new ArrayList<>(n+1);
        for(int i=0; i<=n; ++i) graph.add(new ArrayList<>());
        visited = new ArrayList<>(Collections.nCopies(n+1, false));

        int a, b;
        for(int i=0; i<e; ++i) {
            a = sc.nextInt();
            b = sc.nextInt();
            graph.get(a).add(b);
            graph.get(b).add(a);
        }

        dfs(1);

        long answer = visited.stream().filter(isVisited -> isVisited).count() - 1;

        System.out.println(answer);
    }

    public static void dfs(int here) {
        if(visited.get(here)) return;
        visited.set(here, true);

        for(int there : graph.get(here)) {
            dfs(there);
        }
    }

}

