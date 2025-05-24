// productDB.h
// 2025-05-05 by XERONAME

// conditional compiling to compile only once
#ifndef COMPILED_PRODUCTDB // compiled the code from #ifndef to #endif, if the macro 'COMPILED_PRODUCTDB' was not defined before
#define COMPILED_PRODUCTDB // define macro for conditional compile

#include <string> // for std::string data type
#include <cstring> // for strcpy() function
#include <vector> // for vector container

#include "datetimes.h" // customized header file of date and times
#include "strings_defined.h" // customized header file of pre-declared strings



// Struct - Product
typedef struct Struct_product {
    // 해당 구조체 객체의 데이터는 최초로 생성된 후 수정하는 것을 금지함

    Date date_assigned; // 해당 제품의 데이터가 처음으로 기입(등록)된 날짜

    char* name_product; // 해당 제품의 이름
    char* description; // 해당 제품의 설명
    char* name_vendor; // 해당 제품 공급자의 이름

    // 해당 구조체의 객체는 아래 두 가지의 정수형 번호를 조합하여 고유 식별 번호를 갖는다.
    // 예시 : 각각 번호 (4, 5)와 (4, 23)을 가진 아이템은 서로 다름
    unsigned int code_int_pri; // 해당 제품의 첫 번째 정수형 번호
    unsigned int code_int_sec; // 해당 제품의 두 번째 정수형 번호

    // Struct constructor
    Struct_product( const char* product_name, const char* product_description=(str_u8_none.c_str()), const char* product_vendor=(str_u8_unknown.c_str()) )
    {
        strcpy(name_product, product_name); // assign the pointer, name of product
        strcpy(description, product_description); // assign the pointer, description of product
        strcpy(name_vendor, product_vendor); // assign the pointer, vendor name of product

        assignCurrentDate(date_assigned); // assign the current date time
    }
} Product;



class ProductDB {
    private :
        std::vector<Product> list_products;

    public :
        // get emptiness of vector
        bool listEmpty() { return (list_products.empty()); }

        // get amount of elements in vector
        unsigned int getProductsAmount() { return (list_products.size()); }

        // insert a new Product element to database and return its iterator
        std::vector<Product>::iterator assignNewProduct(const char* product_name,
        const char* product_description=(str_u8_none.c_str()),
        const char* product_vendor=(str_u8_unknown.c_str()))
        {
            std::vector<Product>::iterator iter_inserted; // declare a variable to copy iterator of inserted element
            // insert a Product element to next-of-end of vector named 'list_products', then copy iterator to variable named 'iter_inserted'
            iter_inserted = list_products.insert((list_products.end()), Product(product_name, product_description, product_vendor));

            return iter_inserted; // return iterator, where element inserted
        }

        // access to specified product in productDB
        Product& prod(const std::vector<Product>::iterator iter_target) {
            unsigned int index_number = std::distance(list_products.begin(), iter_target);
            return list_products[index_number];
        }

        // erase a existing Product element from database
        void eraseProduct(const std::vector<Product>::iterator iter_target) {
            list_products.erase(iter_target); // erase element in vector where iterator points
        }

        // pop a existing Product element from database, and return it
        Product popProduct(const std::vector<Product>::iterator iter_target) {
            unsigned int index_number = std::distance(list_products.begin(), iter_target);
            Product elemCopy = list_products[index_number];
            list_products.erase(iter_target); // erase element in vector where iterator points

            return elemCopy;
        }
};

#endif // end of the conditional compile
