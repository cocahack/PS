/**
 * [problem link](https://leetcode.com/problems/string-to-integer-atoi/)
 */
class Leet8 {

    /**
     * 1. 앞에 붙은 공백은 무시
     * 2. 다음 문자가 '-' 또는 '+' 인지 확인. 이는 결과가 음수인지 양수인지를 결정하게 될 것이다. 아무것도 없다면 양수로 가정한다.
     * 3. 숫자가 아닌 문자가 나올 때까지 또는 입력의 끝까지 계속 읽는다. 그 뒤의 나머지 문자열은 무시한다.
     * 4. 문자열을 숫자로 변환한다. ("123" -> 123, "0023" -> 23) 숫자가 없다면 0이다. 상황에 따라 부호도 바꿔야 한다.
     * 5. 결과가 32 비트 정수 범위를 넘어선다면 범위의 가장 끝 범위로 대체한다.
     * 6. 결과를 반환한다.
     */
    fun myAtoi(s: String): Int {
        val trim = s.trimStart()

        val processor = AtoIProcessor(Step2(), trim)

        return processor.process()
    }
}

interface Step{
    fun progress(processor: AtoIProcessor): Boolean

    fun nextStep(processor: AtoIProcessor)

    fun terminate(processor: AtoIProcessor) {
        processor.forward()
        nextStep(processor)
    }
}

class Step2 : Step {
    override fun progress(processor: AtoIProcessor): Boolean {
        val c = processor.current()

        if (c == null) {
            nextStep(processor)
            return false
        }

        if (c == '-') {
            processor.forward()
            processor.setSign(-1)
        }

        if (c == '+') {
            processor.forward()
        }

        nextStep(processor)
        return false
    }

    override fun nextStep(processor: AtoIProcessor) {
        processor.setStep(Step3())
    }

}

class Step3 : Step {
    override fun progress(processor: AtoIProcessor): Boolean {
        val c = processor.current()

        if (c == null || !c.isDigit()) {
            terminate(processor)
            return false
        }

        processor.addChar(c)
        processor.forward()

        return false
    }

    override fun nextStep(processor: AtoIProcessor) {
        processor.setStep(Final())
    }
}

class Final: Step {
    override fun progress(processor: AtoIProcessor): Boolean {
        return true
    }

    override fun nextStep(processor: AtoIProcessor) {
        processor.setStep(this)
    }
}

class AtoIProcessor(
    private var step: Step,
    private val s: String,
) {

    private var sign: Int = 1
    private var container = mutableListOf<Char>()
    private var idx = Idx()

    fun process(): Int {
        while (true) {
            if (step.progress(this)) {
                break
            }
        }

        return processContainer()
    }

    private fun processContainer(): Int {
        var i = 0

        var value = 0L

        while (i < container.size) {

            value = (value * 10) + (container[i] - '0')

            val tmp = value * sign

            if (tmp > Int.MAX_VALUE || tmp < Int.MIN_VALUE) {
                break
            }
            i++
        }

        value *= sign

        if (value > Int.MAX_VALUE) {
            return Int.MAX_VALUE
        }

        if (value < Int.MIN_VALUE) {
            return Int.MIN_VALUE
        }

        return value.toInt()
    }

    fun forward() {
        idx.i++
    }

    fun current(): Char? {
        return if (idx.i < s.length) s[idx.i] else null
    }

    fun addChar(char: Char) {
        this.container.add(char)
    }

    fun setSign(sign: Int) {
        this.sign = sign
    }

    fun setStep(step: Step) {
        this.step = step
    }
}

data class Idx(var i: Int = 0)
