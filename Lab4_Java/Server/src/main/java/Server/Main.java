package Server;

import java.io.IOException;
import java.net.InetAddress;
import java.net.UnknownHostException;


public class Main {
    public static void main(String[] args) throws IOException, InterruptedException {

        var server = new Server(getInetAddress(), 8081);

        while (true) {
            server.start();
        }

    }

    private static InetAddress getInetAddress(){
        InetAddress addr;
        try{
            addr = InetAddress.getByName("127.0.0.1");
        }catch (UnknownHostException e) {
            addr = null;
        }
        return addr;
    }

}