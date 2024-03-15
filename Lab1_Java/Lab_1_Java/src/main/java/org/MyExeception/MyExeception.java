package org.MyExeception;

import java.util.concurrent.Executors;

public class MyExeception extends Exception {
    public MyExeception(){
        super();
    }
    public MyExeception(String message){
        super(message);
    }
}
