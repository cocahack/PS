import kotlin.math.max

class Solution {

    private val set: MutableSet<String> = HashSet()
    private var answer = 0;

    fun maxUniqueSplit(s: String): Int {
        recur(s, 0, 0)

        return answer
    }

    fun recur(s: String, before: Int, cur: Int) {
        if (cur == s.length) {
            answer = max(answer, set.size)
            return
        }

        for (i in cur until s.length) {
            val substring = s.substring(before, i + 1)

            if (!set.contains(substring)) {
                set.add(substring)
                recur(s, i + 1, i + 1)
                set.remove(substring)
            }
        }
    }

}
