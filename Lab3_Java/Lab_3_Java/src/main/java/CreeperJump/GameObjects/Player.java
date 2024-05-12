package CreeperJump.GameObjects;

import CreeperJump.Game.Game;
import CreeperJump.utilz.LoadSave;

import java.awt.*;
import java.awt.image.BufferedImage;

import static CreeperJump.utilz.Constants.Physics.*;
import static CreeperJump.utilz.Constants.PlayerConstants.*;
import static CreeperJump.utilz.Constants.PlayerSize.*;


public class Player extends GameObjects{

    private int playerAction = STATIC;
    private boolean left, right;
    private boolean jump = false;
    private boolean playing_jump = false;
    private boolean wait_animation_jump = false;

    private boolean divideCreeper = false;

    private float airSpeed = 1.0f;

    private int aniTick, aniIndex, aniSpeed = 5;

    private BufferedImage[][] animations;
    public Player(float x, float y, int width, int height) {
        super(x, y, width, height);
        initHitbox(x, y, PLAYER_WIDTH, PLAYER_HEIGHT);

    }

    private void setAnimation(){
        int startAni = playerAction;

        if(jump){
            playing_jump = true;
        }
        if(playing_jump)
            playerAction = JUMP;
        else
            playerAction = STATIC;


        if(startAni != playerAction){
            resetAniTIck();
        }
    }

    private void resetAniTIck(){
        aniTick = 0;
        aniIndex = 0;
    }

    public void updateXPos() {
            if(left){
                hitBox.x += LEFT_SPEED;
                if(divideCreeper)
                    secondHitBox.x += LEFT_SPEED;
            }
            if(right){
                hitBox.x += RIGHT_SPEED;
                if(divideCreeper)
                    secondHitBox.y += RIGHT_SPEED;
            }

            divideCreeper = false;
            if(hitBox.x < 0){
                divideCreeper = true;
                initSecondInitHitBox((hitBox.x + Game.GAME_WIDTH) % Game.GAME_WIDTH, hitBox.y, PLAYER_WIDTH, PLAYER_HEIGHT);
            }else if(hitBox.x + hitBox.width > Game.GAME_WIDTH){
                divideCreeper = true;
                initSecondInitHitBox((hitBox.x + hitBox.width) % Game.GAME_WIDTH - hitBox.width, hitBox.y, PLAYER_WIDTH, PLAYER_HEIGHT);
            }

            if(hitBox.x + hitBox.width <= 0){
                hitBox.x += Game.GAME_WIDTH;
                divideCreeper = false;
            }
            else if(hitBox.x > Game.GAME_WIDTH){
                divideCreeper = false;
            }

            hitBox.x %= Game.GAME_WIDTH;
    }

    public void updateAnimationTick() {

        setAnimation();

        aniTick++;
        if(aniTick >= aniSpeed){
            aniTick = 0;
            aniIndex++;
            if(aniIndex >= GetSpriteAmount(playerAction)){
                aniIndex = 0;
                if(playing_jump)
                    playing_jump = false;
            }

        }
    }
    public void resetDirBooleans(){
        left = false;
        right = false;
    }

    public boolean isLeft() {
        return left;
    }

    public void setLeft(boolean left) {
        this.left = left;
    }

    public boolean isRight() {
        return right;
    }

    public void setRight(boolean right) {
        this.right = right;
    }
    public void setJump(boolean jump){
//        System.out.println("Jump");
        this.jump = jump;
    }

    public void JumpSpeed(){
        airSpeed = 0;
        airSpeed += JUMP_SPEED;
        System.out.println("Jump");
    }
    public void ZeroSpeed(){
        airSpeed = 0;
    }
    public void DoGravity(){
        airSpeed += GRAVITY;
        hitBox.y += airSpeed;
        if(divideCreeper)
            secondHitBox.y += airSpeed;

    }

    public float getAirSpeed(){
        return airSpeed;
    }

    public boolean getPlayingJump(){
        return playing_jump;
    }

    public boolean getWaitJump(){
        return wait_animation_jump;
    }

    public void setWaitJump(boolean jp){
        this.wait_animation_jump = jp;
    }

    public void AntiGravity(){
        airSpeed -= GRAVITY;
    }

    public boolean getDivideCreeper(){
        return divideCreeper;
    }

    public int getPlayerAction(){
        return playerAction;
    }

    public int getAniIndex(){
        return aniIndex;
    }
}
