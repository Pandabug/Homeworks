import java.net.*;
import java.io.*;
import java.util.Date;

public class ServerClock{
    public static void main(String[] args){
        ServerSocket server_socket;
        Socket connection;
        int port = 3333;

        OutputStream out_stream;
        PrintWriter s_out;

        try{
            server_socket = new ServerSocket(port);
            while (true){
                System.out.println("Pending connection");
                connection = server_socket.accept();

                System.out.println("Connected sucesfully!");
                out_stream = connection.getOutputStream();
                s_out = new PrintWriter(out_stream);
                Date date = new Date();
                String today_date = date.toString();
                s_out.println(today_date);
                s_out.close();
                connection.close();
                System.out.println("End connection!");
            }
        } catch (IOException e){
            System.err.println(e);
        }
    }
}
