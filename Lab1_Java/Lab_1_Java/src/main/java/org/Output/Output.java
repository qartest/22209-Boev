package org.Output;

import org.Word.Word;

import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.Reader;
import java.util.ArrayList;
import java.util.Map;
import java.util.Set;

public class Output {
    public void Output_File(ArrayList<Word> data, OutputStreamWriter Output) throws IOException {
        for(Word word : data ){
            Output.write(word.GiveWord() + "," + word.GiveCount() + "," + word.GivePercent() + "%\n");
        }
    }
}
