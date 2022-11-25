/* PROGRAMMING FUNDAMENTAL'S PROJECT FOR FALL 2022 BS(CS)
 * You don't need to change anything in the driver code/main function except the part(s) where instructed.
 * You are expected to define your functionalities in the "functionality.h" header and call them here in the instructed part(s).
 * The game is started with a small box, you need to create other possible in "pieces.h" file in form of array.
    E.g., Syntax for 2 pieces, each having four coordinates -> int Pieces[2][4];
 * Load the images into the textures objects from img directory.
 * Don't make any changes to the "utils.h" header file except for changing the coordinate of screen or global variables of the game.
 * SUGGESTION: If you want to make changes in "utils.h", do it once you complete rest of the functionalities.
 * TIP: You can study SFML for drawing scenes, sprites and window.
 * */

#include <SFML/Graphics.hpp>
#include <iostream>
#include <time.h>
#include <sstream>
#include "utils.h"
#include "pieces.h"
#include "functionality.h"
#include <string>
using namespace sf;

int main(){
    srand(time(0));
    RenderWindow window(VideoMode(600, 480), title);
    Texture obj1, obj2, obj3,obj4,obj5,obj6,obj7,obj8,obj9,obj10;
    Font font;
    RectangleShape rect(sf::Vector2f(300.f, 300.f));
    /*
        Load "frames.png","tiles.png" and "background.png" for Texture objects
    */
    obj1.loadFromFile("img/tiles.png");
    obj2.loadFromFile("img/background.png");
    obj3.loadFromFile("img/frame.png");
    obj4.loadFromFile("img/next.png");
    obj5.loadFromFile("img/tiles.png");
    obj6.loadFromFile("img/score.png");
    obj7.loadFromFile("img/shadow.png");
    obj8.loadFromFile("img/pause.png");
    obj9.loadFromFile("img/rectangle.jpg");
    obj10.loadFromFile("img/button.png");
    font.loadFromFile("font/arcade.TTF");
    
    Text text;
    text.setFont(font);
    
    Sprite sprite(obj1), background(obj2), frame(obj3),box(obj4),block(obj5),score(obj6),shade(obj7),pause(obj8),rectangle(obj9),button(obj10);
    int delta_x=0, colorNum=1;
    float timer=0, delay=0.3;
    bool rotate=0;
    bool reset=false,jump=false,paused=false;
    Clock clock;
    while (window.isOpen()){
        float time = clock.getElapsedTime().asSeconds();
        clock.restart();
        timer+=time;

        //---Event Listening Part---//
        Event e;
        while (window.pollEvent(e)){       
        delay=0.3;             //Event is occurring - until the game is in running state
        delta_x=0;
        
            if (e.type == Event::Closed)                   //If cross/close is clicked/pressed
                window.close();                            //Opened window disposes
            if (e.type == Event::KeyPressed) {             //If any other key (not cross) is pressed
                if (e.key.code == Keyboard::Up)            //Check if the other key pressed is UP key
                    rotate = true;                         //Rotation gets on
                else if (e.key.code == Keyboard::Left)     //Check if the other key pressed is LEFT key
                    delta_x = -1;                          //Change in X-Axis - Negative
                else if (e.key.code == Keyboard::Right)    //Check if the other key pressed is RIGHT key
                    delta_x = 1;                           //Change in X-Axis - Positive
                else if (e.key.code == Keyboard::Escape)    //Check if the other key pressed is Escape key
                    reset=true;					//restarts the game
                else if (e.key.code == Keyboard::Space)    //Check if the other key pressed is Space key
                    jump=true;					//Jumps to Bottom
                else if(e.key.code== Keyboard::P)         //Check if the other key pressed is P key
                    	paused=true;				//Pauses the Game    
                	
                
            }
        }
        if (Keyboard::isKeyPressed(Keyboard::Down))   //Just another way to detect key presses without event listener
            delay=0.05;                                    //If DOWN key is pressed, delay in falling piece decreases from 0 to 0.05

while((paused)){
pause.setPosition(150,35);


rectangle.setPosition(150,50);

window.draw(rectangle);
window.draw(pause);
button.setPosition(130,100);
window.draw(button);
text.setString(" Resume");
text.setPosition(195,200);
window.draw(text);
button.setPosition(130,160);
window.draw(button);
text.setString("Restart");
text.setPosition(195,260);
window.draw(text);

button.setPosition(130,220);
window.draw(button);
text.setString(" Exit");
text.setPosition(205,320);
window.draw(text);

window.display();

//if(Mouse::isButtonPressed(Mouse::Left)){

//if(button.getGlobalBounds().contains(Mouse::getPosition(window))){
//paused=0;
//}
//}
while (window.pollEvent(e)){
if (e.type == Event::Closed)                   //If cross/close is clicked/pressed
 window.close(); 
 
 }               			            //Opened window disposes
if (Keyboard::isKeyPressed(Keyboard::R))   //Checks for R key Pressed
            paused=0;			//Resumes the Game
}

        ///////////////////////////////////////////////
        ///*** START CALLING YOUR FUNCTIONS HERE ***///
        restart(reset);
        reset=false;
        fallingPiece(timer, delay,colorNum,n,n1,nextColor); 	 //Example: fallingPiece() function is called here
        move(delta_x);
        delta_x=0;
        clearLines(numScore);
        rotation(rotate,n);
        rotate=0;
        hardFall(jump);
        jump=false;
        //make_shadow();
        gameOver();
        ///*** YOUR CALLING STATEMENTS END HERE ***///
        //////////////////////////////////////////////


        window.clear(Color::Black);
        window.draw(background);
        for (int i=0; i<M; i++){
            for (int j=0; j<N; j++){
                if (gameGrid[i][j]==0)
                    continue;
                sprite.setTextureRect(IntRect(gameGrid[i][j]*18,0,18,18));
                sprite.setPosition(j*18,i*18);
                sprite.move(28,31); //offset
                window.draw(sprite);
            }
        }
        
        for (int i=0; i<4; i++){
            sprite.setTextureRect(IntRect(colorNum*18,0,18,18));
            sprite.setPosition(point_1[i][0]*18,point_1[i][1]*18);
            sprite.move(28,31);
            window.draw(sprite);
          } 
          
        for (int i=0; i<4; i++){
            shade.setTextureRect(IntRect(colorNum*18,0,18,18));
            shade.setPosition(shadow[i][0]*18,shadow[i][1]*18);
            shade.move(28,31);
            window.draw(shade);
          } 
          
          
          box.setPosition(380,40);
          window.draw(box);
          
          
          for (int i=0;i<4;i++){
                    temp[i][0] = BLOCKS[n1][i] % 2;
                    temp[i][1] = BLOCKS[n1][i] / 2;
                }
                
          for (int i=0; i<4; i++){
            block.setTextureRect(IntRect(nextColor*18,0,18,18));
            block.setPosition(temp[i][0]*18,temp[i][1]*18);
            block.move(429,55);
            window.draw(block); 
          } 
          
 	      
 		 
         score.setPosition(410,320);
         window.draw(score);
         
         text.setString(to_string(numScore));
  	text.setPosition(420,330);
         window.draw(text);
         
        //---The Final on Which Everything is Drawn Over is Loaded---//
        window.draw(frame);
        
        //---The Window that now Contains the Frame is Displayed---//
        window.display();
    }
    return 0;
}
