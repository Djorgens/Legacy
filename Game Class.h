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
  std::string user_input;
  std::string County_Name = "CountyName";
  std::string Player_Name = "Player";
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
  virtual bool IsValidArrowResponse();
  virtual int GetResponseAsInt();
  virtual void Character_Creation();

};