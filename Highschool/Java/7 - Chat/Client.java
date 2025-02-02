import java.net.*;
import java.io.*;

public class Client {
    public static void main(String[] args){
        Socket connessione = null;
        int port = 2345;
        InputStreamReader in, input;
        BufferedReader sIN, tastiera;
        OutputStream out;
        PrintWriter sOUT;
        String msgSend, msgReceive;
        try{
            connessione = new Socket("localhost", port);
            System.out.println("\nConnessione eseguita");
        }
        catch(IOException e){
            System.out.println(e);
            System.exit(-1); // exit program with error
        }
        try{
            in = new InputStreamReader(connessione.getInputStream());
            sIN = new BufferedReader(in);
            out = connessione.getOutputStream();
            sOUT = new PrintWriter(out);
            input = new InputStreamReader(System.in);
            tastiera = new BufferedReader(input);
            System.out.println("\nChat inizializzata");
            while(true){
                msgSend = tastiera.readLine();
                if (msgSend.equals("FINE") || msgSend.equals("Fine") || msgSend.equals("exit") || msgSend.equals("Exit"))
                    break;
                sOUT.println(msgSend);
                sOUT.flush();
                msgReceive = sIN.readLine();
                System.out.println(">> "+msgReceive);
            }
        }catch(IOException e){
            System.out.println(e);
        }try{
            connessione.close();
        }catch(IOException e){
            System.out.println(e);
        }
    }
}