//
// Created by ross on 09/02/2022.
//

#ifndef SIGNAPSE_REEL_H
#define SIGNAPSE_REEL_H
#include "Scene.h"
#include "BlockingQueue.h"
#include "BlockingQueue.cpp"


//!  Reel class.
/*!
    Class for interfacing with a queue of Scene
*/
class Reel{
public:
    //! Constructor.
    /*!
        No functionality.
    */
    Reel();
    //! Member function returns the next Scene in the queue.
    /*!
        \return elem the next Scene in the queue.
    */
    Scene Pop();
    //! Member function returns the Reel number.
    /*!
        \return reelNr an integer.
    */
    int GetNumber();
    bool IsEmpty();


protected:
    //! Protected member variable.
    /*!
        Holds value of the Reel number.
    */
    int reelNr;
    //! Protected member variable.
    /*!
        A queue of Scene.
    */
    BlockingQueue<Scene> sceneQueue;
};


#endif //SIGNAPSE_REEL_H
