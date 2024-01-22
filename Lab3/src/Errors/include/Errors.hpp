#pragma once
#include <iostream>
#include <string>

using namespace std;

class BaseError
{

public:
  virtual int what_index() = 0;
  virtual ~BaseError() = default;
};


class InputFileErorr : public BaseError
{
public:

  InputFileErorr();
  virtual int what_index() = 0;
};

class NotMono final : public InputFileErorr
{
public:
 
  NotMono();
  int what_index();

};

class NotPCM final : public InputFileErorr
{
public:
 
  NotPCM();
  int what_index();

};

class Not16B final : public InputFileErorr
{
public:
 
  Not16B();
  int what_index();

};

class Not44100G final : public InputFileErorr
{
public:
 
  Not44100G();
  int what_index();

};

class NotWav final : public InputFileErorr
{
public:
 
  NotWav();
  int what_index();

};

class ConfigProblem final : public InputFileErorr
{
public:
  ConfigProblem();
  int what_index();
};

class CalledFunctionError : public BaseError
{
public:

    CalledFunctionError();
    virtual int what_index() = 0;
};

class BadWay final : public CalledFunctionError
{
public:

    BadWay();
    int what_index();
};

class NotWay final : public CalledFunctionError
{
public:
    NotWay();
    int what_index();
};

class ProgrammProblem final : public CalledFunctionError
{
public:
    ProgrammProblem();
    int what_index();
};