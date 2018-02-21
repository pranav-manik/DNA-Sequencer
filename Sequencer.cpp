//
//  Sequencer.cpp
//  Project 3
//
//  Created by Pranav Manik on 3/21/17.
//  Copyright © 2017 Pranav Manik. All rights reserved.
//

#include <stdio.h>
#include "Sequencer.h"


//name: Sequencer (default constructor)
//pre: A linked list (DNA) is available
//post: A linked list (DNA) where m_head and m_tail points to NULL
Sequencer::Sequencer(string fileName)
{
    m_dna.SizeOf();
    m_fileName = fileName;
    readFile();
    m_dna.SizeOf();
    mainMenu();
}
//name: Sequencer (destructor)
//pre: There is an existing linked list (DNA)
//post: A linked list (DNA) is deallocated (including nucleotides) to have no memory leaks!
Sequencer::~Sequencer()
{
  //delete *m_dna;
  m_dna.~DNA();
}
//name: readFile
//pre: Valid file name of characters (Either A, T, G, or C)
//post: Populates the LinkedList (DNA)
void Sequencer::readFile()
{
    
    ifstream myFile;
    char *fileName[m_fileName.length()];
    //Converts string to char
    for (unsigned int i = 0; i < m_fileName.length()-1; i++)
      {
	fileName[i] = &m_fileName[i];
      }
    cout << *fileName << endl;
    myFile.open(*fileName);
    int numOfLines = 0;
    //Finds the number of lines in file
    while (!myFile.eof())
    {
        string line;
        myFile >> line;
        numOfLines++;
    }
    numOfLines--;
    myFile.close();
    //Loads in Linked List
    myFile.open(*fileName);
    for (int i = 0; i < numOfLines; i++)
    {
        char nucleotide;
        myFile >> nucleotide;
        m_dna.InsertEnd(nucleotide);
	
    }
    myFile.close();
}
//name: mainMenu
//pre: Populated LinkedList (DNA)
//post: None
void Sequencer::mainMenu()
{
    int userChoice;
    while (userChoice != 5)
    {
        cout << "What would you like to do?:" << endl;
        cout << "1. Display Sequencer (Leading Pairs)" << endl;
        cout << "2. Display Sequencer (Base Pairs)" << endl;
        cout << "3. Inventory Basic Amino Acids" << endl;
        cout << "4. Sequence Entire DNA Strand" << endl;
        cout << "5. Exit" << endl;
        cin >> userChoice;
        
        switch (userChoice)
        {
	  //Displays Single Nucleotides
            case (1):
                m_dna.Display(1);
                break;
		//Displays Base Pairs
            case (2):
                m_dna.Display(2);
                break;
		//Displays Number of any Amino Acid you want
            case (3):
	      m_dna.NumAmino("Tryptophan", "TGG");
	      m_dna.NumAmino("Phenylalanine", "TTT");
                break;
		//Displays all TriNucleotides as Amino Acids
            case (4):
                m_dna.Sequence();
                break;
		//Exits program
            case (5):
                cout << "DNA removed from memory" << endl;
                m_dna.~DNA();
		//~Sequencer();
                break;
            default:
	      cout << "I'm sorry this is not a choice" << endl;
                break;
        }
    }
   
}
