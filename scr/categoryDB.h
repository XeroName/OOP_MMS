// categoryDB.h
// 2025-05-21 by XERONAME
// latest edit at 2025-05-25

// conditional compiling to compile only once
#ifndef COMPILED_CATEGORYDB // compiled the code from #ifndef to #endif, if the macro 'COMPILED_PRODUCTDB' was not defined before
#define COMPILED_CATEGORYDB // define macro for conditional compile

#include <string> // for std::string
#include <cstring> // for strcpy() and strcmp() functions
#include <vector> // for std::vector
#include <limits.h> // for getting limitations of data types

#include "console_controls.h"
#include "strings_defined.h"



typedef struct ItemCategory {
    Icat* category_parent;
    char* category_this;
    std::vector<Icat*> category_children;

    ItemCategory(const char* name_category_this, Icat* ptr_category_parent=NULL)
    {
        strcpy(category_this, name_category_this);
        category_parent = ptr_category_parent;
    }
} Icat;



class IcatDB {
    private :
        std::vector<Icat> categories;

        // add new child category to target category
        void addChildCategory(int idx_target, int idx_child)
        { (categories[idx_target].category_children).push_back(&categories[idx_target]); }

        // remove child category from target category
        bool removeChildCategory(int idx_target, int idx_child) {
            std::vector<Icat*>* children_target = &(categories[idx_target].category_children);
            Icat cat_child = categories[idx_child]; // child category of [target to remove child]

            for (int i=0; i<((*children_target).size()); i++) {
                if ( ((*children_target)[i]) == (&cat_child) ) {
                    (*children_target).erase( ((*children_target).begin()) +i );
                    return true; // succeed to remove children from target
                }
            }
            return false; // failed to find matching children
        }

    public :
        // check whether the count of elements in vector container exceeds max size
        bool exceededMaxSize() { return ((categories.size()) > INT_MAX); }

        // get index number of target category
        int getCategoryIdx(const char* name_category) {
            for (int i=0; i<(categories.size()); i++) {
                // return id number of category, if target category has been found
                if (strcmp(name_category, categories[i].category_this) == 0) { return i; }
            }
            return (-1); // return (-1) if failed to find matching name of category
        }

        // get copy of Icat element in vector, by index number
        Icat getCategoryCopy(int idx) { return categories[idx]; }

        // assign new Icat elemet to vector
        std::vector<Icat>::iterator assignNewCategory(const char* name_category_this, Icat* ptr_category_parent=NULL)
        {
            // terminate off the program if container exceeded its max size
            if (exceededMaxSize) { terminateProgram( 1, true, (str_err_u8_containerExceededMaxSize.c_str()), (str_u8_debug.c_str()) ); }

            // terminate off the program if same category of name already exists
            if (getCategoryIdx(name_category_this) >= 0)
            { terminateProgram( 1, true, (str_err_u8_dataAlreadyExist.c_str()), (str_u8_debug.c_str()) ); }

            std::vector<Icat>::iterator iter_inserted; // declare a variable to copy iterator of inserted element
            // insert a Icat element to next-of-end of vector named 'categories', then copy iterator to variable named 'iter_inserted'
            iter_inserted = categories.insert(categories.end(), Icat(name_category_this, ptr_category_parent));
            return iter_inserted; // return iterator of inserted element
        }

        void linkParentCategory(int idx_target, int idx_parent) {
            categories[idx_target].category_parent = (&categories[idx_parent]);
            addChildCategory(idx_parent, idx_target);
        }

        void unlinkParentCategory(int idx_target, int idx_parent) {
            removeChildCategory(idx_parent, idx_target); // unlink target from parent-category
            categories[idx_target].category_parent = NULL; // unlink parent-category of target
        }
};

#endif // end of the conditional compile
