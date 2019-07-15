
enum title {JUNIOR, SENIOR};
enum specialStatus {NONE, PREGNANT} ;
enum dayOffType {RED_LINE, GREEN_LINE, VACATION_RESERVATION};
//https://tonybai.com/2012/09/26/interoperability-between-go-and-c/
enum color {RED, BLUE, YELLO};
//https://kknews.cc/zh-tw/other/p4pv3vz.html

struct Greetee {
    const char *name;                 
    const char *id;
    enum title position;            
    enum specialStatus status;   
    enum dayOffType askDayOff[31];
    int year; //for test
};

