//
//  finalProject.h
//  finalProject
//
//  Created by Anna Thomas on 9/20/21.
//
#include <iostream>
#include <SFML/Graphics.hpp>//to use smfl library, syntax this way
#include <cmath>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <cassert>
#include <SFML/System/Clock.hpp> //has time.hpp



//The on-screen item that is controlled by the player via the arrow keys. It is used to destroy Blocks.
class Weapon{
    
private:
    
    sf::RectangleShape shape; //We will use member functions to give rectangle some dimensions
    sf::FloatRect boundingBox; //Will use object.getglobalbounds() to initialize this during construction, the boundingBox will be used to determine if contact with another object has been made (Blocks OR 
    sf::Clock timeSinceSwung; //Not using currently
    float tilt; //Keeps track of the angle of the weapon
    
public:
    
    Weapon(float width, float height, float x, float y, float rotation){
        //constructor to make a weapon in the shape of rectangle with width and height, this weapon will serve as the "weapon" that is used to break down blocks
        
        shape.setSize(sf::Vector2f(width, height));
        boundingBox = shape.getGlobalBounds();
        timeSinceSwung.restart(); //starts at 0
        //creates a boundingBox with the global bounds of shape
        
        shape.setOrigin(boundingBox.left + boundingBox.width/2.0f, boundingBox.top + boundingBox.height/2.0f);
        //sets shape's origin == shape's middle
        
        shape.setPosition(x, y); //now the position can be set with respect to the middle of the shape
        tilt = rotation;
        shape.setRotation(tilt);
        //tilts the weapon to a 45 degree angle so it is ready for attacking
        
        
    }
    
    sf::Vector2f getCoordinates(){
        
        return shape.getPosition();
    }
    
    sf::FloatRect getBBox(){ //necessary to update the bounding box whenever you get it
        
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
    
    void moveIt( float x, float y){
        
        shape.move(x, y);
    }
    
    void rotateIt( float degree){
        
        shape.rotate(degree);
    }
    
    float getTilt(){
        
        return tilt;
    }
    
    void resetRotation(float initialTilt){
        
        shape.setRotation(initialTilt);
    }

    
};


#ifndef finalProject_h
#define finalProject_h


#endif /* finalProject_h */


//-----advanced for later------
//    void recoil( float degree){
//
//        shape.rotate(-degree); //recoil to the left by "degree"
//        std::cout << "recoil start!" << std::endl;
//
//        sf::Time currentTime = timeSinceSwung.restart(); //time is at 0
////        sf::Time time = timeSinceSwung.getElapsedTime(); //This function returns the time elapsed since the last call to restart()
//        if (currentTime.asSeconds() > 1 ){ //if more than one second passes
//
//            std::cout<< "time > 1 second" << "\n";
//            shape.rotate(degree); //move the shape back to its starting position
//        }
//
//    }

//    void restartTime(){
//
//        timeSinceSwung.restart();
//    }
