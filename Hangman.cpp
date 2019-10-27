// Keywords II
#include <iostream>
#include <string>
#include <vector>
#include <algorithm> 
#include <ctime> //random number generator
#include <cctype>// Capital and lowercase comparisons.

using namespace std;

int main()
{
    string userName;
    const int MAX_WRONG = 10; //Maximum allowed wrong guesses.
    int simNumber, wrong;
    simNumber = 1; //This keeps track of what simulation is run.
    wrong = 0;
    
    // Hold the recruit's name in a var, and address them by it throughout the simulation.
    
    // Display an overview of what Keywords II is to the recruit
    
    // Display directions to the recruit on how to use Keywords
    cout << "Hello Agent, What is your name? \n";
    cin >>  userName;
    cout << "Hey there, " << userName << endl;
    cout << "Welcome to Keywords II Code Breaker Training Simulation Program\n";
    cout << "You, " << userName << ", have done exceptionally well on Keywords I, \n";
    cout << "which has allowed you access level II... Do not underestimate its difficulty \n";
    cout << "This version is similar to the popular game 'Hangman'... \n";
    cout << "You will have to guess the 'Spy words' letter by letter.\n";
    cout << "Good luck, " << userName << "!\n\n\n\n\n";
    
    // Create a collection of 10 words you had written down manually
TOP:
    // Create an int var to count the number of simulations being run starting at 1
    vector<string> words; //This creates a vector storing the words.
    words.push_back("HIDDEN");
    words.push_back("CIA");
    words.push_back("SILENT");
    words.push_back("HACK");
    words.push_back("UNDERCOVER");
    words.push_back("BRIBERY");
    words.push_back("COMPLIANCE");
    words.push_back("INTEGRITY");
    words.push_back("SECRET");
    words.push_back("LIES");
    
    srand(static_cast<unsigned int>(time(0)));
    random_shuffle(words.begin(), words.end()); //This shuffles the words to make them random.
    
    // Display the simulation # is starting to the recruit.
    cout << userName << ", You are on Simulation #" << simNumber << " out of 3. " << endl;
    
// Pick new 3 random words from your collection as the secret code word the recruit has to guess. 
    const string THE_WORD = words[0];
    string soFar(THE_WORD.size(), '-');  //What is guessed so far.
    string used = "";
 

// While recruit hasn’t made too many incorrect guesses and hasn’t guessed the secret word
    while((wrong < MAX_WRONG) && (soFar != THE_WORD))
    {
        //     Tell recruit how many incorrect guesses he or she has left
        cout << userName << ", you have " << (MAX_WRONG-wrong) << " incorrect guesses left\n";
        cout << "Here are the letters that have already been guessed:\n";
        //     Show recruit the letters he or she has guessed
        cout << used << endl;
        //     Show player how much of the secret word he or she has guessed
        cout << "\nSo far, the word is:\n" << soFar << endl;
        
        char guess;
        
        cout << "\nEnter your Guess: ";
        cin >> guess;
        guess = toupper(guess); //This makes the guess uppercase, since our words are uppercase.
        
        while(used.find(guess) != string::npos)
        {//The letter has already been guessed.
            cout << userName << ", you've already guessed " << guess << endl;
            cout << userName << ", Enter your guess: ";
            cin >> guess;
            guess = toupper(guess);//Makes the guess a capital
        }
        used += guess; //Add the guessed word to the used list.
        
        if(THE_WORD.find(guess) != string::npos)
        {//The guess does not exist within the word
            cout << "Yes! " << userName <<"! " << guess << " is a letter in the word!\n";
            
            for(unsigned int i = 0; i < THE_WORD.length(); ++i)
            {//Move through the word until that letter is found in it.
                if(THE_WORD[i] == guess)
                {
                    soFar[i] = guess;//this replaces the '-' with the proper letter.
                }
            }
        }
        else
        {//The letter does not belong in the word.
            cout << "Sorry, " << userName << ", is not a letter in the word.\n";
            ++wrong;//increase the wrong var.
        }
    }
    if(wrong == MAX_WRONG)
    {//They've maxed out their wrong guesses.
        cout << userName << ", you have cost the company millions.\n";
        cout << "You have been releaved of your duties...\n";
        if(simNumber == 1)//They didn't get one correct...
            cout << "Only a civialian could do as poor as this.\n";
        else if(simNumber == 2)//They got 1 number
            cout << "You, " << userName << ", were only a medicore agent, easily replaceable.\n";
    }
    else
    {//They correctly guessed the word.
        cout << "\nThe word was " << THE_WORD << endl;
        if(simNumber != 3)
        {//They have yet to complete three words.
            simNumber++;//Increase the sim number
            goto TOP;//GO back to the top
        }
        else
        {//They have done three words, and are done.
            cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nCongradulations, " << userName << "! You have completed Keywords II!\n";
            cout << "You incorrectly guessed " << wrong << " times.\n";
            cout << "Not bad if I do say so myself.\n\n\n\n\n\n\n\n";
        }


    }
    return 0;
}

//     Get recruit's next guess

//     While recruit has entered a letter that he or she has already guessed

//          Get recruit ’s guess

//     Add the new guess to the group of used letters

//     If the guess is in the secret word

//          Tell the recruit the guess is correct

//          Update the word guessed so far with the new letter

//     Otherwise

//          Tell the recruit the guess is incorrect

//          Increment the number of incorrect guesses the recruit has made

// If the recruit has made too many incorrect guesses

//     Tell the recruit that he or she has failed the Keywords II course.

// Otherwise

//     Congratulate the recruit on guessing the secret words

// Ask the recruit if they would like to run the simulation again

// If the recruit wants to run the simulation again

//     Increment the number of simulations ran counter

//     Move program execution back up to // Display the simulation # is starting to the recruit. 

// Otherwise 

//     Display End of Simulations to the recruit

//     Pause the Simulation with press any key to continue
//The above does not exist on my Macintosh. ^^^^^

