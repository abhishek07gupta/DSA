#include<vector>
#include<iostream>
using namespace std;

class trieNode{
    public:
        char  data ;
        trieNode * children[26];
        bool isTerminal;

        trieNode(char  ch){
            data = ch;
            for(int i =  0 ; i<26 ; i ++){
                children[i]=NULL;
            }
            isTerminal=false;
        }
};

class trie{
    public:
    trieNode * root;
    trie(){
        root = new trieNode('\0');
    }

    void insertUtil(trieNode * root , string word){
        if(word.length()==0){
            root->isTerminal = true;
            cout<<"inserted  successfully"<<endl;
            return ;
        }

        int index = word[0]-'A';
        trieNode* child ;

        if(root->children[index]!=NULL){
            child = root->children[index];
        }else{
            child = new trieNode(word[0]);
            root->children[index]= child; 
        }
            insertUtil(child,word.substr(1));
    }

    void insert(string word){
        insertUtil(root,word);
    }

    void searchUtil(trieNode * root , string word){
        if(word.length()==0){
            if(root->isTerminal==true){
                cout<<"the word is present"<<endl;
            }else{
                cout<<"the word is not present"<<endl;
            }
            return ;
        }

        int index = word[0]-'A';
        
        if(root->children[index]!=NULL){
            searchUtil(root->children[index],word.substr(1));
        }else{
            cout<<"the word is not presnt "<<endl;
            return ;
        }
    }

    void search(string word){
        searchUtil(root , word);
    }

    void removeUtil(trieNode * root , string word){
        if(word.length()==0){
            if(root->isTerminal==false){
                cout<<"the word was not present only "<<endl;
            }else{
            root->isTerminal=false;
            cout<<"the word has been deleted"<<endl;
            }
            return ;
        }

        int index = word[0]-'A';

        if(root->children[index]!=NULL){
            removeUtil(root->children[index],word.substr(1));
        }else{
            cout<<"the word was not present only "<<endl;
            return ;
        }
    }

    void remove(string word){
        removeUtil(root , word);
    }
};

int main(){
    trie * t = new trie();
    t->insert("HELLO");
    // t->search("abhi");
    t->search("HELLO");
    t->remove("HELL");
    t->remove("HELLO");
    return 0 ;
}