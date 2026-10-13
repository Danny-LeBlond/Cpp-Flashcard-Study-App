/*
Danny LeBlond
12/02/2023
flashcards
Helps people makes card that they can study from.
*/

#include <iostream> // input/output stream
#include <vector>  // includes vectors
#include <cstdlib>  // Include for general purpose like memory allocation, random numbers
#include <ctime> // for time stuff such as seconds.
#include <algorithm> // Include algorithms sorting and searching
#include <fstream>  // Include file stream for reading and writing to files
#include <chrono>  // for time 
#include <thread>  // Include for creating and managing threads
#include "classes.h" //the other file
using namespace std; // so i dont have to type std:: everywhere
void load_old_cards(FlashCardDeck& deck) {//function to get the cards if any from flashcard.txt
    ifstream file("flashcard.txt");//opens the file
    if (file.is_open()) { //makes sure the file opened
        string question;// where the question is held 
        string answer;// where the answer is held
        while (getline(file, question) && getline(file, answer)) {// reads till theres nothing left
            flash_card* newCard = new flash_card(question, answer);//makes a new flash card object
            deck.addCard(newCard);}//adds the flash card to the deck.
        file.close();}}//closes file
    


int main() { //where program starts
    srand(static_cast<unsigned>(time(0)));// Seed the random number generator with current time
    FlashCardDeck deck;// makes a spot for the deck 
    int question_empty=0;//for when they dont put in a question counter
    int answer_empty=0;//for when they dont put in a answer counter
    int no_card_counter=0;//the counter for when they try to study but dont have cards to study from
    int wrong_choice = 6; // Variable to track incorrect choices the user makes when they pick what to do
    string again_or_not;//variable for them to use when they get a card right five time do they want to study it more or not
    load_old_cards(deck);//gets all the old flashcards that are saved in the flashcard.txt file
    while (true) {// infinite loop 
    question_empty=0;
        cout << "\nPress:\n(1) To make a new card\n(2) To Study\n(3) Exit\n";//choices they can make.
        int choice = 0;//where their choice is stored
        cin >> choice;//the input for their choice 
        while (choice != 1 && choice != 2 && choice != 3) {// makes sure they pikc 1,2 or three only
            if (wrong_choice == 1) {//the user has messed with the program to much there not actually trying to study
                choice = 3;// makes the choice 3 (which is exit)
                cout << "\nYou're not understanding the menu. So there's probably no point in studying!\n\n";// message saying there not doing it right 
                this_thread::sleep_for(chrono::seconds(5));// pauses the program so the user can read the above statement 
                 cout << "\nTotal flashcards left: " << deck.getSize() << endl;// tells the amount of flash cards that are left to be study for next time
                ofstream file("flashcard.txt");//opens the flashcard.txt to be wrigth to.
                if (file.is_open()) {// makes sure its open
                    for (flash_card* card : deck.getFlashCards()) {//goes through the cards in the deck
                        file << card->question << "\n" << card->answer << "\n";}//writes question and answers to the file
                file.close();}//closes the file
                break;}// breaks while loop to go to choice 3.
            wrong_choice -= 1;// minus wrong choice count
            cin.clear();// gets rid of what they input 
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore remaining characters in input
            cout << "Not a correct input. Try again. You have " << wrong_choice << " tries left to make a correct choice.\n"; // asks for correct input
            cin >> choice;}// where their choice will be held
        if (choice == 1) {//choice one they picked make a new card
            string question; //where the question will be held
            string answer;//where the answer will be held.
            cin.ignore();// Ignore any remaining newline characters
            cout<<'\n';//line space
            cout << "Enter your question (Press enter twice after question is typed in): ";// asks for a question
            getline(cin, question); //gets the whole line as an input for the question
            while (question.empty()) {//if they didnt put any question
                cout<<"You didnt put anything in.\nPress enter to keep going\n";//message telling they they didnt put in a question
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');// Ignore remaining characters in input
                question_empty++;//counter for how many times they dont put in a question
                if (question_empty<7){// if the counter question_empty is less then 8
                     cout << "Try putting in your question. Try again.\nHere: ";//tells them to put in a the question again
                getline(cin, question);//gets the whole line as an input for the question
                cout << "\n";}//line space
                else if (question_empty>=7) {//if they leave the question blank 7 or more times
                    cout<<"\nNot a correct input. I told you.\nBYE\n";//they tried not putting in a question more then 8 times"
                    this_thread::sleep_for(chrono::seconds(2));//pauser to let them read
                    
                    //from here
                    ofstream file("flashcard.txt");
                     if (file.is_open()) {
                          for (flash_card* card : deck.getFlashCards()) {
                             file << card->question << "\n" << card->answer << "\n";}}    //opens the flashcard file to wright to it
                              file.close();                                                //checks to see if its open rights all the cards to it that are in the deck
                              return 0;}}                                                  //then closes the file . then stops the program
                              //to here

        cin.ignore();// Ignore any remaining newline characters                
            cout << "Enter your answer: ";// asks for a answer
            getline(cin, answer);
            while (answer.empty() && question_empty<7) {//if they didnt put any answer
            cout<<"You didnt put anything in.\nPress enter to keep going\n";//message telling they they didnt put in a answer
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                answer_empty++;//counter for how many times they dont put in a question
                 if (answer_empty<8){// if the counter answer_empty is less then 8
                     cout << "Try putting in your answer. Try again.\nHere: ";//tells them to put in a the answer again
                getline(cin, answer);//gets the whole line as an input for the answer
                cout << "\n";}
                else if (answer_empty==8) {// they have tryed to put in a answer more then 8 times
                    cout<<"\nNot a correct input. I told you.\nBYE\n";//they tried not putting in a answer more then 8 times
                    question="";
                    this_thread::sleep_for(chrono::seconds(2));//pauser to let them read
                    ofstream file("flashcard.txt");//opens the flashcard.txt to be wrigth to.
                    if (file.is_open()) {// makes sure its open
                        for (flash_card* card : deck.getFlashCards()) {//goes through the cards in the deck
                        file << card->question << "\n" << card->answer << "\n";}//writes question and answers to the file                
                    file.close();//closes the file
                    return 0;}}
            }                    
            flash_card* newCard = new flash_card(question, answer);//makes a new flash object with the new question and answer and adds it to the deck
            deck.addCard(newCard);}//adds it to the deck
        else if (choice == 2) {//They picked they want to study
            flash_card* currentCard = deck.getRandomCard(); // Get a random card from the deck       
            if (currentCard == nullptr) {//chekcs to see if there are flashcards 
                no_card_counter++;
                if (no_card_counter<3){
                    cout << "\nNo flashcards available. Please make some first.\n";//There arent any flash cards to study from
                    this_thread::sleep_for(chrono::seconds(2));}//timer to let them read 
                else if (no_card_counter<5){
                    cout<<"\nYou Dont Have Any To Study From. Make Them First.\n";//There arent any flash cards to study from
                    this_thread::sleep_for(chrono::seconds(3));}//timer to let them read 
                else if(no_card_counter==6){
                    cout<<"\nSeem like your not getting it you dont have any flashcards. Were gonna try this one more time.\n";//There arent any flash cards to study from. one more try
                    this_thread::sleep_for(chrono::seconds(4));}//timer to let them read 
                else{
                    cout<<"\nNot a correct input. I told you.\nBYE\n";
                    this_thread::sleep_for(chrono::seconds(2));//timer to let them read 
                     cout << "\nTotal flashcards left: " << deck.getSize() << endl;// tells the amount of flash cards that are left to be study for next time
                    ofstream file("flashcard.txt");//opens the flashcard.txt to be wrigth to.
                    if (file.is_open()) {// makes sure its open
                        for (flash_card* card : deck.getFlashCards()) {//goes through the cards in the deck
                            file << card->question << "\n" << card->answer << "\n";}//writes question and answers to the file
                        file.close();}//closes the file
                    break;}
                continue;}//goes to the next thing which is the main menu again.
            cout << "\nThe question is: \n" << currentCard->question << "\n";// shows a random question in the deck
            cout << "\nTake a moment to think and press ENTER to see the answer.\n";// gives the user time to think about their answer and says to press enter when ready
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');// Clear input buffer for next line
            cin.get();// this is what waits for the users to press enter.
            cout << "The answer is: \n" << currentCard->answer << "\n";//shows the answer to the users question
            cout << "\nDid you get it right? (y for Yes, n for No) don't lie: ";//asks the user if they got the question right or wrong
            string correctness;//the answer to if they got it right or wrong
            cin >> correctness;//input for the right or wrong answer.
            while (correctness != "y" && correctness != "n") {//makes sure they only put in a y or n
                cout << "\n\nThat wasn't y or n. Try again.\n";//tells them to input if there right or wrong again.
                cin >> correctness;}//input for the right or wrong answer.
            if (correctness == "y") {//if they user says they got it correct
                currentCard->right_counter++; // plus one to the counter for correct answers
                if (currentCard->right_counter==1){//when they get a card right one time
                    cout << "You got the card right. Good job, keep going!\n";//saying good job  
                    this_thread::sleep_for(chrono::seconds(3));} //pauser to let them read
                else if (currentCard->right_counter<=3){//they have got a card 2 or 3 times
                    cout << "You've gotten the card right " << currentCard->right_counter << " times. Keep it going!!!";
                    cout << "\n";
                    this_thread::sleep_for(chrono::seconds(3));}//pauser to let them read
                else if (currentCard->right_counter<=4){//they have gotten a card right 4 times in a row
                    cout << "You've gotten the card right " << currentCard->right_counter << " times. ONLY ONE MORE TIME!!!";
                    cout << "\n";
                    this_thread::sleep_for(chrono::seconds(3));}//pauser to let them read
                else{ //they got the card right five times in a row                   
                     cout << "You've gotten the card right " << currentCard->right_counter << " times.\n\nWould you like to keep studying this card or take it out of the deck?\nPress: 'r' to remove card and 'a' study Again.";
                    cin>>again_or_not;// for asking if they want a card to be put back in the deck or removed
                    while (again_or_not !="r" && again_or_not !="a"){//if they put anything other then r or a
                        cout<<"That wasnts a correct choice try again.";
                        cin>>again_or_not;}//they get to try typing in r and a
                    if (again_or_not=="a"){//when they want to add the card to the deck and study it again
                        currentCard->right_counter*=0;}//makes the cards correct counter back to zero to study it again
                    else {//they hit r
                        deck.removeCard(currentCard);//takes the currect card out of the deck 
                        cout<<"The card has been removed.";
                        cout<<"\n";
                    this_thread::sleep_for(chrono::seconds(3));}}}//pauser to let them read
            else {//if they user says they got it wrong
                currentCard->right_counter = 0; // reset the counter for incorrect answers
                cout << "\n\nYou'll get it next time. Keep it up!\nRight counter set back to zero for more practice.\n";//telling them got it wrong 
                    this_thread::sleep_for(chrono::seconds(4));}}//pauser to let them read           
        else if (choice == 3) {//exits the program
            cout << "\nTotal flashcards left: " << deck.getSize() << endl;// tells the amount of flash cards that are left to be study for next time
            ofstream file("flashcard.txt");//opens the flashcard.txt to be wrigth to.
            if (file.is_open()) {// makes sure its open
                for (flash_card* card : deck.getFlashCards()) {//goes through the cards in the deck
                    file << card->question << "\n" << card->answer << "\n";}//writes question and answers to the file                
                file.close();}//closes the file            
            cout << "Goodbye!\n";//tells the user goodbye
            break;}}//exits the infity loop        
    return 0;}// completed program 