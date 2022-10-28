#include "function.h"

void split(const std::string word, std::queue<std::string> &fifo)
{
    auto length = word.length();
    std::string temp;

    if (!word.empty())
    {
        if (isdigit(word[0]))
           return;
        else
           for (unsigned int i = 0; i < length; i++)
           {
              if (!ispunct(word[i]))
                 temp.push_back(word[i]);
              else if (word[i] == '-' && temp.length() > 0)
              {
                 fifo.push(temp);
                 temp.clear();
              }
              else if (ispunct(word[i]) && word[i] == 39)
                 temp.push_back(word[i]);
              else if ((ispunct(word[i]) && isalpha(word[i-1]))
                       || i == length-1)
              {
                 fifo.push(temp);
                 temp.clear();
              }
           }
    }

    // if there's still characters in temp then we probably had to split
    // some characters (e.g. effect--added . . . there--criticised)
    if (temp.length() > 0)
        fifo.push(temp);

    if (fifo.empty())
        fifo.push(word);
    return;
}

void prep(std::string &word)
{   
    if (word.empty()) return;

    unsigned int front = 0, back = word.length()-1;

    // move the front pointer as long as the character isn't an alpha
    while (front < word.length() && !isalpha(word[front])) front++;
    // move the back pointer as long as the character isn't an alpha
    while (back > front && !isalpha(word[back])) back--;

    // if we've removed everything from the word, return an empty word
    if (front == word.length())
       word = "";
    else
       word = word.substr(front, back-front+1);
    
    // lower-case the word
    transform(word.begin(), word.end(), word.begin(), ::tolower);
    return;
}

// Pull a single word out of the input stream.  Clean up any non-word
// garbage and return only words where word is defined as
//
// * Does not start with a digit
// * Does not begin or end with apostrophes (e.g. 'tis )
// * Does allow internal apostrophes
// * Does not allow other internal, non-alpha characters
std::string readNextWord(std::istream &fin)
{
   static std::queue<std::string> fifo;
   std::string word;

   while (true)
   {
      if (!fifo.empty())
      {
         word = fifo.front();
         fifo.pop();
         return word;
      }

      if (!(fin >> word))
         throw "End of input";

      prep(word);

      if (!word.empty())
         split(word, fifo);
   }
}
