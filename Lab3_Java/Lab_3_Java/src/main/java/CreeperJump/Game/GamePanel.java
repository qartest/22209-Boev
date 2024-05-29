package CreeperJump.Game;

import CreeperJump.GameStates.GameState;
import CreeperJump.Inputs.KeyboardInputs;
import CreeperJump.Inputs.MouseInputs;

import javax.swing.*;
import java.awt.*;

import static CreeperJump.Game.Game.*;
import static CreeperJump.utilz.Constants.ScoreConstant.*;



public class GamePanel extends JPanel {
    private MouseInputs mouseInputs;
    private Game game;
    private Render render;

    public GamePanel(Game game){

        mouseInputs = new MouseInputs(this);
        this.game = game;

        setPanelSize();
        addKeyListener(new KeyboardInputs(this));
        addMouseListener(mouseInputs);
        addMouseMotionListener(mouseInputs);

        render = new Render();
    }

    public void setPanelSize(){
        Dimension size = new Dimension(GAME_WIDTH,  GAME_HEIGHT);
        setPreferredSize(size);
        System.out.println("size: " + GAME_WIDTH + " " + GAME_HEIGHT);
    }

    public void paintComponent(Graphics g){
        super.paintComponent(g);


        switch (GameState.state){
            case MENU:
                render.renderMenu(g, game.getMenu().getButtons());
                break;
            case PLAYING:
                render.renderSteps(g, game.getPlaying().getSteps(), game.getPlaying().getGameScore());
                render.renderPlayer(g, game.getPlaying().getPlayer(), game.getPlaying().getGameScore());
                renderGameScore(g, game.getPlaying().getGameScore());
                break;
            default:
                break;
        }


        Toolkit.getDefaultToolkit().sync();
    }

    public Game getGame(){
        return game;
    }

    private void renderGameScore(Graphics g,  int GameScore){
        String string = "Your score:" + GameScore / 10;
        g.setColor(Color.CYAN);
        g.fillRect(0, 0, SCORE_WIDTH , SCORE_HEIGHT);
        g.setColor(Color.BLUE);
        g.setFont(new Font("Arial", Font.PLAIN, 20));

        g.drawString(string, SCORE_BEGIN_X, SCORE_BEGIN_Y);
    }
}
