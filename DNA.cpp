#include "DNA.h"

using namespace std;


//name: DNA (default constructor)
//pre: None
//post: A linked list (DNA) where m_head and m_tail points to NULL
DNA::DNA()
{
    m_head = NULL;
    m_tail = NULL;
    m_size = 0;
}
//name: ~DNA (destructor)
//pre: There is an existing linked list
//post: A linked list (DNA) is deallocated (including all dynamically 
//     allocated nucleotides)
DNA::~DNA()
{
    Clear();
}
//name: InsertEnd
//pre: Takes in a char. Creates new node (nucleotide). 
//     Requires a linked list (strand of DNA)
//post: Adds a new node (nucleotide) to the end of the linked list (strand of DNA).
void DNA::InsertEnd(char payload)
{
    Nucleotide *myNode = new Nucleotide();
    myNode->m_payload = payload;
    myNode->m_next = NULL;
    //applies for the first Node
    if (m_tail == NULL)
    {
        m_head = myNode;
    }
    //applies for rest
    else
    {
      m_tail->m_next=myNode;
    }
    m_tail = myNode;
}
//name: Display
//pre: Outputs the dna strand(s); Pass it 1 for just the nucleotides; 
//     2 for the nucleotides and it's complement (base pair)
//post: None
void DNA::Display(int numStrand)
{
  cout << "Base Pairs:" << endl; 
    Nucleotide *myNode = new Nucleotide();
    myNode = m_head;
    //For just single nucleotides
    if (numStrand == 1)
    {
        for (int i = 0; i < m_size; i++)
        {
            cout << myNode->m_payload << endl;
            myNode = myNode->m_next;
        }
	cout << "END" << endl;
	cout << m_size << " nucleotides listed" << endl;
	cout << m_size/TRINUCLEOTIDE_SIZE << " trinucleotides listed" << endl;
    }
    //For base pairs
    else if (numStrand == 2)
    {
        for (int i = 0; i < m_size; i++)
        {
            cout << myNode->m_payload  << "-";
            char basePair = myNode->m_payload;
            switch (basePair)
            {
                case ('A'):
                    basePair = 'T';
                    break;
                case ('T'):
                    basePair = 'A';
                    break;
                case ('G'):
                    basePair = 'C';
                    break;
                case ('C'):
                    basePair = 'G';
                    break;
                default:
                    break;
            }
            cout << basePair << endl;
            myNode = myNode->m_next;
        }
	cout << "END" << endl;
	cout << m_size << " base pairs listed" << endl;
	cout << m_size/TRINUCLEOTIDE_SIZE << " trinucleotides listed" << endl;
    }
    
}
//name: NumAmino
//pre: Takes in an amino acid name and its trinucleotide codon
//     Trinucleotides are just three nucleotides in a row.
//post: Searches the linked list for specific sequence; outputs results
void DNA::NumAmino(string name, string trinucleotide)
{
  int totalAmino = 0;
  Nucleotide *myNode = new Nucleotide();
  myNode = m_head;
  for (int i = 0; i < (m_size/TRINUCLEOTIDE_SIZE); i++)
    {
      string triNucleotide;
      triNucleotide.push_back(myNode->m_payload);
      triNucleotide.push_back(myNode->m_next->m_payload);
      triNucleotide.push_back(myNode->m_next->m_next->m_payload);
      if (Translate(triNucleotide) == name)
	{
	  totalAmino++;
	}
      myNode = myNode->m_next->m_next->m_next;
    }
  cout << name << ": " << totalAmino << " identified" <<  endl;
}
//name: Sequence
//pre: Takes in full genetic code of one polynucleotide and looks at 
//     one trinucleotide at a time.
//     Known amino acids are displayed, others are unknown. Stored in dynamic array.
//post: Displays either name of amino acid or unknown for each trinucleotide
void DNA::Sequence()
{
    cout <<"Amino Acid List:" << endl;
    Nucleotide *myNode = new Nucleotide();
    myNode = m_head;
    for (int i = 0; i < (m_size/TRINUCLEOTIDE_SIZE); i++)
    {
        string triNucleotide;
        triNucleotide.push_back(myNode->m_payload);
        triNucleotide.push_back(myNode->m_next->m_payload);
        triNucleotide.push_back(myNode->m_next->m_next->m_payload);
        cout << Translate(triNucleotide) << endl;
        
        myNode = myNode->m_next->m_next->m_next;
    }
}
//name: Translate (Provided)
//pre: Takes in three nucleotides (must be G,C,T, or A)
//post: Translates a trinucleotide to its amino acid
string DNA::Translate(const string trinucleotide){
    if((trinucleotide=="ATT")||(trinucleotide=="ATC")||(trinucleotide=="ATA"))
        return ("Isoleucine");
    else if((trinucleotide=="CTT")||(trinucleotide=="CTC")||(trinucleotide=="CTA")||
            (trinucleotide=="CTG")|| (trinucleotide=="TTA")||(trinucleotide=="TTG"))
        return ("Leucine");
    else if((trinucleotide=="GTT")||(trinucleotide=="GTC")||
            (trinucleotide=="GTA")||(trinucleotide=="GTG"))
        return ("Valine");
    else if((trinucleotide=="TTT")||(trinucleotide=="TTC"))
        return ("Phenylalanine");
    else if((trinucleotide=="ATG"))
        return ("Methionine");
    else if((trinucleotide=="TGT")||(trinucleotide=="TGC"))
        return ("Cysteine");
    else if((trinucleotide=="GCT")||(trinucleotide=="GCC")||
            (trinucleotide=="GCA")||(trinucleotide=="GCG"))
        return ("Alanine");
    else if((trinucleotide=="GGT")||(trinucleotide=="GGC")||
            (trinucleotide=="GGA")||(trinucleotide=="GGG"))
        return ("Glycine");
    else if((trinucleotide=="CCT")||(trinucleotide=="CCC")||
            (trinucleotide=="CCA")||(trinucleotide=="CCG"))
        return ("Proline");
    else if((trinucleotide=="ACT")||(trinucleotide=="ACC")||
            (trinucleotide=="ACA")||(trinucleotide=="ACG"))
        return ("Threonine");
    else if((trinucleotide=="TCT")||(trinucleotide=="TCC")||
            (trinucleotide=="TCA")||(trinucleotide=="TCG")||
            (trinucleotide=="AGT")||(trinucleotide=="AGC"))
        return ("Serine");
    else if((trinucleotide=="TAT")||(trinucleotide=="TAC"))
        return ("Tyrosine");
    else if((trinucleotide=="TGG"))
        return ("Tryptophan");
    else if((trinucleotide=="CAA")||(trinucleotide=="CAG"))
        return ("Glutamine");
    else if((trinucleotide=="AAT")||(trinucleotide=="AAC"))
        return ("Asparagine");
    else if((trinucleotide=="CAT")||(trinucleotide=="CAC"))
        return ("Histidine");
    else if((trinucleotide=="GAA")||(trinucleotide=="GAG"))
        return ("Glutamic acid");
    else if((trinucleotide=="GAT")||(trinucleotide=="GAC"))
        return ("Aspartic acid");
    else if((trinucleotide=="AAA")||(trinucleotide=="AAG"))
        return ("Lysine");
    else if((trinucleotide=="CGT")||(trinucleotide=="CGC")||(trinucleotide=="CGA")||
            (trinucleotide=="CGG")||(trinucleotide=="AGA")||(trinucleotide=="AGG"))
        return ("Arginine");
    else if((trinucleotide=="TAA")||(trinucleotide=="TAG")||(trinucleotide=="TGA"))
        return ("Stop");
    else
        cout << "returning unknown" << endl;
    return ("Unknown");
}
//name: IsEmpty
//pre: Takes in a linked list (DNA)
//post: Checks to see if the linked list (strand of DNA) is empty or not
bool DNA::IsEmpty()
{
  //When size of List is 0
    if (m_size == 0)
    {
        return true;
    }
    //when List is at least 1
    else
    {
        return false;
    }
}
//name: SizeOf
//pre: Takes in a linked list (DNA)
//post: Populates m_size with the total number of nucleotides loaded
void DNA::SizeOf()
{
    m_size = 0;
    Nucleotide *myNode = new Nucleotide();
    myNode = m_head;
    while (myNode != NULL)
    {
        m_size++;
        myNode = myNode->m_next;
    }
}
//name Clear
//pre: Takes in a linked list (DNA)
//post: Clears out the linked list (all nodes too)
void DNA::Clear()
{
  Nucleotide *myNode = m_head;
    while (myNode != NULL)
    {
      Nucleotide *next = myNode->m_next;
      delete myNode;
      myNode = next;
    }
    m_head = NULL;
    m_tail = NULL;
    m_size = 0;
}



