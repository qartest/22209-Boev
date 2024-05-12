package CreeperJump.utilz;

import CreeperJump.Game.Game;
import CreeperJump.GameObjects.CobbleStep;
import CreeperJump.GameObjects.GameObjects;
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
                if((step.getHitBox().getY() - (player.getHitBox().getY() + player.getHitBox().getHeight()) >= -4) && ((step.getHitBox().getY() - (player.getHitBox().getY() + player.getHitBox().getHeight()) <= 1))){
                    return true;
                }
            }

            if((step_begin <= player_end_X)  && (step_end  >= player_end_X)){
                if((step.getHitBox().getY() - (player.getHitBox().getY() + player.getHitBox().getHeight()) >= -4) && ((step.getHitBox().getY() - (player.getHitBox().getY() + player.getHitBox().getHeight()) <= 1))){
                    return true;
                }
            }
        }

        if(player.getDivideCreeper()){
            for(GameObjects step : stepsOnTheLevel){
                if(Math.abs(step.getHitBox().getX()  - player.getSecondHitBox().getX()) <= ( PLAYER_WIDTH)) // они умеют одинаковый размер
                    if((step.getHitBox().getY() - (player.getSecondHitBox().getY() + player.getSecondHitBox().getHeight()) >= -3) && ((step.getHitBox().getY() - (player.getSecondHitBox().getY() + player.getSecondHitBox().getHeight()) <= 0))){
                        return true;
                    }
            }
        }
        return false;
    }

    public static void CreateLevel(ArrayList<GameObjects> steps){
        for(int i = 0; i <= Game.TILES_IN_WIDTH; ++i){
            steps.add(new CobbleStep( i * STEP_WIDTH, 1000,  STEP_WIDTH, STEP_HEIGHT));
        }

    }


}
