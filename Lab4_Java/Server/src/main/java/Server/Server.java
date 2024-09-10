package Server;

import java.io.*;
import java.nio.ByteBuffer;
import java.nio.channels.*;
import java.nio.charset.StandardCharsets;
import java.net.InetAddress;
import java.net.InetSocketAddress;
import java.util.Iterator;
import java.util.Set;


public class Server {

    private int port;
    private InetAddress addr;


    public Server(InetAddress addr, int port){
        this.port = port;
        this.addr = addr;
    }

    public void start() throws IOException{

        Selector selector = Selector.open();
        ServerSocketChannel serverSocket = ServerSocketChannel.open();
        serverSocket.bind(new InetSocketAddress(addr, port));
        serverSocket.configureBlocking(false);
        serverSocket.register(selector, SelectionKey.OP_ACCEPT);

        while(true){
            selector.select();
            Set<SelectionKey> selectedKeys = selector.selectedKeys();
            Iterator<SelectionKey> iter = selectedKeys.iterator();
            while (iter.hasNext()) {

                SelectionKey key = iter.next();

                if (key.isAcceptable()) {
                    acceptConnection(selector, serverSocket);
                }

                if (key.isReadable()) {
                    channelTask( key);
                }
                iter.remove();
            }
        }

    }

    private void acceptConnection(Selector selector, ServerSocketChannel serverSocket){
        try {
            SocketChannel client = serverSocket.accept();
            client.configureBlocking(false);
            client.register(selector, SelectionKey.OP_READ);
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }


    private void channelTask(SelectionKey key){
        try(SocketChannel socketChannel = (SocketChannel) key.channel()){

            ByteBuffer buffer = ByteBuffer.allocate(1024);
            int readBytes = socketChannel.read(buffer);

            if(readBytes < 4){
                throw new IOException();
            }

            System.out.println(readBytes);
            buffer.flip();

            int sizename = buffer.getInt();

            System.out.println(buffer.position());
            ByteBuffer filename = ByteBuffer.allocate(sizename);


            filename.put(0, buffer, 4, sizename);
            System.out.println(buffer.position());


            String namestr = new String(filename.array());
            System.out.println(namestr);

            int dataSize = ByteBuffer.allocate(4).put(0, buffer, 4 + sizename, 4).getInt();
            System.out.println(dataSize);

            String FullName = "/home/unusual-kok/GitThere/" + namestr + ".Myfile";
            File myFile = new File(FullName);
            myFile.createNewFile();


            try (BufferedWriter myWrite = new BufferedWriter(new OutputStreamWriter(new FileOutputStream(FullName)))) {

                if(dataSize != 0){
                    ByteBuffer ost = ByteBuffer.allocate(readBytes - 4 - 4 - sizename);
                    ost.put(0, buffer, 4 + 4 + sizename, readBytes - 4 - 4 - sizename);

                    String output = new String(ost.array());
                    myWrite.write(output);
                    System.out.println(output.length());

                    ByteBuffer secondData = ByteBuffer.allocate(1024);

                    while((readBytes = socketChannel.read(secondData)) > 0){

                        System.out.println(readBytes);
                        if(readBytes != 1024){
                            output = new String(ByteBuffer.allocate(readBytes).put(0, secondData, 0, readBytes).array());
                        }
                        else{
                            output = new String(secondData.array());
                        }

                        myWrite.write(output);
                        secondData.flip();
                    }
                }
            }

            var writeBuffer1 = ByteBuffer.allocate(4 + 3 + sizename).putInt(sizename+3);

            String answerName = namestr + "Arc";

            writeBuffer1.put(answerName.getBytes(StandardCharsets.UTF_8));
            writeBuffer1.flip();
           socketChannel.write(writeBuffer1);



        } catch (IOException e) {
            System.out.println("Error with reading");
        }


    }
}
