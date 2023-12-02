#pragma once

enum class State
{
    Dead,
    Alive,
};

enum class Errors{
    CallProgrammIncorrectly,
    ProblemWithInputOfIteration,
    Input,
    CanNotOpenFile,
    InputData,
};

enum class Mode{
    Offline,
    Online,
};

enum class StateOfCall{
    NumberOfRepeat2Words,
    NumberOfRepeat1Words,
    OutputFile1Word,
    OutputFile2Word,
    InputFile,
    Bad,
};


