package CreeperJump.utilz;

import CreeperJump.Game.Game;
import CreeperJump.GameObjects.CobbleStep;
import CreeperJump.GameObjects.GameObjects;
import CreeperJump.GameObjects.JumpStep;
import CreeperJump.GameObjects.Player;

import java.awt.geom.Rectangle2D;
import java.util.ArrayList;

import static CreeperJump.utilz.Constants.PlayerSize.PLAYER_WIDTH;
import static CreeperJump.utilz.Constants.StepSize.STEP_HEIGHT;
import static CreeperJump.utilz.Constants.StepSize.STEP_WIDTH;

public class HelpsMethods {

    public static boolean JumpIntoStep(ArrayList<GameObjects> stepsOnTheLevel, Player player){
        for(GameObjects step : stepsOnTheLevel){
            double player_begin_X = player.getHitBox().getX();
            double player_end_X = player_begin_X + player.getHitBox().getWidth();

            double step_begin = step.getHitBox().getX();
            double step_end = step_begin + step.getHitBox().getWidth();


            if((step_begin <= player_begin_X)  && (step_end  >= player_begin_X)){
                if((step.getHitBox().getY() - (player.getHitBox().getY() + player.getHitBox().getHeight()) >= -5) && ((step.getHitBox().getY() - (player.getHitBox().getY() + player.getHitBox().getHeight()) <= 1))){
                    step.minusHealth();
                    if(step instanceof JumpStep)
                        player.setJumpBoost(true);
                    return true;
                }
            }

            if((step_begin <= player_end_X)  && (step_end  >= player_end_X)){
                if((step.getHitBox().getY() - (player.getHitBox().getY() + player.getHitBox().getHeight()) >= -5) && ((step.getHitBox().getY() - (player.getHitBox().getY() + player.getHitBox().getHeight()) <= 1))){
                    step.minusHealth();
                    if(step instanceof JumpStep)
                        player.setJumpBoost(true);
                    return true;
                }
            }
        }

        if(player.getDivideCreeper()){
            for(GameObjects step : stepsOnTheLevel){
                if(Math.abs(step.getHitBox().getX()  - player.getSecondHitBox().getX()) <= ( PLAYER_WIDTH)) // они умеют одинаковый размер
                    if((step.getHitBox().getY() - (player.getSecondHitBox().getY() + player.getSecondHitBox().getHeight()) >= -4) && ((step.getHitBox().getY() - (player.getSecondHitBox().getY() + player.getSecondHitBox().getHeight()) <= 1))){
                        step.minusHealth();
                        if(step instanceof JumpStep)
                            player.setJumpBoost(true);
                        return true;
                    }
            }
        }
        return false;
    }




}
