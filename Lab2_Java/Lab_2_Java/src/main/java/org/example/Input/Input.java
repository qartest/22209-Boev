package org.example.Input;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.InputStreamReader;

public class Input {
    public Mode mode = Mode.UNKNOWN;
    public BufferedReader reader;
    public Input(String[] args){
        reader = null;
        for (String filename : args) {
            try {
                reader = new BufferedReader(new FileReader(filename));
            } catch (FileNotFoundException ignored) {
            }

            if (reader != null) {
                break;
            }
        }
        mode = Mode.OFFLINE;
        if(reader == null){
            reader = new BufferedReader(new InputStreamReader(System.in));
            mode = Mode.ONLINE;
        }
    }
}
