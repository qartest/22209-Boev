import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.Reader;

public class BadReader extends BufferedReader {
    public BadReader(Reader in, int sz) {
        super(in, sz);
    }

    public BadReader(InputStreamReader in) {
        super(in);
    }

    @Override
    public String readLine() throws IOException {
        throw new IOException();
    }
}
