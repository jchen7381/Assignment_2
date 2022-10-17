#ifndef SEQUENCEMAP_H
#define SEQUENCEMAP_H

#include <string>
#include <vector>
#include <iostream>
using namespace std;

class SequenceMap{
  public:
    
    //zero parameter constructor
    SequenceMap() = default;

    //copy constructor
    SequenceMap(const SequenceMap &rhs) = default;

    //copy assignment
    SequenceMap& operator=(const SequenceMap &rhs) = default;

    //move constructor
    SequenceMap(SequenceMap &&rhs) = default;

    //move assignment
    SequenceMap& operator=(SequenceMap &&rhs) = default;

    //destructor
    ~SequenceMap() = default;

    //parametizeed constructor
    SequenceMap(const std::string &a_rec_seq, const std::string &an_enz_acro){
        recognition_sequence_ = a_rec_seq;
        enzyme_acronyms_ = {an_enz_acro};

    }

    //overloading operators < and >
    bool operator<(const SequenceMap &rhs) const{
        return(recognition_sequence_ < rhs.recognition_sequence_);

    }

    bool operator>(const SequenceMap &rhs) const{
        return(recognition_sequence_ > rhs.recognition_sequence_);

    }
    
    
    //overloading operators << and >>
    friend std::ostream &operator<<(std::ostream &out, const SequenceMap &some_SequenceMap){
        out << some_SequenceMap.recognition_sequence_ << " ";
        std::string str = {some_SequenceMap.recognition_sequence_};
        for( unsigned int i = 0; i < str.size(); ++i){
            out << str[i] << " ";
        }
        
        return out;

    }

    /*
    friend std::ostream &operator>>(std::ostream &in, SequenceMap &some_SequenceMap){
      in >> some_SequenceMap.size();
      for(unsigned int i = 0; i < some_SequenceMap.size(); ++i){

      }
    }
    */

    //member function merge
    void Merge(const SequenceMap &other_sequence){
        for(unsigned int i = 0; i < other_sequence.enzyme_acronyms_.size(); ++i){
        enzyme_acronyms_.push_back(other_sequence.enzyme_acronyms_[i]);
      }
    }

  private:
    std::string recognition_sequence_;
    std::vector<std::string> enzyme_acronyms_;

};


#endif
