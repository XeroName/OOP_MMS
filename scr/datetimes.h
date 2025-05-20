// datetimes.h
// 2025-05-05 by XERONAME

// conditional compiling to compile only once
#ifndef COMPILED_DATETIMES // compiled the code from #ifndef to #endif, if the macro 'COMPILED_DATETIMES' was not defined before
#define COMPILED_DATETIMES // define macro for conditional compile

#include <ctime> // provide the date and time related features



// Struct - Date time
typedef struct {
    bool availability; // 해당 날짜 객체의 유효성
    int year; // 연
    int month; // 월
    int day; // 일
    int hour; // 시
    int minute; // 분
    int second; // 초
} Date;

time_t Timestamp; // create instance of time stamp
struct tm Datetime; // create struct instance of date time



void renewTimestamp() { Timestamp = time(NULL); } // update the time stamp to current
void renewDatetime() { Datetime = *localtime(&Timestamp); } // update the date time structure to current local time
void renewTimes() { renewTimestamp(); renewDatetime(); } // update the date time related variables

void assignCurrentDate(Date& target) {
    renewTimes(); // update the date time

    target.year = (Datetime.tm_year +1900); // assign the current year
    target.month = (Datetime.tm_mon +1); // assign the current month
    target.day = Datetime.tm_mday; // assign the current day

    target.hour = Datetime.tm_hour; // assign the current hour
    target.minute = Datetime.tm_min; // assign the current minute
    target.second = Datetime.tm_sec; // assign the current second

    target.availability = true;
}

#endif // end of the conditional compile
