#include <regex>
#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <unordered_map>
#include <utility>

using str2Int = std::unordered_map<std::string, size_t>;
using intAndWords = std::pair<std::size_t, std::vector<std::string>>;
using int2Words = std::map<std::size_t, std::vector<std::string>>;

// count the frequency of each word
str2Int wordCount(const std::string& text){
  std::regex wordReg(R"(\w+)");
  std::sregex_iterator wordItBegin(text.begin(), text.end(), wordReg);
  const std::sregex_iterator wordItEnd;
  str2Int allWords;
  for (; wordItBegin != wordItEnd;++wordItBegin){
    ++allWords[wordItBegin->str()];
  }
  return allWords;
}

// get to all frequencies the appropriate words
int2Words frequencyOfWords(str2Int& wordCount){
  int2Words freq2Words;
  for ( auto wordIt: wordCount ){
    auto freqWord= wordIt.second;
    if ( freq2Words.find(freqWord) == freq2Words.end() ){
      freq2Words.insert( intAndWords(freqWord, {wordIt.first} ));
    }
    else {
      freq2Words[freqWord].push_back(wordIt.first);
    }
  }
  return freq2Words;
}

int main(int argc,  char* argv[]){

  std::cout << std::endl;

  // get the filename
  std::string myFile = "Test.rtf";

  // open the file
  std::ifstream file(myFile, std::ios::in);
  if (!file){
    std::cerr << "Can't open file "+ myFile + "!" << std::endl;
    exit(EXIT_FAILURE);
  }

  // read the file
  std::stringstream buffer;
  buffer << file.rdbuf();
  std::string text(buffer.str());

  // get the frequency of each word
  auto allWords= wordCount(text);

  std::cout << "The first 20 (key, value)-pairs: " << std::endl;
  auto end= allWords.begin();
  std::advance(end, 20);
  for (auto pair= allWords.begin(); pair != end; ++pair){
    std::cout << "(" << pair->first <<  ": " << pair->second << ")";
  }
  std::cout << "\n\n";

  std::cout << "allWords[Web]: " << allWords["Web"] << std::endl;
  std::cout << "allWords[The]: " << allWords["The"] << "\n\n";

  std::cout << "Number of unique words: ";
  std::cout << allWords.size() << "\n\n";

  size_t sumWords=0;
  for (auto wordIt: allWords) sumWords+= wordIt.second;
  std::cout << "Total number of words: " << sumWords <<"\n\n";

  auto allFreq= frequencyOfWords(allWords);

  std::cout << "Number of different frequencies: " << allFreq.size() << "\n\n";

  std::cout << "All frequencies: ";
  for (auto freqIt: allFreq) std::cout << freqIt.first << " ";
  std::cout << "\n\n";

  std::cout << "The most frequently occurring word(s): " << std::endl;
  auto atTheEnd= allFreq.rbegin();
  std::cout << atTheEnd->first << " :";
  for (auto word: atTheEnd->second) std::cout << word << " ";
  std::cout << "\n\n";

  std::cout << "All word which appears more then 1000 times:" << std::endl;
  auto biggerIt= std::find_if(allFreq.begin(), allFreq.end(), [](intAndWords iAndW){return iAndW.first > 1000;});
  if (biggerIt == allFreq.end()){
    std::cerr << "No word appears more then 1000 times !" << std::endl;
    exit(EXIT_FAILURE);
  }
  else{
    for (auto allFreqIt= biggerIt; allFreqIt != allFreq.end(); ++allFreqIt){
      std::cout << allFreqIt->first << " :";
      for (auto word: allFreqIt->second) std::cout << word << " ";
      std::cout << std::endl;
    }
  }
  std::cout << std::endl;
}

// test.rtf
What is Lorem Ipsum?
Lorem Ipsum is simply dummy text of the printing and typesetting the industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book. It has survived not only five centuries, but also the leap into electronic typesetting, remaining essentially unchanged. It was popularised in the 1960s with the release of Letraset sheets containing Lorem Ipsum passages, and more recently with desktop publishing software like Aldus PageMaker including versions of Lorem Ipsum.

Why do we use it?
It is a long established fact that a reader will be distracted by the readable content of a page when looking at its layout. The point of using Lorem Ipsum is that it has a more-or-less normal distribution of letters, as opposed to using 'Content here, content here', making it look like readable English. Many desktop publishing packages and web page editors now use Lorem Ipsum as their default model text, and a search for 'lorem ipsum' will uncover many web sites still in their infancy. Various versions have evolved over the years, sometimes by accident, sometimes on purpose (injected humour and the like).


Where does it come from?
Contrary to popular belief, Lorem Ipsum the  is not simply random the text. It has roots in a piece of classical Latin literature from 45 BC, making it over 2000 years old. Richard McClintock, a Latin professor at Hampden-Sydney College in Virginia, looked up one of the more obscure Latin words, consectetur, from a Lorem Ipsum passage, and going through the cites of the word in classical literature, discovered the undoubtable source. Lorem Ipsum comes from sections 1.10.32 and 1.10.33 of "de Finibus Bonorum et Malorum" (The Extremes of Good and Evil) by Cicero, written in 45 BC. This book is a treatise on the theory of ethics, very popular during the Renaissance. The first line of Lorem Ipsum, "Lorem ipsum dolor sit amet..", comes from a line in section 1.10.32.

The standard chunk of Web Lorem Ipsum used the  since the 1500s Web is reproduced below for those interested. Sections 1.10.32 and 1.10.33 from "de Finibus Bonorum et Malorum" by Cicero are also reproduced in their exact original form, accompanied by English versions from the 1914 translation by H. Rackham.

Where can I get some?
There are many variations web of passages of Lorem Ipsum the available, but the majority have suffered alteration in some form, by injected humour, or randomised words which don't look even slightly believable. If you are going to use a passage of Lorem Ipsum, you need to be sure there isn't anything embarrassing hidden in the middle of text. All the Lorem Ipsum generators on the Internet tend to repeat predefined chunks as necessary, making this the first true generator on the Internet. It uses a dictionary of over 200 Latin words, combined with a handful of model sentence structures, to generate Lorem Ipsum which looks reasonable. The generated Lorem Ipsum is therefore always free from repetition, injected humour, or non-characteristic words etc.
