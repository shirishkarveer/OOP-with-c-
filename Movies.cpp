/******************************************************************
 * Section 13 Challenge Solution
 * Movies.h
 * 
 * Models a collection of Movies as a std::vector
 * 
 * ***************************************************************/
#include <iostream>
#include "Movies.h"

 /*************************************************************************
    Movies no-args constructor
**************************************************************************/
Movies::Movies() {
}

/*************************************************************************
    Movies destructor
**************************************************************************/
Movies::~Movies() {
}

  /*************************************************************************
    add_movie expects the name of the move, rating and watched count
    
    It will search the movies vector to see if a movie object already exists
    with the same name. 
    
    If it does then return false since the movie already exists
    Otherwise, create a movie object from the provided information
    and add that movie object to the movies vector and return true
    *********************************************************************/
bool Movies::add_movie(std::string name, std::string rating, int watched) {
    for (const Movie &movie: movies) {//range based , check for each movie
        if (movie.get_name() == name)//name that's passed
            return false;
    }//looped thru entire collection and not found the movie
    Movie temp {name, rating, watched};//costruct the mvie using 3 objs
    movies.push_back(temp);
    return true;
}

 /*************************************************************************
    increment_watched expects the name of the move to increment the
    watched count
    
    It will search the movies vector to see if a movie object already exists
    with the same name. 
    If it does then increment that objects watched by 1 and return true.

    Otherwise, return false since then no movies object with the movie name
    provided exists to increment
    *********************************************************************/
bool Movies::increment_watched(std::string name) {
    for (Movie &movie: movies) {//cant be const needs to be a reference, so that we can change
        if (movie.get_name() == name) {
            movie.increment_watched();//method in movie class
            return true;
        }
    }
    return false;//wasn't able to inc anything coz it's not there = empty
}

/*************************************************************************
    display
    
    display all the movie objects in the movies vector.
    for each movie call the movie.display method so the movie
    object displays itself
    *********************************************************************/
void Movies::display() const {
    if (movies.size() == 0) {//nothing to display
        std::cout << "Sorry, no movies to display\n" << std::endl;
    } else {//ther r movies, loop thru movies vector and disp itself
        std::cout << "\n===================================" << std::endl;
        for (const auto &movie: movies)//
            movie.display();
        std::cout << "\n===================================" << std::endl;
    }
}