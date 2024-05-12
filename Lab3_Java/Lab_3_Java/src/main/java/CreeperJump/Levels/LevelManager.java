package CreeperJump.Levels;

import CreeperJump.Game.Game;
import CreeperJump.GameObjects.CobbleStep;
import CreeperJump.GameObjects.GameObjects;
import CreeperJump.utilz.LoadSave;


import java.util.ArrayList;
import java.util.Iterator;
import java.util.Random;

import static CreeperJump.utilz.Constants.StepSize.*;

public class LevelManager {
    private int minYGenerate;
    private ArrayList<GameObjects> steps;

    private Random random = new Random();

    public LevelManager(ArrayList<GameObjects> steps, int nowMin){

        this.steps = steps;
        minYGenerate = 1000;
        GenerateNewLevel();
        minYGenerate -= 1000;
    }

    public void update(int nowMin){
        if(nowMin <= minYGenerate + 1000){
            GenerateNewLevel();
            minYGenerate -= 1000;
        }
    }

    private void GenerateNewLevel(){
        for(int i = 0; i < 1000 / 200; ++i){
            int randomNumber = 4 + random.nextInt(5);
            for(int j = 0; j < randomNumber; ++j){
                int randomX = random.nextInt( Game.GAME_WIDTH);
                int randomY = i * 200 + random.nextInt(200);
                int coordY = minYGenerate - randomY;
                steps.add(new CobbleStep(randomX, coordY, STEP_WIDTH,STEP_HEIGHT));
            }
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
}
