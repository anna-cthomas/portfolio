//
//  main.cpp
//  finalProject
//
//  Created by Anna Thomas on 9/20/21.
//
#include "Weapon.h"
#include "Block.h"
#include "Message.h"
#include <chrono>

bool hitCountThree(Block &someBlock){
    
    if(someBlock.getHitCount() != 3){
        return false;
    }
    return true;
}


int main()
{
    sf::RenderWindow window(sf::VideoMode(1600, 1000), "My window");
    window.setFramerateLimit(60);
    
    
    sf::Music uwu;
//    if(!uwu.openFromFile("uwu.ogg")hplayable";
//        exit(-1);
//    }
   
//    sf::Sound uwuSound;
//    uwuSound.setBuffer(bufferUwu);
    //uwuSound.setPlayingOffset(sf::seconds(8)); //8 sec in for maximum uwu
    
    sf::SoundBuffer bufferExplode;
    if(!bufferExplode.loadFromFile("explode.ogg")){
        std::cout << "error, sound not playable";
        exit (-1);
    }

    sf::Sound explosionSound;
    explosionSound.setBuffer(bufferExplode);
 
    sf::Music bennyHill;
     if(!bennyHill.openFromFile("Bennyhill.ogg"))
    {
        std:: cout << "error";
    }
    
    sf::Music minecraft;
     if(!minecraft.openFromFile("ourTunes.ogg"))
    {
        std:: cout << "error";
    }
    
    minecraft.play();
    minecraft.setPlayingOffset(sf::seconds(26));
    minecraft.setVolume(100);
    
    
    int frameCount = 0;
    //std::chrono::seconds time(0); //ratio for seconds is std::ratio<1> //
    
    Weapon stick(200, 5, 350, 600, -45);
    stick.setColor(150, 90, 50);
    
    Block dirtBlock(300, 300, 800, 600);
    dirtBlock.setColor(136, 100, 10);
    
    Message stickMessage("MinecraftFont.ttf", "become S T I C K", 68, 200, 400);
    stickMessage.setColor( 96, 255, 128);
    stickMessage.makeBold();
    
    Message blockMessage("MinecraftFont.ttf", "dort block", 48, 815, 525);
    blockMessage.setColor( 255, 53, 98);
    blockMessage.makeItalic();
    
    Message helloMessage("ComicSansMS3.ttf", "hello GAMER", 96, 450, 200);
    helloMessage.setColor( 255, 230, 246);
    helloMessage.makeBold();
    
    Message omenMessage("boldComic.ttf", "", 52, 50, 250);
    omenMessage.setColor(200, 20, 30);
    omenMessage.makeUnderlined();
    //omenMessage.makeBold();
    
    Message omenMessage2("MinecraftFont.ttf", "", 52, 50, 350);
    omenMessage2.setColor(19, 204, 236);
    omenMessage2.makeItalic();
    
    Message omenMessage3("comic.ttf", "", 36, 50, 450);
    omenMessage3.setColor(150, 20, 200);
    omenMessage3.makeItalic();
    
    Message omenMessage4("MinecraftFont.ttf", "", 26, 50, 450);
    omenMessage3.setColor(255, 255, 255);
    
    Message departingMessage("MinecraftFont.ttf", "", 200, 55, 200);
   
    Message departingMessage2("MinecraftFont.ttf", "", 400, 75, 400);
    departingMessage2.setColor(255, 0, 0);
    
    Message warningMessage("ComicSansMS3.ttf", "", 200, 75, 200);
    warningMessage.setColor(255, 247, 19);
    
    std::vector<Block> allBlocks;
    allBlocks.push_back(dirtBlock);
    
    while (window.isOpen()){
        
        sf::Event event;
        
        while (window.pollEvent(event)){
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
            // move stick left...
            stick.moveIt(-10, 0.0);
            stick.resetRotation(stick.getTilt());
            
        }
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
            // move stick right...
            stick.moveIt(10, 0.0);
            stick.resetRotation(stick.getTilt());
        }
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
            // move stick up...
            stick.moveIt(0.0, -10);
            stick.resetRotation(stick.getTilt());
        }
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
            // move stick down...
            stick.moveIt(0.0, 10);
            stick.resetRotation(stick.getTilt());
        }
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
            //if esc key is pressed, game is exited
            break;
        }
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
            //if space is pressed, pushback a brand new block into vector of blocks
            //window.setKeyRepeatEnabled(false);
            if (frameCount % 5   == 0){ //only procress a keyclick every 5 frames
                
                std::cout << "Spacebar pressed" << std::endl;
                Block newBlock;
                allBlocks.push_back(newBlock);
            }
            
            else{
                
                std::cout << "A key press can only be excecuted once every five frames.\n";
                
            }
        }
        
        
        if (dirtBlock.getHitCount() == 3){
            
            dirtBlock.resetHitCount();
            
            stickMessage.hideText();
            helloMessage.hideText();
            omenMessage.setMessage("Where one is struck down, two more shall take its place.");
            omenMessage2.setMessage("Make more if you dare. Via spacebar, that is...");
            omenMessage3.setMessage("but don't make too many... ;)");
            minecraft.stop();
            bennyHill.play();
            bennyHill.setVolume(30);
            
        }
       
        int originalMemoryCount = 0;
        dirtBlock.hitCounter( stick );
        blockMessage.hitCounter( stick );
        
        for( Block &x : allBlocks){
            
            x.hitCounter( stick );
            originalMemoryCount++;
        }
        
        allBlocks.erase(std::remove_if(allBlocks.begin(), allBlocks.end(), hitCountThree), allBlocks.end());
        //https://en.wikipedia.org/wiki/Erase–remove_idiom
        int totalMemoryCount = allBlocks.size();
        
        
        if (originalMemoryCount != totalMemoryCount){
            
            int blocksToMake = originalMemoryCount - totalMemoryCount;
            while(blocksToMake != 0){
            
                Block newBlock;
                allBlocks.push_back(newBlock);
            
                Block newBlock2;
                allBlocks.push_back(newBlock2);
                
                blocksToMake--;
            }
        }
        
        if(allBlocks.size() > 20){
            
            warningMessage.setMessage("You are running");
            omenMessage.hideText();
            omenMessage2.hideText();
        }
        
        if(allBlocks.size() > 22){
            
            warningMessage.setMessage("on borrowed");
            warningMessage.setPosition(75, 250);
            warningMessage.changeSize(250);
            omenMessage3.hideText();
        }
        
        if(allBlocks.size() > 24){
            
            warningMessage.setMessage("time");
            warningMessage.setColor(255, 0, 0);
            warningMessage.changeSize(450);
            warningMessage.setPosition(300, 300);
        }
        
        if(allBlocks.size() > 26){
            
            warningMessage.setMessage("uwu");
            warningMessage.changeSize(200);
            warningMessage.setPosition(1000, 550);
            warningMessage.setColor(255, 147, 223);
            //uwu.play();
//            uwu.setVolume(100);

        }
        
//        if(allBlocks.size() > 28){
//
//            uwuSound.stop();
//        }
        
        if (allBlocks.size() > 35){
            
            omenMessage4.setMessage("watch out");
            explosionSound.play();
            explosionSound.setVolume(100);
            bennyHill.setPitch(2);
        }
        
        if (allBlocks.size() > 38){
            
            departingMessage.setMessage("YOU ARE BECOME");
            departingMessage2.setMessage("B L O C K");
            bennyHill.setPitch(1);
            warningMessage.hideText();
        }
        
        if (allBlocks.size() > 40){
         
           
            break;
        }
        
        
        // clear the window with black color
        window.clear(sf::Color::Black);
        
        //for each loop that for each block "x" in allBlocks, draw block "x"
        for ( Block x : allBlocks){
            
            window.draw( x.getShape() );
            
        }
        window.draw( helloMessage.getMessage());
        window.draw( stick.getShape() ); //need to return the shape so that it is an appropriate parameter for draw()
        window.draw( stickMessage.getMessage() );
        window.draw( dirtBlock.getShape() );
        window.draw( blockMessage.getMessage() );
        window.draw( omenMessage.getMessage() );
        window.draw( omenMessage2.getMessage() );
        window.draw( omenMessage3.getMessage() );
        window.draw( omenMessage4.getMessage() );
        window.draw( departingMessage.getMessage() );
        window.draw( departingMessage2.getMessage() );
        window.draw( warningMessage.getMessage() );
        // end the current frame
        window.display();
        
        frameCount++;
    }
    
    
    return 0;
}


/*
 
 ----old way to collide-----
 
 for( int count = 1; count <=3 ; count++){
 
 if (stick.getBBox().intersects(dirtBlock.getBBox())){
 
 std::cout << "Collision!" << std::endl; //tells us in the terminal when stick IS hitting dirtblock
 
 if( count == 1){
 std::cout << "First hit" << std::endl;
 dirtBlock.setScale(0.75, 0.75);
 blockMessage.setScale(0.75, 0.75);
 
 }
 
 else if( count == 2){
 
 std::cout << "Second hit" << std::endl;
 dirtBlock.setScale(0.45, 0.45);
 blockMessage.setScale(0.45, 0.45);
 
 }
 
 else if( count == 3){
 
 std::cout << "Last hit" << std::endl;
 dirtBlock.setScale(0, 0); //destroys dirtBlock
 blockMessage.setScale(0, 0); //destroys the block message
 
 }
 }
 }
 */
//----old program pre classes----

// make into its own class called weapon
//    sf::RectangleShape stick; //the weapon type
//    stick.setSize(sf::Vector2f(200, 5)); //Vector2 is the class, and f is type float
//    stick.setFillColor(sf::Color(150, 90, 50)); // make stick the color of stick
//    sf::FloatRect bBoxStick = stick.getGlobalBounds();
//    stick.setOrigin(bBoxStick.left + bBoxStick.width/2.0f, bBoxStick.top + bBoxStick.height/2.0f);

//make into its own class called block
//sf::RectangleShape dirtBlock; //the block type
//dirtBlock.setSize(sf::Vector2f(300, 300));
//dirtBlock.setFillColor(sf::Color( 136, 100, 10)); //make dirtBlock the color of dirt.
//sf::FloatRect boundingBoxBlock = dirtBlock.getGlobalBounds();
//dirtBlock.setOrigin( boundingBoxBlock.left + boundingBoxBlock.width/2.0f, boundingBoxBlock.top + boundingBoxBlock.height/2.0f);

//    Declare a new font
//    sf::Font minecraftFont;
//    // Load it from its file
//    if (!minecraftFont.loadFromFile("MinecraftFont.ttf")){
//
//        std::cout<< "Error in loading font.\n";
//    }
//
//make a class for messages?

//    sf::Text stickMessage;
//    stickMessage.setFont(minecraftFont);
//    stickMessage.setString("become S T I C K");
//    stickMessage.setCharacterSize(84);
//    stickMessage.setFillColor(sf::Color(96, 255, 128));
//    stickMessage.setStyle(sf::Text::Bold);
//    sf::FloatRect boxStickText = stickMessage.getGlobalBounds();
//    stickMessage.setOrigin( boxStickText.left + boxStickText.width/2.0f, boxStickText.top + boxStickText.height/2.0f);
//    //made a bounding box so that I can set the origin to be at the center of the box

//stick.setRotation(-45.f); //to prop the stick up at an angle of -45 degrees

//    sf::Text dortBlock; //Text for dirt block
//    dortBlock.setFont(minecraftFont);
//    dortBlock.setString("dort block");
//    dortBlock.setCharacterSize(48); //this unit is in pixels
//    dortBlock.setFillColor(sf::Color(255, 53, 98));
//    dortBlock.setStyle(sf::Text::Italic); //make a STATEMENT!
//    sf::FloatRect boundingBoxText = dortBlock.getGlobalBounds();
//    dortBlock.setOrigin(boundingBoxText.left + boundingBoxText.width/2.0f, boundingBoxText.top  + boundingBoxText.height/2.0f);
//    boundingBoxText = dortBlock.getGlobalBounds();

//    set positions
//    int stickX = 350;
//    int stickY = 500;

//stick.setPosition( stickX, stickY ); //won't let use move the stick after set position
//bBoxStick = stick.getGlobalBounds();

//dirtBlock.setPosition( 1000, 800 );
//boundingBoxBlock = dirtBlock.getGlobalBounds(); //should update the new top and bottom for the bounding box

//    stickMessage.setPosition ( 375 , 300);
//    boxStickText = stickMessage.getGlobalBounds();

//    dortBlock.setPosition( 1000, 800 );
//    boundingBoxText = dortBlock.getGlobalBounds();

