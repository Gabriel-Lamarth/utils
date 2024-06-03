// libs
#include <iostream>
#include <string>
#include <vector>
#include <random>
// namespace
using namespace std;

// function prototypes
void showstatus(vector<string>, int, int);
bool verify(vector<char>, char);
void main_menu(void);
string get_word(vector<string>);

// costants
const vector<string> allwords = {
    "ubuntu", "debian", "arch", "tux", "linux", "wayland", "grub", "linus-torvalds", "xorg", "shell", "bash", "security", "kernel", "big", "bedrock", "sudo", "gnome", "fedora", "suse", "xfce", "free", "open-source", "light", "memory", "console", "dolphin", "mint", "matte", "window", "garuda", "hangman", "lutris", "unix", "firefox", "manjaro", "yast", "terminal", "root", "user", "script", "comand-line", "gentoo", "kali", "parrot", "cent-os", "pop-os", "cosmic" 
};

static const string WORD = get_word(allwords);
static const int WSIZE = WORD.size();
static const int MAX_ERRORS = 10;

// main
int main(void){
    //start variables
    vector<string> hangman;
    vector<char> awready_tryed;
    int error = 0;
    int right = 0;
    char guess;

    //start
    main_menu();

    // Initialize hangman with underscores for each letter in the word    
    for (int i = 0; i < WSIZE; i++){
        if (WORD[i] != '-'){
            hangman.push_back(" _ ");
        } else {
            hangman.push_back(" - ");
            right++;
        }
    }

    // main loop
    do {
    
        // print in the prompt
        showstatus(hangman, right, error);

        // get a guess
        cout << "Enter a letter: ";
        cin >> guess;
        
        // verify if there's the inserted letter in the word
        if (verify(awready_tryed, guess)){
            if (WORD.find(guess) < WORD.size() || guess == WORD[0]){ 
                for (int i = 0; i < WSIZE; i++){ // replace the status of the word
                    if (tolower(WORD[i]) == tolower(guess)){
                        hangman[i] = toupper(guess);
                        right++;
                    }        
                }
            } else { // error code
                cout << "\'" << guess << "\' is not in the word." << endl;
                error++;
            }
        } else {
            cout << "You have already tried \'" << guess << "\'." << endl;
        }
        if (error >= MAX_ERRORS) {
            cout << "You Lose!" << endl;
            cout << "The word was '" << WORD << "'." << endl; 
            exit(0);
        } else if (right >= WSIZE){
            showstatus(hangman, right, error);
            cout << "You Win!" << endl;
            exit(0);
        }
        awready_tryed.push_back(guess);
    } while (right < WSIZE);
    
    return 0; //end
}

// function structs
void showstatus(vector<string> f, int right, int error){
    // show the world
    cout << "\nWord: ";
    for (int i = 0; i < WSIZE; i++){
        cout << f[i];
    }
    cout << endl;
    cout << "\nErrors: " << error << endl;
    cout << "\nCorrect Guesses: " << right << endl;
}

bool verify(vector<char> chutes, char ch){
    for (int i = 0; i < chutes.size(); i++){
        if (chutes[i] == ch){
            return false;
        }
    }
    return true;
}

void main_menu(void){
    cout << "Welcome to Reforca!" << endl;
    cout << "Max. of errors: " << MAX_ERRORS << endl;
    cout << "Press any key to start." << endl;
    getchar();
    system("clear");
}

string get_word(vector<string> vec){
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, vec.size() - 1);

    return vec[dis(gen)];
}