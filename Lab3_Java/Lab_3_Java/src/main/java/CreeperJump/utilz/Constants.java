package CreeperJump.utilz;


import CreeperJump.Game.Game;

public class Constants {

    public static class StepSize{
        public static final int STEP_WIDTH_DEFAULT = 60;
        public static final int STEP_HEIGHT_DEFAULT = 20;

        public static final int STEP_WIDTH = (int)(STEP_WIDTH_DEFAULT * Game.SCALE);
        public static final int STEP_HEIGHT = (int)(STEP_HEIGHT_DEFAULT * Game.SCALE);
    }

    public static class PlayerSize{
        public static final int PLAYER_WIDTH_DEFAULT = 60;
        public static final int PLAYER_HEIGHT_DEFAULT = 100;

        public static final int PLAYER_WIDTH = (int)(PLAYER_WIDTH_DEFAULT * Game.SCALE);
        public static final int PLAYER_HEIGHT= (int)(PLAYER_HEIGHT_DEFAULT * Game.SCALE);

        public static final float PLAYER_START_X = Game.GAME_WIDTH / 2f - PLAYER_WIDTH / 2f;
        public static final float PLAYER_START_Y = 500f;
    }

    public static class Physics{
        public static final float GRAVITY = 0.05f * Game.SCALE;
        public static final float JUMP_SPEED = -7.5f * Game.SCALE;

        public static final float LEFT_SPEED = -3.0f * Game.SCALE;
        public static final float RIGHT_SPEED = 3.0f * Game.SCALE;
    }

    public static class PlayerConstants{
        public static final int SIZE_MOVES = 2;
        public static final int MAX_SIZE_MOVE = 5;


        public static final int STATIC = 1;
        public static final int JUMP = 0;



        public static int GetSpriteAmount(int player_action){
            switch (player_action){
                case JUMP:
                    return 5;
                case STATIC:
                default:
                    return 1;
            }
        }
    }

    public static class ScoreConstant{
        public static final int SCORE_WIDTH = 200;
        public static final int SCORE_HEIGHT = 30;

        public static final int SCORE_BEGIN_X = 10;
        public static final int SCORE_BEGIN_Y = 20;
    }

    public static class MenuSettings{
        public static final int MENU_BUTTONS = 2;
        public static final int MENU_ANI_BUTTON = 3;

        public static final int START_GAME = 0;
        public static final int QUIT = 1;

        public static final int B_WIDTH_DEFAULT_START = 400;
        public static final int B_WIDTH_DEFAULT_QUIT = 196;
        public static final int B_HEIGHT_DEFAULT = 40;
        public static final int B_WIDTH_START = (int)(B_WIDTH_DEFAULT_START* Game.SCALE);
        public static final int B_WIDTH_QUIT = (int)(B_WIDTH_DEFAULT_QUIT * Game.SCALE);
        public static final int B_HEIGHT = (int)(B_HEIGHT_DEFAULT * Game.SCALE);

        public static final int START_Y = (int)(500 * Game.SCALE);
        public static final int QUIT_Y = (int)(600 * Game.SCALE);

        public static int GetWidthDefault(int button){

            switch (button){
                case START_GAME:
                    return B_WIDTH_DEFAULT_START;
                case QUIT:
                default:
                    return B_WIDTH_DEFAULT_QUIT;
            }
        }
        public static int GetWidth(int button){

            switch (button){
                case START_GAME:
                    return B_WIDTH_START;
                case QUIT:
                default:
                    return B_WIDTH_QUIT;
            }
        }



        public static int GetStateY(int button){

            switch (button){
                case START_GAME:
                    return START_Y;
                case QUIT:
                default:
                    return QUIT_Y;
            }
        }

    }

}
