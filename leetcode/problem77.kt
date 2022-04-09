// 조합 문제. 중복을 솎아내기 위해서는 현재 위치에 넣을 값이 이전 요소보다 작아서는 안된다.
// 즉, 만들어진 조합은 항상 오름차순이어야 한다.
class Leet77 {

    fun combine(n: Int, k: Int): List<List<Int>> {
        val answer = mutableListOf<List<Int>>()

        val container = MutableList(k) { 0 }
        val visited = MutableList(n + 1) { false }

        fun combineHelper(idx: Int) {
            if (idx == k) {
                answer.add(container.toList())
                return
            }

            for (i in 1 .. n) {
                if (visited[i] || (idx > 0 && container[idx - 1] > i)) {
                    continue
                }

                visited[i] = true
                container[idx] = i
                combineHelper(idx + 1)
                visited[i] = false
            }
        }

        combineHelper(0)

        return answer
    }

}
