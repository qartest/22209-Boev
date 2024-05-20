package CreeperJump.Levels;

import CreeperJump.Game.Game;
import CreeperJump.GameObjects.CobbleStep;
import CreeperJump.GameObjects.GameObjects;
import CreeperJump.GameObjects.JumpStep;
import CreeperJump.GameObjects.TreeStep;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.Random;

import static CreeperJump.utilz.Constants.StepSize.*;

public class LevelManager {
    private int minYGenerate;
    private ArrayList<GameObjects> steps;

    private Random random = new Random();

    public LevelManager(ArrayList<GameObjects> steps){

        this.steps = steps;

        minYGenerate = 1000;
        CreateBegin();
        minYGenerate -= 1000;
    }

    public void update(int nowMin){
        if(nowMin <= minYGenerate + 2000){
            if(minYGenerate >= - 5000){
                GenerateEazyLevel();
            } else if(minYGenerate >= - 15000){
                GenerateMiddleLevel();
            }
            else{
                GenerateHightLevel();
            }
            minYGenerate -= 2000;
        }
    }

    private void GenerateMiddleLevel() {

            for(int i = 0; i < 2000 / 200; ++i){
                int randomNumber = random.nextInt(2);
                for(int j = 0; j < randomNumber; ++j){
                    int randomX = random.nextInt( Game.GAME_WIDTH);
                    int randomY = i * 200 + random.nextInt(200);
                    int coordY = minYGenerate - randomY;
                    steps.add(new CobbleStep(randomX, coordY, STEP_WIDTH,STEP_HEIGHT));
                }
                int randomTreeStep = 1 + random.nextInt(2);
                for(int j = 0; j < randomTreeStep; ++j){
                    int randomX = random.nextInt( Game.GAME_WIDTH);
                    int randomY = i * 200 + random.nextInt(200);
                    int coordY = minYGenerate - randomY;
                    steps.add(new TreeStep(randomX, coordY, STEP_WIDTH,STEP_HEIGHT));
                }
            }
            int randomJump = random.nextInt(2);
            for(int i = 0; i < randomJump; ++i){
                int randomY = random.nextInt(2000);
                int randomX =  random.nextInt( Game.GAME_WIDTH);
                int coordY = minYGenerate - randomY;
                steps.add(new JumpStep(randomX, coordY, STEP_WIDTH,STEP_HEIGHT));
            }


    }

    private void GenerateHightLevel(){

        for(int i = 0; i < 2000 / 200; ++i){
            int randomTreeStep = 1 + random.nextInt(3);
            for(int j = 0; j < randomTreeStep; ++j){
                int randomX = random.nextInt(Game.GAME_WIDTH);
                int randomY = i * 200 + random.nextInt(200);
                int coordY = minYGenerate - randomY;
                steps.add(new TreeStep(randomX, coordY, STEP_WIDTH,STEP_HEIGHT));
            }
        }

    }


    private void GenerateNewLevel(){
        for(int i = 0; i < 2000 / 200; ++i){
            int randomNumber = 1 + random.nextInt(5);
            for(int j = 0; j < randomNumber; ++j){
                int randomX = random.nextInt( Game.GAME_WIDTH);
                int randomY = i * 200 + random.nextInt(200);
                int coordY = minYGenerate - randomY;


                if(j == 3){
                    steps.add(new TreeStep(randomX, coordY, STEP_WIDTH,STEP_HEIGHT));
                }
                else if(j == 2){
                    steps.add(new JumpStep(randomX, coordY, STEP_WIDTH,STEP_HEIGHT));
                }else{
                    steps.add(new CobbleStep(randomX, coordY, STEP_WIDTH,STEP_HEIGHT));
                }

            }
        }
    }
    private void GenerateEazyLevel(){
        for(int i = 0; i < 2000 / 200; ++i){
            int randomNumber = 1 + random.nextInt(3);
            for(int j = 0; j < randomNumber; ++j){
                int randomX = random.nextInt( Game.GAME_WIDTH);
                int randomY = i * 200 + random.nextInt(200);
                int coordY = minYGenerate - randomY;
                steps.add(new CobbleStep(randomX, coordY, STEP_WIDTH,STEP_HEIGHT));
            }
        }
        int randomJump = 1 + random.nextInt(3);
        for(int i = 0; i < randomJump; ++i){
            int randomY = random.nextInt(2000);
            int randomX =  random.nextInt( Game.GAME_WIDTH);
            int coordY = minYGenerate - randomY;
            steps.add(new JumpStep(randomX, coordY, STEP_WIDTH,STEP_HEIGHT));
        }

    }
    public void CheckSteps(int GameScore){

        Iterator<GameObjects> iterator = steps.iterator();

        while(iterator.hasNext()){
            GameObjects now = iterator.next();
            if(now.getHitBox().getY() + GameScore > 1000){
                iterator.remove();
            }
        }
    }

    public void DeleteSteps() {
        Iterator<GameObjects> iterator = steps.iterator();

        while (iterator.hasNext()) {
            GameObjects now = iterator.next();
            if (now.getHealth() == 0) {
                iterator.remove();
            }
        }
    }

    public void CreateBegin(){
        for(int i = 0; i < 1000/200; i++){
            int randomNumber = 4 + random.nextInt(2);
            for(int j = 0; j < randomNumber; ++j){
                int randomX;
                if(i != 3){
                    randomX = random.nextInt( Game.GAME_WIDTH);
                }
                else{
                    if(j % 2 == 0){
                        int gw = (int)(Game.GAME_WIDTH * 0.3f);
                        randomX = random.nextInt(gw);
                    }
                    else{
                        int gw = (int)(Game.GAME_WIDTH * 0.7f);
                        randomX = gw + random.nextInt((int)(Game.GAME_WIDTH * 0.3f));
                    }
                }

                int randomY = i * 200 + random.nextInt(200);
                int coordY = minYGenerate - randomY;

                steps.add(new CobbleStep(randomX, coordY, STEP_WIDTH,STEP_HEIGHT));
            }
        }
        for(int i = 0; i <= Game.TILES_IN_WIDTH; ++i){
            steps.add(new CobbleStep( i * STEP_WIDTH, 1000,  STEP_WIDTH, STEP_HEIGHT));
        }

    }
}
