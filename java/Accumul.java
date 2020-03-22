public class Accumul {

    public static String accum(String s) {
        String result = "";
        for (int i = 0; i < s.length(); i++) {
            if (i > 0) {
                result += "-";
            }
            String ch = Character.toString(s.charAt(i));
            result += ch.toUpperCase();
            if (i - 1 > 0) {
                result += new String(new char[i-1]).replace("\0", ch.toLowerCase());
            }
        }
        return result;
    }
}
