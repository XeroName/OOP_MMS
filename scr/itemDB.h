// itemDB.h
// 2025-04-27 by XERONAME

// conditional compiling to compile only once
#ifndef COMPILED_ITEMDB // compiled the code from #ifndef to #endif, if the macro 'COMPILED_ITEMDB' was not defined before
#define COMPILED_ITEMDB // define macro for conditional compile

#include <string> // for std::string data type
#include <cstring> // for strcpy() function
#include <vector> // for vector container

#include "datetimes.h" // customized header file of date and times
#include "productDB.h" // customized header file of product data base



// type of expiry date
typedef enum ExpiryDate : unsigned char {
    sellBy, // 유통 기한
    usedBy // 소비 기한
} ExpDate;

// type of item category
typedef struct ItemCategory {
    char* primary; // 첫 번째 분류
    char* secondary; // 두 번째 분류
    char* tertiary; // 세 번째 분류
} ItemCat;



// Class - Item
class Item {
    // 품목 클래스 : 단일 또는 다수 제품의 집합
    private :
        Date date_assigned; // 해당 품목의 데이터가 처음으로 기입(등록)된 날짜
        Date date_renewed; // 해당 품목의 데이터가 가장 마지막으로 수정된 날짜

        std::vector<Product> contents; // 해당 품목의 제품 구성 (벡터 컨테이너)

        char* name; // 해당 품목의 이름
        char* description; // 해당 품목의 설명
        char* manufacturer; // 해당 품목의 제조자(또는 업체)
        char* country_origin; // 해당 품목의 원산지
        char* vendor; // 해당 품목의 공급자(또는 업체)

        Date date_manufactured; // 해당 품목의 제조 일자
        Date date_expiry; // 해당 품목의 만료 기한
        ExpDate date_expiry_type; // 해당 품목 만료 기한의 유형 (유통 또는 소비 기한)

        ItemCat category; // 해당 품목의 유형(분류)

        int mass_gram; // 해당 품목의 질량 (단위 : 그램)

        int price_item; // 해당 품목의 가격 (세금 제외)
        int price_tax; // 해당 품목의 세금 (일반적으로 품목가의 10%)
        int price_full; // 해당 품목의 정가(정가=품목가+세금, 할인율 적용 제외)
        double rate_discount; // 해당 품목의 정가 할인율 (예시 : 해당 값이 0.53인 경우, 정가에서 53%가 할인된 값이 최종 판매가에 적용됨)

        unsigned int stock_actual; // 해당 품목의 실제 재고 수량
        unsigned int stock_available; // 해당 품목의 판매 가능 재고 수량
        bool stock_unlimited = false; // 해당 품목의 무제한 판매 가능 여부 (true인 경우, 판매 가능 여부가 재고 수량에 영향을 받지 않음)
        bool on_sale; // 해당 품목의 판매 상태 (true=판매 중, false=판매 중이 아님)

    public :
        //a
};

// Class - Package
class Package {
    // 패키지(품목 구성) 클래스 : 다수 품목의 집합
    private :
        Date date_assigned; // 해당 패키지의 데이터가 처음으로 기입(등록)된 날짜
        Date date_renewed; // 해당 패키지의 데이터가 가장 마지막으로 수정된 날짜

        std::vector<Item> contents; // 해당 패키지의 품목 구성 (벡터 컨테이너)

        char* name; // 해당 패키지의 이름
        char* description; // 해당 패키지의 설명

        ItemCat category; // 해당 패키지의 유형(분류)

        int mass_gram; // 해당 패키지의 질량 (단위 : 그램)

        int price_item; // 해당 패키지의 가격 (세금 제외)
        int price_tax; // 해당 패키지의 세금 (일반적으로 품목가의 10%)
        int price_full; // 해당 패키지의 정가(정가=품목가+세금, 할인율 적용 제외)
        double rate_discount; // 해당 패키지의 정가 할인율 (예시 : 해당 값이 0.53인 경우, 정가에서 53%가 할인된 값이 최종 판매가에 적용됨)

        unsigned int stock_actual; // 해당 패키지의 실제 재고 수량
        unsigned int stock_available; // 해당 패키지의 판매 가능 재고 수량
        bool stock_unlimited = false; // 해당 패키지의 무제한 판매 가능 여부 (true인 경우, 판매 가능 여부가 재고 수량에 영향을 받지 않음)
        bool on_sale; // 해당 패키지의 판매 상태 (true=판매 중, false=판매 중이 아님)
    
    public :
        //a
};

// Class - Selectable Package
class SPackage {
    // 선택형 패키지(품목 구성) 클래스 : 다수 품목의 집합, 일정 갯수의 품목을 선택 가능
    private :
        Date date_assigned; // 해당 패키지의 데이터가 처음으로 기입(등록)된 날짜
        Date date_renewed; // 해당 패키지의 데이터가 가장 마지막으로 수정된 날짜

        std::vector<Item> contents; // 해당 패키지의 품목 구성 (벡터 컨테이너)
        unsigned int content_amount_selectable; // 해당 패키지에서 선택 가능한 품목의 갯수
        bool content_duplicatable = true; // 해당 패키지에서 같은 유형의 품목 선택 가능 여부 (true인 경우, 같은 유형의 품목을 교차 선택 가능)

        char* name; // 해당 패키지의 이름
        char* description; // 해당 패키지의 설명

        ItemCat category; // 해당 패키지의 유형(분류)

        int mass_gram; // 해당 패키지의 질량 (단위 : 그램)

        int price_item; // 해당 패키지의 가격 (세금 제외)
        int price_tax; // 해당 패키지의 세금 (일반적으로 품목가의 10%)
        int price_full; // 해당 패키지의 정가(정가=품목가+세금, 할인율 적용 제외)
        double rate_discount; // 해당 패키지의 정가 할인율 (예시 : 해당 값이 0.53인 경우, 정가에서 53%가 할인된 값이 최종 판매가에 적용됨)

        unsigned int stock_actual; // 해당 패키지의 실제 재고 수량
        unsigned int stock_available; // 해당 패키지의 판매 가능 재고 수량
        bool stock_unlimited = false; // 해당 패키지의 무제한 판매 가능 여부 (true인 경우, 판매 가능 여부가 재고 수량에 영향을 받지 않음)
        bool on_sale; // 해당 패키지의 판매 상태 (true=판매 중, false=판매 중이 아님)
    
    public :
        //a
};




class ItemDB {
    private :
        std::vector<Item> list_items;

    public :
        //a
};

#endif // end of the conditional compile
