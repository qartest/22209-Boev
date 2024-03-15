package org.main;

import org.MyExeception.MyExeception;
import org.Output.Output;
import org.WordConter.WordConter;


import java.io.*;

public class Main {
    public static void main(String[] args) {


        try (InputStreamReader reader = new InputStreamReader(new FileInputStream(args[0]))){
            Output output = new Output();

            int lastIndex = args[1].lastIndexOf('.');

            if(lastIndex != -1){
                String type = args[1].substring(lastIndex + 1);
                if(!type.equals("csv")){
                    throw new MyExeception("Not CSV");
                }
            }
            else{
                throw new MyExeception();
            }

            try(OutputStreamWriter writer = new OutputStreamWriter(new FileOutputStream(args[1]))){
                WordConter wordConter = new WordConter();
                output.Output_File(wordConter.Do(reader), writer);
            }

        } catch (IOException | MyExeception e) {
            throw new RuntimeException(e);
        }

    }
}