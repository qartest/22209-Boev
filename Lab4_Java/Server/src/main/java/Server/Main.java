package Server;

import java.io.IOException;
import java.net.InetSocketAddress;
import java.net.SocketAddress;
import java.nio.ByteBuffer;
import java.nio.channels.DatagramChannel;
import java.util.concurrent.TimeUnit;

public class Main {
    public static void main(String[] args) throws IOException, InterruptedException {

        DatagramChannel chan = DatagramChannel.open();
        chan.configureBlocking( false );
        chan.bind( new InetSocketAddress( 7777 ) );
//        var server = new Server();
        ByteBuffer buffer = ByteBuffer.allocate( 4*1024 );

        while (true) {
            buffer.clear();
            System.out.println("trying non-blocking receive...");
            SocketAddress from = chan.receive(buffer);
            System.out.println("non-blocking receive done.");

            if (from != null) {
                buffer.flip();
                System.out.printf("<<<--- got [%x] byte from %s%n", buffer.get(), from);
            }

            System.out.println( "sleeping..." );
            TimeUnit.SECONDS.sleep( 5 );
        }
    }
}