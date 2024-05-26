package Server;

import java.net.InetAddress;
import java.net.UnknownHostException;
import java.util.concurrent.Executor;
import java.util.concurrent.Executors;
import java.util.logging.Logger;

public class TcpServer {
//    private final Logger logger = LoggerFactory.getLogger(TcpServer.class);

    public void run(){

        var server = new Server(getInetAddress(),8081);

        try{
            var executor = Executors.newFixedThreadPool(2);
            executor.submit(server::start);

            executor.submit(() -> {
                while(!Thread.currentThread().isInterrupted()){
                    try{

                    }catch (Exception ex){
                        System.out.println("error:" + ex.getMessage());
                    }
                }
            });
        } catch (Exception e) {

        }
    }

    private InetAddress getInetAddress(){
        InetAddress addr;
        try{
            addr = InetAddress.getByName("127.0.0.1");
        }catch (UnknownHostException e) {
            addr = null;
        }
        return addr;
    }
}
