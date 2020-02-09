class Solution:
    def numberToWords(self, num: int) -> str:
        if num == 0:
            return 'Zero'
        dict = {
            0: '',
            1: 'One',
            2: 'Two',
            3: 'Three',
            4: 'Four',
            5: 'Five',
            6: 'Six',
            7: 'Seven',
            8: 'Eight',
            9: 'Nine',
            10: 'Ten',
            11: 'Eleven',
            12: 'Twelve',
            13: 'Thirteen',
            14: 'Fourteen',
            15: 'Fifteen',
            16: 'Sixteen',
            17: 'Seventeen',
            18: 'Eighteen',
            19: 'Nineteen',
            20: 'Twenty',
            30: 'Thirty',
            40: 'Forty',
            50: 'Fifty',
            60: 'Sixty',
            70: 'Seventy',
            80: 'Eighty',
            90: 'Ninety',
            100: 'Hundred',
            1000: 'Thousand',
            1000000: 'Million',
            1000000000: 'Billion'
        }

        base = [1000000000, 1000000, 1000, 0]
        base_under100 = [100, 10, 0]


        def process_three_digits(n: int):
            ret = []

            if n >= 100:
                ret.append(dict[n // 100])
                ret.append(dict[100])
                n %= 100

            if n >= 0 and n <= 19:
                    ret.append(dict[n])


            else:
                ret.append(dict[n // 10 * 10])
                n %= 10
                ret.append(dict[n])


            return ' '.join(ret).strip()

        answer = []

        for i in range(len(base)):
            if num >= base[i]:
                if base[i] > 0:
                    answer.append(process_three_digits(num // base[i]))
                    answer.append(dict[base[i]])
                else:
                    answer.append(process_three_digits(num))
            if base[i] > 0:
                num %= base[i]

        return ' '.join(answer).strip()
