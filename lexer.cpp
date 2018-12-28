#include "lexer.h"

/**
 * constructor
 * @param name the name of the file to read from
 */
lexer::lexer(string name){
    this->fileName = name;
}
/**
 * the function gets a file and read every word.
 * each word will be in a differend place.
 * @return a vector which every word is in a different place.
 */
vector<string> lexer::lexerFile() {
    vector<string> buffer;
    string line;
    char* toChar;
    char* cut;
    ifstream lexFile;
    //open the file
    lexFile.open(this->fileName, ios::in);
    //if the open file had been succeed
    if (lexFile.is_open()){
        //go on all the file, each time get a line
        while (getline(lexFile, line)){
            //cut the line, after every space,
            toChar = const_cast <char *>(line.c_str());
            cut = strtok(toChar, " ");
            do{
                //put the word in the vector
                buffer.push_back(cut);
                cut = strtok(NULL, " ");
            } while (cut != NULL);
            //in the end add ";"
            buffer.push_back(";");
        }
        //close the file
        lexFile.close();
        //if there was a problem open the file
    } else {
        //throw exception
        throw "unable to open file.";
    }
    //return the vector
    return buffer;
}