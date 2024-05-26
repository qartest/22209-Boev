package Server;

import java.io.IOException;
import java.net.InetAddress;
import java.net.InetSocketAddress;
import java.net.SocketAddress;
import java.nio.channels.SelectionKey;
import java.nio.channels.Selector;
import java.nio.channels.ServerSocketChannel;
import java.nio.channels.SocketChannel;
import java.util.HashMap;
import java.util.Map;
import java.util.Queue;
import java.util.concurrent.ArrayBlockingQueue;
import java.util.concurrent.ConcurrentLinkedQueue;

public class Server {
    int port;
    InetAddress addr;

    private final Map<SocketAddress, SocketChannel> clients = new HashMap<>();
    private final Queue<SocketAddress> connectedClientsEvents = new ConcurrentLinkedQueue<>();
    private final Queue<SocketAddress> disconnectedClientsEvents = new ConcurrentLinkedQueue<>();
    private final Queue<byte[]> messagesFromClients = new ArrayBlockingQueue<>(1000);
    private final Queue<byte[]> messagesForClients = new ArrayBlockingQueue<>(1000);

    public Server(InetAddress addr, int port){
        this.port = port;
    }

    public void start(){
        try{
            try(var serverSocketChannel = ServerSocketChannel.open()){
                serverSocketChannel.configureBlocking(false);
                var serverSocket = serverSocketChannel.socket();
                serverSocket.bind(new InetSocketAddress(addr, port));
                try(var selector = Selector.open()){
                    serverSocketChannel.register(selector, SelectionKey.OP_ACCEPT);
                    while(!Thread.currentThread().isInterrupted()){
                        handleSelector(selector);
                    }
                }
            }
        }catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    public int send(){

    }

    public
}
