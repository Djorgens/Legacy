#pragma once
#include <string>
#include <list>




//----------------------------------------------//
//---------------Class Game---------------------//
//----------------------------------------------//


class Game
{
private:
	bool playing;
  bool welcome_state = true;
  std::string user_input;
public:
	Game();
	virtual ~Game();
  virtual void Initialize();
  virtual void run();
  virtual void NewLine();
  virtual void Welcome();
  virtual void Start_Game();
  virtual std::string Get_User_Input();
  virtual bool IsValidIntResponse();
  virtual int GetResponseAsInt();

};