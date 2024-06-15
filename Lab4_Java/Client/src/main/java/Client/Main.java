package Client;

import java.io.*;
import java.net.InetAddress;
import java.net.InetSocketAddress;
import java.net.Socket;
import java.net.UnknownHostException;
import java.nio.ByteBuffer;
import java.nio.channels.FileChannel;
import java.nio.channels.SocketChannel;
import java.nio.charset.StandardCharsets;
import java.nio.file.Path;
import java.util.Arrays;

public class Main {
    private static SocketChannel clientSocket;

    private  static final int BUFFERSIZE = 1024;
    public static void main(String[] args) {

        if(args.length < 3){
            System.out.println("Bad input");
            return;
        }

        InetAddress address = getInetAddress(args[0]);
        int port = Integer.parseInt(args[1]);

        try {
            FileChannel file = FileChannel.open(Path.of(args[2]));

            clientSocket = SocketChannel.open(new InetSocketAddress(address, port));
            System.out.println("Check the socket");
            ByteBuffer data = ByteBuffer.allocate(BUFFERSIZE);

            String name = args[2].substring(args[2].lastIndexOf('/') + 1);
            int sizeName = name.length();
            int sizeData = (int) new File(args[2]).length();


            data.putInt(sizeName);
            data.put(name.getBytes(StandardCharsets.UTF_8));
            data.putInt(sizeData);
            int read = 0;

            while((read = file.read(data)) > 0){
                System.out.println(read);
                data.flip();
                int write = clientSocket.write(data);
                System.out.println(write);
                data.flip();
            }



            ByteBuffer answer = ByteBuffer.allocate(1024);
            int readAns = clientSocket.read(answer);
            System.out.println(readAns);

            if(readAns > 0){
                answer.flip();
                System.out.println(answer.getInt());
                System.out.println(new String(ByteBuffer.allocate(readAns - 4).put(0, answer, 4, readAns - 4).array()));
            }

            clientSocket.close();

        } catch (FileNotFoundException e) {
            System.out.println("File not found");
        } catch (IOException e) {
            System.out.println("Server not found");
        }
    }

    private static InetAddress getInetAddress(String name){
        InetAddress addr;
        try{
            addr = InetAddress.getByName(name);
        }catch (UnknownHostException e) {
            addr = null;
        }
        return addr;
    }

}