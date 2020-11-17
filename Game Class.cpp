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
//-------------General Methods------------------//
//----------------------------------------------//

void Game::NewLine(){
  std::cout << std::endl;
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

  /*Testing  Output -- Move into own file soon */
  std::cout << "The Kantorian - " << County_Name << " Contract" << std::endl;
  NewLine();
  std::cout << "As a consequence of the fall of Kantor City," 
  << " the Empire no longer has the resources\n" << "to maintain direct " 
  << "control over " << County_Name <<  ". Emperor Astoree IV of Kantor and San"
  << " hereby\ngrants the county of " << County_Name <<" to "  << Player_Name << "." 
  << std::endl;     
  NewLine();
  std::cout << "The duties of the Emperor include the yearly opening of a portal to" 
  << "supply colonists\nto support the isolated county." << std::endl;
  NewLine();
  std::cout << "The duties of the county include"  << std::endl;
  NewLine();
  std::cout << "The Emperor also grants vassalage of both Mayor Lord Krantou "
  << "and Bishop Tyriel to\n" << Player_Name << ", along with all current crown lands.";

  while (welcome_state) {
    int response;
    user_input = Get_User_Input();

    if(IsValidIntResponse()){
      response = GetResponseAsInt();

      if (response == 1) {
        welcome_state = false;
        Start_Game();
        // std::cout << "Response One" << std::endl; -- debugging message
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
//-----------Start_Game() Methods---------------//
//---------------------------------------------//

void Game::Start_Game(){
  bool valid_option = false;
  std::cout << ">> Start Game" << std::endl;
  std::ifstream file ("ASCII Database/StartGame.txt");
  if (file.is_open())
  std::cout << file.rdbuf(); 


}