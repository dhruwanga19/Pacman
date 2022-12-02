/*****************************************************************//**
 * @file   Ghost.h
 * @brief  This class is used for the creation and management of Ghost Instances.
 *
 * @author Qiuhao Zeng
 * @date   29/11/2022
***********************************************************************/
#include "Entity.h"
#include "Pacman.h"

#ifndef GHOST

#define GHOST

class Ghost: public Entity{

public:
    /**
     * Construct a Ghost Object.
     * @brief Default Constructor. 
     * @see Ghost(int search, Pacman pacman)
     */
    Ghost();
    /**
     * Construct a Ghost object with reference to search algo. number and Pacman.
     * @brief Constructor.
     * @param search Number indicating search algo.
     * @param pacman Pacman Instance to target, (Used for Ghost AI)
     * @see Ghost()
     */
    Ghost(int search, Pacman pacman);
    /**
     * @brief Destructor.
     */
    ~Ghost();
    /**
     * @brief Current Direction of ghost.
     */
    int curDirection = 0;
    /**
     * @brief Enum defining direction (UP,DOWN,LEFT,RIGHT -> 0,1,2,3).
     */
    enum movingDirections : int { UP, DOWN, LEFT, RIGHT };
    /**
     * Set search Algo. 
     * @brief Setter Method.
     * @param search
     */
    void setSearch(int search);
    /**
     * Get Search Algo.
     * @brief Getter Method.
     * @return 
     */
    int getSearch();
    /**
     * Check if ghost can be killed.
     * @brief Getter Method: Ghost Vulnerablitiy 
     * @return True if Vulnerable, False Otherwise
     */
    bool isVulnerable();
    /**
     * Set if ghost can be killed.
     * @brief Setter Method: Ghost Vulnerablitiy
     * @param vulnerability True if Vulnerable, False Otherwise
     */
    void setVulnerable(bool vulnerability);
    /**
     * Set Pacman Instance to target.
     * @brief Setter Method: Pacman Instance
     * @param pacman Pacman instance to target
     */
    void setPacman(Pacman pacman);
    /**
     * Get current Pacman instance that is bieng targetted.
     * @brief Getter Method: Pacman Instance
     * @return Pacman instance that is bieng targeted
     */
    Pacman getPacman();
    /**
     * Set the chase location for Ghost based on internal logic.
     * @brief Set Chase location of ghost.
     */
    void setChaseLocation();
    /**
     * Get the current chase location of ghost.
     * @brief Get Target Tile of Ghost
     * @return Tile Ghost is targetting
     */
    Tile getChaseLocation();
    /**
     * @brief Number of directions available to move..
     */
    int currentAvailDirection = 2;
    /**
     * @brief Flag indicating if ghost can change direction.
     */
    bool canChangeDir = false;


private:
    /**
     * @brief Search Algo, number.
     */
    int search;
    /**
     * @brief Holds ghosts vulnerability state (can be eaten or not).
     */
    bool vulnerable;
    /**
     * @brief Current Pacman.
     */
    Pacman pacman;
    /**
     * @brief Stores current Pacman's location for chasing.
     */
    Tile chaseLocation;

};

#endif