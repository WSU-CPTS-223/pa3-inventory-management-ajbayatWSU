#pragma once

#include <iostream>
#include <string>

using namespace std;

// class to represent one product from the .csv (essentially one row)
class Product
{
    public:
        // strings for each field from the csv (that are important to this application)
        string id,
               name,
               category; // category section has NOT been separated yet

        // constructors
        Product() {}
    
        Product(const string& IDstring, const string& NAMEstring, const string& CATEGORYstring)
            : id(IDstring), name(NAMEstring), category(CATEGORYstring) {}
        
        // getters
        string getId() const
        {
            return id;
        }

        string getName() const
        {
            return name;
        }

        string getCategory() const
        {
            return category;
        }

        // function to print all search results from the find<id> command
        void printAllFields() const
        {
            cout << "ID: " << id << "\n";
            cout << "NAME " << name << "\n";
            cout << "CATEGORY: " << category << "\n";
        }

        // function to print the results from the listInventory <category_string> command
        void printIDandNAME() const
        {
            cout << id << " --- " << name << "\n";
        }
};