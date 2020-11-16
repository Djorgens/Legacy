#include "Game Class.h"
#include <iostream>
#include <fstream>
#include <algorithm>


//----------------------------------------------//
//---------------------Lists--------------------//
//----------------------------------------------//

std::list<std::string> input_all_ints = {"one","1","OnE","ONE","[1]","uno","oNE",
"two","2","twO","TWO","[2]","deux","tWO"};

std::string input_one[7] = {"one","1","OnE","ONE","[1]","uno","oNE"};
int input_one_size = 7; //change this if you change the list above, code depends on it
std::string input_two[7] = {"two","2","twO","TWO","[2]","deux","tWO"};
int input_two_size = 7; //change this if you change the list above, code depends on it

//----------------------------------------------//
//-----------Deconstruct/Constructor------------//
//----------------------------------------------//

Game::Game(){
	playing = true;
};

Game::~Game() {}; 

void Game:: run(){
  {
    Initialize();
    while (playing) {user_input = Get_User_Input();}
    //Shutdown();
  }
};

//----------------------------------------------//
//-----------Welcome() Methods------------------//
//---------------------------------------------//

void Game::Initialize(){
  Welcome();
}

void Game::Welcome(){
  bool valid_option = false;
  std::ifstream file ("ASCII Database/Welcome.txt");
  if (file.is_open())
  std::cout << file.rdbuf(); 

  while (welcome_state) {
    int response;
    user_input = Get_User_Input();

    if(IsValidIntResponse()){
      response = GetResponseAsInt();

      if (response == 1) {
        welcome_state = false;
        std::cout << "Response One" << std::endl;
      }

      if (response == 2) {
        welcome_state = false;
        std::cout << "Response Two" << std::endl;
      }
    }
  }
};

bool Game::IsValidIntResponse(){
  std::list<std::string>::iterator iter;
  iter = std::find(input_all_ints.begin(), input_all_ints.end(), user_input);
  if(iter != input_all_ints.end()) {
    // std::cout << "made it here"; -- debugging message
    return 1;
   }
  else {return 0;}
  //std::cout << "checking input"; -- debugging message
};

int Game::GetResponseAsInt(){
  for (int i = 0; i < input_one_size; i++) {
    if (user_input == input_one[i]) {return 1;}
  };

  for (int i = 0; i < input_two_size; i++) {
    if (user_input == input_two[i]) {return 2;}
  };

  
  return 999;
};

std::string Game::Get_User_Input(){
  std::string input;
  std::cin >> input;
  return input;
};

//----------------------------------------------//
//-------------General Methods------------------//
//----------------------------------------------//

void Game::NewLine(){
  std::cout << std::endl;
};