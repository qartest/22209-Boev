package CreeperJump.GameStates;

import CreeperJump.Game.Game;
import CreeperJump.GameObjects.GameObjects;
import CreeperJump.GameObjects.Player;
import CreeperJump.Levels.LevelManager;
import CreeperJump.utilz.HelpsMethods;

import java.awt.event.KeyEvent;
import java.awt.event.MouseEvent;
import java.util.ArrayList;

import static CreeperJump.Game.Game.SCALE;
import static CreeperJump.utilz.Constants.PlayerSize.*;
import static CreeperJump.utilz.HelpsMethods.JumpIntoStep;

public class Playing extends State implements Statemethods{
    private LevelManager levelManager;
    private Player player;

    private ArrayList<GameObjects> steps = new ArrayList<>();

    private int GameScore = 0;
    private double minYCoord = PLAYER_START_Y;


    public Playing(Game game){
        super(game);
        initClasses();
    }
    private void initClasses(){
        player = new Player(PLAYER_START_X, PLAYER_START_Y, (int) (PLAYER_WIDTH_DEFAULT * SCALE), (int) (PLAYER_HEIGHT_DEFAULT * SCALE));
        levelManager = new LevelManager(steps);
    }

    @Override
    public void update() {
        playerUpdate();

    }

    @Override
    public void mouseClicked(MouseEvent e) {

    }

    @Override
    public void mouseReleased(MouseEvent e) {

    }

    @Override
    public void mousePressed(MouseEvent e) {

    }

    @Override
    public void mouseMoved(MouseEvent e) {

    }

    @Override
    public void keyPressed(KeyEvent e) {
        switch (e.getKeyCode()){

            case KeyEvent.VK_A:
                player.setLeft(true);
                break;
            case KeyEvent.VK_D:
                player.setRight(true);
                break;
            default:
                break;
        }
    }

    @Override
    public void keyReleased(KeyEvent e) {

        switch (e.getKeyCode()){
            case KeyEvent.VK_A:
                player.setLeft(false);
                break;

            case KeyEvent.VK_D:
                player.setRight(false);
                break;
            case KeyEvent.VK_SPACE:
                break;
        }

    }

    @Override
    public void mouseDragged(MouseEvent e) {

    }

    private void playerUpdate(){

        player.updateAnimationTick();

        player.setJump(false);

        if(player.getAirSpeed() > 0){
            if(JumpIntoStep(steps, player)){
                player.ZeroSpeed();
                player.AntiGravity();
                player.setJump(true);
                player.setWaitJump(true);
            }
        } else if((player.getAirSpeed() == 0) && (!player.getPlayingJump())){
            player.JumpSpeed();
            player.PlusJumpBoost();
            player.setWaitJump(false);
            levelManager.DeleteSteps();
        } else if (player.getWaitJump()){
            player.AntiGravity();
        }else if(player.getAirSpeed() < 0){
            if(minYCoord > player.getHitBox().getY()){
                minYCoord = player.getHitBox().getY();
                GameScore = 500 - (int)minYCoord;
            }
        }

        player.DoGravity();
        player.updateXPos();

        levelManager.CheckSteps(GameScore);
        levelManager.update((int)minYCoord);

        checkPlayer();
    }

    public ArrayList<GameObjects> getSteps(){
        return steps;
    }
    public Player getPlayer(){
        return player;
    }

    public int getGameScore(){
        return GameScore;
    }

    private void checkPlayer(){
        if(player.getHitBox().getY() + GameScore > 1000){
            GameState.state = GameState.MENU;
            Game.resetGame = true;
        }
    }
}
