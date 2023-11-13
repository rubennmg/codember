import java.io.BufferedReader;
import java.io.FileReader;

public class challenge02 {

    public static void main(String[] args) {
        String path = "message02.txt";

        try (BufferedReader reader = new BufferedReader(new FileReader(path))) {
            int character;
            int i = 0;
            String result = "";
            while ((character = reader.read()) != -1) {
                switch (character) {
                    case '#':
                        i = i + 1;
                        break;
                    case '@':
                        i -= 1;
                        break;
                    case '*':
                        i *= i;
                        break;
                    case '&': 
                        result = result + Integer.toString(i);
                        break;
                }
            }
            System.out.println(result);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}