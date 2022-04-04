import java.net.*;
import java.io.*;
// import java.util.Date;

public class Server {
    public static void main(String[] args){
        ServerSocket sSocket;
        Socket connessione = null;
        int port = 2345;
        InputStreamReader in, input;
        BufferedReader sIN, tastiera;
        OutputStream out;
        PrintWriter sOUT;
        String msgSend, msgReceive;
        try{
            sSocket = new ServerSocket(port);
            System.out.println("\nIn attesa di connessioni...");
            while(true){
                connessione = sSocket.accept();
                out = connessione.getOutputStream();
                sOUT = new PrintWriter(out);
                in = new InputStreamReader(connessione.getInputStream());
                sIN = new BufferedReader(in);
                input = new InputStreamReader(System.in);
                tastiera = new BufferedReader(input); 
                System.out.println("\nChat inizializzata");
                while(true){
                    msgReceive = sIN.readLine();
                    if (msgReceive == null){
                        System.out.println("\nIl cliente ha chiuso la chat");
                        break;
                    }
                    msgSend = tastiera.readLine();
                    if (msgSend.equals("FINE") || msgSend.equals("Fine") || msgSend.equals("exit") || msgSend.equals("Exit"))
                        break;
                    sOUT.println(msgSend);
                    sOUT.flush();
                    System.out.println(">> "+msgReceive);
                }
                break;
            }
        }
        catch(IOException e){
            System.out.println(e);
        }try{
            connessione.close();
        }catch(IOException e){
            System.out.println(e);
        }
    }
}