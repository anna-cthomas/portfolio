//
//  Message.h
//  finalProject
//
//  Created by Anna Thomas on 9/22/21.
//

#ifndef Message_h
#define Message_h
#include <iostream>
#include <SFML/Graphics.hpp>//to use smfl library, syntax this way
#include <cmath>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <cassert>
#include <SFML/System/Clock.hpp> //has time.hpp

//all member functions and variables for making a text block
class Message{
    
private:
    
    sf::Text messageText;
    sf::Font font;
    sf::FloatRect boundingBox;
    int hitCount;
    
public:
    
    
    Message(std::string fontFileName, std::string message, int messageSize, float x, float y){
        
        
        if (!font.loadFromFile(fontFileName)){
        
            std::cout<< "Error in loading font.\n";
        }
        
        if ( messageSize < 0 || messageSize > 500){
            
            std::cout<< "Inappropriate size value. Please enter a value between 0 and 500." << std::endl;
            exit(-1);
        }
        
        messageText.setFont(font);
        messageText.setString(message);
        messageText.setCharacterSize(messageSize);
        //boundingBox = messageText.getGlobalBounds();
        hitCount = 0;
        messageText.setOrigin(boundingBox.left + boundingBox.width/2.0f, boundingBox.top + boundingBox.height/2.0f);
        messageText.setPosition(x, y);
    }
    
    sf::Vector2f getCoordinates(){
        
        return messageText.getPosition();
    }
    
    sf::FloatRect getBBox(){
        
        return boundingBox = messageText.getGlobalBounds();
    }
    
    sf::Text getMessage(){
        
        return messageText;
    }
    
    void setPosition( float x, float y){
        
        messageText.setPosition(x, y);
        
    }
    
    void matchPoisition ( const sf::Vector2f &coordinates ){
        
        messageText.setPosition(coordinates);
    }
    
    void rotate(float x){
        
        messageText.setRotation(x);
    }
    
    void setColor(float r, float g, float b){
        
        messageText.setFillColor(sf::Color(r, g, b));
        
    }
    
    void setScale(float x, float y){
        
        messageText.setScale(sf::Vector2f(x, y));
    
    }
    
    void makeBold(){
        
        messageText.setStyle(sf::Text::Bold);
    }
    
    void makeItalic(){
        
        messageText.setStyle(sf::Text::Italic);
    }
    
    void makeUnderlined(){
        
        messageText.setStyle(sf::Text::Underlined);
    }
    
    void changeSize(int size){
        
        if ( size < 0 || size > 500){
            
            std::cout<< "Inappropriate size value. Please enter a value between 0 and 500." << std::endl;
            exit(-1);
        }
        messageText.setCharacterSize(size); //font size can't be negative
        
    }
    
    void rotateIt( float degree){
        
        messageText.rotate(degree);
    }
    
    void moveIt( float x, float y){
        
        messageText.move(x, y);
    }
    
    void hideText(){
        
        messageText.setScale(0, 0);
    }
    
    void setMessage(std::string message){
        
        messageText.setString(message);
        
    }
    
    void hitCounter( Weapon &theWeapon){ //this-> is hit by the otherBoundingBox
        
        sf::FloatRect otherBoundingBox = theWeapon.getBBox();
        boundingBox = messageText.getGlobalBounds();

        if( otherBoundingBox.intersects(boundingBox)){
        
            hitCount++;
            
//            if( hitCount == 1){
//
//                theWeapon.rotateIt(-15);//tilt the wepon during recoil
//                std::cout << "First hit" << std::endl;
//                messageText.setScale(0.75, 0.75);
//                theWeapon.moveIt(-20, 0); //recoil 20x to the left
//                messageText.move(20, 0);
//            }
//
//            else if( hitCount == 2){
//
//                theWeapon.rotateIt(-15);
//                std::cout << "Second hit" << std::endl;
//                messageText.setScale(0.45, 0.45);
//                theWeapon.moveIt(-20, 0); //recoil 20x to the left
//                messageText.move(20, 0);
//            }
        
            if( hitCount == 1){
                
                std::cout << "Last hit" << std::endl;
                messageText.setScale(0, 0); //destroys textMessage
                //theWeapon.moveIt(20, 0); //recoil 20x to the right f or w a r d, since there is no more resistance 
            
            }
        }
        
    }
    
};

#endif /* Message_h */
