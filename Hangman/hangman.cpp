#include <iostream>
#include <map>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>
#include <cctype>

void hangman(int incorrect){
	if (incorrect==0){
		std::cout<<"   _____\n       |\n       |\n       |\n       |\n       |\n     __|__";
	}
	else if (incorrect==1){
		std::cout<<"   _____\n   0   |\n       |\n       |\n       |\n       |\n     __|__";
	}
	else if (incorrect==2){
		std::cout<<"   _____\n   0   |\n   |   |\n   |   |\n       |\n       |\n     __|__";
	}
	else if (incorrect==3){
		std::cout<<"   _____\n   0   |\n  \\|   |\n   |   |\n       |\n       |\n     __|__";
	}
	else if (incorrect==4){
		std::cout<<"   _____\n   0   |\n  \\|/  |\n   |   |\n       |\n       |\n     __|__";
	}
	else if (incorrect==5){
		std::cout<<"   _____\n   0   |\n  \\|/  |\n   |   |\n  /    |\n       |\n     __|__";
	}
	else{
		std::cout<<"   _____\n   0   |\n  \\|/  |\n   |   |\n  / \\  |\n       |\n     __|__";
	}
	std::cout<<std::endl;
}

void print(int incorrect, std::vector<std::string> blanks){
	hangman(incorrect);
	std::cout<<"  ";
	for (int i=0;i<(int)blanks.size();i++){
		std::cout<<blanks[i]<<" ";
	}
	std::cout<<std::endl;
}

bool checkletter(char letter, std::string chosenword){
	if (chosenword.find(letter)!= std::string::npos||chosenword.find(toupper(letter))!= std::string::npos){
		return true;
	}
	else {
		return false;
	}

}

std::vector<std::string> updateword(char letter,std::string chosenword, std::vector<std::string> blanks){
	std::string pushed;
	for (int i=0; i<(int)chosenword.size();i++){
		pushed.clear();
		char chosenletter=chosenword[i];
		chosenletter=tolower(chosenletter);
		letter=tolower(letter);
		if (letter==chosenletter){
			pushed.push_back(letter);
			blanks[i]=pushed;
		}
	}
	return blanks;
}

int main(){
	std::map<std::string,std::vector<std::string>> words;
	std::vector<std::string> allcategories,animals,countries, sports,anime,movies,blanks,correct,wrongs;
	std::fstream file,file2,file3,file4,file5;
    std::string word,word2,word3,word4,word5, t, q, animalfile,countryfile,sportsfile,moviesfile,animefile,category, chosenword,letter1;
    char letter, finish, again, cate;
    int topic, random,rancat, categorysize, incorrect;
    bool init, finishbool,gaming;
    gaming=true;
    srand(time(NULL));
 
    animalfile = "animals.txt";
    countryfile = "countries.txt";
    sportsfile = "sports.txt";
    moviesfile="movies.txt";
    animefile="anime.txt";

    file.open(animalfile);
    while (file >> word){
        animals.push_back(word);
    }

    file2.open(countryfile);
    while (file2 >> word2){
        countries.push_back(word2);
    }

    file3.open(sportsfile);
    while (file3 >> word3){
        sports.push_back(word3);
    }
    file4.open(moviesfile);
    while (file4 >> word4){
        movies.push_back(word4);
    }
    file5.open(animefile);
    while (file5 >> word5){
        anime.push_back(word5);
    }

    words["Animals"]=animals;
    words["Countries"]=countries;
    words["Sports"]=sports;
    words["Movies"]=movies;
    words["Anime"]=anime;
    allcategories.push_back("Animals");
    allcategories.push_back("Countries");
    allcategories.push_back("Sports");
    allcategories.push_back("Movies");
    allcategories.push_back("Anime");
    while(gaming){
    	correct.clear();
    	finishbool=false;
    	if (again=='N'){
    		break;
    	}
    	std::cout<<"Select a number for the topic you want: (1) Animals  (2) Countries  (3) Sports  (4) Movies  (5) Anime  (6) Random  (7) End Game"<<std::endl;
	    std::cout<<"Enter Topic: ";
	    std::cin>>topic;
	    if (topic==1){
	    	category="Animals";
	    }
	    else if (topic==2){
	    	category="Countries";
	    }
	    else if (topic==3){
	    	category="Sports";
	    }
	    else if (topic==4){
	    	category="Movies";
	    }
	    else if (topic==5){
	    	category="Anime";
	    }
	    else if (topic==6){
	    	rancat=rand()%allcategories.size();
	    	category=allcategories[rancat];
	    	std::cout<<"Would you like to know the category?\nY/N: ";
	    	std::cin>>cate;
	    	if(cate=='Y'||cate=='y'){
	    		std::cout<<"The category is "<<category<<std::endl;
	    	}
	    }
	    else if (topic==7){
	    	break;
	    }
	    else{
	    	std::cout<<"Invalid entry, try again"<<std::endl;
	    	continue;
	    }
	    categorysize=words[category].size();
	    random= rand()%categorysize;
	    chosenword=words[category][random];
	    blanks.clear();
	    wrongs.clear();
	    std::string clet;
	    for (int i=0; i<(int)chosenword.size();i++){
	    	clet.clear();
	    	clet.push_back(chosenword[i]);
	    	if (chosenword[i]=='_'){
	    		blanks.push_back(" ");
	    		correct.push_back(" ");
	    	}
	    	else{
	    		blanks.push_back("_");
	    		correct.push_back(clet);
	    	}
	    	
	    }
	    incorrect=0;
	    while(true){
	    	print(incorrect, blanks);
	    	std::cout<<"Wrong Letters: ";
	    	for (int i=0;i<(int)wrongs.size();i++){
	    		std::cout<<" "<<wrongs[i];
	    	}
	    	std::cout<<std::endl;
	    	std::cout<<"Enter a letter: ";
	    	std::cin>>letter1;
	    	std::cout<<"==========================="<<std::endl;
	    	if (letter1.size()>1){
	    		std::cout<<"Please enter 1 letter"<<std::endl;
	    		continue;
	    	}
	    	letter=letter1[0];
	    	if (!std::isalpha(letter)){
	    		std::cout<<"Please enter a letter"<<std::endl;
	    		continue;
	    	}
	    	if (std::find(wrongs.begin(), wrongs.end(), letter1) != wrongs.end()){
	    		std::cout<<"Letter has already been entered. Please pick a new letter."<<std::endl;
	    		continue;
	    	}
	    	init=checkletter(letter, chosenword);
	    	if (init==false){
	    		incorrect++;
	    		wrongs.push_back(letter1);
	    	}
	    	else{
	    		blanks=updateword(letter,chosenword,blanks);
	    	}
	    	
	    	/*Case where user has made a complete hangman and can choose to either continue the game
	    	or give up and see the solution*/

	    	if (incorrect>=6 && finishbool==false){
	    		print(incorrect, blanks);
	    		std::cout<<"Would you like to keep playing?\nY/N: ";
	    		std::cin>>finish;
	    		if (finish=='Y'||finish=='y'){
	    			finishbool=true;
	    		}
	    		if (finish=='N'||finish=='n'){
	    			std::cout<<"CORRECT SOLUTION:"<<std::endl;
	    			print(incorrect,correct);
	    			std::cout<<"Would you like to play again?\nY/N: ";
	    			std::cin>>again;
		    		if (again=='N'||again=='n'){
		    			gaming=false;
		    			break;
		    		}
		    		if (again=='Y'||again=='y'){
		    			break;
		    		}
	    		}
	    	}

	    	/*Case where user has correctly gotten the hangman, then asked if they would like to 
	    	play again*/

	    	if (std::find(blanks.begin(), blanks.end(), "_") == blanks.end()){
	    		print(incorrect, blanks);
	    		std::cout<<"YOU WIN! Would you like to play again?\nY/N: ";
	    		std::cin>>again;
	    		if (again=='N'||again=='n'){
	    			gaming=false;
	    			break;
	    		}
	    		if (again=='Y'||again=='y'){
	    			break;
	    		}
	    	}
	    	
	    }
    }


}
