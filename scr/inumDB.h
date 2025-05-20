// inumDB.h
// 2025-05-05 by XERONAME

#include <vector>

// Struct - identifier number of product
typedef struct Inum_product {
    unsigned int primary; // primary number of inum(identifier number)

    static unsigned int primary_rear; // rear of primary inum (static variable)
} ProductInum;
