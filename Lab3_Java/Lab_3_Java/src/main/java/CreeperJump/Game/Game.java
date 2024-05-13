package CreeperJump.Game;

import CreeperJump.GameStates.GameState;
import CreeperJump.GameStates.Playing;

public class Game implements Runnable{

    private GameWindow gameWindow;
    private GamePanel gamePanel;
    private Thread gameThread;

    private Playing playing;
    private CreeperJump.GameStates.Menu menu;

    private final int FPS_SET = 120;
    private final int UPS_SET = 200;
    public static boolean resetGame = true;

    public final static int TILES_DEFAULT_WIDTH = 60;
    public final static int TILES_DEFAULT_HEIGHT = 100;
    public final static float SCALE = 1.0f;
    public final static int TILES_IN_WIDTH = 11;
    public final static int TILES_IN_HEIGHT = 10;

    public final static int  TILES_SIZE_WIDTH = (int)(TILES_DEFAULT_WIDTH * SCALE);
    public final static int  TILES_SIZE_HEIGHT = (int)(TILES_DEFAULT_HEIGHT * SCALE);

    public final static int GAME_WIDTH = TILES_SIZE_WIDTH  * TILES_IN_WIDTH;
    public final static int GAME_HEIGHT = TILES_IN_HEIGHT * TILES_SIZE_HEIGHT;


    public Game(){
        initClasses();
        gamePanel = new GamePanel(this);
        gameWindow = new GameWindow(gamePanel);
        gamePanel.requestFocus();
        startGameLoop();
    }

    private void initClasses(){
        menu = new CreeperJump.GameStates.Menu(this);
    }

    private void startGameLoop(){
        gameThread = new Thread(this);
        gameThread.start();
    }

    public void update(){
       switch (GameState.state){
           case MENU:
                menu.update();
               break;
           case PLAYING:
               if(resetGame)
                   ResetGame();
                playing.update();
                break;
           case QUIT:
           default:
               System.exit(0);
               break;
       }
    }

    @Override
    public void run() {
        double timePerFrame = (1000000000.0 / FPS_SET) ;
        double timePerUpdate = (1000000000.0 / UPS_SET);

        int frames = 0;
        int updates = 0;
        long lastCheck = System.currentTimeMillis();

        double deltaU = 0;
        double deltaF = 0;
        long previousTime = System.nanoTime();

        while (true) {
            long currentTime = System.nanoTime();

            deltaU += (currentTime - previousTime) / timePerUpdate;
            deltaF += (currentTime - previousTime) / timePerFrame;
            previousTime = currentTime;

            if(deltaU >= 1){
                update();
                updates++;
                deltaU--;
            }

            if(deltaF >= 1){
                gamePanel.repaint();
                deltaF--;
                frames++;
            }

            if(System.currentTimeMillis() - lastCheck >= 1000){
                lastCheck = System.currentTimeMillis();
                System.out.println("FPS: " + frames + " UPS " + updates);
                frames = 0;
                updates = 0;
            }
        }
    }
    public void windowFocusLost(){
        if(GameState.state == GameState.PLAYING){
            playing.getPlayer().resetDirBooleans();
        }
    }

    public CreeperJump.GameStates.Menu getMenu(){
        return menu;
    }

    public Playing getPlaying(){
        return playing;
    }

    private void ResetGame(){
        playing = new Playing(this);
        resetGame = false;
    }

}
