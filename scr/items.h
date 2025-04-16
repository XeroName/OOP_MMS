// items.h
// 2025-04-16

#include <string>



enum ItemStatus {
    ACTIVE, // 0, 활성 제품
    OBSOLETE, // 1, 구형 제품
    DISCONTINUE // 2, 판매 중지 제품
};

// Struct - Date time
typedef struct {
    int year; // 연
    int month; // 월
    int date; // 일
    int hour; // 시
    int min; // 분
    int sec; // 초
} Date;

typedef struct {
    std::string big; // 대분류
    std::string mid; // 중분류
    std::string small; // 소분류
} ItemCategory;



// Struct - Item
typedef struct {
    std::string name; // 상품명
    std::string vendor; // 공급자
    std::string item_number; // 상품 번호

    Date date_purchased; // 구입 일자
    Date date_manufactured; // 제조 일자
    Date date_expiration; // 만료 일자 (유통 기한)

    int stock; // 재고

    long long price_purchased; // 구입가
    long long price_full; // 판매가 (정가)

    bool include_tax; // 세금 포함 여부 (VAT, 부가가치세)

    // 상품 분류 (스킵)
    // 상품 상태 (스킵)
    // 프로모션 정보 (스킵)
    // 공급 단위 (스킵)

} Item;

// Struct - Item transaction history
typedef struct {
    Item item; // 거래 품목
    Date date_trans; // 거래 일자
    // 거래자 정보 (스킵)

    bool is_purchase; // true : 구입, false : 판매
} TransHist;
