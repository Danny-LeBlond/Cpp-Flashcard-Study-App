/*
Danny LeBlond
12/02/2023
flashcards
Helps people makes card that they can study from.
*/
#ifndef CLASSES_H
#define CLASSES_H
#include <iostream>     // input/output stream
#include <vector>       // includes vectors
#include <cstdlib>      // include for memory allocation, random numbers
#include <ctime>        // for time-related operations such as seconds
#include <algorithm>    // for sorting and searching
#include <fstream>      // reading and writing to files
#include <chrono>       // for handling time-stuff
#include <thread>       // for making and managing threads
using namespace std;    // to no have to use std::
class flash_card {// declaration of flash_card class
public:
    string question;//holds the questions
    string answer;//holds the answers
    int right_counter;//counter for the times the users gets the card right
    flash_card(string q, string a) : question(q), answer(a), right_counter(0) {} };// constructor for flash_card class
class FlashCardDeck {// declaration of FlashCardDeck class
private:
    vector<flash_card*> flash_cards;//private vectore to store the fash cards 
public:
    ~FlashCardDeck() { // destructor to free memory allocated for flash cards
        for (flash_card* card : flash_cards) {
            delete card;}}
void addCard(flash_card* card) { //to add a card to the deck
        flash_cards.push_back(card);}

    flash_card* getRandomCard() {//to get a random card from the deck
        srand(static_cast<unsigned>(time(0)));
        if (flash_cards.empty())
            return nullptr;
        int random_num = rand() % flash_cards.size();
        return flash_cards[random_num];}

    void removeCard(flash_card* card) {//to remove a card from the deck
        auto it = find(flash_cards.begin(), flash_cards.end(), card);
        if (it != flash_cards.end()) {
            delete *it;
            flash_cards.erase(it);}}

    int getSize() {//gets the number of cards in the deck
        return static_cast<int>(flash_cards.size());}

    vector<flash_card*>& getFlashCards() {//gets a reference to the deck of cards
        return flash_cards;}};

#endif // End of CLASSES_H
