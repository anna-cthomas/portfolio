//
//  Block.h
//  finalProject
//
//  Created by Anna Thomas on 9/22/21.
//

#ifndef Block_h
#define Block_h
#include <iostream>
#include <SFML/Graphics.hpp>//to use smfl library, syntax this way
#include <cmath>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <cassert>
#include <SFML/System/Clock.hpp> //has time.hpp

//all member functions and variables for making a block
class Block{
   
private:
    
    sf::RectangleShape shape; //we will use member functions to give rectangle some dimensions
    sf::FloatRect boundingBox;
    int hitCount;
    
public:
    
    Block(){ //default constructor is rand dimensions
        
        float size = (20 + rand() % 500);
        shape.setFillColor(sf::Color(rand() % 255, rand() % 255, rand() % 255));
        float randomY = (rand() % 1000);
        float randomX = (rand() % 1600);
        
        shape.setSize(sf::Vector2f(size, size));
        shape.setOrigin(boundingBox.left + boundingBox.width/2.0f, boundingBox.top + boundingBox.height/2.0f);
        shape.setPosition(randomX, randomY);
        hitCount = 0;
        
    }

    
//    sf::Vector2f getRandomPos(){
//        
//        float placement = (300 + rand() % 1000);
//        return sf::Vector2f(placement, placement);
//        
//    }
    
    Block(float width, float height, float x, float y){
        
        shape.setSize(sf::Vector2f(width, height));
        // object does not exist at this point so has no bounding bbox:   boundingBox = shape.getGlobalBounds();
        shape.setOrigin(boundingBox.left + boundingBox.width/2.0f, boundingBox.top + boundingBox.height/2.0f);
        shape.setPosition(x, y); //now the position can be set with respect to the middle of the shape
        //since .setPosition in sfml sets a position with respect to the origin
        hitCount = 0;
    }
    
    sf::Vector2f getOrigin(){
        
        float x = boundingBox.left + boundingBox.width/2.0f;
        float y = boundingBox.top + boundingBox.height/2.0f;
        
        return sf::Vector2f(x, y);
    }
    
    sf::Vector2f getCoordinates(){
        
        return shape.getPosition();
    }
    
    bool isGone(){//might not need
        
        if(shape.getSize() != sf::Vector2f( 0, 0)){
            return false;
        }
        return true;
    }
    
    
    void hitCounter( Weapon &theWeapon ){ //this-> is hit by the otherBoundingBox
        
        sf::FloatRect otherBoundingBox = theWeapon.getBBox();
        boundingBox = shape.getGlobalBounds();
//
//
//        sf::SoundBuffer buffer;
//        std::string soundFile = "StickSound.wav";
//
//        if(!buffer.loadFromFile(soundFile)){
//
//            std::cout << "Error\n";
//            exit (-1);
//        }
//
//        sf::Sound sound;
//        sound.setBuffer(buffer);
        
        if( otherBoundingBox.intersects(boundingBox)){
        
            hitCount++;
            
            if( hitCount == 1){
                
                theWeapon.rotateIt(-15);//tilt the wepon during recoil
                std::cout << "First hit" << std::endl;
                shape.setScale(0.75, 0.75);
                //sound.play();
                theWeapon.moveIt(-20, 0); //recoil 20x to the left
                shape.move(20, 0);
                
            }
            
            else if( hitCount == 2){
                
                theWeapon.rotateIt(-15);
                std::cout << "Second hit" << std::endl;
                shape.setScale(0.45, 0.45);
                //sound.play();
                theWeapon.moveIt(-20, 0); //recoil 20x to the left
                shape.move(20, 0);
            }
            
        
            else if( hitCount == 3){
            
                std::cout << "Last hit" << std::endl;
                shape.setScale(0, 0); //destroys dirtBlock
                theWeapon.moveIt(20, 0);
            }
           
        }

    }

    int getHitCount(){
        
        return hitCount;
    }

    
    void resetHitCount(){
        
        hitCount = 0;
    }
    
    sf::FloatRect getBBox(){
        
        return boundingBox = shape.getGlobalBounds();
    }
    
    sf::RectangleShape getShape(){
        
        return shape;
    }
    
    
    void setColor(float r, float g, float b){
        
        shape.setFillColor(sf::Color(r, g, b));
        
    }
    
    void setPosition( float x, float y){
        
        shape.setPosition(x, y);
    }
    
    void setPosition( sf::Vector2f someVector){
        
        shape.setPosition(someVector);
    }
    
    void setScale(float x, float y){
        
        shape.setScale(sf::Vector2f(x, y));
    
    }
    
    void moveIt( float x, float y){
        
        shape.move(x, y);
    }
    
    void rotateIt( float degree){
        
        shape.rotate(degree);
    }
    
};


#endif /* Block_h */
