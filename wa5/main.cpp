#include <iostream>
#include "hashTable.h"

using namespace std;

int main()
{
   HashTable hash(3);
   
   hash["Paul"]++;
   hash["Sarah"]++;
   hash["Chloe"]++;
   hash["Bill"]++;
   hash["Jack"]++;
   hash["Lexi"]++;

   hash.insert("Clay", 1);
   hash.insert("Will", 1);
   hash.insert("Erica", 1);

   if (hash.containsKey("Bill"))
      cout << "Bill is a " << hash["Bill"] << endl;
   else
      cout << "Bill not found" << endl;

   if (hash.containsKey("Paul"))
      cout << "Paul is a " << hash["Paul"] << endl;
   else
      cout << "Paul not found" << endl;

   hash.remove("Chloe");

   if (hash.containsKey("Chloe"))
      cout << "Found Chloe but should not have" << endl;

   if (hash["Chloe"] == 1)
      cout << "Still didn't find Chloe" << endl;

   if (hash.containsKey("Chloe"))
      cout << "Chloe got created by using the [] syntax" << endl;

   if (hash.containsKey("Lexi"))
      cout << "Lexi is a " << hash["Lexi"] << endl;

   hash["Paul"]++;
   
   if (hash.containsKey("Paul"))
      cout << "Paul is a " << hash["Paul"] << endl;
   else
      cout << "Paul not found" << endl;

   
   for (string str : hash.getKeys())
      cout << str << endl;
      
   return 0;
}
