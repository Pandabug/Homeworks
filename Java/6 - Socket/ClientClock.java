import java.net.*;
import java.io.*;

public class ClientClock {
    public static void main(String[] args){
        Socket connection;
        String server = "localhost";
        int port = 3333;

        InputStream input;
        InputStreamReader input_reader;
        BufferedReader s_in;

        try{
            connection = new Socket(server, port);
            System.out.println("Open connection.");

            input = connection.getInputStream();
            input_reader = new InputStreamReader(input);
            s_in = new BufferedReader(input_reader);

            String clock = s_in.readLine();
            System.out.println("Date: " + clock);

            s_in.close();
            connection.close();
            System.out.println("End connection!");
        } catch (IOException e){
            System.err.println(e);
        }
    }
}
