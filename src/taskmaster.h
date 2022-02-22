//
// Created by adam on 09/02/2022.
//

#ifndef SIGNAPSE_TASKMASTER_H
#define SIGNAPSE_TASKMASTER_H
//!  Taskmaster class.
/*!
    Class containing member functions for setting the global signing task.
*/
class Taskmaster{
public:
    //!  Constructor.
    /*!
        No functionality.
    */
    Taskmaster();
    //!  Public member function takes new task as argument and assigns value to the current task.
    /*!
        \param new_task char containing the new task.
    */
    void set_task(char new_task);
protected:
    //!  Protected member variable.
    /*!
        Holds value of the master/global task.
    */
    char master_task;
};


#endif //SIGNAPSE_TASKMASTER_H
