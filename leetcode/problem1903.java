class Solution {
    public String largestOddNumber(String num) {
        String answer = "";

        StringBuilder sb = new StringBuilder();

        for (char c : num.toCharArray()) {
            int cur = c - '0';
            sb.append(c);

            if (cur % 2 == 1) {
                answer = sb.toString();
            }
        }

        return answer;
    }

}
